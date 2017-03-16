#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int T,N;
    int F[1005];
    int len[1005];
    int loop[1005];
    bool flg[1005];
    int pnt;
    int maxlen,looplen;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d",&F[i]); F[i]--;
            //printf("in %d\n",F[i]);
            loop[i]=0;
        }
        maxlen=0;
        for(int i=0;i<N;i++){
            //printf("i=%d\n",i);
            for(int j=0;j<N;j++) flg[j]=0;
            pnt=i;
            flg[pnt]=1; len[i]=1;
            //printf("beginwhile\n");
            while(!flg[F[pnt]]){
                //printf("pnt=%d next=%d\n",pnt,F[pnt]);
                pnt=F[pnt]; flg[pnt]=1;
                len[i]++;
            }
            //printf("endwhile\n");
            if(F[F[pnt]]==pnt){
                if(len[i]>loop[pnt]){
                    loop[pnt]=len[i];
                    //loop[F[pnt]]=0;
                }
            }
            else if(F[pnt]!=i) len[i]=0;

            if(len[i]>maxlen) maxlen=len[i];
        }
        looplen=0;
        for(int i=0;i<N;i++){
            looplen+=loop[i];
            if(loop[i]>0 && loop[F[i]]!=0) looplen--;
            //printf("loop%d = %d >> %d\n",i,loop[i],looplen);
        }
        if(looplen>maxlen) maxlen=looplen;

        printf("Case #%d: %d\n",t,maxlen);
    }
    return 0;
}
