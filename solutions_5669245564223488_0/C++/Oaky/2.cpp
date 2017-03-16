#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef pair<int,int> II;

string str[202];
char tmp[202];

int go(int n, const vector<int>& vec){
    bool seen[26];
    for(int i = 0; i < 26; ++i) seen[i] = false;
    int previous = -1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < str[vec[i]].size(); ++j){
            if((previous != str[vec[i]][j]) and
               (previous != -1) and
               seen[str[vec[i]][j] - 'a']){
                   // printf("$\n");
                   return 0;
            }else{
                previous = str[vec[i]][j];
                seen[str[vec[i]][j] - 'a'] = true;
            }
            // printf("%c", str[vec[i]][j]);
        }
    }
    // printf("#\n");
    return 1;
}

int solve(){
    int n, ans = 0;
    scanf("%d", &n);
    vector<int> vec;
    for(int i = 0; i < n; ++i){
        scanf("%s", tmp);
        str[i] = tmp;
        vec.push_back(i);
    }
    do{
        ans += go(n, vec);
    }while(next_permutation(vec.begin(), vec.end()));
    return ans;
}

int main(){
    int alltest;
    scanf("%d", &alltest);
    for(int i = 1; i <= alltest; ++i){
        printf("Case #%d: %d", i, solve());
    }
    return 0;
}
