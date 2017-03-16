#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>  
#include<set>
#include<string>
#include<sstream>
#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,j,k) for(int i=j;i<k;++i)
#define REPD(i,n) for(int i=n;i>-1;--i)
#define ALL(v) v.begin(),v.end()
#define ll long long
#define PB push_back
using namespace std;

int main()
{
    int ts;cin>>ts;
    REP(tn,ts)
    {
        int r,c,m;
        cin>>r>>c>>m;
        cout<<"Case #"<<(tn+1)<<":"<<endl;
        string tmp=""; REP(i,c) tmp+="*";
        vector<string> sol; REP(i,r) sol.PB(tmp);
        int free = r*c-m;
        if(r==1) { 
                    REP(j,free) sol[0][j]='.'; sol[0][0]='c'; cout<<sol[0]<<endl;
                 }
        else if(c==1) { 
                         REP(j,free) sol[j][0]='.'; sol[0][0]='c'; REP(i,r) cout<<sol[i]<<endl;
                      }
        else if(free==1) { sol[0][0]='c'; REP(i,r) cout<<sol[i]<<endl;
             }
        else {
             //  cout<<r<<" "<<c<<" "<<m<<endl;
                      
                int a=-1,b=-1;
                bool swapOne = false;
                FOR(x,2,r+1)
                 FOR(y,2,c+1)
                 {
                    if(x*y>free) break;
                    int rest = free - x*y;
                    if(rest!=1 && (rest<y || rest<x) && (a==-1 || (rest<free-a*b) )) {a=x,b=y; swapOne = false;} 
                    else if(rest==1 && x>2 && y>2 && (a==-1||(rest<free-a*b) ) )
                    {
                         swapOne = true;
                         a = x;
                         b = y;
                    }
                 }
                
                if(a==-1 || b==-1)  
                cout<<"Impossible"<<endl;
                else {
                     int left = free-a*b;
                       // cout<<a<<" "<<b<<" "<<left<<endl;
                        REP(i,a) REP(j,b) sol[i][j]='.';
                        sol[0][0]='c';
                        if(a<r && left<=c){  
                        if(left>0) REP(i,left) sol[a][i]='.';
                     //   cout<<"!"<<endl;
                        if(swapOne)
                        {
                          sol[a-1][b-1] = '*';
                          sol[a][left]='.';  
                        }
                        
                                }
                        else if(b<c && left<=r) {
                            
                        if(left>0) REP(i,left) sol[i][b]='.';
                             
                            
                        if(swapOne)
                        {
                          sol[a-1][b-1] = '*';
                          sol[left][b]='.' ; 
                        } 
                             
                             }
                             else {cout<<"Impossible"<<endl;continue;}
                             
                             
                        
                      
                        REP(i,r) cout<<sol[i]<<endl;
                     }
                     
                
             }
        
       
    }
    
    return 0;
}
