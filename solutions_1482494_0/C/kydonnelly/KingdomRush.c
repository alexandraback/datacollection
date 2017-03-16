#include <stdio.h>
#include <stdlib.h>

typedef struct _list {
	int val1, val2;
	struct _list *next;
} list;

int main(void) {
	unsigned int cases, kingdoms, *first, *second, moves, stars;
	list *l, *prev;
	
	scanf("%u", &cases);
	
	for (int z=1; z<=cases; z++) {
		scanf("%u", &kingdoms);
		
		moves = 0;
		stars = 0;
		
		first = malloc(sizeof(unsigned int)*kingdoms);
		second = malloc(sizeof(unsigned int)*kingdoms);
		
		l = malloc(sizeof(list) * kingdoms);
	
		for (int i=0; i<kingdoms; i++) {
			scanf("%u %u", &(first[i]), &(second[i]));
		}
		
		l->val1 = first[0];
		l->val2 = second[0];
		l->next = NULL;
		
		for (int i=1; i<kingdoms; i++) {
			list *iter;
			for (iter = l; iter && iter->val2 < second[i]; iter = iter->next) {				
				prev = iter;
			}
			for (iter; iter && iter->val2 == second[i] && iter->val1 < first[i]; iter = iter->next) {
				prev = iter;
			}
			if (iter == NULL) {
				iter = malloc(sizeof(list));
				iter->val1 = first[i];
				iter->val2 = second[i];
				iter->next = NULL;
				prev->next = iter;
			}
			else {
				list *temp = malloc(sizeof(list));
				temp->val1 = iter->val1;
				temp->val2 = iter->val2;
				temp->next = iter->next;
				iter->next = temp;
				iter->val1 = first[i];
				iter->val2 = second[i];
			}
		}
		
		list *max_elem;
		do {
		
		unsigned int prev_moves;
		
		do {
			prev_moves = moves;
			for (list *iter = l; iter != NULL; iter = iter->next) {
				if (iter->val2 <= stars && iter->val2 >= 0) {
					moves++;
					stars++;
					if (iter->val1 >= 0) {
						stars++;
					}
					if (iter->next) {
						iter->val1 = iter->next->val1;
						iter->val2 = iter->next->val2;
						iter->next = iter->next->next;
					}
					else {
						iter->val1 = -1;
						iter->val2 = -1;
					}
				}
			}
		} while (prev_moves != moves);
		
		unsigned int max = 0;
		max_elem = NULL;
		for (list *iter = l; iter != NULL; iter = iter->next) {
			if (iter->val1 >= 0 && iter->val1 <= stars) {
				if (iter->val2 - iter->val1 >= max) {
					max_elem = iter;
				}
			}
		}
		if (max_elem != NULL) {
			moves++;
			stars++;
			max_elem->val1 = -1;
		}
		} while (max_elem != NULL);
		
		list *iter;
		for (iter=l; iter!=NULL; iter=iter->next) {
			if (iter->val2 >= 0) {
				printf("Case #%d: Too Bad\n", z);
				break;
			}
		}
		if (iter == NULL) {
			printf("Case #%d: %u\n", z, moves);
		}
	}
	return 0;
}