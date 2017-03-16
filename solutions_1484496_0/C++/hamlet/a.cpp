#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
int memo[4000000][20][2];
int n;
int c[20];        
bool dp(int t,int pos,int yeah){
    if(pos==n){
        if(t==2000000 && yeah)return 1;    
        return 0;
    }
    if(memo[t][pos][yeah]!=-1)return memo[t][pos][yeah];
    bool dev=dp(t-c[pos],pos+1,1)|dp(t+c[pos],pos+1,1) |dp(t,pos+1,yeah);
    memo[t][pos][yeah]=dev;
    return dev;
}

int main(){
    
   // cout<<24+75*0.34666666666<<" "<<30+75*0.26666666666<<" "<<21+75*0.38666666666666666<<endl;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
   	int tc;cin>>tc;
	for(int caso=1;caso<=tc;caso++){
        cin>>n;
        for(int i=0;i<n;i++)cin>>c[i];
        int sum=0;
        cout<<"Case #"<<caso<<":"<<endl;
        memset(memo,-1,sizeof(memo));
        if(!dp(2000000,0,0)){
            cout<<"Impossible"<<endl;  
            continue;  
        }
        
        vector<int>a,b;
        bool yeah=0;
        int t=2000000;
        for(int i=0;i<n;i++){
            if(dp(t-c[i],i+1,1) ){
                yeah=1;
                t-=c[i];
                a.push_back(c[i]);
                continue;
            }
            
            if(dp(t+c[i],i+1,1) ){
                yeah=1;
                t+=c[i];
                b.push_back(c[i]);
                continue;
            }
            
            if(dp(t,i+1,yeah) ){
                continue;
            }
                
        }
        
        for(int i=0;i<a.size();i++){
            cout<<a[i];
            if(i!=a.size()-1)cout<<" ";
        }
        cout<<endl;
        
        for(int i=0;i<b.size();i++){
            cout<<b[i];
            if(i!=b.size()-1)cout<<" ";
        }
        cout<<endl;
        
        
    }
	
	return 0;
}
