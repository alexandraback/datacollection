#include <stdio.h>

int main () {
	freopen ("output.txt" , "w" , stdout);
	freopen ("A-small-attempt3.in" , "r" , stdin);
	char tr[] = "yhesocvxduiglbkrztnwjpfmaq", c;
	int tt, i;
	scanf ("%d" , &tt);
	getchar ();
	for (i = 1 ; i <= tt ; i++) {
		printf ("Case #%d: " , i);
		for (c = getchar () ; c != '\n' ; c = getchar ()) {
			putchar (c == ' ' ? ' ' : tr[c - 'a']);
		}
		puts ("");
	}
}