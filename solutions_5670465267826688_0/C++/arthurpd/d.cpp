#include <stdio.h>

char m[256][256];
int n[256][256];

char s[11234567];

bool foo()
{
	int l;
	long long b;
	scanf("%d %lld %s", &l, &b, s);
	for(int i = 0; i < l; i++)
		for(int j = 1; j < 12; j++)
			s[i + l*j] = s[i];
	int y = 8 + int(b % 4ll);
	int a = (b <= 8ll) ? l*b : y*l;


	int sign = 0, posi = -1, posk = -1;
	char x = '1';
	for(int i = 0; posi == -1 && i < 4 * l && i < a; i++)
	{
		sign = sign ^ n[x][s[i]];
		x = m[x][s[i]];
		if(sign == 0 && x == 'i')
			posi = i;
	}
	
	if(posi == -1)
		return false;
	
	sign = 0;
	x = '1';

	for(int i = a-1; posk == -1 && a-i < 4*l && i >= 0; i--)
	{
		sign = sign ^ n[s[i]][x];
		x = m[s[i]][x];
		if(sign == 0 && x == 'k')
			posk = i;
	}
	
	if(posk == -1 || posk <= posi)
		return false;
	
	sign = 0;
	x = '1';
	for(int i = posi + 1; i < posk; i++)
	{
		sign = sign ^ n[x][s[i]];
		x = m[x][s[i]];
	}
	
	if(sign != 0 || x != 'j')
		return false;
	
	return true;

}

int
main(void)
{
	m['1']['1'] = '1';
	m['1']['i'] = 'i';
	m['1']['j'] = 'j';
	m['1']['k'] = 'k';

	m['i']['1'] = 'i';
	m['i']['i'] = '1'; n['i']['i'] = 1; 
	m['i']['j'] = 'k';
	m['i']['k'] = 'j'; n['i']['k'] = 1;

	m['j']['1'] = 'j';
	m['j']['i'] = 'k'; n['j']['i'] = 1;
	m['j']['j'] = '1'; n['j']['j'] = 1;
	m['j']['k'] = 'i';

	m['k']['1'] = 'k';
	m['k']['i'] = 'j'; 
	m['k']['j'] = 'i'; n['k']['j'] = 1;
	m['k']['k'] = '1'; n['k']['k'] = 1;

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: %s\n", t, foo() ? "YES" : "NO");
	}

}

























