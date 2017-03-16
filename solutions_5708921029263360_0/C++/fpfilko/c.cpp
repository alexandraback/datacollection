#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
    long long T; cin >> T;
    for(long long t = 1; t<=T; t++) {
        long long j, p, s, k; cin >> j >> p >> s >> k;
        vector<vector<long long>> v;
        map<long long, long long> m;
        for(long long a = 0; a<j; a++) {
            for(long long b = 0; b<p; b++) {
                for(long long c = 0; c<s; c++) {
                   long long a1 = a*30+ b+10, 
                       a2 = a*30+ c+20,
                       a3 = (b+10)*30+c+20;
                   if(m[a1] < k && m[a2] <k && m[a3] <k) {
                     v.push_back(vector<long long>(3));
                     v.back()[0] = a+1;
                     v.back()[1] = b+1;
                     v.back()[2] = c+1;
                     m[a1]++;
                     m[a2]++;
                     m[a3]++;
                   }
                }
            }
        }
        cout << "Case #" << t << ": " << v.size() << "\n";
        for(long long i = 0; i<v.size(); i++) {
            cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << "\n"; 
        }
    }
}
