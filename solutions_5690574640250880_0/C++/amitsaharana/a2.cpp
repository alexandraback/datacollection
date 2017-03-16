#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked

int n,m,b;
int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};
bool v[25];
vector<int> d;
int z;

void go(int x, int y) {
  if(v[x*m+y] || d[x*m+y]) return;
  v[x*m+y] = 1;
  int tot = 0;
  for(int i=0; i<8; i++){ 
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>=0 && nx<n && ny>=0 && ny<m && d[nx*m+ny]) {
	tot = 1;
	//if(z==2) cout<<"Found: "<<nx<<" "<<ny<<endl;
	break;
      }
      // }
  }
    /*
    if(z==2) {
      cout<<"Visiting: "<<x<<" "<<y<<" "<<tot<<endl;
      for(int i=0; i<n*m; i++) {
	cout<<d[i];
      }
      cout<<endl;
    }
    */
  if(!tot) {
    for(int i=0; i<8; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0 && nx<n && ny>=0 && ny<m && (!d[nx*m+ny]) && (!v[nx*m+ny])) {
	  go(nx,ny);
	}
	//	}
    }
  }
}
  
  


int main() {  
  //ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  for(z=1; z<=t; z++) {
    cout<<"Case #"<<z<<":"<<endl;
    cin>>n>>m>>b;
    vector<int> a(n*m);
    d.resize(n*m);
    for(int i=0; i<b; i++) a[i] = 1;
    sort(a.begin(),a.end());
    do {
      /*if(z==2) {
	cout<<"New Perm:"<<endl;
	for(int i=0; i<n*m; i++) {
	  cout<<a[i];
	}
	cout<<endl;
	}*/
      for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
	  if(a[i*n+j]==0) {
	    for(int k=0; k<n*m; k++) v[k] = 0;
	    for(int k=0; k<n*m; k++) d[k] = a[k];
	    go(i,j);
	    /*if(z==2) {
	      cout<<"Clicking: "<<i<<" "<<j<<endl;
	      for(int k=0; k<n*m; k++) cout<<v[k];
	      cout<<endl;
	      }*/
	    bool f= true;
	    for(int k=0; k<n*m; k++) {
	      if(a[k]==0 && v[k]==0) {
		f = false;
	        goto out1;
	      }
	    }
	  out1:
	    if(f) {
	      for(int k=0; k<n; k++) {
		for(int l=0; l<m; l++) {
		  if(i==k && l==j) cout<<"c";
		  else if(a[k*m+l]==0) cout<<".";
		  else cout<<"*";
		}
		cout<<endl;
	      }
	      goto out2;
	    }
	  }
	}
      }	  
    } while(next_permutation(a.begin(),a.end()));
    cout<<"Impossible"<<endl;
  out2:
    ;
  }
  return 0;
}
