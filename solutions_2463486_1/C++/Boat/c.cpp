#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<set>

using namespace std;

long long numm[1000];

char x[100];
int countu(long long n){
     int i=0;
     while(n!=0){
          x[i]='0'+n%10;
          i++;
          n=n/10;
     }
     return i;
}
int isParin(long long n){
     int i=countu(n);
     for(int j=0;j<(i)/2;j++){
          if(x[j]!=x[i-1-j]) return 0;
     }
     return 1;
}

long long ii;
int cnt=1;
int main(){
     freopen("c.txt","w",stdout);
     freopen("C-large-1.in","r",stdin);

     numm[0]=0;
     for(long long i=1;i<10000000;i++){
          if(isParin(i)==1){
          ii=i*i;
          if(isParin(ii)==1){
               numm[cnt]=ii;
               cnt++;
          } //printf("%lld\t\t%lld\n",i,ii);
          }
     }
     numm[cnt]=100000000000000;
     int cnta,cntb;
     int t;
     int a,b;
     long long aa,bb;
     //printf("cnt %d\n",cnt);
     scanf("%d",&t);

     for(int ii=1;ii<=t;ii++){
          cnt=0;
          scanf("%lld %lld",&aa,&bb);
          //printf("%lld %lld",aa,bb);
          cntb=39;
          for(int i=1;i<40;i++){
               //printf(">%d %lld\n",i,numm[i]);
               if(numm[i]>=aa && numm[i-1]<aa) cnta=i-1;
               if(numm[i]>bb){ cntb=i-1; break; }
          }
          //printf("%d %d\n",cntb,cnta);
          printf("Case #%d: %d\n",ii,cntb-cnta);
     }

     return 0;
}
