#include <iostream>
#include <cstdio>
using namespace std;

int t;
double c, f, x;
double pro;
double sek;

int main()
{
	scanf("%d", &t);
	for (int h=1; h<=t; h++)
	{
		cin >> c >> f >> x;
		pro=2;
		sek=0;
		while(1)
		{
			if (x/pro<(c/pro)+(x/(pro+f)))
			break;
			sek+=(c/pro);
			pro+=f;
		}
		sek+=(x/pro);
		printf("Case #");
		printf("%d", h);
		printf(": ");
		printf("%f", sek);
		printf("\n");
	}
	return 0;
}
