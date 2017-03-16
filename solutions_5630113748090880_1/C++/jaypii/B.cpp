#include <bits/stdc++.h>

#define verbose 0
#define inf 1e9;
using namespace std;


void write(int n, vector<int> ans){
   ofstream ofs;
   ofs.open ("out.txt", ios_base::app);
   // ofs << fixed << setprecision(6);
   ofs << "Case #" << n << ":";
   for (int i: ans) ofs << " " << i;
   ofs << endl;
   ofs.close();
}

vector<int> solve(){
    int N, a; cin >> N;
    vector<int> count(2501);
    for (int i = 0; i < (N*2 - 1) * N; i++){
        cin >> a;
        count[a]++;
    }
    vector<int> ret;
    for (int i = 0; i < 2501; i++){
        if (count[i] % 2 == 1){
            ret.push_back(i);
        }
    }
    return ret;
}

int main(void){
   remove("out.txt");
   int T;
   cin >> T;
   for (int i = 0; i < T; i++){
       write(i+1, solve());
   }
   return 0;
}
