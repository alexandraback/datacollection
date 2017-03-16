#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>


using namespace std;

int const MAXN = 1000;

int a,n;
int palle[MAXN];


int solve() {
	scanf("%d %d",&a,&n);
	for (int i=0; i<n; ++i) {
		scanf("%d",palle+i);
	}
	
	sort(palle, palle+n);
	
	int best_ops = n+1; // numero minimo di operazioni
	int size = a; // grandezza attuale della palla
	
	int num_ops = 0; // numero attuale di operazioni effettuate
	
	if ( size <= 1 ) return n;
	
	for (int i=0; i<n; ++i) {
		// per sistemare la palla i posso buttare via tutto il resto o inglobarla
		
		best_ops = min( best_ops, num_ops + n - i );
		
		while ( size <= palle[i] ) {
			num_ops++;
			size += size-1;
		}
		size += palle[i];
		
	}
	
	best_ops = min( best_ops, num_ops );
	
	return best_ops;
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	for (int i=0; i<t; ++i) {
		printf("Case #%d: ",i+1);
		printf("%d\n",solve());
	}
	
	return 0;
}
