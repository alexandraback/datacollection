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
#define MAX 21
const int64 N=22;
struct State{
    State(){
        memset(fields,false,sizeof(fields));
    }
    State(const State& t){
        REP(i,2*xlen+1)REP(j,2*xlen+1)fields[i][j]=t.fields[i][j];
    }
    State& operator=(const State& t){
        State n(t);
        return n;
    }

    void setF(int64 x,int64 y){
        fields[x+xlen][y]=true;
    }
    bool test(int64 x,int64 y)const{
        if(x<-xlen||x>xlen||y<0||y>xlen)return false;
        return fields[x+xlen][y];
    }
    const static int xlen=21;
    bool fields[2*xlen+1][2*xlen+1];
};

void addType(vector<State>& curTypes,State& base,int64 x,int64 y){
    if(y==0||(base.test(x-1,y-1)&&base.test(x+1,y-1))){
        State ns(base);
        ns.setF(x,y);
        cerr<<x<<","<<y<<endl;
        curTypes.push_back(ns);
        return;
    }
    if(!base.test(x-1,y-1))addType(curTypes,base,x-1,y-1);
    if(!base.test(x+1,y-1))addType(curTypes,base,x+1,y-1);
    return;
}

void initState(vector<vector<State> >& allType){

    allType=vector<vector<State> >(N);
    REP(i,N)allType[i]=vector<State>();

    allType[0].push_back(State());
    for(int64 i=1;i<N;i++){
        vector<State>& curTypes=allType[i];
        for(int64 j=0;j<allType[i-1].size();j++){
            State base(allType[i-1][j]);
            int64 xi,yi;
            for(yi=0;yi<N;yi+=2){
                if(!base.test(0,yi)){
                    break;
                }
            }
            addType(curTypes,base,0,yi);
        }
    }
}

double getProb(int64 num,int64 x,int64 y,const vector<vector<State> >& allType){
    const vector<State>& curTypes=allType[num];
    int64 count=0;
    REP(i,curTypes.size())if(curTypes[i].test(x,y))count++;
    return (double)count/curTypes.size();
}

int main(int argc,char** argv){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("output.txt","w",stdout);
    vector<vector<State> > allType;
    initState(allType);
    int caseSize;
    cin>>caseSize;
    REP(caseNum,caseSize){
        int64 num,x,y;
        cin>>num>>x>>y;
        double prob=getProb(num,x,y,allType);
        cout<<"Case #"<<caseNum+1<<": "<<prob<<endl;
    }
    return 0;
}
