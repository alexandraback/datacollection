#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ll long long

char a[20], b[20];
int n;

#define ABS(a) ((a) > 0 ? (a) : (-a))
ll difference(char *one, char *two)
{
	ll sum = 0;
	for (int i=0; i<n; i++){
		sum *= 10;
		sum += one[i] - two[i];
	}

	return sum;
}

bool bigger(char *one, char *two){
	return (difference(one, two) > 0);
}

bool equal(char *one, char *two){
	return difference(one, two) == 0;
}

ll adifference(char *one, char *two)
{
	return ABS(difference(one, two));
}

ll nearest(char *ideal, char *adj, bool reverse){
	bool done = true;
	for (int i = 0; i<n; i++){
		if (adj[i] == 10){
			done = false;
			break;
		}
	}

	if (done)
		return adifference(ideal, adj);

}

char ma[20], mb[20];
ll m;

void printout(char s[20]){
	for (int i=0; i<n; i++)
		printf("%d", s[i]);
}

void printline(char s[20], char t[20])
{
	printout(s);
	printf(" ");
	printout(t);
	printf("\n");
}

void update(char la[20], char lb[20]){
	ll d = adifference(la, lb);
	if (d > m)
		return;

	if (d == m){
		if (bigger(la, ma))
			return;

		if (equal(la, ma) && bigger(lb, mb))
			return;
	}

	m = d;
	for (int i=0; i<n; i++){
		ma[i] = la[i];
		mb[i] = lb[i];
	}
}
	
void maximise(char small[20], char big[20]){
	for (int i=0; i<n; i++){
		if (small[i] == 10)
			small[i] = 9;

		if (big[i] == 10)
			big[i] = 0;
	}
}

void minimise(char big[20], char small[20]){
	maximise(small, big);
}
		
void rec(int pos, char la[20], char lb[20])
{
	if (pos >= n)
		update(la, lb);

	/* We are assuming a[0..pos-1] = b[0..pos-1] */
	char ra[20], rb[20];
	for (int i=0; i<n; i++){
		ra[i] = la[i];
		rb[i] = lb[i];
	}

	if (ra[pos] != 10 && rb[pos] != 10){
		if (ra[pos] == rb[pos])
			return rec(pos + 1, ra, rb);

		if (ra[pos] < rb[pos])
			maximise(ra, rb);
		else
			minimise(ra, rb);
		update(ra, rb);

		return;
	}

	if (ra[pos] == 10 && rb[pos] == 10){
		ra[pos] = 0; rb[pos] = 1; rec(pos, ra, rb);
		ra[pos] = 1; rb[pos] = 0; rec(pos, ra, rb);
		ra[pos] = 0; rb[pos] = 0; rec(pos, ra, rb);
	}

	if (ra[pos] == 10){
		if (rb[pos] > 0){
			ra[pos] = rb[pos] - 1; rec(pos, ra, rb);
		}

		ra[pos] = rb[pos]; rec(pos, ra, rb);
		if (rb[pos] < 9){
			ra[pos] = rb[pos] + 1; rec(pos, ra, rb);
		}
	} else { /* rb[pos] == 10 */
		if (ra[pos] > 0){
			rb[pos] = ra[pos] - 1; rec(pos, ra, rb);
		}

		rb[pos] = ra[pos]; rec(pos, ra, rb);
		if (ra[pos] < 9){
			rb[pos] = ra[pos] + 1; rec(pos, ra, rb);
		}
	}
}

void vyres(void)
{
	scanf("%s %s", a, b);
	n = strlen(a);
	m = 1e18;
	for (int i=0; i<n; i++){
		if (a[i] == '?')
			a[i] = '9' + 1;
		if (b[i] == '?')
			b[i] = '9' + 1;

		a[i] -= '0';
		b[i] -= '0';
	}
	rec(0, a, b);
	printline(ma, mb);
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		printf("Case #%d: ", i + 1);
		vyres();
	}
}
