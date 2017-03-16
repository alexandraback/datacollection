#include <stdio.h>
#include <malloc.h>

#define MAXS 2100
#define SIZE 26

char toparse[][15] = {"ZERO Z 0",
"TWO W 2",
"SIX X 6",
"EIGHT G 8",
"THREE H 3",
"FOUR U 4",
"FIVE F 5",
"SEVEN S 7",
"ONE O 1",
"NINE I 9"};

int *digits[10];
char unique[10];
int order[10];

int *transform(char *s)
{
	int *table = (int *) calloc(SIZE, sizeof(*table));
	for (int i=0; s[i]; i++){
		char c = s[i] - 'A';
		table[c]++;
	}

	return table;
}

void preload(void)
{
	for (int i=0; i<10; i++){
		char name[10], c; int a;
		sscanf(toparse[i], "%s %c %d", name, &c, &a);
		unique[i] = c - 'A';
		digits[i] = transform(name);
		order[i] = a;
	}
}

void vyres(){
	char s[MAXS];
	scanf("%s", s);
	int *t = transform(s);

	int counts[10];
	for (int i=0; i<10; i++){
		int count = t[unique[i]];
		counts[order[i]] = count;
		for (int j=0; j<SIZE; j++)
			t[j] -= count * digits[i][j];
	}

	for (int i=0; i<10; i++){
		for (int j=0; j<counts[i]; j++)
			printf("%d", i);
	}

	free(t);
}


int main(void)
{
	preload();
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		printf("Case #%d: ", i + 1);
		vyres();
		printf("\n");
	}
}
