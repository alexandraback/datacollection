#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1100;
char ch[N];
char res[N * 2];
int main(){
    //freopen("in.txt", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t; scanf("%d", &t);
    while (t --){
        static int ca = 0;
        printf("Case #%d: ", ++ ca);
        scanf("%s", ch);
        int len = strlen(ch);
        res[1000] = ch[0];
        int nowl = ch[0], nowr = ch[0], l = 1000, r = 1000;
        for (int i = 1; i < len; ++ i){
            if (ch[i] >= nowl){
                nowl = ch[i];
                l--;
                res[l] = ch[i];
            }else{
                nowr = ch[i];
                r++;
                res[r] = ch[i];
            }
        }
        res[++ r] = '\0';
        printf("%s\n", res + l);
    }
}
