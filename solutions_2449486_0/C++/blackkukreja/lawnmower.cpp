#include <iostream>
#include <cstdio>
using namespace std;

int main()  {
    int lawn[110][110], T, N, M, I, J, K, L;
    bool wrong;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.txt", "w", stdout);

    cin >> T;
    for(I=1; I<=T; I++) {
        cin >> N >> M;
        for(J=0; J<N; J++)
            for(K=0; K<M; K++)
                cin >> lawn[J][K];

        wrong = false;
        for(J=0; !wrong && J<N; J++)  {
            for(K=0; !wrong && K<M; K++)  {
                for(L=0; L<M; L++)
                    if(lawn[J][L] > lawn[J][K]) { wrong = true; break; }
                if(wrong)   {
                    for(L=0; L<N; L++)
                        if(lawn[L][K] > lawn[J][K]) break;
                    if(L == N) wrong = false;
                }
            }
        }
        if(wrong)   cout << "Case #" << I << ": NO\n";
        else        cout << "Case #" << I << ": YES\n";
    }
    return 0;
}
