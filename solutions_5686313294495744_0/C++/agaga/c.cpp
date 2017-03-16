#include<bits/stdc++.h>
using namespace std;
const int mod=1000000009;
int wart[20][2];
bool tab[20], ok[20][2];
queue<int>q;
int main(){
  int test;
  scanf("%d",&test);
  for(int t=1;t<=test;t++){
    int n, maxi=0;
    scanf("%d",&n);
    char a[2][30];
    for(int i=1;i<=n;i++) {
      scanf(" %s %s", a[0], a[1]);
      for(int j=0;j<2;j++){
	long long w=0;
	for(int k=0;a[j][k];k++){
	  w*=31;
	  if(w>=mod) w%=mod;
	  w+=a[j][k]-'A';
	}
	wart[i][j]=w%mod;
      }
    }
    for(int i=0;i<(1<<n);i++){ //te są niby złe
      int copy=i, faked=0, wpis=0;
      for(int j=1;j<=n;j++){
	
	tab[j]=copy%2;
	copy/=2;
	if(tab[j]==0) q.push(j);
	else faked++;
      }
      while(q.size()){
	int nr=q.front();
	q.pop();
	wpis++;
	for(int j=1;j<=n;j++){
	  if(!tab[j]) continue;
	  if(wart[j][0]==wart[nr][0]) ok[j][0]=1;
	  if(wart[j][1]==wart[nr][1]) ok[j][1]=1;
	  if(ok[j][0] and ok[j][1]) {
	    tab[j]=0;
	    q.push(j);
	  }
	}
      }
      if(wpis==n) maxi=max(maxi, faked);
      for(int i=1;i<=n;i++) ok[i][0]=ok[i][1]=0;
    }
    printf("Case #%d: %d\n", t, maxi);
    for(int i=1;i<=n;i++) wart[i][0]=wart[i][1]=0;
  }
  return 0;
}