#include <bits/stdc++.h>

using namespace std;

double A[1010];
double B[1010];

void solve()
{
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>A[i];
    for(int i=0; i<N; i++)
        cin>>B[i];
    sort(A, A+N);
    sort(B, B+N);
    int deceit_score=0;
    int k_head=0;
    for(int i=0; i<N; i++)
        if(A[i]>B[k_head])
        {
            deceit_score++;
            k_head++;
        }
    printf("%d ", deceit_score);
    int war_score=0;
    set<double> ken(B, B+N);
    for(int i=0; i<N; i++)
    {
        set<double>::iterator it=ken.upper_bound(A[i]);
        if(it==ken.end())
        {
            war_score+=N-i;
            break;
        }
        ken.erase(it);
    }
    printf("%d\n", war_score);
}

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
