#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using namespace std::tr1;

#define rep(i, n) for (int i = 0; i < n; ++i)
int ri() { int a; scanf( "%d", &a ); return a; }
long long rll() { long long a; scanf( "%lld" , &a ); return a ; }

int main()
{
    freopen("C:\\Users\\Administrator\\Desktop\\A-small-attempt0.in","rt",stdin);
    freopen("C:\\Users\\Administrator\\Desktop\\A-small-practice.out","wt",stdout);
	
    int T = ri();
    rep(t, T)
    {
        string s;
        int n;
        cin>>s>>n;
        int M = s.size();
        for (int i = 0; i < M; ++i)
            if (s[i] != 'a' && 
                s[i] != 'e' && 
                s[i] != 'i' && 
                s[i] != 'o' && 
                s[i] != 'u')
            s[i] = '*';
        vector<int> pos(M, 0);
        int start = 0;
        int i = 0;
        while (i < M)
        {
            if (s[i] != '*')
            {
                i++;
                continue;
            }

            int j = i + 1;
            while (j < M && s[j] == '*' && (j - i) < n)
                j++;

            if (j - i >= n)
            {
                for (int k = start; k <= i; ++k)
                    pos[k] = i;
                start = i + 1;
            }
            i++;
        }
        for (int k = start; k < M; ++k)
            pos[k] = -1;
        
        int res = 0;
        for (int i = 0; i < M; ++i)
        {
            if (pos[i] == -1)
                break;
            res += M - (pos[i] + n) + 1;
        }

        printf("Case #%d: ", t+1);
        printf("%d\n", res);
    }
    return 0;
}