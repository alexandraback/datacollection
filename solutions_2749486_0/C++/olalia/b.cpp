#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>


using namespace std;

int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    int X, Y; cin>>X>>Y;
    string s;
    int n=0;
    while (true){
      int x, y;
      x=X; y=Y;
      for (int i=n; i>0; --i){
	if (abs(x)>abs(y)){
	  if (x>0)
	    x-=i;
	  else
	    x+=i;
	}
	else{
	  if (y>0)
	    y-=i;
	  else
	    y+=i;
	}
      }
      if (x==0 && y==0)
	break;
      ++n;
    }
    //cout<<n<<endl;
    s=string(n,'a');
    int x,y;
    x=X; y=Y;
    for (int i=n; i>0; --i){
      if (abs(x)>abs(y)){
	if (x>0){
	  x-=i;
	  s[i-1]='E';
	}
	else{
	  x+=i;
	  s[i-1]='W';
	}
      }
      else{
	if (y>0){
	  y-=i;
	  s[i-1]='N';
	}
	else{
	  y+=i;
	  s[i-1]='S';
	}
      }
    }
      


    
    cout<<"Case #"<<tc<<": "<<s<<endl;
  }
  return 0;
}
