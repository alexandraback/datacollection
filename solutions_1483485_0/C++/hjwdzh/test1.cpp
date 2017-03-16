#include "bind.h"
#include <assert.h>
string st1 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
string st2 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char a[1000];
int main()
{
	bind("A-small-attempt0");
	for (int i = 0; i < st2.length(); i++)
	{
		a[st2[i]] = st1[i];
	}
	a[' '] = ' ';
	a['z'] = 'q';
	a['q'] = 'z';
	int n;
	char buf[200];
	inf.getline(buf,200);
	convert(buf, n);
	for (int k = 0; k < n; k++)
	{
		inf.getline(buf, 200);
		ouf << "Case #" << k + 1 << ": ";
		for (int i = 0; buf[i] != '\0'; i++)
			ouf << a[buf[i]];
		ouf << "\n";
	}
}

