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
#define BSIZE 1010
#define INF 1<<28

using namespace::std;

typedef long long lint;

int n,best;
vector<int> mote;

int f2(int x, int w){
    if(x==n) return 0; 
    
    if(w>mote[x]) return f2(x+1,w+mote[x]);

    int acc = 0, w2 = w;
    while(w2 <= mote[x]) w2 += w2-1, acc++;
    return  min( n-x, acc+f2(x+1,w2+mote[x]) );
}

int main(){
    int tot_cases,ma,x;
    scanf("%d",&tot_cases);
    for(int case_num=1;case_num<=tot_cases;case_num++){
            
        scanf("%d %d",&ma,&n);
        mote.clear();
        FOR(i,n) scanf("%d",&x),mote.push_back(x);
        sort(mote.begin(),mote.end());
       
        best = INF;
        
        if(ma == 1)
            printf("Case #%d: %d\n",case_num,n);
        else
            printf("Case #%d: %d\n",case_num,f(0,ma,0));
    }
    return 0;
}
