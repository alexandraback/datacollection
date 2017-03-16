#include <cstdio>

enum {
	ONE = 1,
	I,
	J,
	K
};
const int _mul[5][5] = 
{
	{0, 0, 0, 0, 0},
	{0, 1, I, J ,K},
	{0, I,-1, K,-J},
	{0, J,-K,-1, I},
	{0, K, J,-I,-1}
};

int inv(int i) {
	if(i == -1 || i == 1)
		return i;
	return -i;
}

int mul(int i,int j) {
	bool isneg = false;
	if( i < 0 ) {
		isneg = !isneg;
		i = -i;
	}
	if( j < 0 ) {
		isneg = !isneg;
		j = -j;
	}
	return isneg ? -_mul[i][j] : _mul[i][j];
}

char str[20000];
int getVal(int idx) {
	return str[idx]-'i'+2;
}
int s[20000];
int main() {
	int T,ics = 0;
	scanf("%d",&T);
	while(T--) {
		int L,X;
		scanf("%d%d%s",&L,&X,str);
		int len = L*X;
		s[0] = getVal(0);
		for(int i=1;i<len;++i) {
			s[i] = mul(s[i-1],getVal(i%L));
		}
		bool found = false;
		if( s[len-1] == -1 ) {
			int si = -1;
			for(int i=0;i<len;++i) if(s[i] == I) {
				si = i;
				break;
			}
			if( si >= 0 ) {
				for(int i=si+1;i<len;++i) if(s[i] == K){
					found = true;
					break;
				}
			}
		}
		printf("Case #%d: %s\n",++ics,found?"YES":"NO");
	}
	return 0;
}
