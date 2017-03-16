//#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define range(i,a,b) for(int i=(a),_b=(b); i<_b; i++)
#define fo(i,n) range(i,0,n)

typedef long long lld;
lld T, N, L;
char word[100100];

bool cons(char c) {
	return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}
ifstream cin("C:\\Users\\James\\Downloads\\A-small-attempt0.in"); ofstream cout("out.txt");

lld solve() {
	lld tot = 0, count = 0;
	cin>>word>>N;
	L = strlen(word);
	lld start=0, end=0;
	while(end<N) count += cons(word[end++]);
	if(count==N) tot += L+1-end, start=1;
	while(end<L) {
		count += cons(word[end])-cons(word[end-N]); end++;
		if(count==N) {
			tot += (end-N+1-start)*(L+1-end);
			start=end-N+1;
		}
	}
	return tot;
}

int main() {
	cin>>T;
	fo(t,T) cout<<"Case #"<<t+1<<": "<<solve()<<'\n';
}
