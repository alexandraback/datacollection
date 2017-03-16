#include <stdio.h>
#include <deque>
#pragma warning(disable:4996)
using namespace std;
FILE *in = fopen("A.in", "r");
FILE *out = fopen("A.out", "w");
int tab[1000011];
int main(){
	int n,dat;
	fscanf(in, "%d", &n);
	deque<pair<int,int> > queue;
	queue.push_back(make_pair(1,1));
	tab[1] = 1;
	while (queue.size() != 0){
		pair<int,int> p1 = queue.front();
		queue.pop_front();
		if (tab[p1.first + 1] == 0 && p1.first+1 <= 1000000){
			tab[p1.first + 1] = p1.second + 1;
			queue.push_back(make_pair(p1.first + 1, p1.second + 1));
		}
		int rev = p1.first % 10;
		p1.first /= 10;
		while (p1.first != 0){
			rev = rev * 10;
			rev = rev + p1.first % 10;
			p1.first /= 10;
		}
		if (tab[rev] == 0 && rev <= 1000000){
			tab[rev] = p1.second + 1;
			queue.push_back(make_pair(rev, p1.second + 1));
		}
	}
	for (int i = 1; i <= n; i++){
		fscanf(in, "%d", &dat);
		fprintf(out, "Case #%d: %d\n", i,tab[dat]);
	}
	return 0;
}