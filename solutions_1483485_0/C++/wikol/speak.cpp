#include <cstdio>
#include <cstring>

using namespace std;

char T[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

char G[200];

int main()
{
	int Z;
	scanf("%d\n", &Z);
	for(int ca = 1;ca<=Z;ca++)
	{
		scanf("%[^\n]\n", G);
		int n = strlen(G);
		for(int i = 0;i<n;i++)
			if(G[i] != ' ')
				G[i] = T[G[i]-'a'];
		printf("Case #%d: ", ca);
		for(int i = 0;i<n;i++)
			printf("%c", G[i]);
		printf("\n");
	}
}
