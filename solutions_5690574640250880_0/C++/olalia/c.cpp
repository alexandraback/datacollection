#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<char> > v;

int r, c;

void printit(){
  for (int i=0; i<r; ++i){
    for (int j=0; j<c; ++j)
      cout<<v[i][j];
    cout<<endl;
  }
  return;
}

int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cout<<"Case #"<<tc<<":\n";
    int m; cin>>r>>c>>m;
    v=vector<vector<char> >(r, vector<char>(c,'*'));
    int mi=min(r, c);
    int n=r*c-m;
    v[r-1][c-1]='c';
    if (mi==1){
      for (int i=m; i<r*c-1; ++i)
	v[i/c][i%c]='.';
      printit();
      continue;
    }
    if (n==1){
      printit();
      continue;
    }
    if (n<4){
      cout<<"Impossible\n";
      continue;
    }
    bool ja=1;
    for (int i=2; ja && i<=r; ++i)
      for (int j=2; ja && j<=c; ++j){
	if (2*i+2*j-4<=n && i*j>=n){
	  ja=0;
	  for (int k=0; k<i; ++k){
	    v[r-1-k][c-1]='.';
	    v[r-1-k][c-2]='.';
	  }
	  for (int k=2; k<j; ++k){
	    v[r-1][c-1-k]='.';
	    v[r-2][c-1-k]='.';
	  }
	  v[r-1][c-1]='c';
	  n-=2*(i+j)-4;
	  for (int k=0; k<n; ++k)
	    v[r-3-k/(j-2)][c-3-k%(j-2)]='.';
	}
      }
    if (ja)
      cout<<"Impossible"<<endl;
    else
      printit();
  }
  return 0;
}
