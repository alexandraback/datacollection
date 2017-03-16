#include <cstdio>

//		   "abcdefghijklmnopqrstuvwxyz";
char K[] = "yhesocvxduiglbkrztnwjpfmaq";

int no = 1;
void test() {
	static char C[110], P[110];
	scanf("\n%[^\n]", C );
	char *c, *p;
	for( c = C, p = P; *c; c++, p++ ) {
		*p = *c;
		if( *p >= 'a' and *p <= 'z' )
			*p = K[*p-'a'];
	}
	*p = 0;
	printf("Case #%d: %s\n", no++, P );
}

int main() {
	int T;
	scanf("%d", &T);
	while( T --> 0 ) {
		test();
	}
	return 0;
}
