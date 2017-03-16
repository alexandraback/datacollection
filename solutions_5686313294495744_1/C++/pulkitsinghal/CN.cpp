#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL
#define ll long long

#define SET(x) memset(x, -1, sizeof(x))
#define CLR(x) memset(x, 0, sizeof(x))
#define MAX 2010

vector <int> edges[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];

bool dfs(int u)
{
    if(visited[u]) return false;
    visited[u] = true;
    int len = edges[u].size(), i, v;
    for(i=0; i<len; i++) {
        v = edges[u][i];
        if(Right[v]==-1) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++) {
        v = edges[u][i];
        if(dfs(Right[v])) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int szL, szR;

int match() {
    SET(Left);
    SET(Right);
    int i, ret = 0;
    bool done;
    do {
        done = true;
        CLR(visited);
        for(i=0; i<MAX; i++) {
            if(Left[i]==-1 && dfs(i)) {
                done = false;
            }
        }
    } while(!done);
    for(i=0; i<MAX; i++) ret += (Left[i]!=-1);
    return ret;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;++tc)
	{
		int n;
		cin >> n;
		string A[n][2];
		for(int i=0;i<n;++i)
			cin >> A[i][0] >> A[i][1];
		map<string,int> F, S;
		map<int,string> FR, SC;
		szL = szR = 0;
		for(int i=0;i<MAX;++i)
			edges[i].clear();
		for(int i=0;i<n;++i)
		{
			if(!F.count(A[i][0]))
			{
				F[A[i][0]] = ++szL;
				FR[szL] = A[i][0];
			}
			if(!S.count(A[i][1]))
			{
				S[A[i][1]] = ++szR;
				SC[szR] = A[i][1];
			}
			edges[F[A[i][0]]].push_back(S[A[i][1]]+n);
		}
		int cnt = match();
		set<string> first, second;
		for(int i=1;i<=szL;++i)
			if(Left[i]!=-1)
			{
				first.insert(FR[i]);
				second.insert(SC[Left[i]-n]);
			}
		for(int i=0;i<n;++i)
		{
			if(!first.count(A[i][0]) or !second.count(A[i][1]))
			{
				++cnt;
				first.insert(A[i][0]);
				second.insert(A[i][1]);
			}
		}
		cout << "Case #" << tc << ": " << n-cnt << endl;
	}
	return 0;
}
