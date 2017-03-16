#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <climits>

using namespace std;
typedef unsigned long long L;
struct Item {
    int type;
    L count;
	bool reduced;    
    Item(): reduced(false) {}
};

vector<Item> boxes, toys;
vector< vector<L> > cache;

L f(int b, int t) {
    if (b == boxes.size() || t == toys.size())
        return 0;
    if (boxes[b].count == 0)
        return f(b + 1, t);
    if (toys[t].count == 0)
        return f(b, t + 1);
	if (! boxes[b].reduced && ! toys[t].reduced && cache[b][t] != -1)
		return cache[b][t];
    if (boxes[b].type == toys[t].type) {
        L c = min(boxes[b].count, toys[t].count);
        boxes[b].count -= c;
        toys[t].count -= c;
		bool bb = boxes[b].reduced;
		bool tt=toys[t].reduced;		
		boxes[b].reduced = true;
        toys[t].reduced = true;
        L c2;
        if (boxes[b].count > toys[t].count)
            c2 = f(b, t + 1);
        else
            c2 = f(b + 1, t);
        boxes[b].count += c;
        toys[t].count += c;
		boxes[b].reduced = bb;
        toys[t].reduced = tt;
        return c + c2;
    }
    
    L ans = max(f(b + 1, t), f(b, t + 1));
    
    if (! boxes[b].reduced && ! toys[t].reduced)
		cache[b][t] = ans;

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);
    freopen("cout", "w", stdout);
#endif

    int cases;
    cin >> cases;

    for (int cas = 1;cas <= cases;++cas) {
        cout << "Case #" << cas << ": ";
        int n, m;
        cin >> n >> m;
        boxes.clear();
        boxes.resize(n);
        toys.clear();
        toys.resize(m);
        for (int i = 0;i < n;++i)
            cin >> boxes[i].count >> boxes[i].type;
        for (int i = 0;i < m;++i)
            cin >> toys[i].count >> toys[i].type;
		
		cache.clear();
		cache.resize(n);
		for (int i=0;i<n;++i)
			cache[i].resize(m,-1);
		
        cout << f(0, 0) << endl;
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    putchar('\n');
#endif
}


