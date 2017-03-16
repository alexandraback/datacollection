#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <future>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
#include <sstream>
#include <memory>
#include <atomic>
#include <queue>
#include <array>
#include <functional>

// -----
// =====

using ll = long long;

ll rev_num(ll _n)
{
	ll res = 0;
	while (_n > 0) {
		res *= 10;
		res += (_n % 10);
		_n /= 10;
	}
	return res;
}

std::unordered_map<ll, std::vector<ll>> graph;

void prepare_graph()
{
	for (ll i = 1; i < 1000000; ++i) {
		graph[i].push_back(i+1);
	}
	for (ll i = 10; i <= 1000000; ++i) {
		graph[i].push_back(rev_num(i));
	}
}

struct Solution
{
	int case_id;
	/* Input fields HERE */
	ll N;
	// ------------------- 

	void read(int _case)
	{
		case_id = _case;
		/* Reading input HERE */
		std::cin >> N;
		// --------------------
	}

	std::stringstream solve()
	{
		std::stringstream out;
		out << "Case #" << case_id << ": ";
		/*  Solution HERE  */
		std::vector<bool> used(1000001, false);
		std::vector<ll> way(1000001, 9999999);
		std::queue<ll> q;
		q.push(1);
		way[1] = 1;
		while (!q.empty()) {
			ll t = q.front();
			q.pop();
			used[t] = true;
			if (t == N) {
				out << way[t] << '\n';
				break;
			}
			for (auto &v : graph[t]) {
				if (!used[v]) {
					way[v] = std::min(way[v], way[t] + 1);
					q.push(v);
				}
			}
		}
		// -----------------
		return out;
	}
};

// ---- Thread-safe Queue template

template <class F>
class thread_pool;

template <class R, class ...Args>
class thread_pool<R(Args...)>
{
public:
	using task_type = std::packaged_task<R(Args...)>;

	thread_pool(unsigned int thread_count = std::thread::hardware_concurrency()) 
	{
		finish.store(false);
		for (unsigned int t = 0; t < thread_count; ++t) {
			threads.emplace_back(&thread_pool::thread_function, this);
		}
	}

	~thread_pool()
	{
		if (!finish.load()) {
			shutdown();
		}
	}

	std::future<R> submit(std::function<R(Args...)> &&data)
	{
		std::shared_ptr<task_type> task = std::make_shared<task_type>(task_type(data));
		std::future<R> result = task->get_future();
		std::unique_lock<std::mutex> lock(mutex);
		queue.push(task);
		lock.unlock();
		non_empty_cond.notify_one();
		return result;
	}

	void shutdown()
	{
		finish.store(true);
		non_empty_cond.notify_all();
		for (auto &thread : threads) {
			thread.join();
		}
		threads.clear();
	}

	bool flag()
	{
		return finish.load();
	}

private:
	std::shared_ptr<task_type> pop_task()
	{
		std::unique_lock<std::mutex> lock(mutex);
		while (!finish.load() && queue.empty()) {
			non_empty_cond.wait(lock);
		}
		if (finish.load()) {
			return std::shared_ptr<task_type>();
		}
		std::shared_ptr<task_type> result;
		queue.front().swap(result);
		queue.pop();
		return result;
	}

	void thread_function()
	{
		std::cerr << "Thread " << std::this_thread::get_id() << " started.\n";
		while (!flag()) {
			std::shared_ptr<task_type> task = pop_task();
			if (task) {
				(*task)();
			}
		}
		std::cerr << "Thread " << std::this_thread::get_id() << " finished.\n";
	}

	
	std::vector<std::thread>				threads;
	std::atomic<bool>						finish;
	std::mutex								mutex;
	std::condition_variable					non_empty_cond;
	std::queue<std::shared_ptr<task_type>>	queue;
};

// -----


// -----
// =====


int main()
{
	prepare_graph();

	thread_pool<std::stringstream()>			pool;
	std::vector<std::future<std::stringstream>>	results;

	int T; std::cin >> T;
	for (int c = 1; c <= T; ++c) {
		std::shared_ptr<Solution> solution = std::make_shared<Solution>();
		solution->read(c);
		results.push_back(pool.submit(std::bind(&Solution::solve, solution)));
	}

	for (auto &out : results) {
		std::cout << out.get().str();
	}

	return 0;
}