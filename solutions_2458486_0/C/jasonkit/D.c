#include "stdio.h"

int main ()
{
	int t,i;

	scanf("%d", &t);

	for (i=0; i<t; i++) {
		int k,n,j;
		int key_avaliable[401] = {0};
		int key_needed[401] = {0};
		int key_in_chest[200][401] = {{0}};
		int key_to_open[200] = {0};

		scanf("%d %d", &k, &n);
		
		for (j=0; j<k; j++) {
			int key;
			scanf("%d", &key);
			key_avaliable[key]++;
		}

		for (j=0; j<n; j++) {
			int t,k,m;
			
			scanf("%d %d", &t, &k);
			key_needed[t]++;
			key_to_open[j] = t;

			for(m=0; m<k; m++) {
				int key;
				scanf("%d", &key);
				key_in_chest[j][key]++;
			}
		}

		int queue[200] = {0};
		int queue_idx = 0;
		
		int chest_in_queue[200] = {0};
		int bt_idx = 0;

		while (queue_idx < n) {
			int has_update = 0;

			for (j=bt_idx; j<n; j++) {
				if (chest_in_queue[j]) {
					continue;
				}

				int ko = key_to_open[j];
				if (key_avaliable[ko] > 0) {
					if ((key_avaliable[ko] + key_in_chest[j][ko]) >= key_needed[ko]) {
						int i;

						for(i=1; i<=400; i++) {
							key_avaliable[i] += key_in_chest[j][i];
						}

						key_needed[ko]--;
						key_avaliable[ko]--;
						
						queue[queue_idx] = j;
						queue_idx++;
						chest_in_queue[j] = 1;
						has_update = 1;
						break;
					}
				}
			}

			if (!has_update) {
				if (queue_idx == 0) {
					break;
				}

				int chest_to_remove = queue[queue_idx-1];
				int i;
				int ko = key_to_open[chest_to_remove];

				bt_idx = chest_to_remove+1;
				queue_idx--;

				key_needed[ko]++;
				key_avaliable[ko]++;
				
				for(i=1; i<=400; i++) {
					key_avaliable[i] -= key_in_chest[chest_to_remove][i];
				}
			}
		}

		if (queue_idx < n) {
			printf("Case #%d: IMPOSSIBLE\n", i+1);
		}else if (queue_idx > n) {
			printf("ERROR!!!!\n");
		}else{
			int j;
			printf("Case #%d:", i+1);
			
			for(j=0; j<n; j++) {
				printf(" %d",queue[j]+1);
			}
			printf("\n");
		}
	}

	return 0;
}
