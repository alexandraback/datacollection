#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<set>
#define clr(x,y) memset(x,y,sizeof(x))
#define ll unsigned long long
using namespace std;

int r,c,f;
int s[100][100];

int get(int i,int j){
    if(i>=r||i<0||j>=c||j<0) return 0;
    if(s[i][j]==-1) return 1;
    else return 0;
}
bool has0(int x,int y){
    for(int i=max(0,x-1);i<=min(r-1,x+1);i++){
        for(int j=max(0,y-1);j<=min(c-1,y+1);j++){
            if(s[i][j]==0)
                return true;
        }
    }
    return false;
}
int main(){
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&r,&c,&f);
        int k=f;
        k = r*c-k;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                s[i][j] = -1;
        bool flag = true;
        if(r==1){
            for(int i=0;i<k;i++) s[0][i] = -2;
        }else if(c==1){
            for(int i=0;i<k;i++) s[i][0] = -2;
        }else if(r==2){
            for(int i=0;i<k/2;i++) s[0][i] = -2;
            for(int i=0;i<(k+1)/2;i++) s[1][i] = -2;
        }else if(c==2){
            for(int i=0;i<k/2;i++) s[i][0] = -2;
            for(int i=0;i<(k+1)/2;i++) s[i][1] = -2;
        }else{
            if(k%2==0){
                int i=0;
                while(k && i<r){
                    s[i][0]=s[i][1]=-2;
                    k-=2;
                    i++;
                }
                i=2;
                while(k && i<c){
                    s[0][i]=s[1][i]=-2;
                    k-=2;
                    i++;
                }
                for(int i=2;i<r;i++)
                    for(int j=2;j<c;j++){
                        if(k!=0){
                            s[i][j]=-2;
                            k--;
                        }
                    }
            }else{
                if(k<9) flag=false;
                else{
                    for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)
                            s[i][j]=-2;
                    k-=9;
                    int i=3;
                    while(k && i<r){
                        s[i][0]=s[i][1]=-2;
                        k-=2;
                        i++;
                    }
                    i=3;
                    while(k && i<c){
                        s[0][i]=s[1][i]=-2;
                        k-=2;
                        i++;
                    }
                }
                for(int i=2;i<r;i++)
                    for(int j=2;j<c;j++){
                        if(i==2&&j==2) continue;
                        if(k!=0){
                            s[i][j]=-2;
                            k--;
                        }
                    }

            }
        }
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(s[i][j]==-2){
                    s[i][j] = get(i-1,j-1)+get(i,j-1)+get(i+1,j-1)+get(i-1,j)+
                    get(i+1,j)+get(i-1,j+1)+get(i,j+1)+get(i+1,j+1);
                }
            }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(s[i][j]!=-1){
                    if(!has0(i,j))
                        flag=false;
                }
            }
        }
        printf("Case #%d:\n",++cas);
        if(flag || f==r*c-1){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(i==0&&j==0) printf("c");
                    else if(s[i][j]!=-1) printf(".");
                    else printf("*");
                }
                printf("\n");
            }
        }else{
            puts("Impossible");
        }
    }
    return 0;
}
