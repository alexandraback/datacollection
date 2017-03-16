#include <bits/stdc++.h>
	
using namespace std;
	
#ifndef ONLINE_JUDGE
	bool debug = false;
#else
	bool debug = true;
#endif
	
typedef long long unsigned llu;
typedef long long lld;
typedef long ld;

//definition

//macros
#define vi  	vector < int >
#define vld 	vector < ld >
#define vlld 	vector < lld >
#define vllu 	vector < llu >
#define pii 	pair <int, int>
#define plld 	pair<lld, lld>
#define vpii 	vector< pii >
#define vplld 	vector< plld >

#define gc  	getchar_unlocked
#define pc  	putchar_unlocked
#define rr  	freopen("input.txt", "r", stdin)
#define wr  	freopen("output.txt", "w", stdout)

//important constants
#define MOD 	1000000007
#define INF  	1LL<<57LL
#define MAX 	1000001
#define pi  	M_PI
#define ESP 	(1e-9)

//looping
#define fr(i,a)         	for(i=0;i<a;i++)
#define fe(i,a)         	for(i=0;i<=a;i++)
#define fu(i,a,n)       	for(i=a;i<n;i++)
#define fue(i,a,n)      	for(i=a;i<=n;i++)
#define fd(i,n,a)       	for(i=n;i>a;i--)
#define fde(i,n,a)      	for(i=n;i>=a;i--)
#define tr(container, it)	for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

//input output
#define sd(n) 		scanf("%d",&n)
#define sld(n) 		scanf("%ld",&n)
#define slld(n) 	scanf("%lld",&n)
#define pfd(n) 		printf("%d",n)
#define pfld(n) 	printf("%ld",n)
#define pflld(n) 	printf("%lld",n)

//shortcut
#define ff      	first
#define ss      	second
#define clr     	clear()
#define pb      	push_back
#define mp      	make_pair
#define gcd(a,b)	__gcd(a,b)
#define sz(a)		((int)(a.size()))
#define len(a)		((int)a.length())
#define all(vi)		vi.begin(), vi.end()
#define mem(i,n)	memset(i,n,sizeof(i))
#define IOS     	ios_base::sync_with_stdio(false); cin.tie(NULL)

#define imax 	numeric_limits<int>::max()
#define imin 	numeric_limits<int>::min()
#define ldmax 	numeric_limits<ld>::max()
#define ldmin 	numeric_limits<ld>::min()
#define lldmax 	numeric_limits<lld>::max()
#define lldmin 	numeric_limits<lld>::min()
//end of definition

const int dx[]={0,1,0,-1,1,1,-1,-1,0};
const int dy[]={1,0,-1,0,-1,1,1,-1,0};

template<typename X> inline X square(const X& a) { return a * a; }


//fast input

int scan_d()		{bool minus = false;int result = 0;char ch;ch = gc();while (true){if (ch == '-') break;if (ch >= '0' && ch <= '9') break;ch = gc();}if (ch == '-') minus = true; else result = ch-'0'; while (true){ch = gc(); if (ch < '0' || ch > '9') break;result = (result<<3) + (result<<1) + (ch - '0');}if (minus) return -result; else return result;}
ld scan_ld()		{bool minus = false;ld result = 0;char ch;ch = gc();while (true){if (ch == '-') break;if (ch >= '0' && ch <= '9') break;ch = gc();}if (ch == '-') minus = true; else result = ch-'0'; while (true){ch = gc(); if (ch < '0' || ch > '9') break;result = (result<<3) + (result<<1) + (ch - '0');}if (minus) return -result; else return result;}
lld scan_lld()		{bool minus = false;lld result = 0;char ch;ch = gc();while (true){if (ch == '-') break;if (ch >= '0' && ch <= '9') break;ch = gc();}if (ch == '-') minus = true; else result = ch-'0'; while (true){ch = gc(); if (ch < '0' || ch > '9') break;result = (result<<3) + (result<<1) + (ch - '0');}if (minus) return -result; else return result;}
llu scan_llu()		{llu result = 0;char ch;ch = gc();while (true){if (ch == '-') break;if (ch >= '0' && ch <= '9') break;ch = gc();}result = ch-'0'; while (true){ch = gc(); if (ch < '0' || ch > '9') break;result = (result<<3) + (result<<1) + (ch - '0');}return result;}

//end of fast input

//fast output

//no line break
void print_d(int n)     	{if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     	{if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     	{if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     	{int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}

//new line
void println_d(int n)		{if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)		{if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)		{if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)		{int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}

//special char
char sp;
void printsp_d(int n)		{if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)		{if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)		{if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)		{int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}

//end of fast output

int main()
{
	rr;wr;
	IOS;
    int t,TT,n,i,j,temp;
    string a,b;
    t=scan_d();
    fue(TT,1,t)
    {
        string x[16],y[16];
		int a[16],b[16];
		n=scan_d();
		map<string,int>M,N;
		map<string,int>::iterator it;
		fr(i,n)
		{
			cin >> x[i] >> y[i];
			M[x[i]] = 0;
			N[y[i]] = 0;
		}
		int nx = 1;
		tr(M,it)
			it->ss = nx++;
		nx=1;
		tr(N,it)
			it->ss = nx++;
		fr(i,n)
		{
			a[i] = M[x[i]];
			b[i] = N[y[i]];
		}
		int dp[(1<<16)+5]={}; fill(dp,dp+(1<<n),-100000);
		dp[0] = 0;
		fr(i,1<<n)
		{
			int L=0,R=0;
			fr(j,n)
			{
				if(((i>>j)&1)){
					L |= (1<<a[j]);
					R |= (1<<b[j]);
				}
			}
			fr(j,n)
			{
				if(!((i>>j)&1))
				{
					temp=((L|(1<<a[j]))==L && (R|(1<<b[j]))==R);
					dp[i+(1<<j)] = max(dp[i+(1<<j)],dp[i]+temp);
				}
			}
		}
        printf("Case #%d: ",TT);
        println_d(dp[(1<<n)-1]);
    }
}
