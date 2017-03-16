#include <bits/stdc++.h>

#define verbose 0
#define inf 1e9;
using namespace std;

void write(int n, string ans){
   ofstream ofs;
   ofs.open ("out.txt", ios_base::app);
   // ofs << fixed << setprecision(6);
   ofs << "Case #" << n << ": " << ans << endl;
   ofs.close();
}

string solve(string s){
    string ret; ret.push_back(s[0]);
    for (int i = 1; i < s.size(); i++){
        if (s[i] - 'A' >= ret[0] - 'A'){
            ret = s[i] + ret;
        }
        else{
            ret.push_back(s[i]);
        }
    }
    return ret;
}

int main(void){
   remove("out.txt");
   int T; string s;
   cin >> T;
   for (int i = 0; i < T; i++){
       cin >> s;
       write(i+1, solve(s));
   }
   return 0;
}
