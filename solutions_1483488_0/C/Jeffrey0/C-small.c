#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <glib.h>

#define ep(...) fprintf(stderr, __VA_ARGS__)
int main(int argc, char **argv) {
	int cases = 0;
	scanf("%d\n", &cases);
	ep("%d cases.\n", cases);
	
	for(int cas = 0; cas < cases; ++cas) {
		int a, b, strl;
		int pairs = 0;
		char as[10];
		scanf("%d %d", &a, &b);
		sprintf(&as[0], "%d", a);
		strl = strlen(as);
		if(strl == 1) {
			ep("Can't shuffle 1-length strings.\n");
		}
		else {
			GHashTable *ht = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
			// possible numbers
			for(int n = a; n < b; ++n) {
				// construct m
				char morig[10];
				sprintf(&morig[0], "%d", n);
				// length of pairs to alter
				for(int i = 1; i < strl; ++i) {
					// source pos: always the end
					int j = strl - i;
					// can't move pairs that go beyond end of string
					if((j + i) > strl) {
						break;
					}
					
					char m[10];
					memset(m, 0, 10);
					
					memcpy(m, &morig[strl - i], i);
					memcpy(m + i, &morig[0], strl - i);
					
					// copy j chars from m
					int num = atoi(m);
					// a <= m is guaranteed since a <= n
					//ep("n=%d,num=%d,b=%d\n", n, num, b);
					if(n < num && num <= b) {
						gchar *pair = g_malloc(20);
						sprintf(&pair[0], "%d,%d", n, num);
						//ep("Pair (%d, %d) is recycled\n", n, num);
						if(g_hash_table_lookup(ht, pair) == NULL) {
							g_hash_table_insert(ht, pair, pair);
							++pairs;
						}
					}
				}
			}
			g_hash_table_destroy(ht);
		}
		printf("Case #%d: %d\n", cas + 1, pairs);
	}

	exit(0);
}