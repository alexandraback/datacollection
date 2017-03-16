//Fruit of Light
//FoL CC
//Apple Strawberry

#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<cstring>

using namespace std;

#define For(i, n) for(int i = 0; i<(n); ++i)
#define INF 1023456789
#define eps 1e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string nums[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE",
};

void rm(vi &cnt, vi& pho, int id) {
    pho[id]++;
    for(auto c : nums[id])
        cnt[c]--;
}

int extra() {
    string word;
    cin >> word;
    vi cnt(256,0);
    vi pho(20);
    for(auto c : word) cnt[c]++;
    
    while(cnt['Z']>0) rm(cnt, pho, 0);
    while(cnt['X']>0) rm(cnt, pho, 6);
    while(cnt['U']>0) rm(cnt, pho, 4);
    while(cnt['R']>0) rm(cnt, pho, 3);
    while(cnt['H']>0) rm(cnt, pho, 8);
    while(cnt['T']>0) rm(cnt, pho, 2);
    while(cnt['O']>0) rm(cnt, pho, 1);
    while(cnt['S']>0) rm(cnt, pho, 7);
    while(cnt['F']>0) rm(cnt, pho, 5);
    while(cnt['N']>0) rm(cnt, pho, 9);
        

    For(i, 10) {
        For(j, pho[i]) cout << i;
    }
    cout << endl;

}

int main(){
    int T;
    cin >> T;
    For(i,T){
        printf("Case #%d: ",i+1);
        extra();
    }
}
