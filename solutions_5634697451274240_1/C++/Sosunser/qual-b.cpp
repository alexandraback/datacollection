#include <bits/stdc++.h>
using namespace std;

int t;
int n;
char ch;
bool a[111];

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d\n",&t);
    for(int k = 1; k <= t; k++){
        n = 0;
        ch = '0';
        while(ch != '\n'){
            scanf("%c",&ch);
            a[n++] = (ch == '-');
        }
        n--;
        int res = 0;
        bool b = 0;
        for(int i = n-1; i >= 0; i--){
            if(a[i] != b){
                b = a[i];
                res++;
            }
        }
        printf("Case #%d: %d\n",k,res);
    }
}