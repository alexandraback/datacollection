//Template of CyberKasumi (Jennifer Santoso a.k.a. Liang Qiuxia)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
using namespace std;

#define LL long long
#define inf 2123123123
#define MOD 1000000007


int a;
int b,c;

int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
char dire[4]={'N','E','S','W'};
int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&a);
    for (int i=1;i<=a;i++){
        scanf("%d %d",&b,&c);
        printf("Case #%d: ",i);
        if (b>0){
            for (int j=1;j<=b;j++){
                printf("WE");
            }
        }
        else if (b<0){
            for (int j=1;j<=-b;j++){
                printf("EW");
            }
        }
        else{
            printf("WEEW");
        }
        if (c>0){
            for (int j=1;j<=c;j++){
                printf("SN");
            }
        }
        else if (c<0){
            for (int j=1;j<=-c;j++){
                printf("NS");
            }
        }
        else{
            printf("NSSN");
        }
        printf("\n");
    }
    return 0;
}
