#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

string org =
	"ejpmysljylckdkxveddknmcrejsicpdrysi"
	"rbcpcypcrtcsradkhwyfrepkymveddknkmkrkcd"
	"dekrkdeoyakwaejtysrreujdrlkgcjv";

string des =
	"ourlanguageisimpossibletounderstand"
	"therearetwentysixfactorialpossibilities"
	"soitisokayifyouwanttojustgiveup"
;

int mapping[256];
int used[256];

char buffer[1000];

int main()
{
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	for (int i = 0; i < org.size(); i++)
	{
		mapping[org[i]] = des[i];
		used[des[i]] = 1;
	}

	mapping['y'] = 'a';
	mapping['e'] = 'o';
	mapping['q'] = 'z';

	used['a'] = used['o'] = used['z'] = 1;

	for (int i = 'a'; i <= 'z'; i++)
	{
		if (used[i] == 0)
		{
			for (int j = 'a'; j <= 'z'; j++)
			{
				if (mapping[j] == 0)
					mapping[j] = i;
			}
		}
	}


	gets(buffer);
	int n = atoi(buffer);

	for (int i = 0; i < n; i++)
	{
		printf("Case #%d: ", i+1);
		gets(buffer);
		for (int j = 0; buffer[j]; j++)
		{
			putchar(buffer[j]>='a'&&buffer[i]<='z'?mapping[buffer[j]]:buffer[j]);
		}
		putchar('\n');
	}

	return 0;


	return 0;
}