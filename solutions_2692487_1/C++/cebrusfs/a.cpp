#include <cstdio>
#include <deque>
#include <algorithm>
#define MAX 105

using namespace std;

deque<int> ary;

int main()
{
    int T;
    scanf("%d", &T);

    for(int Ti=1; Ti<=T; Ti++)
    {
        int A, n;
        scanf("%d %d", &A, &n);

        ary.clear();
        for(int i=0; i<n; i++)
        {
            int t;
            scanf("%d", &t);
            ary.push_back(t);
        }

        sort(ary.begin(), ary.end());

        int ans = n;
        int op = 0;
        while(1)
        {
            while(!ary.empty() && A > ary.front())
            {
                A += ary.front();
                ary.pop_front();
            }

            ans = min(op + (int)ary.size(), ans);

            if(ary.empty() || A-1 < 1)
                break;

            ary.push_front(A-1);
            op += 1;
        }
        printf("Case #%d: %d\n", Ti, ans);


    }
}
