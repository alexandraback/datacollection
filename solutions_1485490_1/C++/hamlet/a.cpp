#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;  // H A M L E T
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

long long A[101];
int tipoA[101];
long long B[101];
int tipoB[101];
int n,m;

long long memo[101][101];

long long dp(int pos1,int pos2){
    if(pos1==n || pos2==m)return 0;
    if(memo[pos1][pos2]!=-1)return memo[pos1][pos2];
    long long dev=max(dp(pos1+1,pos2),dp(pos1,pos2+1) );
    
    long long sum=0;
    for(int i=pos2;i<m;i++){
        if(tipoA[pos1]==tipoB[i]){
            if(sum<=A[pos1]){
                if(sum+B[i]>A[pos1] ){
                    dev=max(dev,A[pos1]+dp(pos1+1,i+1) );    
                }else{
                    dev=max(dev,sum+B[i]+dp(pos1+1,i+1) );
                }    
            }
        }    
    }
    
    sum=0;
    
    for(int i=pos1;i<n;i++){
        if(tipoA[i]==tipoB[pos2]){
            if(sum<=B[pos2]){
                if(sum+A[i]>B[pos2] ){
                    dev=max(dev,B[pos2]+dp(i+1,pos2+1) );    
                }else{
                    dev=max(dev,sum+A[i]+dp(i+1,pos2+1) );
                }    
            }
        }    
    }
    
    if(tipoA[pos1]==tipoB[pos2]){
        long long sum1=0;
        for(int i=pos1;i<n;i++){
            if(tipoA[pos1]==tipoA[i])sum1+=A[i];
            long long sum2=0;
            for(int j=pos2;j<m;j++){
                if(tipoB[pos2]==tipoB[j])sum2+=B[j];
                
                if(tipoA[i]==tipoB[j]){
                    dev=max(dev,min(sum1,sum2)+dp(i+1,j+1));
                }    
            }    
        }
    }
    
    
    memo[pos1][pos2]=dev;
    return dev;
}

int main(){
    
   // cout<<24+75*0.34666666666<<" "<<30+75*0.26666666666<<" "<<21+75*0.38666666666666666<<endl;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
   	int tc;cin>>tc;
	for(int caso=1;caso<=tc;caso++){
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>A[i]>>tipoA[i];
        for(int i=0;i<m;i++)cin>>B[i]>>tipoB[i];
        memset(memo,-1,sizeof(memo));
        cout<<"Case #"<<caso<<": "<<dp(0,0)<<endl;
    }
	
	return 0;
}
