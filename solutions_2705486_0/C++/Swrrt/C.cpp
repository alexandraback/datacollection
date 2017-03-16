#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#define oo 1000000000
using namespace std;
int W=521196;
string A[522000],ST;
char ss[105];
set <string> Oh[12];
int F[4005][6];
inline void Up(int &a,int b){
    a=min(a,b);
}
inline void Do(int L,int R,int X,int Y){
    string t=ST.substr(L-1,R-L+1);
    if(Oh[t.size()].count(t)){
        Up(F[R][max(X-(R-L+1),0)],Y);
        return ;
    }
    int i,j;
    for(i=X;i<(int)t.size();i++){
        char t1=t[i],c1;
        for(c1='a';c1<='z';c1++){
            t[i]=c1;
            if(Oh[t.size()].count(t)){
                Up(F[R][max(4-(int(t.size())-i-1),0)],Y+1);
                return ;
            }
            for(j=i+5;j<(int)t.size();j++){
                char t2=t[j],c2;
                for(c2='a';c2<='z';c2++){
                    t[j]=c2;
                    if(Oh[(int)t.size()].count(t))
                        Up(F[R][max(4-(int(t.size())-j-1),0)],Y+2);
                }
                t[j]=t2;
            }
        }
        t[i]=t1;
    }
}
int main(){
    int n,m,i,j,k,l,T,tt=0;
    FILE *fp;
    fp=fopen("garbled_email_dictionary.txt","r");
    for(i=1;i<=W;i++){
        fscanf(fp,"%s",ss);
        A[i]=ss;
        Oh[A[i].size()].insert(A[i]);
    }
    fclose(fp);
    freopen("C.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        tt++;
        scanf("%s",ss);
           ST=ss;
        for(i=0;i<=4001;i++)
            for(j=0;j<=5;j++)F[i][j]=oo;
        F[0][0]=0;
        for(i=0;i<(int)ST.size();i++)
            for(j=0;j<5;j++)
                if(F[i][j]!=oo){
                    for(k=1;k<=10&&i+k<=(int)ST.size();k++){
                        Do(i+1,i+k,j,F[i][j]);
                    }
                }
        int ans=oo;
        for(i=0;i<5;i++)ans=min(ans,F[ST.size()][i]);
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
