#include<bits/stdc++.h>
#define rep(i,x,y) for(i=x;i<y;i++)
#define rrep(i,x,y) for(i=x;i>=y;i--)
#define trv(y,x) for(typeof(x.begin())y=x.begin();y!=x.end();y++)
#define trvr(y,x) for(typeof(x.rbegin())y=x.rbegin();y!=x.rend();y++)
#define pb(f) push_back(f)
#define pi_ printf("\n")
#define pi(a) printf("%d\n",a)
#define pil(a) printf("%lld\n",a)
#define sc(a) scanf("%d",&a)
#define ll long long
#define scl(a) scanf("%lld",&a)
#define scs(a) scanf("%s",a)
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define inf 1000000009
#define maxn 100009
using namespace std;
//#include<windows.h>
FILE *fin = freopen("1.in","r",stdin);
FILE *fout = freopen("out.txt","w",stdout);
using namespace std;
typedef pair<int,int> pii;
typedef vector<int > vi;
typedef vector< pii > vpii;

int main()
{
	int t,i,j,k,cas=0;
	sc(t);while(t--)
	{
		cas++;	printf("Case #%d: ",cas);
		string s;
		cin>>s;int a[26];
		multiset<int> S;
		rep(i,0,26) a[i]=0;
		rep(i,0,s.length())
		{
			a[(char)s[i]-'A']++;
		}
		while(a[25]!=0)
		{
		//	cout<<a[25]<<endl;
			S.insert(0);
			a[25]--;a[4]--;a[17]--;a[14]--;
		}
		
		while(a[22]!=0)
		{
			S.insert(2);
			a[19]--;a[22]--;a[14]--;
		}
		
		while(a[20]!=0)
		{
			S.insert(4);
			a[20]--;a[5]--;a[14]--;a[17]--;
		}
		
		while(a[23]!=0)
		{
			S.insert(6);
			a[23]--;a[18]--;a[8]--;//a[14]--;
		}
		
		while(a[6]!=0)
		{
			S.insert(8);
			a[6]--;a[4]--;a[8]--;a[7]--;a[19]--;
		}
		
		while(a[14]!=0)
		{
			S.insert(1);
			a[14]--;a[13]--;a[4]--;//a[14]--;
		}
		
		while(a[19]!=0)
		{
			S.insert(3);
			a[19]--;a[7]--;a[17]--;a[4]-=2;
		}
		
		while(a[5]!=0)
		{
			S.insert(5);
			a[5]--;a[8]--;a[21]--;a[4]--;
		}
		
		while(a[18]!=0)
		{
			S.insert(7);
			a[18]--;a[4]-=2;a[21]--;a[13]--;
		}
		
		while(a[13]!=0)
		{
			S.insert(9);
			a[13]-=2;a[8]--;a[4]--;//a[14]--;
		}
	//	cout<<S.size();
		trv(it,S)
		cout<<*it;
		cout<<endl;
	//	cout<<"vfd";
	}
}
