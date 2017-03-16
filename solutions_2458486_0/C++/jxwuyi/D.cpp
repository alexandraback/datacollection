#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cassert>
#include<complex>
using namespace std;

const int MaxN = 300;

int N, K;

vector<int> key[MaxN], cur;
int lock[MaxN];
int G[MaxN][MaxN];
vector<int> room[MaxN];

void NormalizeKey(vector<int>&key, vector<int>&ind)
{
	vector<int> tmp;
	for(int i=0;i<key.size();++i)
	{
		int id = -1;
		for(int j=0;j<ind.size();++j)
			if(ind[j]==key[i]) id = j;
		if(id>-1) tmp.push_back(id);
	}
	key=tmp;
}

void Init()
{
	int k;
	scanf("%d %d", &k, &N);
	int x;
	cur.clear();
	for(int i=0;i<k;++i)
	{
		scanf("%d", &x);
		cur.push_back(x);
	}
	
	sort(cur.begin(), cur.end());
	
	vector<int> keyind;
	
	for(int i=1;i<=N;++i)
	{
		key[i].clear();
		scanf("%d %d", lock+i, &k);
		keyind.push_back(lock[i]);
		for(int j=0;j<k;++j)
		{
			scanf("%d", &x);
			key[i].push_back(x);
		}
		sort(key[i].begin(), key[i].end());
	}
	
	sort(keyind.begin(), keyind.end());
	keyind.erase(unique(keyind.begin(), keyind.end()), keyind.end());
	K = keyind.size();
	for(int i=0;i<K;++i) room[i].clear();
	
	NormalizeKey(cur, keyind);
	for(int i=1;i<=N;++i) {
		NormalizeKey(key[i], keyind);
		lock[i] = lower_bound(keyind.begin(), keyind.end(), lock[i]) - keyind.begin();
		room[lock[i]].push_back(i);
	}
	/*
	cerr << "cur : ";for(int i=0;i<cur.size();++i) cerr << cur[i]<<", "; cerr << endl;
	for(int i=1;i<=N;++i)
	{
	cerr << "room#"<<i<<"  lock = "<<lock[i]<<endl;
	cerr << " > key : ";
	for(int j=0;j<key[i].size();++j) cerr << key[i][j]<<", "; cerr << endl;
	}
	*/
}

bool mark[MaxN], vst[MaxN];
vector<int> active;
int Q[MaxN], fron, tail;
int Bfs(int st, vector<int>& cur)
{
	fill(vst, vst + N + 1, false);
	fron=tail = 0;
	Q[tail ++] = st;
	while(fron < tail)
	{
		int u = Q[fron++], t;
		
	//	cerr << "---->> BFS to "<<u<<endl;
		
		vector<int> &lis = (st == u ? cur : key[u]);
		for(int i=0;i<lis.size();++i)
			if(!i || lis[i] != lis[i-1])
			{
				int k = lis[i];
				for(int j=0;j<room[k].size();++j)
					if(!vst[t = room[k][j]] && !mark[t])
					{
						vst[t] = true;
						Q[tail ++] = t;
					}
			}
	}
	return tail - 1;
}

bool check()
{
	map<int,int> cnt;
	for(int i=0;i<cur.size();++i) cnt[cur[i]]++;
	for(int i=1;i<=N;++i)
		for(int j=0;j<key[i].size();++j)
			cnt[key[i][j]]++;
	for(int i=1;i<=N;++i)
		if(!cnt[lock[i]]) return false;
		else -- cnt[lock[i]];
	
//	cerr << "Amount Check OK!!"<<endl;	
	
	return Bfs(0, cur) == N;
}

vector<int> res;

void run()
{
	Init();
	
	memset(mark,false,sizeof(mark)); mark[0] = true;
	
	if(!check()) {
		puts("IMPOSSIBLE");
		return ;
	}
	
	
	//cerr << ">> Check OK!"<<endl;
	res.clear();
	int st = 0;
	for(int rem = N; rem >= 1; -- rem)
	{
		bool found = false;
		
	//	cerr << "--> Rem = "<<rem<<"  locate at : "<<st<<endl;
			
		for(int i=1;i<=N;++i)
		if(!mark[i])
		{
			vector<int> tmp = cur;
			vector<int>::iterator it = find(tmp.begin(), tmp.end(), lock[i]);
			if(it == tmp.end()) continue;
			tmp.erase(it);
			
			tmp.insert(tmp.end(), key[i].begin(), key[i].end());
			sort(tmp.begin(), tmp.end());
			
			mark[i] = true;
			if(Bfs(i, tmp) == rem - 1)
			{
				found = true;
				res.push_back(i);
				st = i;
				cur = tmp;
				break;
			}
			
			mark[i] = false;
		}
		if(!found) {
			puts("IMPOSSIBLE");
			return ;
		}
		
		room[lock[st]].erase(find(room[lock[st]].begin(), room[lock[st]].end(), st));
	}
	
	for(int i=0;i<res.size();++i)
	{
		if(i) putchar(' ');
		printf("%d", res[i]);
	}
	puts("");
} 

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	
	int test;
	scanf("%d", &test);
	for(int no=1;no<=test;++no)
	{
		printf("Case #%d: ", no);
		run();
	}
}

