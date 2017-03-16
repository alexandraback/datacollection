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
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

#define maxn 60
#define maxm 110
#define maxnumber 10000000

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

/*int d[20];

bool ispalindromes(LL p)
{
	int l=0;
	while (p)
	{
		d[++l]=p%10;
		p/=10;
	}
	bool flag=true;
	for (int i=1;i<=l/2;i++)
		if (d[i]!=d[l+1-i]) flag=false;
	return flag;
}*/

LL a[maxn];

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
	
	/*int count=0;
	for (LL i=1;i<=maxnumber;i++)
	{
		LL p=i*i;
		if (ispalindromes(i) && ispalindromes(p))
			cout<<"    a["<<++count<<"]="<<p<<"LL;"<<endl;
	}*/

    a[1]=1LL;
    a[2]=4LL;
    a[3]=9LL;
    a[4]=121LL;
    a[5]=484LL;
    a[6]=10201LL;
    a[7]=12321LL;
    a[8]=14641LL;
    a[9]=40804LL;
    a[10]=44944LL;
    a[11]=1002001LL;
    a[12]=1234321LL;
    a[13]=4008004LL;
    a[14]=100020001LL;
    a[15]=102030201LL;
    a[16]=104060401LL;
    a[17]=121242121LL;
    a[18]=123454321LL;
    a[19]=125686521LL;
    a[20]=400080004LL;
    a[21]=404090404LL;
    a[22]=10000200001LL;
    a[23]=10221412201LL;
    a[24]=12102420121LL;
    a[25]=12345654321LL;
    a[26]=40000800004LL;
    a[27]=1000002000001LL;
    a[28]=1002003002001LL;
    a[29]=1004006004001LL;
    a[30]=1020304030201LL;
    a[31]=1022325232201LL;
    a[32]=1024348434201LL;
    a[33]=1210024200121LL;
    a[34]=1212225222121LL;
    a[35]=1214428244121LL;
    a[36]=1232346432321LL;
    a[37]=1234567654321LL;
    a[38]=4000008000004LL;
    a[39]=4004009004004LL;

	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		printf("Case #%d: ",TT);
		LL l,r;
		cin>>l>>r;
		int ans=0;
		for (int i=1;i<=55;i++)
			if (a[i]>=l && a[i]<=r) ans++;
		cout<<ans<<endl;
	}
	
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
