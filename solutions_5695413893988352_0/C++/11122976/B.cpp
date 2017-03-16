/**************************************************
 * Author	 : xiaohao Z
 * Blog	 : http://www.cnblogs.com/shu-xiaohao/
 * Last modified : 2016-04-30 23:44
 * Filename	 : A.cpp
 * Description	 : 
 * ************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned int,unsigned int> puu;
typedef pair<int, double> pid;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T, kase = 1;
	cin >> T;
	string sa, sb;
	while(T --) {
		cin >> sa >> sb;
		char a, b;
		a = b = '0';
		int f = 0, t = 0, is = 0;
		for(int i=0; i<sa.size(); i++) {
			if(sa[i] == '?' && sb[i] == '?') {
				if(!f) {is = 1; continue;}
				sa[i] = a; sb[i] = b;
			}else if(sa[i] == '?' && sb[i] != '?') {
				if(!f) sa[i] = sb[i];
				else sa[i] = a;
			}else if(sa[i] != '?' && sb[i] == '?') {
				if(!f) sb[i] = sa[i];
				else sb[i] = b;
			}else {
				f = 1;
				if(sa[i] > sb[i]) {
					if(sa[i] - sb[i] > 5) {
						if(is) t = 1, a = '9', b = '0';
						else a = '0', b = '9';
					}else if(sa[i] - sb[i] <= 5) {
						a = '0', b = '9';
					}
				} else if(sa[i] < sb[i]) {
					if(sb[i] - sa[i] > 5) {
						if(is) t = 2, b = '9', a = '0';
						else b = '0', a = '9';
					}else if(sb[i] - sa[i] <= 5) {
						b = '0', a = '9';
					}
				} else f = 0;
			}
		}
		for(int i=sa.size() - 1; i>=0; i--) {
			if(sa[i] == '?' && sb[i] == '?' && t) {
				if(t == 1) sb[i] = '1', sa[i] = '0';
				if(t == 2) sa[i] = '1', sb[i] = '0';
				t = 0;
			}else if(sa[i] == '?' && sb[i] == '?') sa[i] = sb[i] = '0';
		}
		cout << "Case #" << kase ++ << ": " << sa << ' ' << sb << endl;
	}
	return 0;
}

