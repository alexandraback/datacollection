#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

#define sort(V) sort(V.begin(),V.end())

const int mod = 10000019;
int dist[mod+1];
bool vst[mod+1];

int hash(vector<int> v)
{
	int x = 0;
	int q = 1;
	for (int i = 0; i < v.size(); i++)
	{
		x += v[i]*q;
		q *= 11;
		x %= mod;
		q %= mod;
	}
	return x;
}

int bfs(vector<int> S)
{
	queue<vector<int> > Q;
	vst[hash(S)] = true;
	dist[hash(S)] = 0;
	Q.push(S);
	while(!Q.empty())
	{
		vector<int> v = Q.front();
		Q.pop();
		int H = hash(v);
		if (H == 0) return dist[H];
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 1; j <= v[i]/2; j++)
			{
				vector<int> w = v;
				w[i] -= j;
				w.push_back(j);
				sort(w);
				int h = hash(w);
				if (vst[h]) continue;
				//cout << h << "\n";
				Q.push(w);
				dist[h] = dist[H]+1;
				vst[h] = true;
			}
		}
		vector<int> w = v;
		for (int i = 0; i < w.size(); i++) if (w[i] > 0) w[i]--;
		sort(w);
		int h = hash(w);
		if (vst[h]) continue;
		//cout << h << "\n";
		Q.push(w);
		dist[h] = dist[H]+1;
		vst[h] = true;
		//cout << Q.size() << "\n";
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
		cerr << t << "\n";
		int n;
		cin >> n;
		vector<int> V;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			V.push_back(x);
		}
		sort(V);
		cout << "Case #" << t << ": " << bfs(V) << "\n";
		memset(vst,0,sizeof(vst));
		memset(dist,0,sizeof(dist));
	}


    return 0;
}
