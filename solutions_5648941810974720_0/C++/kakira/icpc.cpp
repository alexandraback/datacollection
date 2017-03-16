#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
 
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define _D(p) std::cout<<"L"<<__LINE__<<" : " #p " = "<<(p)<<std::endl;
#define _D2(p,q) std::cout<<"L"<<__LINE__<<" : " #p " = "<<(p) << ", " #q " = "<<(q)<<std::endl;
#define _DN(v) std::cout<<"L"<<__LINE__<<" : " #v " = ["; rep(i,(v).size()) {std::cout<<v[i]<<(i==v.size()-1?"":", ");}std::cout<<"]"<<std::endl;
#define _DNN(v) std::cout<<"L"<<__LINE__<<" : " #v " = [" << std::endl; rep(i,(v).size()) {std::cout<<"    [";rep(j,(v)[0].size()){std::cout<<v[i][j]<<(j==v[0].size()-1?"":", ");}std::cout<<"],"<<std::endl;}std::cout<<"]"<<std::endl;
 
using namespace std;
 
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
 
const int INF=1<<29;
const double EPS=1e-9;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    string jisyo[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int cnt[10][256] = {{0}};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < jisyo[i].size(); ++j) {
            cnt[i][jisyo[i][j]]++;
        }
    }
    /*
    for (int j = 'A'; j < 'Z'; ++j) {
        cout << (char)j << ": ";
        for (int i = 0; i < 10; ++i) {
            cout << cnt[i][j] << ", ";
        }
        cout << endl;
    }
    */

    for (int test = 1; test <= T; ++test) {
        string s;
        cin >> s;
        

        string s_ = s;



        /*
        for (int i = 0; i < 256; ++i) {
            cout << i << ":" << count[i] << endl;
        }
        */
        string ans_;

        vector<int> order;
        for (int i = 0; i < 10; ++i) {
            order.push_back(i);
        }
        do {
            string ans;
            int count[256] = {0};
            for (int i = 0; i < s.size(); ++i) {
                count[s[i]]++;
            }
            for (int moji = 0; moji < 10; ++moji) {
                bool flag = true;
                while(1){
                    for (int j = 0; j < 256; ++j) {
                        if (cnt[order[moji]][j] > count[j]) flag = false;
                    }
                    if (!flag) break;
                    for (int j = 0; j < 256; ++j) {
                        count[j] -= cnt[order[moji]][j];
                    }
                    ans += order[moji] + '0';
                }
            }
            bool nukedasu = true;
            for (int i = 0; i < 256; ++i) {
                if (count[i] != 0) {nukedasu = false;}
            }
            if (nukedasu) {
                sort(all(ans));
                ans_ = ans;
                cout << "Case #" << test << ": " << ans << endl;
                break;
            }
        } while(next_permutation(all(order)));


        string tests = "";
        for (int i = 0; i < ans_.size(); ++i) {
            tests += jisyo[ans_[i] - '0'];
        }
        sort(all(s_));
        sort(all(tests));
        if (s_ != tests) {
            cout << s << ":" << s_ << "," << tests << endl;

        }

        //cout << "Case #" << test << ": " << ans << endl;
        
    }
    return 0;
}