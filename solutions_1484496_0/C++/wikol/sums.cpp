#include <cstdio>
#include <algorithm>

using namespace std;

int m[2000005];
int T[50];

void output_mask(int mask)
{
	for(int i = 0;i<20;i++)
		if(mask & (1<<i))
			printf("%d ", T[i]);
	printf("\n");
}

bool process_mask(int mask)
{
	int s = 0;
	for(int i = 0;i<20;i++)
		if(mask & (1<<i))
			s += T[i];
	if(m[s] != 0)
	{
		output_mask(mask);
		output_mask(m[s]);
		return true;
	}
	m[s] = mask;
	return false;
}
void read()
{
	scanf("%*d");
	for(int i = 0;i<20;i++)
		scanf("%d", &T[i]);
}
void get_result(int c)
{
	read();
	printf("Case #%d:\n", c);
	bool done = false;
	for(int mask = 1;mask<(1<<20);mask++)
	{
		done = process_mask(mask);
		if(done)
			break;
	}
	if(!done)
		printf("Impossible\n");
	for(int i = 0;i<=2000000;i++)
		m[i] = 0;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1;i<=t;i++)
		get_result(i);
	return 0;
}

