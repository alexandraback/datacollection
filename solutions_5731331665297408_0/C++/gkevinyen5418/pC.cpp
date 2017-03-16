#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

int T, N, M;
char _c[10][10]; string c[10];
int A[10]; bool flag;
string Ans;
string cur;
bool OK[10][10];
stack <int> stk;

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    scanf("%d", &T);

    for(int Ti = 1; Ti <= T; Ti++)
    {
        flag = false;
        memset(OK, false, sizeof(OK));
        scanf("%d %d", &N, &M);

        for(int Ni = 1; Ni <= N; Ni++)
            scanf("%s", _c[Ni]), c[Ni] = string(_c[Ni]);

        for(int Mi = 0; Mi < M; Mi++)
        {
            int a, b; scanf("%d %d", &a, &b);
            OK[a][b] = OK[b][a] = true;
        }

        for(int Ni = 0; Ni < N; Ni++) A[Ni] = Ni+1;

        do
        {
            cur = c[A[0] ];
            while( !stk.empty() ) stk.pop();
            stk.push(A[0]);

            for(int Ni = 1; Ni < N; Ni++)
            {
                int p = A[Ni];
                while(1)
                {
                    if( stk.empty() ) goto ed;
                    if( OK[ stk.top() ][p] ) break;
                    stk.pop();
                }
                cur += c[p];
                stk.push(p);
            }

            if( !flag ) Ans = cur;
            else if( cur < Ans ) Ans = cur;
            flag = true;

            ed:;
        }while( next_permutation(A, A+N) );

        printf("Case #%d: ", Ti);
        cout<<Ans<<endl;
    }
}
