#include <bits/stdc++.h>
using namespace std;

const int N  = 2005;
char str[N];

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int TC, tc;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++){
        scanf("%s", str);
        int n = strlen(str);
        deque<char>dq;
        char leftest = 0;

        for(int i = 0; i < n; i++){
            if(str[i] >= leftest){
                dq.push_front(str[i]);
                leftest = str[i];
            }else {
                dq.push_back(str[i]);

            }
        }
        printf("Case #%d: ", tc);
        while(!dq.empty()){
            printf("%c", dq.front());
            dq.pop_front();
        }
        printf("\n");
    }
    return 0;
}
