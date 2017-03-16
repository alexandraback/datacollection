#include<iostream>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<string>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define REPN(i,N) for(int i=0;i<N;i++)
#define FORa(i,a,N) for(int i=a;i<N;i++)
#define FORs(i,a,s,N) for(int i=a;i<N;i+=s)
#define vi vector<int>
#define vii vector< vector<int> >
#define LL long long

ifstream fin("Bsmall.in");
//ifstream fin("BLarge.in");
ofstream fout("Bsmall.out");
//ofstream fout("BLarge.out");

int E,R,N;
int Vz[10000010];

int brute(int task,int ELeft)
{
    if(task==N)
    return 0;
    if(ELeft<0)return -1<<30;
    int res=0;
    for(int i=0;i<=ELeft;i++)
    {
        res=max(res,brute(task+1,(ELeft-i+R)>E?E:(ELeft-i+R) )+(Vz[task]*i));
    }
    return res;
}
int main()
{
    int T;
    fin>>T;
    FORa(t,1,T+1)
    {
        fin>>E>>R>>N;
        REPN(i,N)
        {
           fin>>Vz[i];
        }
        fout<<"Case #"<<t<<": "<<brute(0,E)<<endl;
    }
    return 0;
}
