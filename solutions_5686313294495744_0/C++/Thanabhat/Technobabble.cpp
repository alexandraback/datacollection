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

set<int> s[1024];

bool check(int i, int j){
    set<int> ss;
    int last=ss.size();
    for(set<int>::iterator it=s[i].begin();it!=s[i].end();it++){
        ss.insert(*it);
    }
    while(last!=ss.size()){
        last=ss.size();
        for(set<int>::iterator it=s[j].begin();it!=s[j].end();it++){
            for(set<int>::iterator it2=s[*it].begin();it2!=s[*it].end();it2++){
                ss.insert(*it2);
            }
        }
    }
    return ss.find(j)!=ss.end();
}

int solve(int cc){
    int N;
    char A[1024][22],B[1024][22];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s %s",A[i],B[i]);
        s[i].clear();
    }
    int sol=0;
    for(int i=0;i<N;i++){
        int a=-1,b=-1;
        for(int j=0;j<N;j++){
            if(j==i||check(j,i)){
                continue;
            }
            if(strcmp(A[i],A[j])==0){
                a=j;
            }
            if(strcmp(B[i],B[j])==0){
                b=j;
            }
        }
        if(a!=-1&&b!=-1){
            sol++;
            s[a].insert(i);
            s[b].insert(i);
        }
    }
    printf("Case #%d: %d\n",cc,sol);
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
