#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked

  
int read_int() {
  int ret = 0;
  char c = gc();
  while(c!='0') {
    c = gc();
  }
  c = gc();
  c = gc();
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  //cout<<"Read: "<<ret<<endl;
  return ret;
}


int main() {  
  //ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  for(int z=1; z<=t; z++) {
    cout<<"Case #"<<z<<": ";
    int n;
    scanf("%d",&n);
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++) {
      a[i] = read_int();
    }
    for(int i=0; i<n; i++) {
      b[i] = read_int();
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    /*
    cout<<endl;
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0; i<n; i++) cout<<b[i]<<" ";
    cout<<endl;
    */
    vector<int> c(b);
    int tot1=0, tot2=0;
    for(int i=0; i<n; i++) {
      bool f= true;
      for(int j=0; j<b.size(); j++) {
	if(b[j]>a[i]) {
	  b.erase(b.begin()+j,b.begin()+j+1);
	  f = false;
	  break;
	}
      }
      if(f) {
	tot1 = n-i;
	break;
      }
    }
    while(c.size()>0) {
      if(a[0]>c[0]) {
	tot2++;
	a.erase(a.begin(),a.begin()+1);
	c.erase(c.begin(),c.begin()+1);
      }
      else {
	a.erase(a.begin(),a.begin()+1);
	c.erase(c.begin()+c.size()-1,c.begin()+c.size());
      }
    }
    cout<<tot2<<" "<<tot1<<endl;      
  }
  return 0;
}
