#include <cstdio>
#include <cstring>

int mul[4][4] = {	{0, 1, 2, 3},
					{1, 0, 3, 2},
					{2, 3, 0, 1},
					{3, 2, 1, 0} };
					
int sgn[4][4] = {	{0, 0, 0, 0},
					{0, 1, 0, 1},
					{0, 1, 1, 0},
					{0, 0, 1, 1} };
					
int conv[255];
long long T, L, X, t;
bool possi, possj, possk;
char str[10000 + 1];
int i;
int ms, m;
int s;
					
int main() {
	conv['i'] = 1;
	conv['j'] = 2;
	conv['k'] = 3;
	scanf("%lld", &T);
	for(t = 1; t <= T; ++t) {
		scanf("%lld%lld", &L, &X);
		scanf("%s", str);
		if(X > 16)
			X = 16 + (X - 16) % 4;
		//X %= 16;
		possi = possj = possk = false;
		ms = m = 0;
		while(X--) {
			for(i = 0; str[i]; ++i) {
				s = conv[str[i]];
				ms = ms ^ sgn[m][s];
				m = mul[m][s];
				if(!possi) {
					if(ms == 0 && m == 1)
						possi = true;
				}
				else if(!possj) {
					if(ms == 0 && m == 3)
						possj = true;
				}
				else if(str[i + 1] == 0 && ms == 1 && m == 0 && X == 0)
					possk = true;
			}
		}
		printf("Case #%lld: %s\n", t, possk?"YES":"NO");
	}
	return 0;
}
