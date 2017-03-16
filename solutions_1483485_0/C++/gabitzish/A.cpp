#include <cstdio>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	string alphabet = "yhesocvxduiglbkrztnwjpfmaq";
	int N;
	scanf("%d\n", &N);
	for (int i = 1; i <= N; i++) 
	{
		printf("Case #%d: ", i);
		char c;
		do {
			scanf("%c", &c);
			if (c == '\n' || c == ' ') printf("%c", c);
			else printf("%c", alphabet[c - 'a']);
		} while (c != '\n');
	}
	return 0;
}

/*
a - y   h - b	o - e	v - g
b - n	i - k  	p - v	w - t
c - f	j - u	q - z	x - h
d - i	k - o	r - p	y - a
e - c	l - m	s - d	z - q
f - w	m - x	t - r	
g - l	n - s	u - j	
*/