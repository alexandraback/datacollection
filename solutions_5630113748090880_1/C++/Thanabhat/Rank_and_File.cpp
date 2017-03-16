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
    int N;
    int cnt[3000],in;
    for(int i=0;i<=2500;i++){
        cnt[i]=0;
    }
    scanf("%d",&N);
    for(int i=0;i<2*N-1;i++){
        for(int i=0;i<N;i++){
            scanf("%d",&in);
            cnt[in]++;
        }
    }
    vector<int> sol;
    for(int i=1;i<=2500;i++){
        if(cnt[i]%2==1){
            sol.push_back(i);
        }
    }
    sort(sol.begin(),sol.end());

    printf("Case #%d: ",cc);
    for(int i=0;i<N;i++){
        printf("%d ", sol[i]);
    }
    printf("\n");

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        solve(i);
    }

	return 0;
}
