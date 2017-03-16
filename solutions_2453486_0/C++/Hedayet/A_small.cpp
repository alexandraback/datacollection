//Bismillahir Rahmanir Rahim
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

#define mp make_pair
#define rep(i,n) for(int i=0,_n=n;i<_n;i++)
#define reps(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define pi 2.0*acos(0.0)
#define MAX 2147483647
#define MIN -2147483647
#define torad(a) (a*pi)/180.0;
#define eps 0.000000001
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front

typedef long long ll;
typedef vector<int>VI;
typedef map<string,int> MSI;
typedef set<int>SI;
typedef pair<int,int>PAR;
typedef vector<PAR>VP;


string str[10];

int diaWin(char ch){
    int x = 0, y =0,c=0,d=0;
    while(x<4){
        if(str[x][y]==ch||str[x][y]=='T')c++;
        x++;
        y++;
    }

    x=0,y=3;
    while(x<4){
        if(str[x][y]==ch||str[x][y]=='T')d++;
        x++;
        y--;
    }
    return (c==4)|(d==4);
}

int Win(char ch){
    rep(i,4){
        int c = 0,d=0;
        rep(j,4){
            if(str[i][j]==ch||str[i][j]=='T')c++;
            if(str[j][i]==ch||str[j][i]=='T')d++;
        }
        if(c==4||d==4)return 1;
    }
    return 0;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int kas;
	cin>>kas;
	rep(cas,kas){
	    rep(i,4)cin>>str[i];
	    int over = 1;
	    rep(i,4){
	        rep(j,4)
	        if(str[i][j]=='.')over=0;
	    }
	    int ret = Win('X')|diaWin('X');
	    printf("Case #%d: ",cas+1);

	    if(ret){
	        printf("X won\n");
	        continue;
	    }
	    ret = Win('O')|diaWin('O');
	    if(ret){
	        printf("O won\n");
	        continue;
	    }
	    if(over){
	        printf("Draw\n");
	    }else
	    printf("Game has not completed\n");
	}

return 0;
}
