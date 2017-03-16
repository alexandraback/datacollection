#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
#include <ctime>
using namespace std;

#define pii pair<int,int>
#define MPII make_pair<int,int>
#define PLL pair<lng,lng>
#define MPLL make_pair<lng,lng>
#define PI 3.1415926535897932384626433832795
#define DEG2RAD (PI/180.0)
#define RAD2DEG (1.0/DEG2RAD)
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=n-1;i>=0;--i)
#define forn1(i,n) for(int i=0;i<n+1;++i)
#define forv(i,v) for(int i=0;i<v.size();++i)
#define forvr(i,v) for(int i=v.size()-1;i>=0;--i)
#define fors(i,s) for(int i=0;i<s.length();++i)
#define EPS 1e-12
#define eps EPS
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<EPS)
#define maxll ((1LL<<62)-1+(1LL<<62))
#define SQ(a) ((a)*(a))
#define SWAP(t,a,b) {t ____tmpasdasdasd=(a);(a)=(b);(b)=____tmpasdasdasd;}
#define abs(a) ((a)<0?-(a):(a))
#define ALL(a) (a).begin(),(a).end()

std::list<int> order;
// bool visited[201]; // in this array we save visited vertices

struct Chest {
	int type;
	int num;
	map<int, int> keys;
};

//bool myfunction (Chest i,Chest j) { return (i.keys.size()>j.keys.size()); }

bool check_if_ok (map<int,int> keys, vector<Chest> chests, int n)
{
	bool is_ok = true;
	map<int, int> all_keys(keys);
	forn (i, n) {
		std::map<int, int>::iterator it;
		for (it = chests[i].keys.begin(); it != chests[i].keys.end(); ++it) {
			all_keys[it->first]+=it->second;
		}
	}

	map<int, int> all_keys_2(all_keys);
	// check 1
	forn (i, n) {
		bool found = false;
		if (all_keys[chests[i].type] > 0) {
			all_keys[chests[i].type]--;
		} else {
			is_ok = false;
			break;
		}
	}

	// check 2
	forn (i, n) {
		bool found = false;
		if (all_keys_2[chests[i].type] - chests[i].keys[chests[i].type] < 1) {
			is_ok = false;
			break;
		}
	}
	return is_ok;
}

bool special_dfs(int n, map<int, int> keys_storage, vector<Chest> chests)
{
	forn (i, chests.size()) {
		if (keys_storage[chests[i].type] > 0) {
			map<int, int> keys_storage_temp (keys_storage);
			vector<Chest> chest_temp;
			keys_storage_temp[chests[i].type]--;
			std::map<int, int>::iterator it;
			for (it = chests[i].keys.begin(); it != chests[i].keys.end(); ++it) {
				keys_storage_temp[it->first]+=it->second;
			}
			chest_temp.insert(chest_temp.end(), chests.begin(), chests.end());
			chest_temp.erase(chest_temp.begin() + i);

			if (chest_temp.size() == 0) {
				order.push_back(chests[i].num);
				return true;
			}

			if (!check_if_ok(keys_storage_temp, chest_temp, chest_temp.size()))
				continue;

			order.push_back(chests[i].num);
			bool ret = special_dfs(n, keys_storage_temp, chest_temp);

			if (!ret) {
				order.pop_back();
			} else {
				return true;
			}
		}
	}
	return false;
}


int main(){
	freopen("c:\\jam\\2013\\d.in","r",stdin);
	freopen("c:\\jam\\2013\\d.out","w",stdout);

	int tc;
	cin>>tc;

	forn(q,tc){
		int K, N, ret, temp, temp1;
		map<int,int> keys;
		vector<Chest> chests;
		cin >> K;
		cin >> N;
		ret = 0;

		order.erase (order.begin(),order.end());

		forn (i, K) {
			cin >> temp;
			keys[temp]++;
		}

		forn (i, N) {
			Chest tempC;
			tempC.num = i+1;
			cin >> tempC.type;
			cin >> temp;
			forn (k, temp) {
				cin >> temp1;
				tempC.keys[temp1]++;
			}
			chests.push_back(tempC);
		}
		bool is_ok = true;

		is_ok = check_if_ok(keys, chests, N);

		if (is_ok) is_ok = special_dfs(N, keys, chests);

		cout <<"Case #"<<q+1<<":";

		if (is_ok) {
			std::list<int>::const_iterator iterator;
			for (iterator = order.begin(); iterator != order.end(); ++iterator) {
				std::cout << " " << *iterator;
			}
		} else {
			std::cout << " IMPOSSIBLE";
		}
		std::cout << endl;
	}

	return 0;
}
