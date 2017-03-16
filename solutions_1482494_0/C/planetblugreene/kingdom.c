#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct level_s {
	unsigned a;
	unsigned b;
	struct level_s * next;
} level;

int main() {
	unsigned t,n;
	//unsigned *a,*b;
	level * l;
	level *prev, *cur, *first;
	level * this_one, *that_one;
	unsigned i,j;
	
	unsigned stars;
	unsigned plays;
	unsigned this_s;
	char can_adv,do_one;
	
	scanf("%u\n",&t);
	for(i=1; i<=t; i++) {
		//read the testcase
		scanf("%u\n",&n);
		l = malloc(n*sizeof(level));
		//a = malloc(n*sizeof(unsigned));
		//b = malloc(n*sizeof(unsigned));
		for(j=0; j<n; j++) {
			//scanf("%u %u\n",a+j,b+j);
			scanf("%u %u\n",&(l[j].a),&(l[j].b));
			l[j].next = &(l[j+1]);
		}
		l[n-1].next = NULL;
		first = l;
		
		stars = 0;
		plays = 0;
		can_adv = 1;
		do_one = 0;
		this_one = NULL;
		
		//loop over the levels repeatedly
		while (stars < n*2 && can_adv) {
			cur = first;
			prev = first;
			can_adv = 0;
			//then, for a given level, if we can earn two stars from it, do it!
			while (cur) {
				//For a given level, if we can earn two stars from it, we might as well do so
				if(cur->a < 5000 && cur->a <= stars && cur->b < 5000 && cur->b <= stars) {
					stars += 2; plays ++;
					//remove this one from the linked list so we don't check it anymore
					prev->next = cur->next;
					if(cur == first) {
						first = cur->next;
					}
					can_adv = 1;
					break;
				}
				//if we have made it through all the way and couldn't advance two stars at once, but did note that we can advance a single star, then do that
				if(do_one) {
					if (this_one->a < 5000) {
						this_one->a = 6000;
						stars ++; plays ++;
						do_one = 0;
						can_adv = 1;
						break;
					}
					this_one->b = 6000;
					stars ++; plays ++;
					do_one = 0;
					can_adv = 1;
					//we've already played this one once, so it's done, so remove it
					if (this_one == first) {
						first = this_one->next;
					} else {
						that_one->next = this_one->next;
					}
					break;
					/*if (cur->a < 5000 && cur->a <= stars) {
						cur->a = 6000;
						stars ++; plays ++;
						do_one = 0;
						can_adv = 1;
						if (cur->b > 5000) {
							prev->next = cur->next;
							if(cur == first) {
								first = cur->next;
							}
						}
						break;//start again from the beginning
					}
					if (cur->b < 5000 && cur->b <= stars) {
						cur->b = 6000;
						stars ++; plays ++;
						do_one = 0;
						can_adv = 1;
						if (cur->a > 5000) {
							prev->next = cur->next;
							if(cur == first) {
								first = cur->next;
							}
						}
						break;//start again from the beginning
					}*/
				} else if(! can_adv) {//otherwise just note if this one will allow us to advance
					if(cur->a < 5000 && cur->a <= stars) {
						if (this_one) {
							if (cur->b > this_s) {
								this_one = cur;
								that_one = prev;
								this_s = cur->b;
							}
						} else {
							this_one = cur; that_one = prev;
							this_s = cur->b;
						}
						can_adv = 1;
					}
					if(cur->b < 5000 && cur->b <= stars) {
						can_adv = 1;
						this_one = cur;
						that_one = prev;
						this_s = 5000;
					}
				}
				prev = cur;
				cur = cur->next;
			}
			//if we exit the loop at the end of our list
			if ((!cur) && can_adv) {
				do_one = 1;
			}
		}
		
		if(!can_adv)
			printf("Case #%u: Too Bad\n",i);
		else
			printf("Case #%u: %u\n",i,plays);
		
		//leaking memory on purpose because malloc is complaining for some reason
		free(l);
		//free(a); free(b);
	}
	return 0;
}