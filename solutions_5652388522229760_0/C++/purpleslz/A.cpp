#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int TestCase;

int main()
{
    freopen("Acnm.in", "r", stdin);
    freopen("Acnm.out","w",stdout);
    scanf("%d", &TestCase);
    
    for (int T = 1; T <= TestCase; ++T)
    {
        bool flag = 0;
        int N;
        scanf("%d", &N);
        
        bool v[10];
        memset(v, 0, sizeof(v));
        
        if (N == 0)
        {
           printf("Case #%d: INSOMNIA\n", T);
        }
        else
        {
            int len = 0;
            
            for (int tmp = N; tmp; tmp /= 10) ++len;
            
            int MAX = 1;
            for (int i = 1; i <= len; ++i) MAX *= 10;
            
            MAX += 200;
            long long tmp = 0;
            int cnt = 0;
            long long ans = 0;
            for (int i = 1; i <= MAX; ++i)
            {
                tmp += N;
                for (long long cnm = tmp; cnm; cnm /= 10)
                    if (!v[cnm%10])
                    {
                      //  cout << "i = " << i << " " << cnm%10 << endl;
                        v[cnm%10] = 1;
                        ++cnt;
                    }
                if (cnt == 10)
                {
                    flag = 1;
                    break;
                }
            }
            
            if (flag)
            {
               printf("Case #%d: ", T);
               cout << tmp << endl;
            }
            else
               printf("Case #%d: INSOMNIA\n", T);
                
        }
    }
    return 0;
}
