#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <deque>
#include <vector>
using namespace std;
int main(int argc, char **argv) {
	FILE *fp = fopen(argv[1], "r");
	int max, i; 
	fscanf(fp, "%d\n", &max);

	for(i=1;i<=max;i++) {
		deque<char> list;
		char c;
		fscanf(fp, "%c", &c);
		list.push_front(c);
		while (c != '\n') {
			fscanf(fp, "%c", &c);
			if (list.front() <= c)
				list.push_front(c);
			else
				list.push_back(c);
		}
		printf("Case #%d: ", i);
		while (!list.empty()) {
			printf("%c", list.front());
			list.pop_front();
		}
	}
}
