#include <bits/stdc++.h>

#define INF (1 << 29)
#define rep2(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define EPS 1e-10

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector<int> solve(int N, vector< vector<int> > arr){
    vector<int> res;
    res.reserve(N);
    int memo[3000];
    memset(memo,0,sizeof(memo));
    rep(i,arr.size()) rep(j,arr[i].size()) memo[arr[i][j]]++;

    rep(i,3000) if(memo[i]%2) res.push_back(i);
    return res;
}

int main()
{
    int T;
    cin >> T;
    rep(case_num,T){
        int N;
        cin >> N;
        vector< vector<int> > arr(2*N-1);
        rep(i,2*N-1){
            arr[i].resize(N,0);
            rep(j,N) cin >> arr[i][j];
        }
        vector<int> res = solve(N,arr);
        cout << "Case #" << case_num+1 << ": ";
        rep(i,N-1) cout << res[i] << ' ';
        cout << res[N-1] << endl;
    }
    return 0;
}

