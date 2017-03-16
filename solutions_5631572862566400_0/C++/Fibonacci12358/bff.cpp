#include <iostream>

using namespace std;

int t;
int bff[11];
int taken[11];
int circle[10];
int mx;

void check(int n){
    /*for(int i=0;i<n;i++){
        cout<<circle[i]<<" ";
    }
    cout<<endl;*/
    if(n==1){
        return;
    }
    if(bff[circle[0]]!=circle[n-1]&&bff[circle[0]]!=circle[1]){
        return;
    }
    if(bff[circle[n-1]]!=circle[0]&&bff[circle[n-1]]!=circle[n-2]){
        return;
    }
    for(int i=1;i<n-1;i++){
        if(bff[circle[i]]!=circle[i-1]&&bff[circle[i]]!=circle[i+1]){
            return;
        }
    }
    if(mx<n){
        mx=n;
    }
}

void assign(int n,int c){
    if(n==c){
        return;
    }
    for(int i=1;i<=n;i++){
        if(!taken[i]){
            circle[c]=i;
            taken[i]=true;
            check(c+1);
            assign(n,c+1);
            taken[i]=false;
        }
    }
}

int main(){
    cin>>t;
    for(int x=0;x<t;x++){
        mx=0;
        int n;
        cin>>n;
        for(int i=1;i<n+1;i++){
            cin>>bff[i];
        }
        for(int i=0;i<11;i++){
            taken[i]=false;
        }
        assign(n,0);
        cout<<"case #"<<x+1<<": "<<mx<<endl;
    }
    return 0;
}
