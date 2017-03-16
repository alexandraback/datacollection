#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#define LL long long
#define LD long double

#define VI vector<int>

#define sd(x) scanf("%d",&x)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PI pair< int , int >
#define PP pair< PI , PI >

int main(){
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    int t,i,j,k,l,x,o,p,c=1,e;
    string s[4];
    cin>>t;
    while(t--){
        printf("Case #%d: ",c);
        c++;
        e=0;
        for(i=0;i<4;i++){
            cin>>s[i];
        }
        for(i=0;i<4;i++){
            x=0;
            o=0;
            p=0;
            for(j=0;j<4;j++){
                if(s[i][j]=='T'){
                    p++;
                }
                else if(s[i][j]=='X'){
                    x++;
                }
                else if(s[i][j]=='O'){
                    o++;
                }
                else{
                    e++;
                }
            }
            if((x==3&&p==1)||x==4){
                printf("X won\n");
                break;
            }
            if((o==3&&p==1)||o==4){
                printf("O won\n");
                break;
            }
            x=0;
            o=0;
            p=0;
            for(j=0;j<4;j++){
                if(s[j][i]=='T'){
                    p++;
                }
                else if(s[j][i]=='X'){
                    x++;
                }
                else if(s[j][i]=='O'){
                    o++;
                }
            }
            if((x==3&&p==1)||x==4){
                printf("X won\n");
                break;
            }
            if((o==3&&p==1)||o==4){
                printf("O won\n");
                break;
            }
        }
        if(i<4){
            continue;
        }
        x=0;
        o=0;
        p=0;
        for(i=0;i<4;i++){
            if(s[i][i]=='T'){
                p++;
            }
            else if(s[i][i]=='X'){
                x++;
            }
            else if(s[i][i]=='O'){
                o++;
            }
        }
        if((x==3&&p==1)||x==4){
            printf("X won\n");
            continue;
        }
        if((o==3&&p==1)||o==4){
            printf("O won\n");
            continue;
        }
        x=0;
        o=0;
        p=0;
        for(i=0;i<4;i++){
            if(s[i][3-i]=='T'){
                p++;
            }
            else if(s[i][3-i]=='X'){
                x++;
            }
            else if(s[i][3-i]=='O'){
                o++;
            }
        }
        if((x==3&&p==1)||x==4){
            printf("X won\n");
            continue;
        }
        if((o==3&&p==1)||o==4){
            printf("O won\n");
            continue;
        }
        if(e){
            printf("Game has not completed\n");
        }
        else{
            printf("Draw\n");
        }
    }
    return 0;
}
