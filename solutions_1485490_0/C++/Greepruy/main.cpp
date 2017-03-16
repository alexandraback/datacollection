#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct NODE
{
    long long num;
    int type;
};
NODE line1[1000];
NODE line2[1000];
int N,M;
long long cal(int i, int j)
{
    if (i == N || j == M)return 0;
    if (line1[i].type == line2[j].type)
    {
        long long Min = line1[i].num;
        bool flag = false;
        if (Min > line2[j].num)
        {
            Min = line2[j].num;
            flag = true;
        }
        line2[j].num -= Min;
        line1[i].num -= Min;

        long long Max = 0;

        if (!flag)
        {
            Max = cal(i+1,j) + Min;
        }
        else
        {
            Max = cal(i,j+1) + Min;
        }
        line2[j].num += Min;
        line1[i].num += Min;
        return Max;
    }
    long long Max2 = cal(i+1,j);
    long long Max1 = cal(i,j+1);
    return  Max1 > Max2 ? Max1 : Max2;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    for (int ci = 1; ci <= T; ++ci)
    {
        cin >> N >>M;
        memset(line1,0,sizeof(line1));
        memset(line2,0,sizeof(line2));
        for (int i = 0; i < N; ++i)
        {
            cin>>line1[i].num>>line1[i].type;

        }

        for (int i = 0; i < M; ++i)
        {
            cin>>line2[i].num>>line2[i].type;
        }
        cout<<"Case #"<<ci<<": ";
        cout <<  cal(0,0)<<endl;
    }
}
