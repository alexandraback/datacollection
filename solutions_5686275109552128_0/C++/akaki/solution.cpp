#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int i,j,k,l,m,n, ans, cur , test,s,t, mx, a,d, ii;
string str;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    cin>>t;
    while(t--){
        mx = 0;
        priority_queue <int> mq;
        test++;
        cin>>d;
        for (i=0;i<d;i++){
            cin>>a;
            mq.push(a);
            if (mx<a) mx = a;
        }
        ans = mx;
        //number of special minutes
        for (i=0;i<mx;i++){
            //number of normal minutes
            for (ii=0;ii<mx-i;ii++){
                priority_queue <int> myq = mq;
                for (j=0;j<i;j++){
                    a = myq.top();
                    myq.pop();
                    if (a>ii){
                        myq.push(ii);
                        myq.push(a-ii);
                    } else myq.push(a);
                }
                if (myq.size()==0 || myq.top()<=ii)
                    if (ans>i+ii) 
                        ans = i+ii;
            }
        }
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
    return 0;
}
