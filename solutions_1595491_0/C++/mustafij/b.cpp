#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<locale>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(a) (int((a).size()))
typedef istringstream iss; typedef ostringstream oss; typedef long long lli;
const double TOLL=1e-9;

bool marked[2][11][40];
int N,S,P, arr[200], memo[110][110];

int recur(int ind,int sur)
{
    if(ind>=N)
    {
        if(sur==S) return 0;
        return -20000;
    }
    if(memo[ind][sur]!=-1) return memo[ind][sur];
    int rv=-20000;
    for(int i=0;i<2;i++) for(int j=0;j<11;j++) if(marked[i][j][arr[ind]])
    {
        int t=recur(ind+1,sur+i);
        if(j>=P) t++;
        rv=max(rv,t);
    }
    return memo[ind][sur]=rv;
}

int main()
{
    memset(marked,false,sizeof marked);

    for(int score=0;score<31;score++)
    {
        for(int i=0;i<11;i++) for(int j=0;j<11;j++)
        {
            int k=score-i-j;
            if(k<0 || k>10) continue;
            int mn=min(min(i,j),k), mx=max(max(i,j),k);
            int ind=0;
            if(mx-mn>2) continue;
            if(mx-mn>1) ind=1;
            marked[ind][i][score]=marked[ind][j][score]=marked[ind][k][score]=true;
        }
    }
    //cerr<<marked[1][8][18];

    int t; cin>>t; int cn=0;
    while(t--)
    {
        cin>>N>>S>>P; memset(memo,-1,sizeof memo);
        for(int i=0;i<N;i++) cin>>arr[i];


        int rv=recur(0,0);
        printf("Case #%d: %d\n",++cn,rv);


    }

}
