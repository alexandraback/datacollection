#include <stdio.h>

char otestuj(int cislo, char *pole)
{
	char s = 0;
	while (cislo > 0){
		int c = cislo % 10;
		if (!pole[c])
			s++;

		pole[c] = 1;
		cislo /= 10;
	}
	
	return s;
}

void vyres(void)
{
	int n;
	scanf("%d", &n);
	if (!n){
		printf("INSOMNIA\n");
		return;
	}

	char byly[10];
	for (int i=0; i<10; i++)
		byly[i] = 0;

	char kolik = 0;
	int i = 1;
	for (; kolik < 10; i++)
		kolik += otestuj(n * i, byly);

	printf("%d\n", (i - 1) * n);
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		printf("Case #%d: ", i+1);
		vyres();
	}
}
