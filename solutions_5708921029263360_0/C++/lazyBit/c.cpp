#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
 
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>
 
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
// #include <random>
 
using namespace std;
 
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <string> vs;
 
typedef long long LL; //NOTES:int64
typedef unsigned long long ULL; //NOTES:uint64
typedef unsigned uint;
 
const double pi = acos(-1.0); //NOTES:pi
const double eps = 1e-11; //NOTES:eps
const int MAXI = 0x7fffffff;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dz[] = "SENW";
 
#define rep(i,n)        for (int i=0;i<n;i++)
#define loop(i,a,b)     for (int i=(a),_b=(b); i<_b; i++)
#define rloop(i,b,a)    for (int i=(b)-1,_a=(a); i>=_a; i--)
#define Reset(a,b)      memset((a),(b),sizeof(a))
 
#define endline         putchar('\n')
#define space           putchar(' ')
#define EXIT(x)         {cout << x;return 0;}
 
#define fi              first
#define se              second
#define pb              push_back
 
#define S(x)            scanf("%d",&x);
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define deb(i,a,n) for(i=0;i<n;i++){cout<<a[i]<<" ";}
#define db(x,y)          printf("%d %d\n",x,y);
#define debug(args...)	{dbg,args; cerr<<endl;}
#define dline			cerr<<endl	
#define INF				(int)1e9
#define LINF			(long long)1e18
#define EPS				1e-9
#define maX(a,b)		((a)>(b)?(a):(b))
#define miN(a,b)		((a)<(b)?(a):(b))
#define abS(x)			((x)<0?-(x):(x))
#define mod             1000000007
 
struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{	
		cerr<<v<<" ";	
		return *this;	
	}
} dbg;
 
void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}
 
map<string,int> mp;
map<string,bool> mp1;
vector<string> v;
void print9(int j,int p,int ss,int num) {
	vector<string> ans;
	if(j==1) {
		ans.push_back("1 1 1");
		ans.push_back("1 1 2");
		ans.push_back("1 2 2");
		ans.push_back("1 2 3");
		ans.push_back("1 3 1");
		ans.push_back("1 3 3");
	} else if(p==1) {

		ans.push_back("1 1 1");
		ans.push_back("1 1 2");
		ans.push_back("2 1 2");
		ans.push_back("2 1 3");
		ans.push_back("3 1 1");
		ans.push_back("3 1 3");

} else {

		ans.push_back("1 1 1");
		ans.push_back("2 1 1");
		ans.push_back("2 2 1");
		ans.push_back("3 2 1");
		ans.push_back("1 3 1");
		ans.push_back("3 3 1");

}

printf("Case #%d: %d\n",num,6);
 		for(int i=0;i<ans.size();i++) {
 			cout<<ans[i]<<endl;
 		}
}
int main()
{
	#ifndef ONLINE_JUDGE
        input;
        output;
    #endif
	int n,i,j,k,l,m,t,ss=0,d,p;
	char a,b,c;
	int num=1;
	S(t);
	while(t--){
		mp.clear();
		mp1.clear();
		v.clear();
 		S(j);S(p);S(ss);S(k);

 		int possibilities = j*p*ss;
 		if(possibilities==9) {print9(j,p,ss,num);num++;continue;}
 		for(int i=0;i<j;i++) 
 			for(int ii=0;ii<p;ii++)
 				for(int iii=0;iii<ss;iii++) {


 			a = char('a'+i);
 			b = char('k'+ii);
 			c = char('s'+iii);

 			string ans="";
 			
 			// cout<<ans;
 			ans+=char('1'+i);
 			ans+=" ";
 			ans+=char('1'+ii);
 			ans+=" ";
 			ans+=char('1'+iii);
 			if(mp1[ans]!=1) {
 				mp1[ans]=1;
 			} else continue;

 			string s1 = "";
 			s1+=a;
 			s1+=b;
 	      // cout<<a<<' '<<b<<' '<<c<<endl;
 			// cout<<s<<' '<<k<<' '<<mp[s]<<endl;
 		if(mp[s1]+1>k) continue;
 		string s2="";
 		s2+=b;
 		s2+=c;
 		// cout<<s2<<' '<<k<<endl;
 		if(mp[s2]+1>k) continue;
 		string s3="";
 		s3+=a;
 		s3+=c;
 		// cout<<s3<<' '<<k<<endl;
 		if(mp[s3]+1>k) continue;
 		 
 		mp[s1]++;
 		mp[s2]++;
 		mp[s3]++;
 			v.push_back(ans);
 			


 		
 	}

 		printf("Case #%d: %d\n",num++,(int)v.size());
 		for(i=0;i<v.size();i++) {
 			cout<<v[i]<<endl;
 		}

 		// if(possibilities==9) {
 		// 	if(k==2){
 		// 	if(v.size()!=6) break;
 		// }
 		// }
	}
	return (0);
} 
