#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
#define X first
#define Y second
#define RED 0
#define GREEN 1
#define BLUE 2
typedef long long LL;
//typedef __int128_t VL;
typedef long double LD;

int n;
char word[1000123];
int word_length;
bool cons[1000123];

int main(){
	int testy;
	scanf("%d ", &testy);
	for(int t = 1; t <= testy; t++){
		scanf(" %s %d ", word, &n);
		word_length = strlen(word);
		for(int i = 0; i < word_length; i++)
			cons[i] = (word[i]!='a' && word[i]!='e' && word[i]!='i' && word[i]!='o' && word[i]!='u');
		
		int last_begin = -1000123, conseq = 0;
		LL res = 0LL;
		for(int i = 0; i < word_length; i++){
			if(cons[i])
				conseq++;
			else
				conseq = 0;
			if(conseq >= n)
				last_begin = i-n+2;
//printf("%d %d\n", last_begin, conseq);
			res += max(0, last_begin);
		}
	
	
		printf("Case #%d: %lld\n", t, res);
	

	}
	return 0;
}
