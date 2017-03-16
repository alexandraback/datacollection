#include <iostream>
#include <algorithm>
using namespace std;
int g[110][110];
bool a[110][110];
int n,m;
bool check(int x,int y){
    int a=x,b=x,c=y,d=y,j,k=g[x][y];
    bool xx=false,yy=false;
    while(a<n){
        if(g[a][y]>k)
        {xx=true;
        break;
        }
        a++;
    }
    while(b>=0){
        if(g[b][y]>k){xx=true;
        break;
        }
        b--;
    }
    while(c<m){
        if(g[x][c]>k){yy=true;
        break;
        }
        c++;
    }
    while(d>=0){
        if(g[x][d]>k){yy=true;
        break;
        }
        d--;
    }
    if(xx&yy)return false;
    return true;
}
int main()
{

//    freopen("test.txt","r",stdin);//B-small-attempt0.in
    freopen("B-small-attempt5.in","r",stdin);//B-small-attempt0.in
    freopen("B-small-attempt0.out","w",stdout);
    int t,i,j,k;
    bool tmp;
    cin>>t;
    for(i=1;i<=t;i++){
        tmp=true;
        cin>>n>>m;
        for(j=0;j<n;j++){
            for(k=0;k<m;k++){
                scanf("%d",&g[j][k]);
                a[j][k]=false;
            }
        }
         for(j=0;j<n;j++){
            for(k=0;k<m;k++){

                    tmp=check(j,k);

                    if(!tmp){
                        break;
                    }

            }
            if(!tmp){
                break;
            }
        }

        printf("Case #%d: ",i);
        if(!tmp){
            printf("NO\n");
        }else {
            printf("YES\n");

        }




    }


    return 0;
}
