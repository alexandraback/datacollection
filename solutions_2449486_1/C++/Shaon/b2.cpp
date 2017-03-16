#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[105][105];
int n,m;
int main(){
    freopen("B-large.in","r",stdin);
    freopen("out.out","w",stdout);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&m);


        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                scanf("%d",&arr[i][j]);
            }
        }


        bool pos=true;

        for (int j=0;j<n;++j){
            for (int k=0;k<m;++k){

                int wrong=0;

                for (int p=0;p<n;++p){
                    if ( arr[p][k]> arr[j][k]){
                        wrong++;
                        break;
                    }
                }

                for (int p=0;p<m ;++p){
                    if ( arr[j][p]> arr[j][k]){
                        wrong++;
                        break;
                    }
                }
                if ( wrong==2 ){
                    pos=false;
                    j=k=n+m+1;
                }
            }
        }


        if ( pos ){
            printf("Case #%d: YES\n",kk);
        }else{
            printf("Case #%d: NO\n",kk);
        }

    }
    return 0;
}
