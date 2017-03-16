#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <math.h>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP2(i,m,n) for(int i=m;i<(int)n;++i)
#define FILL(a,num,val) REP(i,num)a[i]=val
#define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
typedef pair<int,int> ipair;//NOTES:ipair
typedef pair<double,double> fpair;//NOTES:fpair
const double pi=acos(-1.0);//NOTES:pi
const double eps=1e-11;//NOTES:eps
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
#define MAX 11

uint64 dfs(uint64 moteSize,vector<uint64> motes,int index){
    if(index>=motes.size())return 0;
    while(moteSize>motes[index]&&index<motes.size()){
        moteSize+=motes[index];
        index++;
    }
    uint64 num=0;
    if(index<motes.size()){
        if(moteSize>1){
            num=min((uint64)(motes.size()-index),dfs(2*moteSize-1,motes,index)+1);
        }else{
            num=motes.size()-index;
        }

    }

    return num;
}

int main(int argc,char** argv){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int caseSize;
    cin>>caseSize;
    REP(caseNum,caseSize){
        uint64 moteSize,moteNum;
        cin>>moteSize>>moteNum;
        vector<uint64> motes(moteNum);
        REP(i,moteNum)cin>>motes[i];
        sort(motes.begin(),motes.end());
        uint64 num=dfs(moteSize,motes,0);
        cout<<"Case #"<<caseNum+1<<": "<<num<<endl;
    }

    return 0;
}
