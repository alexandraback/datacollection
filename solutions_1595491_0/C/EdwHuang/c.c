#include <stdio.h>

struct trip {
	int a, b, c, type;
};

struct trip trip_make(int i)
{
	struct trip t;
	t.a = i / 3;
	t.b = i / 3;
	t.c = i / 3;
	t.type = i - 3 * (i / 3);
	switch (t.type) {
	case 2:
		t.b++;
	case 1:
		t.a++;
	case 0:
		break;
	default:
		fprintf(stderr, "trip_make: wtf?");
		break;
	}
	return t;
}

int main(void)
{
	int N, S, p, t[100];
	char buf[1024];
	char numbuf[10];
	int i, j, k;
	int count, maybe;
	struct trip trp;
	while(fgetc(stdin) != '\n');
	while (fgets(buf, 1024, stdin)) {
		for (i = 0; i < 100; i++) t[i] = 0;
		i = 0;
		for (j = 0; ; i++, j++) {
			if (buf[i] == '\0' || buf [i] == '\n' || buf[i] == ' ') {
				i++;
				break;
			}
			numbuf[j] = buf[i];
		}
		numbuf[j] = '\0';
		N = atoi(numbuf);
		for (j = 0; ; i++, j++) {
			if (buf[i] == '\0' || buf [i] == '\n' || buf[i] == ' ') {
				i++;
				break;
			}
			numbuf[j] = buf[i];
		}
		numbuf[j] = '\0';
		S = atoi(numbuf);
		for (j = 0; ; i++, j++) {
			if (buf[i] == '\0' || buf [i] == '\n' || buf[i] == ' ') {
				i++;
				break;
			}
			numbuf[j] = buf[i];
		}
		numbuf[j] = '\0';
		p = atoi(numbuf);
		count = 0;
		maybe = 0;
		for (k = 0; k < N; k++) {
			for (j = 0; ; i++, j++) {
				if (buf[i] == '\0' || buf [i] == '\n' || buf[i] == ' ') {
					i++;
					break;
				}
				numbuf[j] = buf[i];
			}
			numbuf[j] = '\0';
			t[k] = atoi(numbuf);
			trp = trip_make(t[k]);
			if (trp.a >= p) count++;
			else if ((trp.a == p - 1) && (trp.b >= 1) && (trp.type == 2 || trp.type == 0)) maybe++;
		}
		if (maybe >= S) maybe = S;
		printf("%d\n", count + maybe);
	}
}
