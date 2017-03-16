#include<cstdio>
#include<iostream>

using namespace std;

void translate(char*);

int main()
{
	int t, i;
	char a[101];
	cin>>t;
	cin.ignore(10, '\n');
	for ( i=0; i<t; i++)
	{
		gets(a);
		translate(a);
		cout<<"Case #"<<i+1<<": ";
		puts(a);
	}
	return 0;
}

void translate(char* x)
{
	for( int i=0; x[i]; i++)
	{
		switch(x[i])
		{
		case 'a':
			x[i] = 'y';
			break;
		case 'b':
			x[i] = 'h';
			break;
		case 'c':
			x[i] = 'e';
			break;
		case 'd':
			x[i] = 's';
			break;
		case 'e':
			x[i] = 'o';
			break;
		case 'f':
			x[i] = 'c';
			break;
		case 'g':
			x[i] = 'v';
			break;
		case 'h':
			x[i] = 'x';
			break;
		case 'i':
			x[i] = 'd';
			break;
		case 'j':
			x[i] = 'u';
			break;
		case 'k':
			x[i] = 'i';
			break;
		case 'l':
			x[i] = 'g';
			break;
		case 'm':
			x[i] = 'l';
			break;
		case 'n':
			x[i] = 'b';
			break;
		case 'o':
			x[i] = 'k';
			break;
		case 'p':
			x[i] = 'r';
			break;
		case 'q':
			x[i] = 'z';
			break;
		case 'r':
			x[i] = 't';
			break;
		case 's':
			x[i] = 'n';
			break;
		case 't':
			x[i] = 'w';
			break;
		case 'u':
			x[i] = 'j';
			break;
		case 'v':
			x[i] = 'p';
			break;
		case 'w':
			x[i] = 'f';
			break;
		case 'x':
			x[i] = 'm';
			break;
		case 'y':
			x[i] = 'a';
			break;
		case 'z':
			x[i] = 'q';
			break;
		}
	}
}