#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>


using namespace std;


int p[100];
int r, n, m, k;

void Load()
{
	for (int i = 0; i < k; i++)
		cin >> p[i];
}

map <string, int> res;

void Solve()
{
	int min3, min5, min2, min4;
	min3 = min5 = min2 = min4 = 0;
	int i, j;

	for (i = 0; i < k; i++) {
	   	int cmin3, cmin5, cmin2, cmin4;
		cmin3 = cmin5 = cmin2 = cmin4 = 0;

		j = 0;
		int t = p[i];
		while (t % 3 == 0) {
			t /= 3;
			cmin3++;
		}
		while (t % 5 == 0) {
			t /= 5;
			cmin5++;
		}
		while (t % 2 == 0) {
			t /= 2;
			cmin2++;
		}
		if (min2 < cmin2)
			min2 = cmin2;
		if (min3 < cmin3)
			min3 = cmin3;
		if (min5 < cmin5)
			min5 = cmin5;
	}
		while (min3+min5+min2 > 3) {
			min2 -= 2;
			min4++;
		}

	min2 = 0;
	map<string, int>::iterator it;
	string ans = "zzz";
	int bst = -1;
	cerr << min2 << ' ' << min3 << ' ' << min4 << ' ' << min5 << "\n";
	for (it = res.begin(); it != res.end(); ++it)
	{
		string s = (*it).first;
		int cnt = (*it).second;
		int h, z;
		cerr << s << "\n";
		h = 0;		
		for (z = 0; z < 3; z++)
			if (s[z] == '3') h++;
		cerr << h << '\n';
		if (h < min3) continue;
		h = 0;
		for (z = 0; z < 3; z++)
			if (s[z] == '4') h++;
		cerr << h << '\n';
		if (h < min4) continue;
		h = 0;
		for (z = 0; z < 3; z++)
			if (s[z] == '5') h++;
		cerr << h << '\n';
		if (h < min5) continue;
		cerr << "*\n";
		if (cnt > bst) {
			bst = cnt; 
			ans = s;
		}	
	}
	cout << ans << "\n";
}



void Calc()
{
	string s = "222";
	while (true)
	{
	    string t= s;
	    sort(t.begin(), t.end());
	    res[t]++;
	    s[2]++;
	    if (s[2] > '5') {
	    	s[2] = '2';
		    s[1]++;
		}
		if (s[1] > '5') {
	    	s[1] = '2';
		    s[0]++;
		}
		if (s[0] > '5') {
			break;
		}
	}

}
int main()
{
	srand(time(NULL));
	Calc();
	int nt, tt;
	cin >> nt >> r >> n >> m >> k;
	cout << "Case #" << 1 << ":\n";
	nt = r;
	for (tt = 1; tt <= nt; tt++) {
		Load();
		Solve(); 
	}
	return 0;
}
