#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
char str[1000001];
int n, TC, consec, l, start[1000000];
long long ans;
bool isV(char x){
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return true;
    return false;
}
long long add(int x){
    return x*(x+1)/2;
}
int main(){
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        queue<int> q;
        ans = consec = 0;
        scanf("%s %d", str, &n); l = strlen(str);
        for(int i = 0; i < l; ++i){
            start[i] = 0;
            q.push(i);
            if(!isV(str[i])) consec++;
            else consec = 0;
            if(consec >= n){
                //printf("yay %d\n", consec);
                while(!q.empty()){
                    if(q.front() <= i - n+1){
                        start[q.front()] = l - i;
                        q.pop();
                    }
                    else break;
                }
            }
        }
        for(int i = 0; i < l; ++i){
            //printf("%d\n", start[i]);
            ans += start[i];
        }
        printf("Case #%d: %lld\n", tc, ans);
    }
    //system("pause");
}
