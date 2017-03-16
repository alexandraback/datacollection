#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
vector<string> S = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
void findAns(int M[])
{
    int num[10] = {0};
    while(M['Z'-'A'] > 0){
        num[0]++;
        for(int i = 0; i < (int)S[0].length(); i++){
            M[S[0][i] - 'A']--;
        }
    }
    while(M['W' - 'A'] > 0){
        num[2]++;
        for(int i = 0; i < (int)S[2].length(); i++){
            M[S[2][i] - 'A']--;
        }
    }
    while(M['X' - 'A'] > 0){
        num[6]++;
        for(int i = 0; i < (int)S[6].length(); i++){
            M[S[6][i] - 'A']--;
        }
    }
    while(M['G' - 'A'] > 0){
        num[8]++;
        for(int i = 0; i < (int)S[8].length(); i++){
            M[S[8][i] - 'A']--;
        }
    }
    while(M['T' - 'A'] > 0){
        num[3]++;
        for(int i = 0; i < (int)S[3].length(); i++){
            M[S[3][i] - 'A']--;
        }
    }
    while(M['R' - 'A'] > 0){
        num[4]++;
        for(int i = 0; i < (int)S[4].length(); i++){
            M[S[4][i] - 'A']--;
        }
    }
    while(M['O' - 'A'] > 0){
        num[1]++;
        for(int i = 0; i < (int)S[1].length(); i++){
            M[S[1][i] - 'A']--;
        }
    }
    while(M['F' - 'A'] > 0){
        num[5]++;
        for(int i = 0; i < (int)S[5].length(); i++){
            M[S[5][i] - 'A']--;
        }
    }
    while(M['V' - 'A'] > 0){
        num[7]++;
        for(int i = 0; i < (int)S[7].length(); i++){
            M[S[7][i] - 'A']--;
        }
    }
    while(M['N' - 'A'] > 0){
        num[9]++;
        for(int i = 0; i < (int)S[9].length(); i++){
            M[S[9][i] - 'A']--;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < num[i]; j++){
            printf("%d",i);
        }
    }
    printf("\n");
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T,N; string S;
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
        cin >> S;
        N = S.length();
        int M[26] = {0};
        for(int i = 0; i < N; i++){
            M[S[i] - 'A']++;
        }
        printf("Case #%d: ",t);
        findAns(M);

    }
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
