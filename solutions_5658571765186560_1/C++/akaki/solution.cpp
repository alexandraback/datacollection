#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int i,j,k,l,m,n, ans, cur , test,s,t, mx, a,d, ii,x,r,c;
string str;
void solve(int who){
    if (who == 1) {
        cout<<"Case #"<<test<<": GABRIEL\n";
    } else
    cout<<"Case #"<<test<<": RICHARD\n";
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    cin>>t;
    while(t--){
        cin>>x>>r>>c;
        test++;
        if (x==1) {solve(1);continue;}
        if (x==2) {
            if ((r*c)%2==0) 
                solve(1); else
                solve(2);
            continue;
        }
        if (x==3){
            if ((r*c)%3!=0 || (r==1) || (c==1))
                solve(2); else
                solve(1);
            continue;
        }
        if (x==4){
            if ((r*c)%4!=0 || (r==1) || (c==1) || (r==2) || (c==2))
                solve(2); else
                solve(1);
            continue;
        } 
        if (x==5){
            if ((r*c)%5!=0 || (r==1) || (r==2) || (r==3) ||(c==1) || (c==2) || (c==3))
                solve(2); else
                solve(1);
                continue;
        }
        if (x==6){
            if ((r*c)%6!=0 || (r==1) || (r==2) || (r==3) || (c==1) || (c==2) || (c==3))
                solve(2); else
                solve(1); 
            continue;
        } 
        solve(2);
    } 
    return 0;
}
