#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<utility>
#include<numeric>
#include<iterator>
using namespace std;

#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define memo(a,b) memset(a,b,sizeof(a))

#define all(a) a.begin(),a.end()
#define pb push_back
#define mpp(a,b,c) make_pair(make_pair(a,b),c)

#define inf (1<<29)
#define i64 long long
#define pi (2.0*acos(0.0))
#define eps (1e-9)

typedef pair< int , int >  pii;

bool isWin(string maze[4],char player){
    int i,j;
    for(i = 0;i<4;i++){
        for(j = 0;j<4;j++)
            if(maze[i][j]!=player && maze[i][j]!='T')
                break;
        if(j == 4) return true;
        for(j = 0;j<4;j++)
            if(maze[j][i]!=player && maze[j][i]!='T')
                break;
        if(j == 4) return true;
    }
    for(i = 0;i<4;i++)
        if(maze[i][i]!=player && maze[i][i]!='T')
                break;
    if(i == 4) return true;
    for(i = 0;i<4;i++)
        if(maze[i][3 - i]!=player && maze[i][3 - i]!='T')
                break;
    if(i == 4) return true;
    return false;
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.ans","w",stdout);
    int t,cs = 1,i,j;
    string maze[4];
    scanf("%d",&t);
    while(t--){
        for(i = 0;i<4;i++)
            cin>>maze[i];
        printf("Case #%d: ",cs++);
        if(isWin(maze,'X'))
            printf("X won\n");
        else if(isWin(maze,'O'))
            printf("O won\n");
        else{
            for(i = 0;i<4;i++){
                for(j = 0;j<4;j++)
                    if(maze[i][j]=='.')
                        break;
                if(j<4) break;
            }
            if(i < 4)
                printf("Game has not completed\n");
            else printf("Draw\n");
        }
    }
	return 0;
}
