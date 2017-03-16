#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

long long bestdiff;
string best;

void calc(string c, string j, int index, long long diff) {
  if (index>0) {
    if (c[index-1]<'0' || c[index-1]>'9' || j[index-1]<'0' || j[index-1]>'9')
      return;
  }
  if (index==c.length()) {
    string res=c+" "+j;
    long long d = diff<0?-diff:diff;
    if (d<bestdiff) {
      bestdiff=d;
      best=res;
    } else if (d == bestdiff) {
      if (res<best) {
	best=res;
      }
    }
    return;
  }
  if (diff==0) {
    if (c[index]=='?' && j[index]=='?') {
      c[index]='0';
      j[index]='0';
      calc(c,j,index+1,0);
      c[index]='1';
      calc(c,j,index+1,1);
      c[index]='0';
      j[index]='1';
      calc(c,j,index+1,-1);
    } else if (c[index]=='?') {
      c[index]=j[index];
      calc(c,j,index+1,0);
      c[index]=j[index]-1;
      calc(c,j,index+1,-1);
      c[index]=j[index]+1;
      calc(c,j,index+1,1);
    } else if (j[index]=='?') {
      j[index]=c[index];
      calc(c,j,index+1,0);
      j[index]=c[index]-1;
      calc(c,j,index+1,1);
      j[index]=c[index]+1;
      calc(c,j,index+1,-1);
    } else {
      calc(c,j,index+1,(c[index]-j[index]));
    }
  } else {
    if (c[index]=='?') {
      if (diff<0) {
	c[index]='9';
      } else {
	c[index]='0';
      }
    }
    if (j[index]=='?') {
      if (diff<0) {
	j[index]='0';
      } else {
	j[index]='9';
      }
    }
    calc(c,j,index+1,diff*10+(c[index]-j[index]));
  }
}
    
int main(){
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    string c,j;
    cin>>c>>j;
    bestdiff = 9223372036854775807;
    calc(c,j,0,0);
    cout<<"Case #"<<t<<": "<<best<<endl;
  }
}
