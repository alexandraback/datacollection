#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <bitset>
#include <list>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int base[16]={1,9,19,109,199,1099,1999,10999,19999,109999,199999,1099999,1999999,10999999,19999999,109999999};
int T;
int main()
{
	freopen("i.txt","r",stdin);
	scanf("%d",&T);
	for (int testcase=1;T--;testcase++){
		printf("Case #%d: ",testcase);
		LL N;
		cin>>N;
		VI num;
		num.clear();
		for (;N;N/=10){
			num.push_back(N%10);
		}
		LL ans=0;
		int len=num.size();
		if (len==1){
			printf("%d\n",num[0]);
			continue;
		}
		int mid=(len-1)/2+1;
		bool prefix,suffix;
	       	prefix=false;
		suffix=false;	
		for (int i=0;i<mid;i++){
			if (num[i]!=0){
				suffix=true;
				break;
			}
		}
		if (!suffix){
			int pos=0;
			for (;pos<len;pos++){
				if (num[pos]!=0)
					break;
			}
			num[pos]--;
			for (pos--;pos>=0;num[pos--]=9);
			ans++;
			if (num[len-1]==0){
				len--;
				mid=(len-1)/2+1;
			}
		}
		if (len==1){
			printf("%d\n",ans+num[0]);
			continue;
		}
		for (int i=1;i<len;i++)
			ans+=base[i];
		ans++;
		for (int i=len-2;i>=mid;i--){
			if (num[i]>0){
				prefix=true;
				break;
			}
		}
		if (num[len-1]>1)
			prefix=true;
		int t=1;
		if (prefix){
			for (int i=len-1;i>=mid;i--){
				ans+=(LL)num[i]*t;
				t*=10;
			}
		}
		t=1;
		for (int i=0;i<mid;i++){
			ans+=(LL)num[i]*t;
			t*=10;
		}
		cout<<ans<<endl;
	}
        return 0;
}
