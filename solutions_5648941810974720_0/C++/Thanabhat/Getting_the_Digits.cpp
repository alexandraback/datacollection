/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

int solve(int cc){
    char str[3000];
    scanf("%s",str);
    int cnt[26];
    int len = strlen(str);
    int sol[10];

    for(int i=0;i<26;i++){
        cnt[i]=0;
    }
    for(int i=0;i<10;i++){
        sol[i]=0;
    }

    for(int i=0;i<len;i++){
        cnt[str[i]-'A']++;
    }

    sol[0]+=cnt['Z'-'A'];
    cnt['Z'-'A']-=sol[0];
    cnt['E'-'A']-=sol[0];
    cnt['R'-'A']-=sol[0];
    cnt['O'-'A']-=sol[0];

    sol[2]+=cnt['W'-'A'];
    cnt['T'-'A']-=sol[2];
    cnt['W'-'A']-=sol[2];
    cnt['O'-'A']-=sol[2];

    sol[4]+=cnt['U'-'A'];
    cnt['F'-'A']-=sol[4];
    cnt['O'-'A']-=sol[4];
    cnt['U'-'A']-=sol[4];
    cnt['R'-'A']-=sol[4];

    sol[6]+=cnt['X'-'A'];
    cnt['S'-'A']-=sol[6];
    cnt['I'-'A']-=sol[6];
    cnt['X'-'A']-=sol[6];

    sol[8]+=cnt['G'-'A'];
    cnt['E'-'A']-=sol[8];
    cnt['I'-'A']-=sol[8];
    cnt['G'-'A']-=sol[8];
    cnt['H'-'A']-=sol[8];
    cnt['T'-'A']-=sol[8];

    sol[1]+=cnt['O'-'A'];
    cnt['O'-'A']-=sol[1];
    cnt['N'-'A']-=sol[1];
    cnt['E'-'A']-=sol[1];

    sol[3]+=cnt['R'-'A'];
    cnt['T'-'A']-=sol[3];
    cnt['H'-'A']-=sol[3];
    cnt['R'-'A']-=sol[3];
    cnt['E'-'A']-=sol[3];
    cnt['E'-'A']-=sol[3];

    sol[5]+=cnt['F'-'A'];
    cnt['F'-'A']-=sol[5];
    cnt['I'-'A']-=sol[5];
    cnt['V'-'A']-=sol[5];
    cnt['E'-'A']-=sol[5];

    sol[7]+=cnt['V'-'A'];

    sol[9]+=cnt['I'-'A'];

    printf("Case #%d: ",cc);
    for(int i=0;i<10;i++){
        for(int j=0;j<sol[i];j++){
            printf("%d",i);
        }
    }
    printf("\n");

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    scanf("%d,",&T);
    for(int i=1;i<=T;i++){
        solve(i);
    }

	return 0;
}
