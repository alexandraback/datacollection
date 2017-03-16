#include<iostream>
#include<cstdio>

using namespace std;

void myPrint(char *l)
{
	if(!l[0])
		return;
	int i, max, ch;
	ch = l[0];
	max = 0;
	for(i = 1; l[i]; i++)
	{
		if(l[i]>=ch)
		{
			ch = l[i];
			max = i;
		}
	}
	cout<< l[max];
	l[max] = 0;
	myPrint(l);
	cout<< (l+max+1);
}

int main()
{
	int T;
	char line[1010];
	gets(line);
	sscanf(line, "%d", &T);
	for(int t=1; t<=T; t++)
	{
		gets(line);
		cout<<"Case #"<<t<<": ";
		myPrint(line);
		cout<<endl;
	}
	return 0;
}
