#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
//#include <sys/time.h>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second


#define MAX 205
li N;
li used[MAX];
vector<li> keys;
vector<li> opened;
vector<li> E[MAX];
map<li, vector<li> > indices;


void run()
{
	while(sz(keys)){
		li key = keys.back();
		keys.pop_back();
		
		//cerr << "key : " << key << endl;
		
		li best = -1;
		rep(i, sz(indices[key])){
			li cur = indices[key][i];
			if(used[cur]) continue;
			if(best == -1) best = cur;
			
			//cerr << "cur : " << cur << endl;
			
			bool found = false;
			set<li> checked;
			queue<li> q;
			rep(j, sz(E[cur])) q.push(E[cur][j]);
			
			while(sz(q)){
				li cur_key = q.front();
				q.pop();
				if(cur_key == key){
					found = true;
					break;
				}
				rep(i, sz(indices[cur_key])){
					li next = indices[cur_key][i];
					rep(j, sz(E[next])){
						li next_key = E[next][j];
						if(checked.count(next_key)) continue;
						q.push(next_key);
						checked.insert(next_key);
					}
				}
			}
			
			if(found){
				best = cur;
				break;
			}
		}
		
		if(best == -1) continue;
		//cerr << "best : " << best << endl;
		used[best] = true;
		opened.pb(best);
		rep(i, sz(E[best])) keys.pb(E[best][i]);
		
	}
}

int main()
{
	li T;
	cin >> T;
	
	rep(step, T){
		rep(i, MAX) E[i].clear();
		indices.clear();
		opened.clear();
		memset(used, false, sizeof(used));
		
		li k;
		cin >> k >> N;

		keys = vector<li>(k);
		rep(i, k) cin >> keys[i];

		rep(i, N){
			li type, num;
			cin >> type >> num;
			indices[type].pb(i);
			E[i] = vector<li>(num);
			rep(j, num) cin >> E[i][j];
		}
		
		run();
		cout << "Case #" << step + 1 << ":";
		if(sz(opened) != N){
			cout << " IMPOSSIBLE" << endl;
		}else{
			rep(i, sz(opened)) cout << " " << opened[i] + 1;
			cout << endl;
		}
	}
}

















