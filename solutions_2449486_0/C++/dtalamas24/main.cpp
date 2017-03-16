#include <cstdio>
#include <iostream>

using namespace std;

bool sip;
int A[105][105], B[105][105], ctos, cto1, cto2, grande;

int main()
{
    freopen("lawnin.txt","r",stdin);
	freopen("lawn.txt","w",stdout);
    scanf("%d",&ctos);
    for(int va=1; va<=ctos; va++){
        scanf("%d%d",&cto2,&cto1);
        for(int i=cto2; i>0; i--){
            for(int e=1; e<=cto1; e++){
                scanf("%d",&A[e][i]);
                B[e][i]=100;
            }
        }
        for(int e=1; e<=cto1; e++){
            grande=A[e][1];
            for(int i=2; i<=cto2; i++){
                if(A[e][i]>grande){
                    grande=A[e][i];
                }
            }
            for(int i=1; i<=cto2; i++){
                B[e][i]=min(B[e][i], grande);
            }
        }
        for(int i=1; i<=cto2; i++){
            grande=A[1][i];
            for(int e=2; e<=cto1; e++){
                if(A[e][i]>grande){
                    grande=A[e][i];
                }
            }
            for(int e=1; e<=cto1; e++){
                B[e][i]=min(B[e][i], grande);
            }
        }
        sip=true;
        for(int i=cto2; i>0; i--){
            for(int e=1; e<=cto1; e++){
                if(B[e][i]!=A[e][i]){
                    sip=false;
                    i=0;
                    break;
                }
            }
        }
        if(sip){
            printf("Case #%d: YES\n",va);
        }
        else {
            printf("Case #%d: NO\n",va);
        }
    }
    return 0;
}
