#include<cstdio>
#include<cstring>
#include<sstream>

using namespace std;

char tab[10];

int rottab() {
	int size = strlen(tab);
	char last = tab[size-1];
	for(int i=size-1; i>0; i--) 
		tab[i] = tab[i-1];
	tab[0] = last;	
}

int rot(int n) {
	if(n < 10)
		return n;

	stringstream ins;
	ins << n;
	ins >> tab;
	
	rottab();
		
	while(tab[0]=='0')
		rottab();
		
	ins.clear();
	ins << tab;
	ins >> n;
	return n;	
	
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		static int x = 1;
		printf("Case #%d: ", x++);
		int A, B;
		scanf("%d%d", &A, &B);
		int result = 0;
		for(int n=A; n < B; n++) {
			int r = rot(n);
			
			while(r != n) {
				if(r > n && r <= B)
					result++;
				r = rot(r);
			}	
		}
		printf("%d\n", result);
	}
	return 0;
}
