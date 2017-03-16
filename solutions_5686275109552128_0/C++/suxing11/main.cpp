#include <stdio.h>
#include <map>
#include <vector>


using namespace std;
map <vector<int>, int > hash;


int gao(vector <int> vec)
{
	int i, j, ans;
	vector<int> vv;
	if (hash.find(vec) != hash.end()) return hash[vec];
	for (i = 9; i > 0; i--)
		if (vec[i] != 0) break;
	if (i == 0) return hash[vec] = 0;
	if (i == 1) return hash[vec] = 1;
	
	vv = vec;
	for (j = i-1; j >= 0; j--)
		vv[j] = vv[j+1];
	vv[i] = 0;
	ans = gao(vv)+1;
	
	vv = vec;
	for (j = 1; j < i; j++)
	{
		vv = vec;
		vv[j]++, vv[i-j]++;
		vv[i]--;
		ans = min(ans, 1+gao(vv));
	}
	return hash[vec] = ans;
}


int main()
{
	int i, d, pi;
	int T, cas;
	freopen ("B-small-attempt1.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	for (cas = 1 ; cas <= T; cas++)
	{
		vector <int> vec(10, 0);
		scanf ("%d", &d);
		for (i = 0; i < d; i++)
			scanf ("%d", &pi), vec[pi]++;
		printf ("Case #%d: %d\n", cas, gao(vec));
	}
	
	return 0;
}
