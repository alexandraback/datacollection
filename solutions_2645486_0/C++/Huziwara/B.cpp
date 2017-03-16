#include <cstdio>
#include <algorithm>
using namespace std;


int bitmax(int bit[1<<14],int k)
{
  int m=0;
  while(k){
    //printf("%d %d\n",k,k&(-k));
    m=max(m,bit[k]);
    k-=k&(-k);
  }
  return m;
}

void bitadd(int bit[1<<14],int k,int v)
{
  while(k<1<<14){
    bit[k]=max(bit[k],v);
    k+=k&(-k);
  }
}


int main()
{
  int T;
  scanf("%d",&T);
  for(int C=1;C<=T;C++){
    long long E,R;
    int n;
    scanf("%lld%lld%d",&E,&R,&n);
    static pair<int,int> v[10000000];
    for(int i=0;i<n;i++){
      scanf("%d",&(v[i].first));
      v[i].second=i;
    }
    sort(v,v+n);
    int bit1[1<<14]={0},bit2[1<<14]={0};
    long long A=0;
    for(int i=n-1;i>=0;i--){
      //printf("%d %d\n",i,v[i].second);
      int V=v[i].first,j=v[i].second,k=bitmax(bit1,j+1),l=bitmax(bit2,n-j);
      //printf("%d %d\n",i,v[i].second);
      long long E1=E,E2=0;
      if(k>0){
	k=k-1;
	if(E1>(j-k)*R){
	  E1=(j-k)*R;
	}
      }
      if(l>0){
	l=n-l;
	if(E2<E-(l-j)*R){
	  E2=E-(l-j)*R;
	}
      }
      if(E1>E2){
	A+=(E1-E2)*V;
      }
      //printf("%d %d %d %lld %lld\n",j,k,l,E1,E2);
      bitadd(bit1,j+1,j+1);
      bitadd(bit2,n-j,n-j);
    }
    printf("Case #%d: %lld\n",C,A);
  }
  return 0;
}
