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

int mult(vector<vector<int>> A, int n) {
    n--;
    vector<vector<int>> B = A;
    vector<vector<int>> temp = A;
    
    while(n != 0) {
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                int sum = 0;
                for (int k = 0; k < A.size(); ++k) {
                    sum += B[i][k] * A[k][j];
                }
                temp[i][j] = sum;
            }
        }

        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                B[i][j] = temp[i][j];
            }
        }
        n--;
    }
    return B[0][A.size() - 1];
}

/*
int dfs(vector<vector<int> >&A, int v) {
    int ret = 1;
    int N = A.size();
    for (int i = 0; i < N; ++i) {
        if (A[i][v]) {
            ret += dfs(A, i);
        }
    }
    return ret;
}
*/

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int B, M;
        cin >> B >> M;
        int n = B * (B - 1) / 2;

        bool flag = false;
        for (int i = 0; i < 1 << n; ++i) {
            vector<vector<int>> ans;
            for (int ii = 0; ii < B; ++ii) {
                ans.push_back(vector<int>());
                for (int jj = 0; jj < B; ++jj) {
                    ans[ii].push_back(0);
                }
            }
            int nowx = 1;
            int nowy = 0;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    ans[nowy][nowx] = 1;
                }
                if (++nowx >= B) {
                    nowy++;
                    nowx = nowy + 1;
                }
            }

            int sum = 0;
            for (int i = 1; i <= ans.size(); ++i) {
                sum += mult(ans, i);
            }

            if (sum == M) {
                cout << "Case #" << test << ": POSSIBLE" << endl;
                for (int ii = 0; ii < B; ++ii) {
                    for (int jj = 0; jj < B; ++jj) {
                        cout << ans[ii][jj]; 
                    }
                    cout << endl;
                }
                flag = true;
                break;
            }
/*
            if (dfs(ans, B - 1) == M) {
                cout << dfs(ans, B - 1) << endl;
                for (int ii = 0; ii < B; ++ii) {
                    for (int jj = 0; jj < B; ++jj) {
                        cout << ans[ii][jj] << " "; 
                    }
                    cout << endl;
                }
                cout << endl;
            }
            */
            /*
            int sum = 0;
            for (int i = 1; i <= B; ++i) {
                sum += mult(ans, i);
            }
            if (sum == M) {
                for (int ii = 0; ii < B; ++ii) {
                    for (int jj = 0; jj < B; ++jj) {
                        cout << ans[ii][jj] << " "; 
                    }
                    cout << endl;
                }
                cout << endl;
            }
            */
            /*
            for (int ii = 0; ii < B; ++ii) {
                for (int jj = 0; jj < B; ++jj) {
                    cout << ans[ii][jj] << " "; 
                }
                cout << endl;
            }
            cout << endl;
            */



        }
        if (!flag) {
            cout << "Case #" << test << ": IMPOSSIBLE" << endl;
        }
    }


    return 0;
}