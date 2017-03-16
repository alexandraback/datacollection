#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!='\0'; ++n)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second

#define pb push_back

const int inv=numeric_limits<int>::max();
const int minv=numeric_limits<int>::min();

int T;

char B[4][10];
bool X,O,e;
bool cX,cO;

int main()
{
	gi(T);
	
	rep(z,T)
	{
		rep(i,4)
			gs(B[i]);
		
		X=false; O=false; e=false;
		
		rep(i,4)
		{
			cX=true; cO=true;
			
			rep(j,4)
			{
				if(B[i][j]=='O')
					cX=false;
				else if(B[i][j]=='X')
					cO=false;
				else if(B[i][j]=='.')
				{
					cX=false;
					cO=false;
					e=true;
				}
			}
			
			X = X or cX;
			O = O or cO;
		}
		
		rep(j,4)
		{
			cX=true; cO=true;
			
			rep(i,4)
			{
				if(B[i][j]=='O')
					cX=false;
				else if(B[i][j]=='X')
					cO=false;
				else if(B[i][j]=='.')
				{
					cX=false;
					cO=false;
				}
			}
			
			X = X or cX;
			O = O or cO;
		}
		
		cX=true; cO=true;
			
		rep(i,4)
		{
			if(B[i][i]=='O')
				cX=false;
			else if(B[i][i]=='X')
				cO=false;
			else if(B[i][i]=='.')
			{
				cX=false;
				cO=false;
			}
		}
		
		X = X or cX;
		O = O or cO;
		
		cX=true; cO=true;
			
		rep(i,4)
		{
			if(B[i][3-i]=='O')
				cX=false;
			else if(B[i][3-i]=='X')
				cO=false;
			else if(B[i][3-i]=='.')
			{
				cX=false;
				cO=false;
			}
		}
		
		X = X or cX;
		O = O or cO;
		
		printf("Case #%d: ",z+1);
		if(X)
			printf("X won\n");
		else if(O)
			printf("O won\n");
		else if(e)
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}
	
	return 0;
}