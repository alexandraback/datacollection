#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[105][105];
int n,m;
int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("out.out","w",stdout);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&m);

        int mx=0;
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                scanf("%d",&arr[i][j]);
                mx=max(mx,arr[i][j]);
            }
        }


        bool pos=true;

        for (int i=mx;i>0;--i){
            for (int j=0;j<n;++j){
                for (int k=0;k<m;++k){

                    if ( arr[j][k]== i ){

                        int wrong=0;

                        for (int p=0;p<n;++p){
                            if ( arr[p][k]> i){
                                wrong++;
                                break;
                            }
                        }

                        for (int p=0;p<m ;++p){
                            if ( arr[j][p]> i){
                                wrong++;
                                break;
                            }
                        }
                        if ( wrong==2 ){
                            pos=false;
                            j=k=n+m+1;
                            i= -1;
                        }
                    }
                }
            }
        }
        if ( pos ){
            printf("Case #%d: YES\n",kk);
        }else{
            printf("Case #%d: NO\n",kk);
        }

    }

}
