#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<cassert>
#include<iomanip>
using namespace std;

#define LL long long
#define PI pair<int,int>
#define F first
#define S second
#define MP make_pair
#define VI vector<int>
#define VPI vector<PI>
#define PB push_back

char a[5][5];
int r[2][4],c[2][4],d[2][2];

int main()
{
    freopen("input2.txt","r", stdin);
    freopen("output2.txt", "w", stdout);
    int cases;
    scanf("%d", &cases);
    for(int casenum=1;casenum<=cases;casenum++){
        for(int i=0;i<4;i++) scanf("%s", &a[i]);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++) d[i][j] = 0;
            for(int j=0;j<4;j++) r[i][j] = c[i][j] = 0;
        }
        bool over = true;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(a[i][j] == 'X'){
                    r[0][i]++;
                    c[0][j]++;
                    if(i == j) d[0][0]++;
                    if(i+j == 3) d[0][1]++;
                }
                else if(a[i][j] == 'O'){
                    r[1][i]++;
                    c[1][j]++;
                    if(i == j) d[1][0]++;
                    if(i+j == 3) d[1][1]++;
                }
                else if(a[i][j] == 'T'){
                    r[0][i]++; c[0][j]++;
                    r[1][i]++; c[1][j]++;
                    if(i == j) d[0][0]++,d[1][0]++;
                    if(i+j == 3) d[0][1]++,d[1][1]++;
                }
                else{
                    over = false;
                }
            }
        }
        bool w[2]={0,0};
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++) w[i] = w[i] | (d[i][j] == 4);
            for(int j=0;j<4;j++) w[i] = w[i] | (r[i][j] == 4);
            for(int j=0;j<4;j++) w[i] = w[i] | (c[i][j] == 4);
        }
        if(w[0]) printf("Case #%d: X won\n", casenum);
        else if(w[1]) printf("Case #%d: O won\n", casenum);
        else if(over) printf("Case #%d: Draw\n", casenum);
        else printf("Case #%d: Game has not completed\n", casenum);
    }
    return 0;
}
