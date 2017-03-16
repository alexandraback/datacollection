#include<iostream>
#include<cstdio>
using namespace std;
char s[2000];
char a[3000];
int n, b, e;
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    for (int t = 0; t < n; ++t){
        b = 1500;
        e = 1500;
        scanf("%s", s);
        for (int i = 0; s[i] != '\0'; ++i){
            //cout<<i<<' '<<s[i]<<endl;
            if ((i > 0)&&(s[i] >= a[b])){
                --b;
                a[b] = s[i];
            }else{
                a[e] = s[i];
                ++e;
            }
        }
        a[e] = '\0';
        printf("Case #%d: %s\n", t + 1, a + b);
    }
}
