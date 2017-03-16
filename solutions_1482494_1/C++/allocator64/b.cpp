#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
class Item{
public:
	int one, two;
	int done;
};
vector<Item> v;
int T,n;
int main(){
	scanf("%d", &T);
	for (int testcase = 0; testcase < T; ++ testcase){
		scanf("%d", &n);
		v.resize(n);
		for (int i = 0; i < n; ++ i){
			scanf("%d%d", &v[i].one, &v[i].two);
			v[i].done = 0;
		}
		int stars = 0;
		int cnt = 0;
		int turns = 0;
		while (cnt < n){
			bool fail = 1;
			bool end = 0;
			for (int i = 0; i < n; ++ i)
				if (v[i].done < 2 && v[i].two <= stars){
					//cerr << "Two! " << i + 1 << " " << v[i].two << " " << stars << endl;
					stars += 2 - v[i].done;
					v[i].done = 2;
					cnt ++;
					turns ++;
					end = 1;
					fail = 0;
					break;
				}
			if (end)
				continue;
			int pos = -1;
			int max = -1;
			for (int i = 0; i < n; ++ i)
				if (v[i].done == 0 && v[i].one <= stars && max < v[i].two){
					pos = i;
					max = v[i].two;
				}
			if (pos != -1){
				//cerr << "One " << pos + 1 << " " << v[pos].one << " " << stars << endl;
				stars += 1;
				v[pos].done = 1;
				turns ++;
				end = 1;
				fail = 0;
			}
			if (end)
				continue;
			if (fail)
				break;
		}
		printf("Case #%d: ", testcase + 1);
		if (cnt < n)
			printf("Too Bad\n");
		else
			printf("%d\n", turns);
	}
	return 0;
}