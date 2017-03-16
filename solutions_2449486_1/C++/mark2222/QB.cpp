#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct patch{
    int x,y,h;
    patch(){}
    patch(int xa,int ya,int ha){x=xa;y=ya;h=ha;}
};
bool cmp(patch a,patch b){
    return a.h>b.h;
}
patch patches[10000];
bool takenx[2][100],takeny[2][100];
int main(){
    freopen("QB.in","r",stdin);
    freopen("QB.out","w",stdout);
    int numcases;
    scanf("%d",&numcases);
    for(int ccase=0;ccase<numcases;ccase++){
        memset(takenx,false,sizeof(takenx));
        memset(takeny,false,sizeof(takeny));
        int ylen,xlen;
        scanf("%d%d",&ylen,&xlen);
        for(int i=0;i<ylen;i++){
            for(int i2=0;i2<xlen;i2++){
                int patchi=i*xlen+i2;
                patches[patchi].x=i2;
                patches[patchi].y=i;
                scanf("%d",&patches[patchi].h);
            }
        }
        sort(patches,patches+xlen*ylen,cmp);
        bool possible=true;
        int ch=101;
        int flag=0;
        for(int i=0;i<ylen*xlen;i++){
            //printf("%d %d %d %d\n",patches[i].x,patches[i].y,patches[i].h,takenx[flag][2]);
            if(patches[i].h<ch){
                ch=patches[i].h;
                flag=1-flag;
                memcpy(takenx[flag],takenx[1-flag],sizeof(takenx[1-flag]));
                memcpy(takeny[flag],takeny[1-flag],sizeof(takeny[1-flag]));
            }
            if(takenx[1-flag][patches[i].x]&&takeny[1-flag][patches[i].y]){
                possible=false;
                break;
            }
            else{
                takenx[flag][patches[i].x]=true;
                takeny[flag][patches[i].y]=true;
            }
        }
        if(possible) printf("Case #%d: YES\n",ccase+1);
        else printf("Case #%d: NO\n",ccase+1);
    }
    return 0;
}
