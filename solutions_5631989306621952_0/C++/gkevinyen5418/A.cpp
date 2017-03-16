#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

char s[2000]; int sn;

int main()
{
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);

    int T;
    scanf("%d", &T);

    deque<char> deq;

    for(int Ti = 1; Ti <= T; Ti++)
    {
        scanf("%s", s);
        sn = strlen(s);

        deq.clear();
        deq.push_back(s[0] );

        for(int si = 1; si < sn; si++)
            if( s[si] >= deq[0] ) deq.push_front(s[si]);
            else deq.push_back(s[si]);

        printf("Case #%d: ", Ti);

        for(int si = 0; si < sn; si++)
            printf("%c", deq[si]);
        puts("");
    }
}
