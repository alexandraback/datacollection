#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

#define FOR(i,a,b) for(int i = a ; i < b ; ++i)
#define MAX 1010

int N, a[MAX], bst, b[MAX], stars, done1[MAX], done2[MAX], ans, best;

int main(){
  
  int T, i;
  
  cin>>T;
  
  for(int k = 0 ; k < T ; ++k){
  
  ans = stars = 0;
  cin>>N;
  FOR(j,0,N){
    cin>>a[j]>>b[j];
    done1[j] = done2[j] = 0;
  }
  while(stars < 2*N){
    for(i = 0 ; i < N ; ++i)
      if((b[i] <= stars)&&!done2[i]){
	stars += 2-done1[i];
	done1[i] = done2[i] = 1;
	ans++;
	break;
      }
    if(i == N){
      best = -1;
      for(i = 0 ; i < N ; ++i)
	if((a[i] <= stars)&&!done1[i]){
	  if(b[i] > best){
	    best = b[i];
	    bst = i;
	  }
	}
      stars++;
      done1[bst] = 1;
      ans++;
      if(best == -1){
	printf("Case #%d: Too Bad\n", k+1);
	ans = 0;
	break;
      }
    }
  }
  if(ans){
    printf("Case #%d: ", k+1);	cout<<ans<<endl;
  }
  
  }
  
  return 0;
  
}