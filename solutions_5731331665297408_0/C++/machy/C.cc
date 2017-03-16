#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

typedef long long LL;
using namespace std;

bool checkRoute2(int goal, int pos, vector<vector<int> >& mat, vector<int>& memo){
    if(pos == goal) return true;
    memo[pos] = 1;
    int N = mat.size();
    for(int i = 0; i < N; i++){
        if(!mat[pos][i]) continue;
        if(memo[i]) continue;
        if(checkRoute2(goal, i, mat, memo)) return true;
    }
    return false;
}

bool checkRoute(int a, int b, vector<vector<int> >& mat){
    int N = mat.size();
    vector<int> memo(N, 0);
    memo[a] = 1;
    bool ans = checkRoute2(a, b, mat, memo);
    return ans;
}

int getValue(vector<vector<int> >& mat, int pos, int cur, vector<int>& visited, vector<string>& zipcode){
    if(pos < 0) return -1;
    if(!visited[pos]) return pos;
    int best = -1;
    int N = mat.size();
    for(int j = 0; j < N; j++){
        if(!mat[pos][j]) continue;
        if(j == cur) continue;
        if(best == -1 || zipcode[best] > zipcode[j]) best = j;
    }
    return best;
}

string solve(vector<string>& zipcode, vector<vector<int> >& mat, int pos, vector<int>& visited){
    string ans;
    int N = mat.size();
    while(true){
        int best = -1;
        for(int j = 0; j < N; j++){
            if(!mat[pos][j]) continue;
            int p1 = getValue(mat, best, pos, visited, zipcode);
            int p2 = getValue(mat, j, pos, visited, zipcode);
            if(p2 < 0) continue;
            if(p1 < 0 || zipcode[p1] > zipcode[p2]){
                best = j;
            }
        }
        if(best == -1) break;
        if(!visited[best]){
            ans += zipcode[best];
            visited[best] = 1;
        }
        mat[pos][best] = 0;
        mat[best][pos] = 0;
        if(!checkRoute(pos, best, mat)){
            ans += solve(zipcode, mat, best, visited);
        }
    }
    return ans;
}

string solve(vector<string>& zipcode, vector<vector<int> >& mat){
    int pos = min_element(zipcode.begin(), zipcode.end()) - zipcode.begin();
    int N = zipcode.size();
    vector<int> visited(N, 0);
    visited[pos] = 1;
    return zipcode[pos] + solve(zipcode, mat, pos, visited);
}

int main(){
    int T;

    cin >> T;
    for(size_t t = 1; t <= T; t++){
        int N, M;
        cin >> N >> M;
        vector<string> zipcode(N);
        vector<vector<int> > mat(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++){
            cin >> zipcode[i];
        }
        for(int i = 0; i < M; i++){
            int n1, n2;
            cin >> n1 >> n2;
            mat[n1-1][n2-1] = 1;
            mat[n2-1][n1-1] = 1;
        }
        string ans = solve(zipcode, mat);
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}

