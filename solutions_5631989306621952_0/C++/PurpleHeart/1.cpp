#include <cstdio>
#include <string>

using namespace std;

int cases;
char mt[5005];

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%s", mt);
		string gao(mt), res;
		for(int i = 0; i < gao.length(); ++i)
			res = max(res + gao[i], gao[i] + res);
		printf("Case #%d: %s\n", xx, res.c_str());
	}
}
