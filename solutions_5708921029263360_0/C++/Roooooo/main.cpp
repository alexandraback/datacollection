#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
#include <cstring>

#define MAX
#define INF 99999
#define MOD
#define MP make_pair
#define AA first
#define BB second
#define IS(X) cout << #X << " = " << X << endl;
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef queue<int> QI;
typedef priority_queue<int> PQI;
int j,p,s,k;
int cap[55][55]; //保存每个边的容量
int pathPreNode[55]; //保存增广路径上，每个节点的前一个节点
struct A{
    int id[5];
};
vector<A> v;
int BFS(int start, int end)
{
    memset(pathPreNode,-1,sizeof(pathPreNode));
    pathPreNode[start]=start;

    int curNode,i,preNode;
    int pathMinFlow=INF;
    queue<int> q;
    q.push(start);
    int cnt = 0;
    A a;
    while(!q.empty()) {
        curNode=q.front();
        a.id[cnt++] = curNode;
        q.pop();
        if(curNode==end) {
            for(curNode=end;curNode!=start;curNode=preNode) {
                preNode=pathPreNode[curNode];
                pathMinFlow= pathMinFlow<=cap[preNode][curNode]? pathMinFlow: cap[preNode][curNode];
            }
            cnt = 0;
            return pathMinFlow;
        }
        for(i=0;i<=1+s+j+p;i++) {
            if(pathPreNode[i]==-1 && cap[curNode][i]>0)
            {
                q.push(i);
                pathPreNode[i]=curNode;
            }
        }
    }
    return -1;
}

int EK(int start, int end)
{
    int oneFlow,maxFlow=0,curNode,preNode;
    while(true) {
        oneFlow=BFS(start,end);
        if(oneFlow==-1) {
            break;
        }
        else
        {
            maxFlow+=oneFlow;
            for(curNode=end;curNode!=start;curNode=preNode)
            {
                preNode=pathPreNode[curNode];
                cap[preNode][curNode]-=oneFlow;
                cap[curNode][preNode]+=oneFlow;
            }
        }
    }
    return maxFlow;
}

void work() {
    for(int x = 1;x <= j;x++) for(int y = 1;y <= p;y++) for(int z = 1;z <= s;z++) {
        printf("%d %d %d\n",x,y,z);
    }
}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("OUT.TXT","w",stdout);
    int t;cin >> t;
    int cc = 0;
    while(t--) {
        cin >> j >> p >> s >> k;
        if(k >= s) {
            printf("Case #%d: %d\n",++cc,j*p*s);
            work();
        } else {
            v.clear();
            memset(cap,0,sizeof cap);
            for(int x = 1;x <= j;x++) cap[0][x] = INF;
            for(int x = 1;x <= j;x++) for(int y = 1+j;y <= p+j;y++) {
                cap[x][y] = k;
            }
            for(int y = 1+j;y <= p+j;y++) for(int z = 1+j+p;z <= s+j+p;z++) {
                cap[y][z] = k;
            }
            for(int z = 1+j+p;z <= s+j+p;z++) cap[z][s+j+p+1] = INF;
            int tot = EK(0,s+j+p+1);
            printf("Case #%d: %d\n",++cc,tot);
            while(tot) {
                for(int x = 1;x <= j;x++) for(int y = 1+j;y <= p+j;y++) for(int z = 1+p+j;z <= s+j+p;z++) {
                    if(cap[y][x] && cap[z][y]) {
                        printf("%d %d %d\n",x,y,z);
                        cap[y][x]--;cap[z][y]--;tot--;
                    }
                }
            }
        }
    }
    return 0;
}
