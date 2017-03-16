#include <cstdio>
#include <algorithm>

using namespace std;

int T[10000005];

int A,B,log;

void read()
{
	scanf("%d%d", &A, &B);
	log = 10;
	while(A/log >= 10)
		log *= 10;
}
void roll(int &a)
{
	int b = a%10;
	a /= 10;
	a += log*b;
}
void canonize(int a)
{
	int canon = 1000000000;
	for(int i = 0;i<10;i++)
	{
		canon = min(a,canon);
		roll(a);
	}
	T[canon]++;
}
void result(int ca)
{
	for(int i = A;i<=B;i++)
		canonize(i);
	long long res = 0;
	for(int i = 1;i<=10000000;i++)
	{
		res += (long long)(T[i])*(long long)(T[i]-1)/2;
		T[i] = 0;
	}
	printf("Case #%d: %lld\n",ca,res);
}
int main()
{
	int Z;
	scanf("%d", &Z);
	for(int i = 1;i<=Z;i++)
	{
		read();
		result(i);
	}
	return 0;
}
