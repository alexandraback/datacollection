#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
in ab(in a){
  return a<0?-a:a;
}
VI pw10;
in tra(string s){
  in r=0;
  forv(i,s){
    r+=(s[i]-'0')*pw10[sz(s)-i-1];
  }
  return r;
}
in bst1,bst2;
in bstd;
void st(in c1, in c2){
  bstd=ab(c1-c2);
  bst1=c1;
  bst2=c2;
}
void consb(in c1, in c2){
  in d=ab(c1-c2);
  if(d>bstd)
    return;
  if(d<bstd){
    st(c1,c2);
    return;
  }
  if(c1>bst1)
    return;
  if(c1<bst1){
    st(c1,c2);
    return;
  }
  if(c2<bst2)
    st(c1,c2);
}
string t1,t2;
void cons(in d, in typ){
  string a=t1;
  string b=t2;
  forn(i,d){
    if(a[i]=='?' && b[i]=='?')
      a[i]=b[i]='0';
    if(a[i]=='?')
      a[i]=b[i];
    if(b[i]=='?')
      b[i]=a[i];
    if(a[i]!=b[i])
      return;
  }
  if(a[d]=='?' && b[d]=='?'){
    a[d]='0'+typ;
    b[d]='1'-typ;
  }
  if(a[d]=='?'){
    if(typ){
      if(b[d]=='9')
	return;
      a[d]=b[d]+1;
    }
    else{
      if(b[d]=='0')
	return;
      a[d]=b[d]-1;
    }
  }
  if(b[d]=='?'){
    if(typ){
      if(a[d]=='0')
	return;
      b[d]=a[d]-1;
    }
    else{
      if(a[d]=='9')
	return;
      b[d]=a[d]+1;
    }
  }
  if(typ && a[d]<=b[d])
    return;
  if(!typ && a[d]>=b[d])
    return;
  for(in i=d+1;i<sz(a);++i){
    if(a[i]=='?'){
      if(typ)
	a[i]='0';
      else
	a[i]='9';
    }
    if(b[i]=='?'){
      if(typ)
	b[i]='9';
      else
	b[i]='0';
    }
  }
  consb(tra(a),tra(b));
}
void opt(in a, in s){
  for(in i=s-1;i>0;--i){
    if(a<pw10[i])
      cout<<0;
  }
  cout<<a;
}
void docase(){
  cin>>t1>>t2;
  bstd=pw10[18];
  string tp1=t1;
  string tp2=t2;
  bool isok=1;
  forv(i,tp1){
    if(tp1[i]!='?' && tp2[i]!='?' && tp1[i]!=tp2[i])
      isok=0;
    if(tp1[i]!='?')
      tp2[i]=tp1[i];
    if(tp2[i]!='?')
      tp1[i]=tp2[i];
    if(tp1[i]=='?')
      tp1[i]=tp2[i]='0';
  }
  if(isok){
    cout<<tp1<<" "<<tp2<<endl;
    return;
  }
  forv(i,tp1){
    cons(i,1);
    cons(i,0);
  }
  opt(bst1,sz(t1));
  cout<<" ";
  opt(bst2,sz(t1));
  cout<<endl;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  pw10.resize(19);
  pw10[0]=1;
  for(in i=1;i<sz(pw10);++i)
    pw10[i]=pw10[i-1]*10;
  in T;
  cin>>T;
  for(in zz=1;zz<=T;zz++){
    cout<<"Case #"<<zz<<": ";
    docase();
  }
  return 0;
}
