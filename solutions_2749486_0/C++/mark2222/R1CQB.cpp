#include<cstdio>
#include<vector>
using namespace std;
int minmoves[101][101];
vector<int> xs[2],ys[2];
int main(){
    freopen("R1CQB.in","r",stdin);
    freopen("R1CQB.out","w",stdout);
    int numcases;
    scanf("%d",&numcases);
    for(int ccase=0;ccase<numcases;ccase++){
        int cx,cy;
        scanf("%d%d",&cx,&cy);
        printf("Case #%d: ",ccase+1);
        if(cx>0){
            for(int i=0;i<cx;i++) printf("WE");
        }
        else{
            for(int i=0;i<(-cx);i++) printf("EW");
        }
        if(cy>0){
            for(int i=0;i<cy;i++) printf("SN");
        }
        else{
            for(int i=0;i<(-cy);i++) printf("NS");
        }
        printf("\n");
    }
    return 0;
}
