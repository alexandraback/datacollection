#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked

int n,m,b;
int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};
bool v[5500];
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

  
int e[55][55];

int main2() {  
  //ios_base::sync_with_stdio(0);
  int t=1;
  cin>>t;
  for(z=1; z<=t; z++) {
    cout<<"Case #"<<z<<":"<<endl;
    cin>>n>>m>>b;
    //cout<<"N: "<<n<<" "<<m<<" "<<b<<endl;
    int b2 = b;
    memset(e,0,sizeof(e));
    bool f= true;
    if(n==1 || m==1) {
      if(n==1) {
	for(int i=n*m-1; i>=n*m-b; i--) e[0][i] = 1;
      }
      else {
	for(int i=n*m-1; i>=n*m-b; i--) e[i][0] = 1;
      }
    }
    else if(n==2 || m==2) {
      if(b==n*m-2 || (b%2 && b!=n*m-1)) f = false;
      else if(b==n*m-1) {
	for(int i=0; i<n; i++) {
	  for(int j=0; j<m; j++) {
	    e[i][j] = 1;
	  }
	}
	e[0][0] = 0;
      }
      else {
	for(int j=(n*m)/2; j>=(n*m)/2-b/2; j--) {
	  if(n==2) {
	    e[0][j] = e[1][j] = 1;
	  }
	  else e[j][0] = e[j][1] = 1;
	}
      }
    }
    else {
      if(b==n*m-2 || b==n*m-3 || b==n*m-5 || b==n*m-7) f = false;
      else if(b==n*m-1) {
	for(int i=0; i<n; i++) {
	  for(int j=0; j<m; j++) {
	    e[i][j] = 1;
	  }
	}
	e[0][0] = 0;
      }
      else if(b==n*m-9) {
	for(int i=0; i<n; i++) {
	  for(int j=0; j<m; j++) {
	    e[i][j] = 1;
	  }
	}
	for(int i=0; i<3; i++) {
	  for(int j=0; j<3; j++) {
	    e[i][j] = 0;
	  }
	}
      }
      else if(b==n*m-4) {
	for(int i=0; i<n; i++) {
	  for(int j=0; j<m; j++) {
	    e[i][j] = 1;
	  }
	}
	for(int i=0; i<2; i++) {
	  for(int j=0; j<2; j++) {
	    e[i][j] = 0;
	  }
	}
      }
      else if(b==n*m-6) {
	for(int i=0; i<n; i++) {
	  for(int j=0; j<m; j++) {
	    e[i][j] = 1;
	  }
	}
	for(int i=0; i<3; i++) {
	  for(int j=0; j<2; j++) {
	    e[i][j] = 0;
	  }
	}
      }
      else if(b==n*m-8) {
	for(int i=0; i<n; i++) {
	  for(int j=0; j<m; j++) {
	    e[i][j] = 1;
	  }
	}
	for(int i=0; i<3; i++) {
	  for(int j=0; j<3; j++) {
	    e[i][j] = 0;
	  }
	}
	e[2][2] = 1;
      }
      else {
	int r = n-1, c = m-1;
	while(b>0 && r>=2) {
	  c = m-1;
	  while(c>=2 && b>0) {
	    e[r][c] = 1;
	    c--;
	    b--;
	  }
	  r--;
	}
	//cout<<"Rem B: "<<b<<endl;
	if(b%2) {
	  e[2][2] = 0;
	  b++;
	}
	//cout<<"New B: "<<b<<endl;
	r = n-1;
	while(b>0 && r>=3) {
	  //cout<<"Placing: "<<r<<endl;
	  e[r][1] = e[r][0] = 1;
	  r--;
	  b-=2;
	}
	c = m-1;
	while(b>0 && c>=3) {
	  //cout<<"Placing: "<<c<<endl;
	  e[0][c] = e[1][c] = 1;
	  c--;
	  b-=2;
	}
	//cout<<"Final: "<<r<<" "<<c<<" "<<b<<endl;
      }
    }
    if(f) {
      
      for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
	  if(i==0 && j==0) cout<<'c';
	  else if(e[i][j]==0) cout<<'.';
	  else cout<<"*";
	}
	cout<<endl;
      }
      
      for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
	  v[i*m+j] = 0;
	}
      }
      d.resize(n*m);
      for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
	  if(e[i][j]==1) d[i*m+j] = 1;
	  else d[i*m+j] = 0;
	}
      }
      go(0,0);
      int tot = 0;
      for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
	  tot+=(e[i][j]==1);
	}
      }
      for(int i=0; i<n*m; i++) {
	if(v[i]==0 && d[i]==0) {
	  assert(false);
	}
      }
      //cout<<"TOT: "<<tot<<" "<<b2<<endl;
      assert(tot==b2);
    }
    else cout<<"Impossible"<<endl;
  }
  return 0;
}

int main3(int n2, int m2) {
  //cin>>n>>m;
  n = n2; m = m2;
  for(int i=0; i<=n*m-1; i++) {
    b = i;
    main2();
  }
  return 0;
}

int main() {
  /*
  for(int i=1; i<=20; i++) {
    for(int j=1; j<=25; j++) {
      main3(i,j);
    }
  }
  */
  main2();
  return 0;
}
