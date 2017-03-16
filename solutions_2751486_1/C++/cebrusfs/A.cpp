#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1000006

char str[MAX];

bool check(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
        c == 'u';
}

long long count(int l, int r)
{
    long long d = r - l + 1;

    return d * (d+1)/2;
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int Ti=1; Ti<=T; Ti++)
    {
        int n;
        scanf(" %s %d", str, &n);

        int len = strlen(str);

        vector< pair<int, int> > ary;
        for(int l=0, r=0; r < len; r++)
        {

            while(r - l + 1 > n)
                l++;

            if(check(str[r]))
                l = r + 1;


            //printf("%d %d %c\n", l, r, str[r]);

            if(r - l + 1 < n)
                continue;
//            printf("!%d %d %c\n", l, r, str[r]);

            ary.push_back( make_pair(l, r) );
        }

        long long ans = count(0, len-1);


        sort(ary.begin(), ary.end());
        int ml = -1;
        for(size_t i=0; i<ary.size(); i++)
        {
            ans -= count(ml+1, ary[i].second - 1);
            ans += count(ary[i].first + 1, ary[i].second - 1);

            ml = max( ary[i].first, ml );
        }
        ans -= count(ml+1, len-1);

        printf("Case #%d: %lld\n", Ti, ans);
    }
}
