#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<string>
#include<vector>

using namespace std;
map<long long, int> m;
int i, n, k;
string s[105];
vector<char> v[105];
char st[100005];
int mp[1000];

int N, M, K;

int main(){
freopen("B-small-attempt1.in", "r", stdin);
//freopen("B_out.txt", "w", stdout);
int a, b, c, d;
int R, T;
string S;
cin >> R;
T = R;
long long cnt;
int ord[1000], cmp[1000], kboom;
while(T--){
    scanf("%d", &N);
    kboom = 0;
    cnt = 0;
    for(b=0;b<256;b++) cmp[b] = 0;
    for(a=0;a<N;a++){
        ord[a] = a;
        v[a].clear();
        for(b=0;b<256;b++) mp[b] = 0;
        scanf("%s", st);
        s[a] = st;
        for(b=0;b<s[a].length();b++){
            cmp[s[a][b]] = 1;
            if(v[a].empty()){
                v[a].push_back(s[a][b]);
                mp[s[a][b]] = 1;
            }
            else if(s[a][b] == v[a][v[a].size()-1]) continue;
            else if(mp[s[a][b]] == 0){
                v[a].push_back(s[a][b]);
                mp[s[a][b]] = 1;
            }
            else {
                //printf("");

                goto endja;
            }
        }
//        for(b=0;b<v[a].size();b++)printf("%c", v[a][b]);
//        printf("\n");
    }
    c = 0;
    for(a=0;a<256;a++)if(cmp[a]) c++;
    d = 0;
    do{
        d = 0;
        for(a=0;a<N;a++){
            d += v[ord[a]].size();
            if(a and v[ord[a]][0] == v[ord[a-1]][v[ord[a-1]].size()-1]) d--;
        }
//        printf("> %d\n", d);
        if(c == d) cnt++;
    }while(next_permutation(ord, ord+N));
    endja:;
//    printf("%d ", c);
    printf("Case #%d: %lld\n", R-T, cnt%1000000007);

}

return 0;
}
