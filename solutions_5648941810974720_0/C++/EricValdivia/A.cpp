#include<bits/stdc++.h>
using namespace std;

string arr[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int numsize[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};
char cad[3000];
int test, cont[300], letras, l, res[3000], resSize;

bool dfs(int num, int idx){
    if(letras == l){
        resSize = idx;
        return true;;
    }
    for(int i = num; i < 10; i++){
        int error = -1;
        for(int j = 0; j < numsize[i]; j++){
            if(cont[arr[i][j]] == 0){
                error = j;
                break;
            }
            else{
                cont[arr[i][j]]--;
            }
        }

        if(error == -1){
            letras += numsize[i];
            if(dfs(i, idx + 1)){
                res[idx] = i;
                return true;
            }
            letras -= numsize[i];

            for(int j = 0; j < numsize[i]; j++){
                cont[arr[i][j]]++;
            }
        }
        else{
            for(int j = 0; j < error; j++){
                cont[arr[i][j]]++;
            }
        }
    }
    return false;
}

void solve(){
    scanf("%s", cad);
    l = strlen(cad);
    resSize = 0;
    letras = 0;
    for(int i = 0; i < 300; i++) cont[i] = 0;
    for(int i = 0; i < l; i++) cont[cad[i]]++;
    dfs(0, 0);
    for(int i = 0; i < resSize; i++) printf("%d", res[i]);
    printf("\n");
}

int main(){
    freopen("ASmall.out", "w", stdout);
    freopen("ASmall.in", "r", stdin);
    scanf("%d", &test);
    for(int testCase = 1; testCase <= test; testCase++){
        printf("Case #%d: ", testCase);
        solve();
    }
    fclose(stdout);
}
