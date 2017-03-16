#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main()
{
	int t, caseNum = 1, i, j, n, perm[16], max, now;
	char in1[16][30], in2[16][30];
	set<string> w1, w2;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%s%s", in1[i], in2[i]);
		now = 0;
		for(i = 0;i < n;i++){
			w1.clear();
			w2.clear();
			for(j = 0;j < n;j++){
				if(i != j){
					w1.insert(string(in1[j]));
					w2.insert(string(in2[j]));
				}
			}
			if(w1.find(string(in1[i])) != w1.end() && w2.find(string(in2[i])) != w2.end())
				now += 1;
		}
		printf("Case #%d: %d\n", caseNum++, now);
	}
	return 0;
}
