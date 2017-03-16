#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define INP_FILE "C-small-attempt0.in"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int


int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
    int a,b;
    cin>>a>>b;
    int ans = 0;
    for(int i = a; i<=b; ++i) {
      int d = 1, tmp=i; while(tmp>0) { tmp/=10; d*=10;}
      d/=10;
      tmp = (i%10)*d + i/10;
      while(tmp!=i) { 
        if (a<=tmp && tmp<=b && tmp<i ) ++ans;
        tmp = (tmp%10)*d + tmp/10;
      }
    }
		printf("Case #%d: %d\n",tst,ans);
	}
	
	return 0;
}