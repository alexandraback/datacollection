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
#include <typeinfo>
 
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
    for (int tests = 0; tests < T; ++tests) {
        string A, B;
        cin >> A >> B;
        string ansA, ansB;
        int mindiff = 10000;

        if (A.size() == 3) {
            for (char a = '0'; a <= '9'; ++a) {
                for (char b = '0'; b <= '9'; ++b) {
                    for (char c = '0'; c <= '9'; ++c) {
                        string s1 = string(1, a) + string(1, b) + string(1, c);

                        if (s1.size() != A.size()) continue;

                        for (char d = '0'; d <= '9'; ++d) {
                            for (char e = '0'; e <= '9'; ++e) {
                                for (char f = '0'; f <= '9'; ++f) {
                                    string s2 = string(1, d) + string(1, e) + string(1, f);

                                    if (s2.size() != B.size()) continue;
                                    bool ok = true;
                                    for (int i = 0; i < A.size(); ++i) {
                                        if (A[i] != '?' && A[i] != s1[i]) ok = false;
                                        if (B[i] != '?' && B[i] != s2[i]) ok = false;
                                    }

                                    int numA = stoi(s1);
                                    int numB = stoi(s2);
                                    if (ok && abs(numA - numB) < mindiff) {
                                        mindiff = abs(numA - numB);
                                        ansA = s1;
                                        ansB = s2;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (A.size() == 2) {
            for (char a = '0'; a <= '9'; ++a) {
                for (char b = '0'; b <= '9'; ++b) {
                    string s1 = string(1, a) + string(1, b);

                    if (s1.size() != A.size()) continue;

                    for (char d = '0'; d <= '9'; ++d) {
                        for (char e = '0'; e <= '9'; ++e) {
                            string s2 = string(1, d) + string(1, e);

                            if (s2.size() != B.size()) continue;
                            bool ok = true;
                            for (int i = 0; i < A.size(); ++i) {
                                if (A[i] != '?' && A[i] != s1[i]) ok = false;
                                if (B[i] != '?' && B[i] != s2[i]) ok = false;
                            }

                            int numA = stoi(s1);
                            int numB = stoi(s2);
                            if (ok && abs(numA - numB) < mindiff) {
                                mindiff = abs(numA - numB);
                                ansA = s1;
                                ansB = s2;
                            }
                        }
                    }
                }
            }
        } else {
            for (char a = '0'; a <= '9'; ++a) {
                string s1 = string(1, a);

                if (s1.size() != A.size()) continue;

                for (char d = '0'; d <= '9'; ++d) {
                    string s2 = string(1, d);

                    if (s2.size() != B.size()) continue;
                    bool ok = true;
                    for (int i = 0; i < A.size(); ++i) {
                        if (A[i] != '?' && A[i] != s1[i]) ok = false;
                        if (B[i] != '?' && B[i] != s2[i]) ok = false;
                    }

                    int numA = stoi(s1);
                    int numB = stoi(s2);
                    if (ok && abs(numA - numB) < mindiff) {
                        mindiff = abs(numA - numB);
                        ansA = s1;
                        ansB = s2;
                    }
                }
            }
        }

        cout << "Case #" << tests + 1 << ": " << ansA << " " << ansB << endl;
    }
    return 0;
}