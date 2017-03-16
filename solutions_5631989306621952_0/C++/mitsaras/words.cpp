#include<cstdio>
#include<cstring>
#include<deque>

using namespace std;

int main(){
    int T;
    char S[2000];

    scanf("%d\n", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%s\n", S);
        int L = strlen(S);
        //printf("t: %d, %s, %d\n", t, S, L);
        deque<char> str;
        for (int i = 0; i <= L-1; i++) {
            if (S[i] >= str[0])
                str.push_front(S[i]);
            else
                str.push_back(S[i]);
        }
        printf("Case #%d: ", t);
        deque<char>::iterator it;
        for (it = str.begin(); it != str.end(); it++)
            printf("%c", *it);
        printf("\n");
    }
    return 0;
}
