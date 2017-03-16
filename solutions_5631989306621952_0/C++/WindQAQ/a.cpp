#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>

#define MAX 1024

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int i = 1; i <= T; i++){
		char str[MAX];
		scanf("%s", str);

		int len = strlen(str);
		deque <char> d;
		d.push_back(str[0]);
		for(int j = 1; j < len; j++){
			// printf("str[j] = %c\n", );
			if(d.front() <= str[j])
				d.push_front(str[j]);
			else
				d.push_back(str[j]);

		}

		printf("Case #%d: ", i);
		for(int j = 0; j < d.size(); j++)
			printf("%c", d[j]);
		printf("\n");
	}
}