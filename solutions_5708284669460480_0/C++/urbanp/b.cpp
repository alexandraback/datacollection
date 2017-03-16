#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
#include <limits>
#include <map>
#include <math.h> 
#include <iostream>
#include <set>

#define CAP 110
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

char word[CAP], keyboard[CAP], curr[CAP];
double high, total;
int K, L, S;

void solve();
void iter(int a);
double count();
double cases();

int main(){
	/*strcpy(curr, "CBCBCBC");
	strcpy(word, "CBC");
	L = 3;
	S = 7;
	printf("%lf\n", count());*/
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}

void solve(){
	high=0;
	total=0;
	scanf("%d %d %d\n", &K, &L, &S);
	scanf("%s", keyboard);
	scanf("%s", word);

	double cut = cases();
	iter(0);
	double ret = high-total/cut; // replace with something... : D
	//printf("high: %lf, total: %lf, cut: %lf\n", high, total, cut);
	printf("%.10lf\n", ret);
}

void iter(int a){
	if(a==S){ //until string length
		curr[S] = '\0';
		double tmp = count();
		if(tmp>high)
			high = tmp;
		total+=tmp;
		return;
	}
	for(int i=0; i<K; i++){
		curr[a] = keyboard[i];
		iter(a+1);
	}
}

double count(){
	double ret = 0.0;
	bool unbroken;
	for(int i=0; i<S-L+1; i++){ //för varje startposition
		unbroken = true;
		for(int j=i; j<L+i; j++){ //matcha ordet mot buffern
			//printf("%c %c\n", word[j-i], curr[j-i]);
			if(word[j-i]!=curr[j]){
				//printf("breaking\n");
				unbroken = false;
				break;
			}
		}
		if(unbroken){
			//printf("%s found at %d\n", word, i);
			ret+=1.0;
		}
	}
	return ret;
}

double cases(){
	return pow((double) (K), (double)(S));
}