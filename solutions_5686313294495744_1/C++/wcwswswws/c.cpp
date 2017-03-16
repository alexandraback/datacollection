#include <string.h>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 20005
#define MAXE 600000
#define inf  0x3f3f3f3f
struct Edge{  int v,c,x; }E[MAXE]; //指向的节点, 剩余可增广的流量
int l[MAXN],e;                     //必须保证e的初始值是偶数
void init(){ e=0; memset(l,-1,sizeof(l));  }
inline void insert(int u,int v,int f,int invf){ //u->v=f   v->u=invf
	E[e].v=v; E[e].c=f;   E[e].x=l[u]; l[u]=e++;
	E[e].v=u; E[e].c=invf;E[e].x=l[v]; l[v]=e++;
}
struct Netflow{
	int src,sink; //需要初始化
	//以上
	int L[MAXN],Q[MAXN]; //L=level  Q=queue
	int _bfs(){ //广搜,并标记level(只取流量大于0的边)
		int s=0,t=0,u;
		memset(L,0xff,sizeof(L));
		L[src]=0; Q[t++]=src;
		while (s<t){
			u=Q[s++];
			for (int p=l[u];p>=0;p=E[p].x)
				if (E[p].c && L[E[p].v]==-1)
					L[(Q[t++]=E[p].v)]=L[u]+1;
		}
		return L[sink]!=-1;
	}
	int _find(int u,int in){ //in:能流入u节点的最大流量. 返回u节点能流出的最大流量
		if (u==sink) return in;
		int t,w=0; //w表示已经从u流出的总流量
		for (int p=l[u];p>=0 && w<in;p=E[p].x){
			if (E[p].c>0 && L[E[p].v]==L[u]+1){
				if (t=_find(E[p].v,min(E[p].c,in-w))){
					E[  p].c-=t;
					E[p^1].c+=t; //这里表示必须
					w+=t;     //多路增广优势巨大
				}
			}
		}
		if( w<in )L[u]=-1;//关键的一句话
		return w;
	}
	int dinic(){
		int t,res=0;
		while (_bfs())while (t=_find(src,inf))res+=t;
		return res;
	}
}flow; //********模板结束***********
//init(); insert(...); flow.src=.. ; flow.dinic();

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("C-large.in");
    fout.open("C-large.out");
    int test;
    fin >> test;
    for (int t = 1; t <= test; t++) {
        map<string, int> a, b;
        int a_num = 0, b_num = 0;
        vector< pair<int, int> > vec;
        int n;
        fin >> n;
        for (int i = 0; i < n; i++) {
            string s, t;
            int x, y;
            fin >> s >> t;
            if (a.find(s) == a.end()) {
                a[s] = a_num++;
            }
            x = a[s];
            if (b.find(t) == b.end()) {
                b[t] = b_num++;
            }
            y = b[t];
            vec.push_back(pair<int, int>(x, y));
        }
        init();
        for (int i = 0; i < a_num; i++) {
            insert(1, 2 + i, 1, 0);
        }
        for (int i = 0; i < b_num; i++) {
            insert(2 + a_num + i, 2 + a_num + b_num, 1, 0);
        }
        for (int i = 0; i < n; i++) {
            int x = vec[i].first, y = vec[i].second;
            insert(2 + x, 2 + a_num + y, 1, 0);
        }
        flow.src = 1;
        flow.sink = 2 + a_num + b_num;
        int ans = n - flow.dinic();
        for (int i = l[1]; i >= 0; i = E[i].x) {
            if ((E[i].v <= 1 + a_num) && (E[i].c == 1)) { ans--; }
        }
        for (int i = 0; i < b_num; i++)
            for (int j = l[2 + a_num + i]; j >= 0; j = E[j].x) {
                if ((E[j].v == 2 + a_num + b_num) && (E[j].c == 1)) { ans--; }
            }
        fout << "Case #" << t << ": " << ans << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
