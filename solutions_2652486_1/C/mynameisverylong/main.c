#include <stdio.h>

long tab[4][4][4][130];

int initmark(long a,long b,long c,long *x){
    
    a+=2;
    b+=2;
    c+=2;
    
    x[1]=1;
    x[a]=1;
    x[b]=1;
    x[c]=1;
    x[a*b]=1;
    x[a*c]=1;
    x[b*c]=1;
    x[a*b*c]=1;
    
    return 0;
}

long minp(long po,long n,long *a){
    
    long i,mi;
    
    for (i=0,mi=0;i<n;i++){
        
        if (a[i]<a[mi]){
            
            mi=i;
        }
    }
    
    a[mi]*=po;
    return 0;
}

long maxp(long long x,long a){
    
    long ans;
    
    ans=0;
    
    while ((x%a)==0){
        
        x=x/a;
        ans++;
    }
    
    return ans;
}

int main(){
    
    long t,r,m,n,k,i,j,x,y,z,ii,zz,an[20],mark,mark2,p;
    long n2,n3,n5,n7,nt;
    long long tmp;
    
    freopen("C-small-2-attempt2.in.txt", "r",stdin);
    freopen("C-small-2-attempt2.out.txt", "w",stdout);

    
    scanf("%ld",&t);
    
    scanf("%ld%ld%ld%ld",&r,&n,&m,&k);
    
    
    if (n==3){
        for (i=0;i<4;i++){
            
            for (j=0;j<4;j++){
                
                for (x=0;x<4;x++){
                    
                    for (y=0;y<130;y++){
                        
                        tab[i][j][x][y]=0;
                    }
                    
                    initmark(i,j,x,tab[i][j][x]);
                }
            }
        }
        
        printf("Case #1:\n");
        for (i=0;i<r;i++){
            
            for (j=0,p=1;j<k;j++){
                
                scanf("%ld",an+j);
                
                p*=an[j];
            }
            
            mark=1;
            for (x=3;x>=0&&mark;x--){
                
                for (y=0;y<4&&mark;y++){
                    
                    for (z=3;z>=0&&mark;z--){
                        
                        if (p!=1&&((p%(x+2)!=0)||(p%(y+2)!=0)||(p%(z+2)!=0))){
                            
                            continue;
                        }
                        
                        for (zz=0,mark2=1;zz<k&&mark;zz++){
                            
                            if (tab[x][y][z][an[zz]]==0){
                                
                                mark2=0;
                                break;
                            }
                        }
                        
                        if (mark2==1){
                            
                            printf("%ld%ld%ld\n",x+2,y+2,z+2);
                            mark=0;
                        }
                    }
                }
            }
        }
    }
    if (n==12){
        
        printf("Case #1:\n");
        
        for (ii=0;ii<r;ii++){
            
            n2=0;
            n3=0;
            n5=0;
            n7=0;
            for (j=0;j<k;j++){
                
                scanf("%lld",&tmp);
                
                nt=maxp(tmp,2);
                if (nt>n2){
                    
                    n2=nt;
                }
                
                
                nt=maxp(tmp,3);
                if (nt>n3){
                    
                    n3=nt;
                }
                
                nt=maxp(tmp,5);
                if (nt>n5){
                    
                    n5=nt;
                }
                
                nt=maxp(tmp,7);
                if (nt>n7){
                    
                    n7=nt;
                }
                
            }
            for (i=0;i<n;i++){
                
                an[i]=1;
            }
            
            for (i=0;i<n7;i++){
                
                minp(7,12,an);
            }
            for (i=0;i<n5;i++){
                
                minp(5,12,an);
            }
            for (i=0;i<n3;i++){
                
                minp(3,12,an);
            }
            for (i=0;i<n2;i++){
                
                minp(2,12,an);
            }
            
            for (i=0;i<n;i++){
                
                printf("%ld",an[i]);
            }
            
            printf("\n");
        }

    }
    
    return 0;
}

