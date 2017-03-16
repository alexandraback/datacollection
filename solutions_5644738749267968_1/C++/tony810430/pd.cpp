#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int T;
vector<double> a,b;
int N,cas;

int solvea()
{
    int ans=0,j=N-1;
    for( int i = N-1; i >= 0; i-- ){
        for( ; j >= 0; j-- ){
            if( a[i] > b[j] ){
                ans++;j--;break;
            }
        }
    }
    return ans;
}

int use[2000];
int solveb()
{
    int ans=0;
    memset(use,0,sizeof(use));
    for( int i = 0; i < N; i++ ){
        int cand;
        for( cand = 0; cand < N; cand++ ){
            if( use[cand] == 0 && b[cand] > a[i] )break;
        }
        if( cand == N ){
            ans++;
            for( int j = 0; j < N; j++ ){
                if( use[j] == 0 ){
                    use[j]++;break;
                }
            }
        }else{
            use[cand] = 1;
        }
    }

    return ans;
}

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("pd.large","w",stdout);
    scanf(" %d",&T);

    for( cas = 1; cas <= T; cas++ ){
        scanf(" %d",&N);
        a.resize(N);
        b.resize(N);
        for( int i = 0; i < N; i++ )
            scanf(" %lf",&a[i]);
        for( int i = 0; i < N; i++ )
            scanf(" %lf",&b[i]);
        sort(b.begin(),b.end());
        int pb = solveb();
        sort(a.begin(),a.end());
        int pa = solvea();
        printf("Case #%d: %d %d\n",cas,pa,pb);
    }

    return 0;
}
