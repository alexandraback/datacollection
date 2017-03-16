#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<string>
#include<bitset>
#include<set>
#include<algorithm>

#define FOR(a,b) for(int a=0;a<b;a++)
#define FORR(a,b) for(int a=b-1;a>=0;a--)
#define FOR2(a,b,c) for(int a=b;a<c;a++)
#define FORR2(a,b,c) for(int a=c-1;a>=b;a--)
#define EACH(i,v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

#define VI vector<int>
#define VVI vector< vector<int> >
#define PII pair<int,int>
#define VS vector<string>

#define MAXN  1000
#define BSIZE 1000010

using namespace::std;

typedef long long lint;

char buffer[BSIZE];
int n;

inline lint count(){
    lint cnt = 0;
    int i=0,j=0,c=0,l = strlen(buffer);
    while(j<l || c==n){
        while(j<l && c<n){
            if(buffer[j]=='a'||buffer[j]=='e'||buffer[j]=='i'||buffer[j]=='o'||buffer[j]=='u')
                c = 0;
            else c++;
            j++;
        }
        if(c==n) cnt += l-j+1;
        i++;
        if(c==n && j-n<i) c--;
    }
    return cnt;
}

int main(){
    int tot_cases;
    scanf("%d",&tot_cases);
    for(int case_num=1;case_num<=tot_cases;case_num++){

        scanf("%s %d",buffer,&n);
        printf("Case #%d: %lld\n",case_num,count());
    }
    return 0;
}
