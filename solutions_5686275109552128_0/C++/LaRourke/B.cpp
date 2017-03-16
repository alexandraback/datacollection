#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

void solve(vector<int> Ds, int * best_t, int count){
    if (count>=*best_t) return;
    sort(Ds.begin(), Ds.end());
    //for(int i=0;i<Ds.size();i++) cout<<Ds[i]<<" "; cout<<":"<<*best_t<<endl;
    int D_max = Ds[Ds.size()-1];
    int D_size = Ds.size();
    if (*best_t>D_max+count) *best_t = D_max+count;
    for(int splits=2;splits<=sqrt(D_max); splits++){
        Ds.push_back(0);
        int where = D_size-1;
        for(int i=0;i<D_max%splits;i++) {Ds[where] = D_max/splits+1;where++;}
        for(int i=0;i<splits-D_max%splits;i++) {Ds[where] = D_max/splits; where++;}
        solve(Ds, best_t, count+splits-1);
    }
    
}

int main() {
    int T; cin>>T;
    for(int case_id = 1;case_id<=T;case_id++){
        vector<int> Ds;
        int best_t = 99999999;
        int n; cin>>n;
        for(int i=0;i<n;i++){
            int a; cin>>a; Ds.push_back(a);
        }
        solve(Ds, &best_t, 0);
        printf("Case #%d: %d\n", case_id, best_t);
        
    }
}