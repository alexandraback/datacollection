#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 26 + 5, mo = 1000000000 + 7;

int n;
bool mid[N], visit[N];
int loop[N], ind[N], next[N];

int work()
{
	cin >> n;
    memset(mid, 0, sizeof(mid));
    memset(loop, 0, sizeof(loop));
    memset(ind, 0, sizeof(ind));
    memset(next, -1, sizeof(next));
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; ++i) {
    	string s1;
    	vector<int> s2;
    	cin >> s1;
		for (int j = 0; j < s1.size(); ++j)
			 if (s2.empty() || s1[j] - 'a' != s2.back())
			 	s2.push_back(s1[j] - 'a');
		for (int j = 1; j + 1 < s2.size(); ++j) {
			if (mid[s2[j]])
				return 0;
			mid[s2[j]] = true;
		}		
		if (s2.size() == 1)
			++loop[s2[0]];
		else {
			if (next[s2[0]] != -1 || ind[s2.back()] > 0)
				return 0;
			next[s2[0]] = s2.back();
			++ind[s2.back()];
		}		
    }
    for (int i = 0; i < 26; ++i) 
    	if (loop[i] || ind[i] > 0 || next[i] != -1) {
    		visit[i] = true;
    		if (mid[i])
    			return 0;
    	}
    vector<int> ans(1, 0);
    for (int i = 0; i < 26; ++i)
    	if (visit[i] && ind[i] == 0) {
    		++ans[0];
    		int t = i;
    		while (t != -1) {
    			visit[t] = false;
    			t = next[t];
    		}
    	}
    for (int i = 0; i < 26; ++i) {
    	if (visit[i])
    		return 0;    
    	if (loop[i] > 1)
    		ans.push_back(loop[i]);
    }
    int ret = 1;
    for (int i = 0; i < ans.size(); ++i)
    	for (int j = 2; j <= ans[i]; ++j)
    		ret = ret * j % mo;
    return ret;
}

int main()
{
    freopen("b1.in", "r", stdin);
    freopen("b1.out", "w", stdout);
    
    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);        
        printf("%d\n", work());
    }
    
    return 0;
}

