#include<cstdio>
#include<cstring>
using namespace std;
char map[4][5];
bool iso(char c){
    return c=='O'||c=='T';
}
bool isx(char c){
    return c=='X'||c=='T';
}
int main(){
    freopen("QA.in","r",stdin);
    freopen("QA.out","w",stdout);
    int numcases;
    scanf("%d",&numcases);
    for(int ccase=0;ccase<numcases;ccase++){
        for(int i=0;i<4;i++){
            scanf("%s",map[i]);
        }
        bool xwon=false,owon=false;
        for(int i=0;i<4;i++){
            bool foundmatch=true;
            for(int i2=0;i2<4;i2++){
                if(!iso(map[i][i2])) foundmatch=false;
            }
            if(foundmatch) owon=true;
        }
        for(int i=0;i<4;i++){
            bool foundmatch=true;
            for(int i2=0;i2<4;i2++){
                if(!iso(map[i2][i])) foundmatch=false;
            }
            if(foundmatch) owon=true;
        }
        {
            bool foundmatch=true;
            for(int i=0;i<4;i++){
                if(!iso(map[i][i])) foundmatch=false;
            }
            if(foundmatch) owon=true;
        }
        {
            bool foundmatch=true;
            for(int i=0;i<4;i++){
                if(!iso(map[i][3-i])) foundmatch=false;
            }
            if(foundmatch) owon=true;
        }
        for(int i=0;i<4;i++){
            bool foundmatch=true;
            for(int i2=0;i2<4;i2++){
                if(!isx(map[i][i2])) foundmatch=false;
            }
            if(foundmatch) xwon=true;
        }
        for(int i=0;i<4;i++){
            bool foundmatch=true;
            for(int i2=0;i2<4;i2++){
                if(!isx(map[i2][i])) foundmatch=false;
            }
            if(foundmatch) xwon=true;
        }
        {
            bool foundmatch=true;
            for(int i=0;i<4;i++){
                if(!isx(map[i][i])) foundmatch=false;
            }
            if(foundmatch) xwon=true;
        }
        {
            bool foundmatch=true;
            for(int i=0;i<4;i++){
                if(!isx(map[i][3-i])) foundmatch=false;
            }
            if(foundmatch) xwon=true;
        }
        printf("Case #%d: ",ccase+1);
        if(xwon&&owon){ printf("Something's wrong!");return 0;}
        else if(xwon) printf("X won");
        else if(owon) printf("O won");
        else{
            bool completed=true;
            for(int i=0;i<4;i++){
                for(int i2=0;i2<4;i2++){
                    if(map[i][i2]=='.') completed=false;
                }
            }
            if(completed) printf("Draw");
            else printf("Game has not completed");
        }
        printf("\n");
    }
    return 0;
}
