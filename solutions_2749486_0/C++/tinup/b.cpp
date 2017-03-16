/*Author : Punit Singh */
// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>
//Data Structures
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))

typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
void precompute()
{

}
int main()
{
    #ifdef TEST
    freopen("B-small-attempt4.in","r",stdin);
 	freopen("out.txt","w",stdout);
    #endif
    precompute();
    int t,ctr=1,x,y,z,step;
    bool f;
    string s;
    cin>>t;
    while(ctr<=t)
    {
        s="";
        //f=false;
        cin>>x>>y;
        step=0;
        if(y<0)
        {
            rep(i,abs(y+1)){
            s+="SN";step+=2;}
            s+="S";step++;
        }
        else if(y>0)
        {
            rep(i,y-1){
            s+="NS";step+=2;}
            s+="N";step++;
        }
        step=sz(s)+1;
        if(x<0)
        {
            if(abs(x)<step)
            {
                rep(i,abs(x))
                s+="EW";
            }
            else
            {
                s+="W";
                rep(i,abs(x)-step)
                s+="EW";
            }
        }
        else if(x>0)
        {
            if(x<step)
            {
                rep(i,x)
                s+="WE";
            }
            else
            {
                s+="E";
                rep(i,x-step)
                s+="WE";
            }
        }
        printf("Case #%d: ",ctr++);
        cout<<s<<endl;
    }
    return 0;
}
