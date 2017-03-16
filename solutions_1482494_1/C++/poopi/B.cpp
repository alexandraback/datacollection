										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

ifstream fin ("B.in");
ofstream fout ("B.out");

#define cin fin
#define cout fout
#define int64 long long
#define P pair<int, int>

int n;
int a[1010], b[1010];
int mark[1010];
priority_queue <P> q;

int main(){
	int T, test = 0;
	for(cin >> T; T--; ){
		while(!q.empty())
			q.pop();
		memset(mark, 0, sizeof mark);
		cerr << T << endl;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
			q.push(P(-b[i], i));
		}
		int res = n, str = 0;
		while(str < 2 * n){
			while(!q.empty() && -q.top().first <= str){
				P tmp = q.top();
				q.pop();
				str += 2 - mark[tmp.second];
				mark[tmp.second] = 2;
			}
			int idx = -1, mx = -1;
			for(int i = 0; i < n; i++)
				if(mark[i] == 0 && a[i] <= str && b[i] > mx)
					idx = i, mx = b[i];
			if(idx == -1)
				break;
			str++;
			res++;
			mark[idx] = 1;
		}
		if(str != 2 * n)
			cout << "Case #" << ++test << ": Too Bad" << endl;
		else cout << "Case #" << ++test << ": " << res << endl;
	}
	return 0;
}
