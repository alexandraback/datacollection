#include <iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
using namespace std;
int T , Tn=0 ;
int n,m;
char grid[100][100];
bool ROW(int B){
    bool ret=0;
    bool is=0;
  //  cout<<B<<endl;
    int lim,res,mod;
    for(lim=n;lim>1;lim--){
        res=B/lim;
        if(res<=1) continue;
        mod=B%lim;
        if(res==m && mod) break;
        if(res>m) break;
        if(mod!=1){
            ret=1;
            break;
        }
        else{
            if(lim>3 && res>2){
                is=ret=1;
                break;
            }
        }
    }
    if(!ret) return 0;
    //cout<<lim<<endl;
    // cout<<"ROW ";
    int col , row;
    for( col=m;col>0 && B>0;col--){
        for( row=n;row>n-lim;row--){
            B--; grid[row][col]='.';
            if(!B) break;
        }
        if(!B) break;
    }
    if(is){
       // cout<<row<<' '<<col<<endl;
        grid[1][col+1]='*';
        grid[row-1][col]='.';
    }
    return true;
}
bool COL(int B){
    bool ret=0,is=0;
    int lim,res,mod;
    for(lim=m;lim>1;lim--){
        res=B/lim;
        if(res<=1) continue;
        mod=B%lim;
        if(res>n) break;
        if(res==n && mod) break;
        if(mod!=1){
            ret=1;
            break;
        }
        else{
            if(lim>3 && res>2){
                is=ret=1;
                break;
            }
        }
    }
    if(!ret) return 0;
    //cout<<lim<<endl;
    // cout<"COL ";
    int row , col;
    for( row=n ;row>0 && B ; row--){
        for( col=m;col>m-lim;col--){
            B--; grid[row][col]='.';
            //cout<<row<<' '<<col<<endl;
            if(B==0) break;
        }
        if(B==0) break;
    }
    //cout<<"is"<<endl;
    if(is){
        grid[row+1][1]='*';
        grid[row][col-1]='.';
    }
    return true;
}
int B;
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>T;
    while(T--){
        Tn++;
        cin>>n>>m>>B;
        printf("Case #%d:\n",Tn);
        //cout<<n<<' '<<m<<' '<<B<<endl;
        if(n*m==B+1){
            for(int j=1;j<n;j++){
                for(int i=1;i<=m;i++)
                    putchar('*');
                puts("");
            }
            for(int i=1;i<m;i++) putchar('*');
            puts("c");
            continue;
        }
        if(n==1){

            for(int j=1;j<m;j++)
                if(B){
                    B--;
                    putchar('*');
                }
                else putchar('.');
            puts("c");
            continue;
        }
        if(m==1){
            for(int j=1;j<n;j++)
                if(B){
                    B--;
                    puts("*");
                }
                else puts(".");
            puts("c");
            continue;
        }
        if(n==2){
            if( B%2==1  || B>n*m-4){
                puts("Impossible");
                continue;
            }
            for(int j=1;j<=B/2;j++) putchar('*');
            for(int j=B/2+1;j<=m;j++) putchar('.');
            puts("");
            for(int j=1;j<=B/2;j++) putchar('*');
            for(int j=B/2+1;j<m;j++) putchar('.');
            puts("c");
            continue;
        }
        if(m==2){
            if(B%2==1 || B>n*m-4){
                puts("Impossible");
                continue;
            }
            for(int j=1;j<n;j++){
                if(B){
                    puts("**");
                    B-=2;
                }
                else puts("..");
            }
            puts(".c");
            continue;
        }
        for(int j=1;j<=n;j++) for(int i=1;i<=m;i++) grid[j][i]='*';
        int ooo=n*m-B;
        B=ooo;
        //cout<<B<<endl;
        if(B<4){
            puts("Impossible");
            continue;
        }
        //cout<<"is"<<endl;
        bool sol=0;
        sol|=ROW(B);
        if(!sol) {
            for(int j=1;j<=n;j++) for(int i=1;i<=m;i++) grid[j][i]='*';
            sol|=COL(B);
        }
        if(!sol){
            puts("Impossible");
            continue;
        }
        grid[n][m]='c';
        for(int j=1;j<=n;j++){
            for(int i=1;i<=m;i++)
                putchar(grid[j][i]);
            puts("");
        }
    }
}
