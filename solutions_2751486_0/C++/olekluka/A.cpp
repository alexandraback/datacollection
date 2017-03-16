//Aleksander Łukasiewicz
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long int LL;
const int MAXN = 1000000;

int t, n;
char name[MAXN + 3];

int main()
{
    scanf("%d", &t);
    for(int pp=1; pp<=t; pp++)
    {
	scanf("%s", name);
	scanf("%d", &n);
	LL res = 0;
	int len = strlen(name), counter = 0, prev = 0;
	for(int i=0; i<len; i++)
	{
	    if(name[i]!='a' && name[i]!='e' && name[i]!='i' && name[i]!='o' && name[i]!='u')
		counter++;
	    else
		counter = 0;
	    
	    if(counter==n)
	    {
		res += (LL)(i-prev-n+2)*(LL)(len - i);
		counter--;
		prev = i - n + 2;
	    }
	}
	printf("Case #%d: %lld\n", pp, res);
    }

return 0;
}