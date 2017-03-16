#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

#define lli long long int

int flag[3000];
vector<int> lists;

void clr(){
    for(int i=0;i<2550;i++) flag[i] = 0;
}

void print(int mx){
    lists.clear();
    for(int i=0;i<=mx;i++){
        if(flag[i]%2==1) lists.push_back(i);
    }
    cout<<lists[0];
    for(int i=1;i<lists.size();i++){
        cout<<" "<<lists[i];
    }
    cout<<endl;
}

int main(){
    freopen("B-large.txt","r",stdin);
    freopen("out.txt","w",stdout);
    //printf("Hello CodeJam !!! :P :D\n");
    int t,n,a,mx;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>n;
        mx = 0;
        for(int i=0;i<n*n;i++){
            cin>>a;
            flag[a]++;
            if(mx<a) mx = a;
        }
        for(int i=0;i<n*n-n;i++){
            cin>>a;
            flag[a]++;
            if(mx<a) mx = a;
        }
        cout<<"Case #"<<cas<<": ";
        print(mx);
        clr();
    }

}
