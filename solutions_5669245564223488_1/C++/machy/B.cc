#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

bool loop_check2(vector<pair<int,int> >& sides, int N, int left, vector<int>& memo){
    memo[left] = 1;
    for(int i = 0; i < sides.size(); i++){
        if(sides[i].first == left && sides[i].first != sides[i].second){
            int right = sides[i].second;
            if(memo[right] != 0) return false;
            if(!loop_check2(sides, N, right, memo)) return false;
        }
    }
    memo[left] = 0;
    return true;
}

bool loop_check(vector<pair<int,int> >& sides, int N){
    vector<int> memo(26, 0);
    for(int a = 0; a < 26; a++){
        if(!loop_check2(sides, N, a, memo)) return false;
    }
    return true;
}

int solve(vector<string>& cars, int N){
    int n_alpha = 26;
    LL ans = 1;
    vector<int> inside(n_alpha, 0);
    vector<pair<int, int> > sides(N);
    for(int i = 0; i < N; i++){
        int left = cars[i][0] - 'a';
        int cur = left;
        int cnt = 0;
        for(int j = 1; j < cars[i].size(); j++){
            int c = cars[i][j] - 'a';
            if(c != cur){
                inside[c]++;
                cnt++;
                cur = c;
            }
        }
        int right = cur;
        inside[right]--;
        if(cnt >= 2 && left == right) return 0;
        sides[i] = pair<int,int>(left, right);
    }
    int free_term = 0;
    for(int i = 0; i < n_alpha; i++){
        int cnt_left = 0;
        int cnt_right = 0;
        int cnt_mono = 0;
        for(int j = 0; j < sides.size(); j++){
            if(sides[j].first != sides[j].second){
                if(sides[j].first == i) cnt_left++;
                if(sides[j].second == i) cnt_right++;
            }else{
                if(sides[j].first == i) cnt_mono++;
            }
        }
        if(inside[i] + max(cnt_left, cnt_right) >= 2) return 0;
        if(inside[i] > 0 && cnt_mono > 0) return 0;
        for(LL j = cnt_mono; j >= 1; j--){
            ans = ans * j % MOD;
        }
        if(cnt_left + cnt_right == 1){
            free_term++;
        }
        if(cnt_left == 0 && cnt_right == 0 && cnt_mono > 0){
            free_term += 2;
        }
    }
    if(free_term < 1) return 0;
    free_term /= 2;
    for(; free_term > 1; free_term--){
        ans = ans * free_term % MOD;
    }
    if(!loop_check(sides, N)) return 0;
    return ans;
}

int main(){
    int T;

    cin >> T;
    for(size_t t = 1; t <= T; t++){
        int N;
        cin >> N;
        vector<string> cars(N);
        for(int n = 0; n < N; n++){
            cin >> cars[n];
        }
        int res = solve(cars, N);
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}

