#include<iostream>
#include<algorithm>

using namespace std;

int N;
int T;
int F[1111];
int t;

bool rec(int *ans,int n,int c,int u){
  if(n==c){
    if(!((F[ans[0]]==ans[1]||F[ans[0]]==ans[n-1])&&(F[ans[n-1]]==ans[0]||F[ans[n-1]]==ans[n-2]))){
      return false;
    }else{
      for(int i=0;i<n;i++){
	//	cerr<<ans[i]<<endl;
      }
      cout<<"Case #"<<t<<": "<<n<<endl;
      return true;
    }
  }else{
    for(int i=0;i<N;i++){
      if(!(u>>i&1)){
	ans[c]=i;
	if(c>=2){
	  auto p=ans[c-1];
	  if(ans[c-2]!=F[p]&&ans[c]!=F[p])continue;
	}
	if(rec(ans,n,c+1,u|1<<i))return true;
      }
    }
    return false;
  }
}

int main(){
  cin>>T;
  for(t=1;t<=T;t++){
    cin>>N;
    for(int i=0;i<N;i++){
      cin>>F[i];
      F[i]--;
    }
    int ans[1111];
    for(int i=N;!rec(ans,i,0,0);i--);
  }
}
