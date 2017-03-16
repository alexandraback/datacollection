#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
in ways[2][2][2][2];
int main(){
  in tt;
  cin>>tt;
  for(in zz=1;zz<=tt;zz++){
    cout<<"Case #"<<zz<<": ";
    in A,B,K;
    cin>>A>>B>>K;
    A--;
    B--;
    K--;
    forn(i,2)
      forn(j,2)
      forn(k,2)
      forn(l,2)
      ways[i][j][k][l]=0;
    in sw,nw;
    ways[0][1][1][1]=1;
    for(in i=32;i>=0;i--){
      sw=i%2;
      nw=!sw;
      forn(j,2)
	forn(k,2)
	forn(l,2)
	ways[nw][j][k][l]=0;
      forn(l,2){
	forn(m,2){
	  forn(n,2){
	    in a=((A&(1LL<<i))!=0);
	    in b=((B&(1LL<<i))!=0);
	    in k=((K&(1LL<<i))!=0);
	    in nl,nm,nn;
	    in kd;
	    for(in ad=0;ad<=1;ad++){
	      for(in bd=0;bd<=1;bd++){
		kd=(ad&bd);
		if(l==1 && ad>a)
		  continue;
		if(m==1 && bd>b)
		  continue;
		if(n==1 && kd>k)
		  continue;
		if(l==1 && ad==a)
		  nl=1;
		else
		  nl=0;
		if(m==1 && bd==b)
		  nm=1;
		else
		  nm=0;
		if(n==1 && kd==k)
		  nn=1;
		else
		  nn=0;
		ways[nw][nl][nm][nn]+=ways[sw][l][m][n];
	      }
	    }
	  }
	}
      }
    }
    in sm=0;
    forn(i,2)
      forn(j,2)
      forn(k,2)
      sm+=ways[nw][i][j][k];
    cout<<sm<<endl;
  }
  return 0;
}

