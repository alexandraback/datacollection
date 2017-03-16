#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <bitset>
#include <vector>
#include <utility>
#include <map>
#include <set>

#define INF 1061109567
#define IM 2001000
#define PI M_PI

#define FU(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define CL(a,v) memset((a),(v),sizeof(a))

using namespace std;

int A,B;
bool vis[IM];

int main()
{
//    freopen("in.in","r",stdin);
  //  freopen("out.out","w",stdout);
    int T;
    cin>>T;
    CL(vis,0);
    FU(k,1,T+1){
	    cout<<"Case #"<<k<<": ";
	    cin>>A>>B;
	    int sum = 0;
	    int len = 0;
	    int te = A;
	    while(te){
		    len++;
		    te /= 10;
	    }
	    int E = 1;
	    FU(i,1,len) E *= 10;
	    FU(v,A,B){
		  int x = v;
		  int y = v;
		  int q[10];
		  int cnt = 0;
		  FU(i,1,len){
			  y = x/10 + (x%10)*E;
			  x = y;
			  if(!vis[y] && y > v && y <= B){
				  sum++;
				  q[cnt++] = y;
				  vis[y] = true;
			  }
		  }
		  FU(i,0,cnt)
			  vis[q[i]] = false;
	    }
	    cout<<sum<<endl;
    }
    return 0;
}
