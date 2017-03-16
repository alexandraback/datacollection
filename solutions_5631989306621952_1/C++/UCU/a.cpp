/*
ID: jsnjhcb1
PROG: a
LANG: C++
*/
/*************************************************************************
	> File Name: a.cpp
	> Author: UCU
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  4/16 09:03:46 2016
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
int n;
char s[1010];
char ans[2010];
int be,ed;
bool judge(){
    for(int i=be-1;i<=ed;++i){
        if(ans[i] > ans[i+1]){
            return true;
        }
        else if(ans[i] < ans[i+1]){
            return false;
        }
    }
    return false;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        printf("Case #%d: ",ca);
        scanf("%s",s);
        int len = (int)strlen(s);
        memset(ans,'\0',sizeof ans);
        ans[1005] = s[0];
        be = 1005;
        ed = 1005;
        for(int i=1;i<len;++i){
            ans[be-1] = ans[ed+1] = s[i];
            if(judge()){
                be--;
            }
            else{
                ed++;
            }
            //printf("%d %d\n",be,ed);
        }
        for(int i=be;i<=ed;++i){
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
