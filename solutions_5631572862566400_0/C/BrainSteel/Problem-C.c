/*
 
 Google Code Jam Round 1A
 April 15, 2016
 
 Jesse Pritchard
 Public contact: chaserdevelopment@gmail.com
 
 Problem C
 
 */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

#define INT_ARRAY_SIZE(N) ((sizeof(int) * (N)))

typedef struct list {
    int* data;
    int num;
    int satisfied;
} intlist;

intlist listinit() {
    intlist result;
    result.num = 0;
    result.data = NULL;
    result.satisfied = 0;
    return result;
}

void listadd(intlist* list, int item) {
    list->num++;
    list->data = realloc(list->data, INT_ARRAY_SIZE(list->num));
    list->data[list->num - 1] = item;
}

intlist getstartcaps(intlist* find) {
    intlist result = listinit();
    
    int* seen = malloc(INT_ARRAY_SIZE(find->num));
    memset(seen, 0, INT_ARRAY_SIZE(find->num));
    
    int i;
    for (i = 0; i < find->num; i++) {
        seen[find->data[i]] = 1;
    }
    
    for (i = 0; i < find->num; i++) {
        if (!seen[i]) {
            listadd(&result, i);
        }
    }
    
    free(seen);
    return result;
}

intlist getpath(int* list, int N, int start) {
    int* used = malloc(INT_ARRAY_SIZE(N));
    memset(used, 0, INT_ARRAY_SIZE(N));
    
    intlist result = listinit();
    listadd(&result, start);
    
    int last = start;
    int done = 0;
    while (!done) {
        if (list[last] == start || result.data[result.num - 1] == list[last]) {
            result.satisfied = 1;
            break;
        }
        else if (used[list[last]]) {
            break;
        }
        else {
            listadd(&result, list[last]);
            used[last] = 1;
            last = list[last];
        }
    }
    
    free(used);
    return result;
}

int getfirstintersection(intlist one, intlist two, int* indexone, int* indextwo) {
    int i, j;
    int val = -1;
    for (i = 0; i < one.num; i++) {
        for (j = 0; j < two.num; j++) {
            if (one.data[i] == two.data[j]) {
                if (indexone) {
                    *indexone = i;
                }
                if (indextwo) {
                    *indextwo = j;
                }
                val = one.data[i];
                goto DONE;
            }
        }
    }
    
DONE:
    return val;
}

int main() {
    long num, iii;
    scanf(" %ld", &num);
    for (iii = 0; iii < num; iii++) {
        
        int N;
        scanf(" %d", &N);
        
        intlist input = listinit();
        input.data = malloc(INT_ARRAY_SIZE(N));
        input.num = N;
        int i;
        for (i = 0; i < N; i++) {
            scanf(" %d", &input.data[i]);
            input.data[i]--;
        }
        
        intlist caplist = getstartcaps(&input);
        
        intlist* lists = malloc(sizeof(intlist) * caplist.num);
        
        int largest = caplist.num;
        for (i = 0; i < input.num; i++) {
            intlist test = getpath(input.data, input.num, input.data[i]);
            if (test.satisfied) {
                largest = test.num > largest ? test.num : largest;
            }
        }
        
        for (i = 0; i < caplist.num; i++) {
            lists[i] = getpath(input.data, input.num, caplist.data[i]);
            if (lists[i].satisfied) {
                largest = lists[i].num > largest ? lists[i].num : largest;
            }
        }
        
        int j;
        for (i = 0; i < caplist.num; i++) {
            for (j = i + 1; j < caplist.num; j++) {
                int first, second;
                int intersect = getfirstintersection(lists[i], lists[j], &first, &second);
                if (intersect > -1) {
                    largest = first + second + 1 > largest ? first + second + 1 : largest;
                }
            }
        }
        
        
        printf("Case #%ld: %d\n", iii + 1, largest);
        
        free(input.data);
        free(caplist.data);
        for (i = 0; i < caplist.num; i++) {
            free(lists[i].data);
        }
        free(lists);
    }
    return 0;
}

