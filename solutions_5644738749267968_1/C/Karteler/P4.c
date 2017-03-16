#include <stdio.h>
#include <stdlib.h>

void swap(float* a, float* b)
{
    float tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
 
int partition(float vec[], int left, int right)
{
    int i, j;
 
    i = left;
    for (j = left + 1; j <= right; ++j)
    {
        if (vec[j] > vec[left])
        {
            ++i;
            swap(&vec[i], &vec[j]);
        }
    }
    swap(&vec[left], &vec[i]);
 
    return i;
}
 
void quickSort(float vec[], int left, int right)
{
    int r;
 
    if (right > left)
    {
        r = partition(vec, left, right);
        quickSort(vec, left, r - 1);
        quickSort(vec, r + 1, right);
    }
}

int main (void) {
	int a, b;
	
	int cases;
	int currentCase;
	
	int numberBlocks;
	int tempNumberBlocks;
	int naomiDeceitWin;
	int naomiWin;
	
	float* naomi;
	float* ken;
	float* tempNaomi;
	float* tempKen;

	scanf("%d", &cases);
	for (currentCase = 1; currentCase <= cases; currentCase++) {
		naomiDeceitWin = 0;
		naomiWin = 0;
	
		scanf("%d", &numberBlocks);
		
		naomi = (float *) malloc (numberBlocks*sizeof(float));
		ken = (float *) malloc (numberBlocks*sizeof(float));
		tempNaomi = (float *) malloc (numberBlocks*sizeof(float));
		tempKen = (float *) malloc (numberBlocks*sizeof(float));
		
		for (a = 0; a < numberBlocks; a++) {
			scanf("%f", &naomi[a]);
		}
		for (a = 0; a < numberBlocks; a++) {
			scanf("%f", &ken[a]);
		}
		
		quickSort(naomi, 0, numberBlocks-1);
		quickSort(ken, 0, numberBlocks-1);
		for (a = 0; a < numberBlocks; a++) {
			tempNaomi[a] = naomi[a];
			tempKen[a] = ken[a];
		}
		
		tempNumberBlocks = numberBlocks;
		a = 0;
		while(1) {
			for (a = 0; a < tempNumberBlocks; ) {
				for (b = 0; b < tempNumberBlocks; b++) {
					if (tempNaomi[a] > tempKen[b]) {
						break;
					}
				}
				if (b == 0) {
					for ( ; b < tempNumberBlocks-1; b++) {
						tempNaomi[b] = tempNaomi[b+1];
					}
					naomiWin++;
				}
				else if (b > 0 && b < tempNumberBlocks) {
					for (b = b-1; b < tempNumberBlocks-1; b++) {
						tempKen[b] = tempKen[b+1];
					}
					for (b = 0; b < tempNumberBlocks-1; b++) {
						tempNaomi[b] = tempNaomi[b+1];
					}
				}
				tempNumberBlocks--;
			}
			if (tempNumberBlocks == 0) {
				break;
			}
		}
		for (a = 0; a < numberBlocks; a++) {
			if (naomi[a] > ken[a] && a == numberBlocks-1) {
				naomiDeceitWin = numberBlocks;
				numberBlocks = 0;
			}
			else if (naomi[a] < ken[a]) {
				for (b = 0; b < numberBlocks-1; b++) {
					ken[b] = ken[b+1];
				}
				a = -1;
				numberBlocks--;
			}
		}
		
		printf("Case #%d: %d %d\n", currentCase, naomiDeceitWin, naomiWin);
		
		free(naomi);
		free(ken);
		free(tempNaomi);
		free(tempKen);
	}
	return 0;
}