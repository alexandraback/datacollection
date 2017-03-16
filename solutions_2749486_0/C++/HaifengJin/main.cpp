#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

string a = "EW";
string b = "WE";
string c = "NS";
string d = "SN";
int x, y;

int main()
{
	freopen("t.txt", "r", stdin);
	freopen("y.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &x, &y);
		printf("Case #%d: ", i + 1);
		if (x > 0)
			for (int i = 0; i < x; i++)
				printf("%s", b.c_str());
		else
			for (int i = 0; i < -x; i++)
				printf("%s", a.c_str());
		if (y > 0)
			for (int i = 0; i < y; i++)
				printf("%s", d.c_str());
		else
			for (int i = 0; i < -y; i++)
				printf("%s", c.c_str());
		putchar('\n');

	}
}
