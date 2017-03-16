#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int T, N, nr, sum, solution;
string S;

int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    cin>>T;
    for(int t = 1; t <= T; t++)
    {
        cin>>N>>S;
        sum = 0;
        solution = 0;
        for(int i = 0; i <= N; i++)
        {
            nr = S[i] - '0';
            if(i > sum)
            {
                solution = solution + i - sum;
                sum = i;
            }
            sum = sum + nr;
        }
        cout<<"Case #"<<t<<": "<<solution<<"\n";
    }
    return 0;
}
