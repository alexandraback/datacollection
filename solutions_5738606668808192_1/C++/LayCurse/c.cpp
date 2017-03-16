#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(double *x){scanf("%lf",x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(double x, char c){printf("%.15f",x);mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

char memarr[17000000]; void *mem = memarr;
#define MD 1000000007

struct myrand32{
  unsigned x,y,z,w;

  myrand32(void){x=123456789,y=362436069,z=521288629,w=(unsigned)time(NULL);}
  myrand32(unsigned seed){x=123456789,y=362436069,z=521288629,w=seed;}
  inline unsigned get(void){unsigned t;t=(x^(x<<11));x=y;y=z;z=w;w=(w^(w>>19))^(t^(t>>8));return w;}
  inline double getUni(void){return get()/4294967296.0;}
  inline int get(int a){return (int)(a*getUni());}
  inline int get(int a, int b){return a+(int)((b-a+1)*getUni());}
  inline ll get(ll a){return(ll)(a*getUni());}
  inline ll get(ll a, ll b){return a+(ll)((b-a+1)*getUni());}
  inline double get(double a, double b){return a+(b-a)*getUni();}
  inline int getExp(int a){return(int)(exp(getUni()*log(a+1.0))-1.0);}
  inline int getExp(int a, int b){return a+(int)(exp(getUni()*log((b-a+1)+1.0))-1.0);}
};

int getPrime(int N, int res[]){int i,a,b,s=1,f[4780],S=1;const int r=23000;bool B[r],*p=B;N/=2;res[0]=2;b=min(r,N);REP(i,1,b)p[i]=1;REP(i,1,b)if(p[i]){res[s++]=2*i+1;f[S]=2*i*(i+1);if(f[S]<N){for(;f[S]<r;f[S]+=res[S])p[f[S]]=0;S++;}}for(a=r;a<N;a+=r){b=min(a+r,N);p-=r;REP(i,a,b)p[i]=1;REP(i,1,S)for(;f[i]<b;f[i]+=res[i])p[f[i]]=0;REP(i,a,b)if(p[i])res[s++]=2*i+1;}return s;}
int ps, p[10000];

int N, J;
set<string> s;
int yaku[22];

int main(){
  int i, j, k, b;
  int T, TC = 0;
  myrand32 rnd;
  string tmp;

  rep(i,100) rnd.get();
  ps = getPrime(10000,p);

  reader(&T);
  while(T--){
    //fprintf(stderr,"rest %d\n",T);
    printf("Case #%d:\n", ++TC);

    reader(&N,&J);

    while(J){
      tmp = "";
      rep(i,N){
        if(i==0 || i==N-1){ tmp += "1"; continue; }
        tmp += '0'+rnd.get(2);
      }
      if(s.count(tmp)) continue;

      REP(b,2,11) yaku[b] = -1;
      REP(b,2,11){
        rep(i,ps){
          if(p[i] > pow(b,N-1)) break;
          k = 0;
          rep(j,N) k = (k*b+tmp[j]-'0') % p[i];
          if(k==0){ yaku[b]=p[i]; break; }
        }
        if(yaku[b]==-1) break;
      }
      if(b!=11) continue;

      J--;
      s.insert(tmp);
      writer(tmp.c_str(),' ');
      writerArr(yaku+2,9);
    }
  }

  return 0;
}
