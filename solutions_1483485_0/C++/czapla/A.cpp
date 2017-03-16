#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

char zamien[300];
char wczyt;

int main(){
	string G = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee z";
	string S = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo q";
	for(int i = 0; i < G.size(); i++){
		zamien[G[i]] = S[i];
	}
	zamien['\n'] = '\n';

	int testy;
	scanf("%d ", &testy);
	for(int t = 1; t <= testy; t++){
		printf("Case #%d: ", t);
		wczyt = 0;
		while(wczyt!='\n'){
			scanf("%c", &wczyt);
			printf("%c", zamien[wczyt]);
		}
	}
	return 0;
}
