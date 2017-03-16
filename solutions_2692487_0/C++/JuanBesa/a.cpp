#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

struct State
{
    int M;
    std::vector<int> food;
    int ops;

    State(int _M, std::vector<int> _food, int _ops)
    : M(_M),food(_food), ops(_ops)
    {}
};

void
eat(std::vector<int>& food, int& M)
{
        while(!food.empty())
        {
            if(food.front() < M)
            {
                M += food.front();
                food.erase(food.begin());
            }
            else
                break;
        }
}

int main(void)
{
    int runs;
    std::cin >> runs;

    for(int r = 1; r <= runs; ++r)
    {
        std::cout << "Case #" << r << ": ";

        int M;
        std::cin >> M;
        int N;
        std::cin >> N;

        std::vector<int> food;
        for(int i = 0; i < N; i++)
        {
            int t;
            std::cin >> t;
            food.push_back(t);
        }

        std::sort(food.begin(), food.end());

        while(!food.empty())
        {
            if(food.front() < M)
            {
                M += food.front();
                food.erase(food.begin());
            }
            else
                break;
        }

        std::list<State> queue;
        queue.push_back(State(M,food, 0));

        int min;
        while(!queue.empty())
        {
            State current = queue.front();
            queue.pop_front();
            eat(current.food, current.M);
            if(current.food.size() == 0)
            {
                min = current.ops;
                break;
            }
            queue.push_back(State(current.M + current.M-1, current.food, current.ops+1));
            current.food.pop_back();
            queue.push_back(State(current.M, current.food, current.ops+1));
        }

        std::cout << min << std::endl;
    }

    return 0;
}
