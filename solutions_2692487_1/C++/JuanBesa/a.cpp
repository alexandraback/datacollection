#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

struct State
{
    long M;
    std::vector<int>::iterator start;
    std::vector<int>::iterator end;
    int ops;

    State(int _M, std::vector<int>::iterator _start,std::vector<int>::iterator _end, int _ops)
    : M(_M),start(_start),end(_end), ops(_ops)
    {}
};

std::vector<int>::iterator
eat(std::vector<int>::iterator start, std::vector<int>::iterator end, long& M)
{
    while(start!= end)
    {
        if(*start < M)
        {
            M += *start;
            start++;
        }
        else
            break;
    }
    return start;
}

int main(void)
{
    int runs;
    std::cin >> runs;

    for(int r = 1; r <= runs; ++r)
    {
        std::cout << "Case #" << r << ": ";

        long M;
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

        std::vector<int>::iterator it = eat(food.begin(),food.end(),M);

        std::list<State> queue;
        queue.push_back(State(M,it, food.end(), 0));

        int min;
        while(!queue.empty())
        {
            State current = queue.front();
            queue.pop_front();
            current.start = eat(current.start,current.end, current.M);
            if(current.start == current.end)
            {
                min = current.ops;
                break;
            }
            if(M != 1)
                queue.push_back(State(current.M + current.M-1, current.start,current.end, current.ops+1));
            queue.push_back(State(current.M, current.start, --current.end, current.ops+1));
        }

        std::cout << min << std::endl;
    }

    return 0;
}
