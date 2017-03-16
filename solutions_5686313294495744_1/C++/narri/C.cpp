#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
#include <stdint.h>
#include <climits>
#include <iostream>


using namespace std;
#if 0
namespace maxflow
{
	/* O(N^2) memory is used for this one, be careful */
	/* cap[a][b] nonzero means there is an edge there */
	const int MAXV = 5000;
	const int INF = INT_MAX;
	int cap[MAXV][MAXV];
	int flow[MAXV][MAXV];
	int pred[MAXV];
	int val[MAXV];
	int flow_size;
	//the output is visible in flow
	void find_maxflow(int N,int src,int sink)
	{
		flow_size = 0;
		memset(flow,0,sizeof(flow));
		while(1)
		{
			//remove labels
			memset(pred,-1,sizeof(pred));
			memset(val,-1,sizeof(val));
			//start with src
			pred[src] = -1;
			val[src] = INF;
			set<int> U;U.clear();
			U.insert(src);
			while(val[sink] == -1)
			{
				//check for done
				if(U.empty()){return;}
				int v = (*U.begin());U.erase(v);
				int delta = val[v];
				for(int i=0;i<N;++i)
				{
					if(val[i] != -1){continue;}
					if(cap[v][i] && flow[v][i] < cap[v][i])
					{
						pred[i] = v;
						val[i] = min(delta,cap[v][i]-flow[v][i]);
						U.insert(i);
					}
					if(cap[i][v] && flow[i][v]>0)
					{
						pred[i] = v;
						val[i] = min(delta,flow[i][v]);
						U.insert(i);
					}
				}
			}
			vector<int> w(1,sink);
			for(int t=0;w[t] != src;++t)
			{
				w.push_back(pred[w[t]]);
			}
			reverse(w.begin(),w.end());
			int delta = val[sink];
			flow_size += delta;
			for(int i=1;i<w.size();++i)
			{
				if(cap[w[i-1]][w[i]])
				{
					flow[w[i-1]][w[i]] += delta;
				}
				else
				{
					flow[w[i]][w[i-1]] -= delta;
				}
			}
		}
	}
};
#endif

#if 1
namespace maxflow
{
	/* this version uses maps for cap and flow */
	const int MAXV = 5000;
	const int INF = INT_MAX;
	map<pair<int,int>,int> cap;
	map<pair<int,int>,int> flow;
	int pred[MAXV];
	int val[MAXV];
	int flow_size;
	//the output is visible in flow
	void find_maxflow(int N,int src,int sink)
	{
		flow_size = 0;
		flow.clear();
		while(1)
		{
			//remove labels
			memset(pred,-1,sizeof(pred));
			memset(val,-1,sizeof(val));
			//start with src
			pred[src] = -1;
			val[src] = INF;
			set<int> U;U.clear();
			U.insert(src);
			while(val[sink] == -1)
			{
				//check for done
				if(U.empty()){return;}
				int v = (*U.begin());U.erase(v);
				int delta = val[v];
				pair<int,int> iv = make_pair(0,v);
				pair<int,int> vi = make_pair(v,0);
				for(int i=0;i<N;++i,++iv.first,++vi.second)
				{
					if(val[i] != -1){continue;}
					if(cap.find(vi) != cap.end() && flow[vi] < cap[vi])
					{
						pred[i] = v;
						val[i] = min(delta,cap[vi]-flow[vi]);
						U.insert(i);
					}
					if(cap.find(iv) != cap.end() && cap[iv] && flow[iv]>0)
					{
						pred[i] = v;
						val[i] = min(delta,flow[iv]);
						U.insert(i);
					}
				}
			}
			vector<int> w(1,sink);
			for(int t=0;w[t] != src;++t)
			{
				w.push_back(pred[w[t]]);
			}
			reverse(w.begin(),w.end());
			int delta = val[sink];
			flow_size += delta;
			for(int i=1;i<w.size();++i)
			{
				pair<int,int> ab = make_pair(w[i-1],w[i]);
				if(cap.find(ab) != cap.end() && cap[ab])
				{
					flow[ab] += delta;
				}
				else
				{
					flow[make_pair(w[i],w[i-1])] -= delta;
				}
			}
		}
	}
};
#endif


int get_ident(const string &a, vector<string> &pool, map<string, int> &mapool) {
    if(mapool.find(a) != mapool.end()) {
        return mapool[a];
    }
    int r = pool.size();
    pool.push_back(a);
    mapool[a] = r;
    return r;
}

int main(int argc, char **argv) {
    int T;
    cin >> T;
    for(int _cn = 1;_cn <= T;++_cn) {
        int N;
        cin >> N;
        vector<string> pool;
        map<string, int> mapool;
        vector<pair<int,int> > input;
        set<int> leftids;
        set<int> rightids;
        for(int i=0;i<N;++i) {
            string a,b;
            cin >> a >> b;
            int ia = get_ident(a, pool, mapool);
            int ib = get_ident(b, pool, mapool);
            leftids.insert(ia);
            rightids.insert(ib);
            input.push_back(make_pair(ia,ib));
        }
        vector<int> vleft(leftids.begin(), leftids.end());
        vector<int> vright(rightids.begin(), rightids.end());
        const int NUM_WORDS = pool.size();
        const int SOURCE = 0;
        const int SINK = 1;
        //map first words to second words
        const int LEFTST = 2;
        const int RIGHTST = 2 + NUM_WORDS;
#if 1
        map<pair<int,int>,int> &cap = maxflow::cap;
        cap.clear();
        for(int i=0;i<vleft.size();++i) {
            cap[make_pair(SOURCE,LEFTST + vleft[i])] = 1;
        }
        for(int i=0;i<vright.size();++i) {
            cap[make_pair(RIGHTST + vright[i],SINK)] = 1;
        }
        for(int i=0;i<N;++i) {
            cap[make_pair(LEFTST + input[i].first,RIGHTST + input[i].second)] = 1;
        }
#endif
#if 0
        std::cerr << "MEMSET START" << std::endl;
        memset(maxflow::cap, 0, sizeof(maxflow::cap));
        std::cerr << "MEMSET END" << std::endl;
        for(int i=0;i<vleft.size();++i) {
            maxflow::cap[SOURCE][LEFTST + vleft[i]] = 1;
        }
        for(int i=0;i<vright.size();++i) {
            maxflow::cap[RIGHTST + vright[i]][SINK] = 1;
        }
        for(int i=0;i<N;++i) {
            maxflow::cap[LEFTST + input[i].first][RIGHTST + input[i].second] = 1;
        }

#endif
        maxflow::find_maxflow(RIGHTST + NUM_WORDS, SOURCE, SINK);
        int num_doubles = maxflow::flow_size;
        int singles = (int)vleft.size() + (int)vright.size() - 2*num_doubles;
        int myanswer = N - singles - num_doubles;
        //cerr << num_doubles << " " << singles << " " << myanswer << endl;
        printf("Case #%d: %d\n", _cn, myanswer);
    }

    return 0;
}

