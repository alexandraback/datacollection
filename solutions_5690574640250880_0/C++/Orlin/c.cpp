#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include <pthread.h>

const bool MULTITHREADED = true;
const int NUM_WORKERS = 8;

using std::string;
using std::vector;

struct input_t {
    void read() {
        std::cin >> r >> c >> m;
    }

    int r;
    int c;
    int m;
};

struct output_t {
    void write(const int& case_number) {
        std::cout << "Case #" << case_number << ":\n";

        if (board.empty())
            std::cout << "Impossible\n";
        else if (!transposed) {
            for (int i = 0; i < (int)board.size(); i++) {
                for (int j = 0; j < (int)board[0].size(); j++)
                    std::cout << board[i][j];

                std::cout << '\n';
            }
        } else {
            for (int j = 0; j < (int)board[0].size(); j++) {
                for (int i = 0; i < (int)board.size(); i++)
                    std::cout << board[i][j];

                std::cout << '\n';
            }
        }
    }

    bool transposed;
    vector<string> board;
};

output_t solve(const input_t& input) {
    int r = input.r, c = input.c, m = input.m;
    output_t output;
    vector<string>& board = output.board;

    if (c > r) {
        output.transposed = true;
        int x = c; c = r; r = x;
    } else output.transposed = false;

    if (m == r*c - 1) {
        board = vector<string>(r, string(c, '*'));
        board[0][0] = 'c';
        return output;
    }

    if (c == 1) {
        board = vector<string>(r, ".");
        board[0][0] = 'c';
        for (int i = 0; i < m; i++) board[r-1-i][0] = '*';
        return output;
    }

    if (c == 2) {
        if (m % 2 || m == 2*r - 2) return output;
        board = vector<string>(r, "..");
        board[0][0] = 'c';
        for (int i = 0; i < m; i+=2) board[r-1-i/2] = "**";
        return output;
    }

    if (m > r*c-4) return output;

    if (m <= (r-2)*(c-2)) {
        board = vector<string>(r, string(c, '.'));
        board[0][0] = 'c';
        for (int i = 0; i < r-2 && m; i++)
            for (int j = 0; j < c-2 && m; j++) {
                board[r-1-i][c-1-j] = '*';
                m--;
            }

        return output;
    }

    if ((m - (r-2)*(c-2)) % 2 && m > r*c - 9) return output;

    board = vector<string>(r, string(c, '.'));
    board[0][0] = 'c';
    for (int i = 0; i < r-2; i++)
        for (int j = 0; j < c-2; j++)
            board[r-1-i][c-1-j] = '*';

    m -= (r-2)*(c-2);
    int sent = 1 + m%2;
    if (m % 2) {
        board[2][2] = '.';
        m++;
    }

    for (int i = r-1; i > sent && m; i--) {
        board[i][0] = '*';
        board[i][1] = '*';
        m -= 2;
    }

    for (int j = c-1; j > sent && m; j--) {
        board[0][j] = '*';
        board[1][j] = '*';
        m -= 2;
    }

    return output;
}

struct environment {
    environment(const vector<input_t>& in, vector<output_t>& out)
        : input(in), output(out), task_queue() {

        for (int i = 0; i < (int)input.size(); i++) task_queue.push(i);
        pthread_mutex_init(&queue_mutex, NULL);
    }

    ~environment() {
        pthread_mutex_destroy(&queue_mutex);
    }

    const vector<input_t>& input;
    vector<output_t>& output;
    std::queue<int> task_queue;
    pthread_mutex_t queue_mutex;
};

void* worker_thread(void* _env) {
    environment& env = *(reinterpret_cast<environment*>(_env));

    while (true) {
        int task = -1;
        pthread_mutex_lock(&env.queue_mutex);
        if (!env.task_queue.empty()) {
            task = env.task_queue.front();
            env.task_queue.pop();
        }
        pthread_mutex_unlock(&env.queue_mutex);
    
        if (task == -1) break;

        env.output[task] = solve(env.input[task]);
    }

    return NULL;
}

void solve_all(const vector<input_t>& input, vector<output_t>& output) {
    environment env(input, output);

    vector<pthread_t> threads(NUM_WORKERS);
    for (int i = 0; i < NUM_WORKERS; i++)
        pthread_create(&(threads[i]), NULL, worker_thread, &env);

    for (int i = 0; i < NUM_WORKERS; i++)
        pthread_join(threads[i], NULL);
}

int main() {
    int tests;
    string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    iss >> tests;

    vector<input_t> input(tests);
    vector<output_t> output(tests);
    for (int i = 0; i < tests; i++)
        input[i].read();

    if (MULTITHREADED)
        solve_all(input, output);
    else 
        for (int i = 0; i < tests; i++)
            output[i] = solve(input[i]);

    for (int i = 0; i < tests; i++)
        output[i].write(i+1);

    return 0;
}
