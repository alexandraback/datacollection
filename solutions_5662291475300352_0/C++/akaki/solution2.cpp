#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int i,j,k,l,m,n, ans, cur , test,s,t, mx, a[1005],d, ii,x,r,c;
string str;
int start[1000], speed[1000];
int h[1000];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output2.txt","w", stdout);
    cin>>t;
    while(t--){
        cin>>n;
        test++;
        for (i=0;i<n;i++){
            cin>>start[i];
            cin>>h[i];
            cin>>speed[i];
        }
        long long start1,start2;
        long long speed1, speed2;
        if (n==1){
            start1 = start2 = start[0];
            speed1 = speed[0];
            speed2 = speed[0]+1;
        } else
        {
            start1 = start[0];
            start2 = start[1];
            speed1 = speed[0];
            speed2 = speed[1];            
        }
        //player 1 is faster 
        if (speed1>speed2){
            swap(start1, start2);
            swap(speed1, speed2);
        }
        
        if ((360LL-start2)*speed2>=speed1*(720LL-start1)) {
            ans = 1;
        } else ans = 0;
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    } 
    return 0;
}
