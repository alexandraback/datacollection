//Jakub "Cubix651" Cisło
//Zadanie: A
#include <cstdio>
#include <cstring>
typedef long long int LL;

const int MAX = 6291556;
int n, t, s;
char str[MAX];
bool pocz[MAX], kon[MAX];
LL res;

int main()
{
	scanf("%d", &t);
	for(int tt = 1; tt <= t; ++tt)
	{
		scanf("%s", str);
		scanf("%d", &n);
		
		s = strlen(str);
		for(int i = 0; i <= s+1; ++i)
			pocz[i] = kon[i] = false;
		
		for(int b = 0, e = 0; e < s;)
		{
			if(str[e] == 'a' || str[e] == 'e' || str[e] == 'i' || str[e] == 'o' || str[e] == 'u')
			{
				++e;
				b = e;;				
			}
			else
			{
				++e;
			}
			if(e-b == n)
			{
				pocz[b] = true;
				kon[e] = true;
				++b;
			}
		}
		kon[s+1] = true;
		/*for(int i = 0; i <= s; ++i)
		{
			if(pocz[i])
				printf("P: %d\n", i);
			if(kon[i])
				printf("K: %d\n", i);
		}*/
		res = LL(s) * LL(s+1) / 2;
		
		int p = -1, k = 0;
		while(!kon[k]) ++k;
		
		while(k < s+2)
		{
			//printf("(%d, %d)\n", p, k);
			res -= LL(k - p - 2)*LL(k-p-1)/2;
			++k;
			++p;
			if(k > s+1) break;
			while(!kon[k]) ++k;
			while(!pocz[p]) ++p;
		}
		
		//printf("%lld\n", res);
		
		LL l = 0;
		for(int i = 0; i < s; ++i)
			if(pocz[i])
				++l;
		
		res += l * LL(n-2) * LL(n-1) / 2;
		printf("Case #%d: %lld\n", tt, res);
	}
	return 0;
}
