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
#define IM 110
#define PI M_PI

#define FU(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define CL(a,v) memset((a),(v),sizeof(a))

using namespace std;

int N,S,P;
int cnt1;
int sum;
int sup;

int main()
{
   // freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int T;
    cin>>T;
    FU(k,1,T+1){
	    sum = cnt1 = 0;
	    sup = 0;
	    cout<<"Case #"<<k<<": ";
	    cin>>N>>S>>P;
	    int x = P*3-4;
	    int y = P*3-2;
	    int te;
	    FU(i,0,N){
		    cin>>te;
		    if(te >= y && te >= P){
			    sum++;
		    }else if(te >= x && te >= P){
			    cnt1++;
		    }
		    if(!(te == 0 || te == 1 || te == 29 || te == 30))
			    sup++;
	    }
	    sum += min(cnt1,S);
	    if(sup < S)
	    sum = min(sum,sup);
	    cout<<sum<<endl;
    }
    return 0;
}
