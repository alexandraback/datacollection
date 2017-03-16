#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int tc;
int num[128];
char str[2020];
char exchar[10] = {'Z', 'W', 'X', 'G', 'T', 'S', 'R', 'V', 'I', 'O'};
int exnum[10] = {0, 2, 6, 8, 3, 7, 4, 5, 9, 1};
char exword[10][8] = {"ZERO", "TWO", "SIX", "EIGHT", "THREE", "SEVEN", "FOUR", "FIVE", "NINE", "ONE"};
vector<int> ans;

void excute(int n){
    for(int i = 0; exword[n][i]; i++) num[exword[n][i]]--;
}

int main(){
    freopen("As.in", "r", stdin);
    freopen("As.out.", "w", stdout);
    scanf("%d", &tc);
    for(int wer = 1; wer <= tc; wer++){
        for(int i = 0; i < 128; i++) num[i] = 0;
        scanf("%s", str);
        printf("Case #%d: ", wer);
        for(int i = 0; str[i]; i++) num[str[i]]++;
        for(int i = 0; i < 10; i++){
            while(num[exchar[i]]){
                ans.push_back(exnum[i]);
                excute(i);
                //printf("%d(%d)", exnum[i], num[exchar[i]]);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) printf("%d", ans[i]);
        puts("");
        vector<int>().swap(ans);
    }
}
