#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define gmax(a,b) ((a)>(b)?(a):(b))
#define gmin(a,b) ((a)<(b)?(a):(b))

long long f[20][10];
long long v[20];
long long E, R;
int N;

int main()
{
    //freopen("B.in", "r", stdin);
    int T;
    cin >> T;
    for(int Case = 1; Case <= T; Case++){
        cout << "Case #"<<Case<<": ";
        memset(f, 0, sizeof(f));
        cin >> E >> R >> N;
        for(int i=1; i<=N; i++){
            cin >> v[i];
        }
        for(int i=0; i<=E;i++)
            f[1][i] = (E-i)*v[1];
        for(int i=2; i<=N; i++){
            for(int j=0; j<=E; j++){
                for(int k=j-R; k<=E; k++){
                    if(k<0)continue;
                    f[i][j] = gmax(f[i][j], f[i-1][k] + v[i]*(gmin(k+R, E)-j));
                }
            }
        }
        cout << f[N][0] <<endl;

    }
    return 0;
}
