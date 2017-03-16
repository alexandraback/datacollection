#include <iostream>
#include <cstring>
#include <algorithm>

#include <vector>
#include <set>
#include <deque>
#define F first
#define S second
using namespace std;
bool used[1000];
int main() {
    int t;
    cin>>t;
    for(int i = 0; i < t; ++i) {
        int n;
        cin>>n;

        vector<pair<int, string> > qwe(n);
        vector<string> v(n);
        vector<set<int> > zz(n);
        for(int i = 0; i < n; ++i) {
            cin>>v[i];
            qwe[i].S = v[i];
            qwe[i].F = i;
        }
        int hah = 0;
        do {
            memset(used, 0, sizeof(used));
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < qwe[i].S.size(); ++j) {
                    if(used[qwe[i].S[j]]) goto ohi3;
                    if(j != qwe[i].S.size()-1) {
                        if(qwe[i].S[j] != qwe[i].S[j+1]) used[qwe[i].S[j]] = 1;
                    }
                }
                if(i != n-1) {
                    if(qwe[i].S.back() != qwe[i+1].S.front()) used[qwe[i].S.back()] = 1;
                }
            }
            ++hah;
            ohi3:;
        } while(next_permutation(qwe.begin(), qwe.end()));;
        cout<<"Case #"<<i+1<<": "<<hah<<'\n';
        continue;
        for(int i = 0; i < n; ++i) {
            for(int j= 0 ; j < v[i].size(); ++j) {
                zz[i].insert(v[i][j]);
            }
        }
        vector<pair<pair<int,int>, int> > cute(n);
        int maara = 0;
        for(int i = 0; i < n; ++i) {
            deque<int> lol;
            set<int> qwe;
            for(int j = 0; j < v[i].size(); ++j) {
                lol.push_back(v[i][j]);
            }
            int eka = v[i][0];
            for(;lol.size();) {
                if(lol.front() != eka) break;
                qwe.insert(lol.front());
                lol.pop_front();
            }
            int vika = v[i].back();
            for(;lol.size();) {
                if(lol.back() != vika) break;
                qwe.insert(lol.back());
                lol.pop_back();
            }
            for(;lol.size();) {
                for(int j = 0; j < n; ++j) {
                    if(i == j) continue;
                    if(zz[j].count(lol.back())) {
                        goto pois;
                    }
                }
                if(qwe.count(lol.back())) goto pois;
                lol.pop_back();
            }
        }
        for(int i = 0; i < n; ++i) {
            cute[i].F.F = i;
            cute[i].F.S = v[i].front()-'a';;
            cute[i].S = v[i].back()-'a';
        }
        do {
            memset(used, 0, sizeof(used));
            for(int i = 0; i < n; ++i) {
                if(used[cute[i].F.S]) goto ohi;
                if(used[cute[i].S]) goto ohi;
                if(cute[i].S != cute[i].F.S) used[cute[i].F.S] = 1;
                if(i != n-1) {
                    if(cute[i].S != cute[i+1].F.S) used[cute[i].S] =1;
                }

            }
            ++maara;
            ohi:;
        } while(next_permutation(cute.begin(), cute.end()));
        cout<<"Case #"<<i+1<<": "<<maara<<'\n';
        continue;
        pois:;
        cout<<"Case #"<<i+1<<": 0\n";
    }
}
