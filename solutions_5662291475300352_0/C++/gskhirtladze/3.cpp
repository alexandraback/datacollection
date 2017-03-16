// GSKHIRTLADZE

#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define Pii pair < int , int >
#define tree int t,int l,int r
#define left 2*t,l,(l+r)/2
#define right 2*t+1,(l+r)/2+1,r
#define f_sum(i,r) for (int i=r;i>=0;i=(i&(i+1))-1)
#define f_upd(i,r) for (;i<=r;i=(i|(i+1)))
#define ged(x) scanf("%I64d",&x)
#define getcx getchar
#define LL long long
#define INF 1000000000
#define eps 0.00000001
#define P7 1000000007
#define N5 262145
#define N6 1048577
#define SS system("pause")

using namespace std;

inline void inp(int &n);
LL gcd(LL A,LL B),lcm(LL A,LL B),pow(LL A,LL B,LL P);
vector <int> z_function (string s);
/*/int PR[N5],SZ[N5],parent(int u);void uni(int u,int v);/**/
/*/int lp[N6+2];vector < int > pr;void get_pr(int N);/**/

int t1,t,n,i,j;
vector < pair < double , double > > vec;
double d,h,m;
main() {
    freopen("out.out","w",stdout);
  cin>>t;
  for (t1=1;t1<=t;t1++)
   {
   cout<<"Case #"<<t1<<": ";
       vec.clear();
     cin>>n;
     for (i=1;i<=n;i++)
     {
      cin>>d>>h>>m;
      for (j=m;j<m+h;j++)
       vec.pb(mk(d,360.0/(double)j));
     }
     if (vec.size() ==1)
     {
        cout<<0<<endl;
        continue;
     }
     sort(vec.begin(),vec.end());
    if (vec[0].se > vec[1].se)
     {

      double xx=(vec[1].fi-vec[0].fi)/(vec[0].se-vec[1].se);
      vec[0].fi+=xx*vec[0].se;
      vec[1].fi+=xx*vec[1].se;
      if (vec[0].fi >= 360) { cout<<0<<endl; continue; }
      swap(vec[0],vec[1]);
     }
     if (vec[0].se  == vec[1].se)
      {
         cout<<0<<endl;
         continue;
      }
       double tim2,tim=(360.0-vec[0].fi)/vec[0].se;
       tim2=(360.0+360.0-vec[1].fi)/vec[1].se;
       if (tim2 > tim) cout<<0<<endl; else
                        cout<<1<<endl;
   }

 }

inline void inp(int &n )
 {n=0; int ch=getcx();int sign=1;
  while(ch<'0'||ch>'9'){if(ch=='-')sign=-1; ch=getcx();}
  while(  ch >= '0' && ch <= '9' ) n=(n<<3)+(n<<1)+ch-'0',ch=getcx();
  n=n*sign;}

LL gcd(LL A,LL B) { return A>B?gcd(B,A):A?gcd(B%A,A):B; }
LL lcm(LL A,LL B) { return A/gcd(A,B)*B; }
LL pow(LL A,LL B,LL P) { if (!B) return 1%P; LL h=pow(A,B/2,P); h=(h*h)%P; if (B%2) h*=A; return h%P; }

/*/vector <int> z_function (string s) {
  int n = (int) s.length(); vector<int> z (n);
  for (int i=1, l=0, r=0; i<n; ++i) {
    if (i <= r) z[i] = min (r-i+1, z[i-l]);
    while (i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
    if (i+z[i]-1 > r) l = i,  r = i+z[i]-1; } return z; }/**/

/*/void get_pr(int N) {
 for (int i=2;i<=N;i++)
  {if (lp[i] == 0){ pr.pb(i); lp[i]=i; }
   for (int j=0;j<pr.size()&& pr[j]<=lp[i] && pr[j]*i<=N;j++) lp[pr[j]*i]=pr[j]; } }/**/

/*/int parent(int u) {
  if (PR[u] == u) return u;
  PR[u]=parent(PR[u]);return PR[u];}/**/

/*/void uni(int u,int v){
 u=parent(u); v=parent(v);
 SZ[u]+=SZ[v]; SZ[v]=0; PR[v]=u;}/**/
