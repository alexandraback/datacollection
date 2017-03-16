#include<cstdio>
#include<queue>

using namespace std;

#define MAX_PAN 1000

class Dinners
{
public:
    Dinners(){}
    int Input()
    {
        int D=0;
        scanf("%d", &D);

        while(!pancakes.empty()) pancakes.pop();

        for(int i=0; i<D; i++)
        {
            int pancake = 0;
            scanf("%d", &pancake);
            pancakes.push(pancake);
        }

        return 0;
    }

    int GetSmallMinutes()
    {
        int special_min = 0;
        int small_cost_min = pancakes.top();

        int i=0;
        for(; i<small_cost_min-1; i++)
            dinner_time[i] = 0;

        while(!pancakes.empty())
        {
            int pancake = pancakes.top();

            int dinner_time_tmp[MAX_PAN];
            int i=0;
            for(; i<small_cost_min-1; i++)
                dinner_time_tmp[i] = -1;

            for(i=0; i<pancake; i++)
                for(int j=0; j+i<small_cost_min-1; j++)
                {
                    int cur_cost_time = (pancake+i)/(i+1);
                    if(cur_cost_time < dinner_time[j])
                        cur_cost_time = dinner_time[j];

                    if(dinner_time_tmp[j+i] == -1 || cur_cost_time < dinner_time_tmp[j+i])
                    {
                        dinner_time_tmp[j+i] = cur_cost_time;
                    }
                }

            for(i=0; i<small_cost_min-1; i++)
            {
                dinner_time[i] = dinner_time_tmp[i];
            }
            pancakes.pop();
        }

        for(i=0; i<small_cost_min-1; i++)
            if(dinner_time[i]+i < small_cost_min)
                small_cost_min = dinner_time[i]+i;

        return small_cost_min;
    }
private:
    priority_queue<int> pancakes;
    int dinner_time[MAX_PAN];
};


Dinners testObj;
int main(int argc, char* argv[])
{
    int T=0;
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        testObj.Input();
        printf("Case #%d: %d\n", i+1, testObj.GetSmallMinutes());
    }
    return 0;
}

