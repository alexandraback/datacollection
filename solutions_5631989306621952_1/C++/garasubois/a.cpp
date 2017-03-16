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

string solve(string str){
    int tar = 0;
    int sz = str.size();
    if(sz<=1) return str;

    rep(i,sz) if(str[i]>=str[tar]) tar = i;

    return str[tar]+solve(str.substr(0,tar))+str.substr(tar+1,sz-tar-1);
}

int main()
{
    int N;
    cin >> N;
    rep(case_num,N){
        string str;
        cin >> str;
        cout << "Case #" << case_num+1 << ": " << solve(str) << endl;
    }
    return 0;
}

