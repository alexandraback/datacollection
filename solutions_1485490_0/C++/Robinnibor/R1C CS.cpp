#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

long long int w[102][102][102]={0};

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int cases,cc,i,j,ii,jj,n,m;
    long long int a[102],b[102],an;
    long long int aa[102],bb[102];
    int A[102],B[102];
    scanf("%d",&cases);
    
    for(cc=1;cc<=cases;cc++){
        memset(w,0,sizeof(w));
        scanf("%d%d",&n,&m);
        an=0;
        for(i=1;i<=n;i++)scanf("%I64d%d",&a[i],&A[i]);
        for(i=1;i<=m;i++)scanf("%I64d%d",&b[i],&B[i]);
        memcpy(aa,a,sizeof(aa));
        memcpy(bb,b,sizeof(bb));
        for(i=0;i<=m;i++){
            for(j=i;j<=m;j++){
                for(ii=j;ii<=m;ii++){
                    memcpy(a,aa,sizeof(a));
                    memcpy(b,bb,sizeof(b));
                    long long int left,tan=0;
                    left=a[1];
                    for(jj=1;jj<=i;jj++)if(B[jj]==A[1]){
                       if(left>=b[jj]){tan+=b[jj];left-=b[jj];b[jj]=0;}
                            else {
                                tan+=left;
                                b[jj]-=left;
                                left=0;
                            }
                    }
                    //fprintf(stderr,"tan=%I64d\n",tan);
                    if(n>=2){
                        left=a[2];
                        for(jj=i;jj<=j;jj++)if(B[jj]==A[2]){
                            if(left>=b[jj]){tan+=b[jj];left-=b[jj];b[jj]=0;}
                            else {
                                tan+=left;
                                b[jj]-=left;
                                left=0;
                            }
                        }
                    }
                    //fprintf(stderr,"tan=%I64d\n",tan);
                    if(n>=3){
                        left=a[3];
                        for(jj=j;jj<=ii;jj++)if(B[jj]==A[3]){
                            
                            if(left>=b[jj]){tan+=b[jj];left-=b[jj];b[jj]=0;}
                            else {
                                tan+=left;
                                b[jj]-=left;
                                left=0;
                            }
                            
                        }
                    }
                    //fprintf(stderr,"tan=%I64d\n",tan);
                    //fprintf(stderr,"%d %d %d tan=%I64d\n",i,j,ii,tan);
                    an=max(an,tan);
                }
            }
        }
        
        printf("Case #%d: %I64d\n",cc,an);
    }
    
    return 0;
}
