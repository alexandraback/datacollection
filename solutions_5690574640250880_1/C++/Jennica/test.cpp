#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char mat[60][60];
int main(){
    freopen("C-large.in","r",stdin);
    //freopen("C-small-attempt0.in","r",stdin);
    freopen("C.out","w",stdout);
    int T,tc=0,m,n,i,j,cnt,flag,t,im,tot,bl,hei,re;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&m,&n,&cnt);
        flag=0;
        im=0;
        tot=m*n;
        bl=tot-cnt;
        if(m<n){
            t=m;
            m=n;
            n=t;
            flag=1;
        }
        if(n==1){
            mat[0][0]='c';
            for(i=1;i<m-cnt;++i) mat[i][0]='.';
            for(;i<m;++i) mat[i][0]='*';
        }else if(n==2){
            if(bl==1){
                mat[0][0]='c';mat[0][1]='*';
                for(i=1;i<m;++i){
                    mat[i][0]=mat[i][1]='*';
                }
            }else if(bl%2==1 || bl==2){
                im=1;
            }else{
                mat[0][0]='c';mat[0][1]='.';
                for(i=1;i<m-cnt/2;++i){
                    mat[i][0]=mat[i][1]='.';
                }
                for(;i<m;++i){
                    mat[i][0]=mat[i][1]='*';
                }
            }
        }else{
            if(bl==1){
                for(i=0;i<m;++i) for(j=0;j<n;++j) mat[i][j]='*';
                mat[0][0]='c';
            }else if(bl==2 || bl==3 || bl==5 || bl==7){
                im=1;
            }else{
                for(i=0;i<m;++i) for(j=0;j<n;++j) mat[i][j]='.';
                mat[0][0]='c';
                if(cnt<=tot-n*3){
                    if(cnt%n==n-1){
                        hei=0;
                        for(i=m-1;i>=0;--i){
                            for(j=n-1;j>=0;--j){
                                if(hei==cnt-1) goto G;
                                mat[i][j]='*';
                                ++hei;
                            }
                        }
                        G:
                        mat[i-1][n-1]='*';
                    }else{
                        hei=0;
                        for(i=m-1;i>=0;--i){
                            for(j=n-1;j>=0;--j){
                                if(hei==cnt) goto L;
                                mat[i][j]='*';
                                ++hei;
                            }
                        }
                    }
                }else if(cnt<=tot-n*2){
                    if(cnt%n==n-1){
                        hei=0;
                        for(i=m-1;i>=0;--i){
                            for(j=n-1;j>=0;--j){
                                if(hei==cnt-2) goto Q;
                                mat[i][j]='*';
                                ++hei;
                            }
                        }
                        Q:
                        mat[0][n-1]=mat[1][n-1]='*';
                    }else{
                        hei=0;
                        for(i=m-1;i>=0;--i){
                            for(j=n-1;j>=0;--j){
                                if(hei==cnt) goto L;
                                mat[i][j]='*';
                                ++hei;
                            }
                        }
                    }
                }else{
                    re=cnt-(tot-n*2);
                    if(re%2==0){
                        for(i=m-1;i>=2;--i){
                            for(j=n-1;j>=0;--j){
                                mat[i][j]='*';
                            }
                        }
                        for(j=n-1;j>=n-re/2;--j) mat[0][j]=mat[1][j]='*';
                    }else{
                        for(i=m-1;i>=2;--i){
                            for(j=n-1;j>=0;--j){
                                mat[i][j]='*';
                            }
                        }
                        mat[2][0]=mat[2][1]=mat[2][2]='.';
                        for(j=n-1;j>=n-(re+3)/2;--j) mat[0][j]=mat[1][j]='*';
                    }
                }
            }
        }
        L:
        printf("Case #%d:\n",++tc);
        if(im){
            printf("Impossible\n");
            continue;
        }
        if(flag){
            for(j=0;j<n;++j){
                for(i=0;i<m;++i){
                    printf("%c",mat[i][j]);
                }
                printf("\n");
            }
        }else{
           for(i=0;i<m;++i){
                for(j=0;j<n;++j){
                    printf("%c",mat[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
