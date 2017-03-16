/*
ID: jsnjhcb1
PROG: b
LANG: C++
*/
/*************************************************************************
	> File Name: b.cpp
	> Author: UCU
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  4/16 09:48:43 2016
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<string>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<iomanip>
#include<climits>
#include<fstream>
using namespace std;
int T;
int num[2550];
int main(){
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        printf("Case #%d: ",ca);
        int n;
        scanf("%d",&n);
        memset(num,0,sizeof num);
        int m = 0;
        for(int i=0;i<2*n-1;++i){
            for(int j=0;j<n;++j){
                int tmp;
                scanf("%d",&tmp);
                m = max(tmp,m);
                ++num[tmp];
            }
        }
        int cnt = 0;
        for(int i=1;i<=m;++i){
            if(num[i]&1){
                printf("%d",i);
                cnt++;
                if(cnt == n){
                    printf("\n");
                }
                else{
                    printf(" ");
                }
            }
        }
    }
    return 0;
}
