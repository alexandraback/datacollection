#include <bits/stdc++.h>
using namespace std;
int p[1010];
int main(){
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        cout<<"Case #"<<tc<<": ";
        int d;
        cin>>d;
        priority_queue<int> lol;
        for (int i=0;i<d;i++){
            cin>>p[i];
        }
        int mv=1e9;
        for (int v=1000;v>0;v--){
            int t=0;
            for (int i=0;i<d;i++){
                t+=p[i]/v+(p[i]%v>0);
                t--;
            }
            mv=min(mv, v+t);
        }
        cout<<mv<<endl;
    }
}
