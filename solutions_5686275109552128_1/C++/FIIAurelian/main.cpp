#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;


int T,N,P[1010],solution,ok,cnt,x;

int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    cin>>T;
    for(int t = 1; t <= T; t++)
    {
        cin>>N;
        for(int i = 1; i <= N; i++)
        {
            cin>>P[i];
        }
        solution = 0;
        for(int result = 1; result <= 20000000; result++)
        {
            for(int moves = 0; moves < result; moves++)
            {
                int eat = result - moves;
                cnt = 0;
                for(int i = 1; i <= N; i++)
                {
                    x = P[i];
                    cnt = cnt + x / eat;
                    if(x % eat == 0)
                        cnt = cnt - 1;
                }
                if(cnt <= moves)
                {
                    solution = result;
                    break;
                }
            }
            if(solution)break;
        }
        cout<<"Case #"<<t<<": "<<solution<<"\n";
    }
    return 0;
}
