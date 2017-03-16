#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int x=0;x<t;x++){
        int n;
        cin>>n;
        int m;
        int h[2501];
        for(int i=0;i<2501;i++){
            h[i]=0;
        }
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<n;j++){
                cin>>m;
                h[m]++;
            }
        }
        int sol[2501];
        int ind=0;
        for(int i=0;i<2501;i++){
            sol[i]=0;
        }
        for(int i=0;i<2501;i++){
            if(h[i]%2==1){
                sol[ind]=i;
                ind++;
            }
        }
        sort(sol, sol+ind);
        cout<<"Case #"<<x+1<<":";
        for(int i=0;i<ind;i++){
            cout<<" "<<sol[i];
        }
        cout<<endl;
    }
    return 0;
}
