#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

#define xx first
#define yy second
#define ll long long
#define pb push_back
#define pp pop_back
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
using namespace std;
int t,r,c,m;
char a[60][60];
bool dp[60][60][60*60];
bool mark[60][60][60*60];
int par[60][60][60*60];
bool check[60][60];
bool Mem(int pos,int last,int sum){
    bool &ret=dp[pos][last][sum];
    if(sum==m){
        if(last!=1)return ret=true;
        else return ret=false;
    }
    if(pos==r+1)return ret=false;
    if(mark[pos][last][sum])return ret;
    mark[pos][last][sum]=true;
    for(int i=1;i<=last;i++){
        if(sum+i<=m){
            ret|=Mem(pos+1,i,sum+i);
            if(ret==1){
                par[pos][last][sum]=i;
                break;
            }
        }
    }
    return ret;
}
int main(){
    ifstream cin("1.in");
    ofstream cout("1.out");
    cin>>t;
    for(int l=1;l<=t;l++){
        memset(dp,0,sizeof(dp));
        memset(mark,0,sizeof(mark));
        memset(par,-1,sizeof(par));
        memset(check,0,sizeof(check));
        cin>>r>>c>>m;
        cout<<"Case #"<<l<<":"<<endl;
        if(r==1 || c==1){
            if(c==1 && r==1){
                cout<<"c"<<endl;
            }
            else if(r==1){
                int cnt=c-m;
                cout<<"c";
                for(int i=2;i<=cnt;i++)cout<<".";
                for(int i=cnt+1;i<=c;i++)cout<<"*";
                cout<<endl;
            }
            else if(c==1){
                int cnt=r-m;
                cout<<"c"<<endl;
                for(int i=2;i<=cnt;i++)cout<<"."<<endl;
                for(int i=cnt+1;i<=r;i++)cout<<"*"<<endl;
            }
        }
        else{
            bool ans=0;
            m=(r*c)-m;
            if(m==1){
                for(int i=1;i<=r;i++){
                    for(int j=1;j<=c;j++)a[i][j]='*';
                }
                a[1][1]='c';
                for(int i=1;i<=r;i++){
                    for(int j=1;j<=c;j++)cout<<a[i][j];
                    cout<<endl;
                }
            }
            else{
                int st1,st2,st3;
                for(int i=2;i<=c;i++){
                    if(2*i<=m){
                        ans|=Mem(3,i,2*i);
                        if(ans==1){
                            st1=3;
                            st2=i;
                            st3=2*i;
                            break;
                        }
                    }
                }
                if(ans==0)cout<<"Impossible"<<endl;
                else{
                    vi v;
                    v.clear();
                    v.pb(st2);
                    v.pb(st2);
                    while(par[st1][st2][st3]!=-1){
                        v.pb(par[st1][st2][st3]);
                        int n1,n2,n3;
                        n1=st1+1;
                        n2=par[st1][st2][st3];
                        n3=st3+par[st1][st2][st3];
                        st1=n1;
                        st2=n2;
                        st3=n3;
                    }
                    for(int i=1;i<=v.size();i++){
                        for(int j=1;j<=v[i-1];j++){
                            a[i][j]='.';
                            check[i][j]=true;
                        }
                    }
                    for(int i=1;i<=r;i++){
                        for(int j=1;j<=c;j++){
                            if(!check[i][j])a[i][j]='*';
                        }
                    }
                    a[1][1]='c';
                    for(int i=1;i<=r;i++){
                        for(int j=1;j<=c;j++){
                            cout<<a[i][j];
                        }
                        cout<<endl;
                    }
                }
            }
        }
    }
}
