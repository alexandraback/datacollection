#include <cstdio>
#include <cstring>

int nCase;

int Solve( )
{
    int n, S, p;
    int ans = 0;

    scanf("%d%d%d", &n, &S, &p);

    for (int i = 0; i < n; ++i) {
       int input;

       scanf("%d", &input);

       if ((input + 2) / 3 >= p) {
           ++ans;
       } else if (S > 0 && 
               (input + 1) % 3 == 0 &&
               (input + 2) / 3 + 1 >= p) {
           ++ans;
           --S;
       } else if (S > 0 && input != 0 && 
               input % 3 == 0 &&
               input / 3 + 1 >= p) {
           ++ans;
           --S;
       }
    }

    return ans;
}

void InputAndSolve( )
{
    scanf("%d", &nCase);

    for (int caseCnt = 1; caseCnt <= nCase; ++caseCnt) {
        printf("Case #%d: %d\n", caseCnt, Solve( ));
    }
}

int main( )
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    InputAndSolve( );

    return 0;
}
