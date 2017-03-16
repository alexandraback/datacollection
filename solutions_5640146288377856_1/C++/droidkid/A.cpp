/*
 * A.cpp
 * 
 * 
 * 
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;



int main(){
    int t;
    cin>>t;
    for(int T=0; T<t; T++){
        cout<<"Case #"<<T+1<<": ";
        int r,c,w;
        cin>>r>>c>>w;
        int temp = c/w;
        if(c%w!=0)temp++;
        int ans = r*temp + (w-1);
        cout<<ans<<endl;
    }
}

