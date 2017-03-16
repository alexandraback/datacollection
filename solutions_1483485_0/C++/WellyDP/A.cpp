#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>
#define INF 2000000000
#define ii pair<int, int>

using namespace std;

char arr[30]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main() {
	int ntc,pjg;
	char kal[105];
	scanf("%d",&ntc);
	for (int tc=1;tc<=ntc;tc++) {
		getchar(); scanf("%[^\n]s",kal);
		pjg=strlen(kal);
		printf("Case #%d: ",tc);
		for (int i=0;i<pjg;i++) {
			if (kal[i]==' ') printf(" "); else
			printf("%c",arr[kal[i]-'a']);
		}
		puts("");	
	} 
    return 0;
}
