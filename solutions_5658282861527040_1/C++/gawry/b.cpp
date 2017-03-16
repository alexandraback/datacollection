#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cassert>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

string binary(int x){
  string s;
  for(int i=0;i<32;i++){
    s+='0'+x%2;
    x/=2;
  }
  reverse(s.begin(),s.end());
  return s;
}
int main(){
  int c;
  scanf("%d",&c);
  for(int cc=1;cc<=c;cc++){
    int _A,_B,_K;
    scanf("%d %d %d",&_A,&_B,&_K);
    long long res=0;
    //for(int i=0;i<A;i++)for(int j=0;j<B;j++)res+=(i&j)<K;
    string A=binary(_A),B=binary(_B),K=binary(_K);
    //cout<<A<<endl<<B<<endl<<K<<endl;
    long long t[33][2][2][2]={};
    t[0][0][0][0]=1;
    for(int i=0;i<32;i++)for(int x=0;x<2;x++)for(int y=0;y<2;y++)for(int z=0;z<2;z++)for(int a=0;a<2;a++)for(int b=0;b<2;b++){
      if(!x&&a>A[i]-'0')continue;
      if(!y&&b>B[i]-'0')continue;
      int c=a&b;
      if(!z&&c>K[i]-'0')continue;
      int xx=x||a<A[i]-'0',yy=y||b<B[i]-'0',zz=z||c<K[i]-'0';
      t[i+1][xx][yy][zz]+=t[i][x][y][z];
    }
    printf("Case #%d: %lld\n",cc,t[32][1][1][1]);
  }
}
