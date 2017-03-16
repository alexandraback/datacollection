#include <bits/stdc++.h>
#define MOD 1000000007
#define MINF -1000000000000000000

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,string> ss;

char getchar(int a)
{
    return a+'A';
}

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int t;
    fin >> t;
    int T=t;

    while(t--)
    {
        fout<<"Case #"<<T-t<<": ";
        ll m,n;
        fin>>n>>m;
        if((1LL<<(n-2)) < m ){
            fout<<"IMPOSSIBLE\n";
            continue;
        }
        fout<<"POSSIBLE\n";
        int mat[n][n];
        memset(mat,0,sizeof(mat));
        for(int ctr1=1;ctr1<n;ctr1++)
            for(int ctr2=ctr1+1;ctr2<n;ctr2++)
                mat[ctr1][ctr2]=1;
        m--;

        mat[0][n-1]=1;
        for(int ctr1=0;ctr1<n-2;ctr1++){
            if(m&(1LL<<ctr1)){
                mat[0][n-2-ctr1]=1;
            }
        }
        for(int ctr1=0;ctr1<n;ctr1++){
            for(int ctr2=0;ctr2<n;ctr2++)
                fout<<mat[ctr1][ctr2];
            fout<<"\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}
