/*
 * C.cpp
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


int c,d,v;
vector<int> coins;
int main(){
    int t;
    cin>>t;
    for(int T=1; T<=t; T++){
        long long curNeeded = 1;
        int ans = 0;
        cin>>c>>d>>v;
        coins.clear();
        for(int i=0; i<d; i++){
            int x; cin>>x;
            coins.push_back(x);
        }
        sort(coins.begin(), coins.end());
        int pos = 0;
        while(curNeeded <= v){
            
            if(pos < d && coins[pos] <= curNeeded){
                curNeeded += (c*coins[pos]);
                pos++;
                continue;
            }
            ans++;
            curNeeded += (c*curNeeded);
        }

        cout<<"Case #"<<T<<": "<<ans<<endl;
    }
}

