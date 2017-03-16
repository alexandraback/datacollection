#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int cas, cas_n, x, y, count;
	scanf("%d", &cas_n);
	for(cas=1; cas<=cas_n; cas++) {
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", cas);
		count = 1;
		while(1) {
			if(x > 0 && abs(x - count) < x) {
				x -= count;
				printf("%c", 'E');
			}
			else if( x < 0 && abs(x + count) < abs(x) ) {
				x += count;
				printf("%c", 'W');
			}
			else {
				break;
			}
			count++;
		}
		while(1) {
			if(y > 0 && abs(y - count) < y) {
				y -= count;
				printf("%c", 'N');
			}
			else if( y < 0 && abs(y + count) < abs(y) ) {
				y += count;
				printf("%c", 'S');
			}
			else {
				break;
			}
			count++;
		}

		while(1) {
			if(x > 0) {
				printf("%s", "WE");
				x--;
			}
			else if(x < 0) {
				printf("%s", "EW");
				x++;
			}
			else {
				break;
			}
		}
		while(1) {
			if(y > 0) {
				printf("%s", "SN");
				y--;
			}
			else if(y < 0) {
				printf("%s", "NS");
				y++;
			}
			else {
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
