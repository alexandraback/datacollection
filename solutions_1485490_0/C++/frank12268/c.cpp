#include<iostream>

const int MAXN = 100+10;

long long a[MAXN];
int A[MAXN];
long long b[MAXN];
int B[MAXN];
int m,n;
long long f[MAXN][MAXN];

void work(){
    for (int i=0;i<=n;++i){
        f[i][0] = 0;
    }
    for (int j=0;j<=m;++j){
        f[0][j] = 0;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            f[i][j] = (f[i-1][j]>f[i][j-1])?f[i-1][j]:f[i][j-1];
            for (int k=1;k<=100;++k){
                long long same = 0,tmp;
                int ti = i;
                while (ti>0&&A[ti]!=k){
                    --ti;
                }
                long long aleft = a[ti];
                int tj = j;
                while (tj>0&&B[tj]!=k){
                    --tj;
                }
                long long bleft = b[tj];
                while (ti>0&&tj>0){
                    tmp = std::min(aleft,bleft);
                    same += tmp;
                    if (f[i][j]<same+f[ti-1][tj-1]){
                        f[i][j] = same+f[ti-1][tj-1];
                    }
                    aleft -= tmp;
                    bleft -= tmp;
                    if (aleft==0){
                        --ti;
                        while (ti>0&&A[ti]!=k){
                            --ti;
                        }
                        aleft = a[ti];
                    }
                    if (bleft==0){
                        --tj;
                        while (tj>0&&B[tj]!=k){
                            --tj;
                        }
                        bleft = b[tj];
                    }
                }
            }
        }
    }
    std::cout << f[n][m] << std::endl;
}

int main(){
    int noc;
    std::cin >> noc;
    for (int tnoc=1;tnoc<=noc;++tnoc){
        std::cout << "Case #" << tnoc << ": ";
        std::cin >> n >> m;
        for (int i=1;i<=n;++i){
            std::cin >> a[i] >> A[i];
        }
        for (int i=1;i<=m;++i){
            std::cin >> b[i] >> B[i];
        }
        work();
    }
    return 0;
}
