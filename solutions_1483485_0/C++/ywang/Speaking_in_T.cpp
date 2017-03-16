#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
//char a[] = "yhesocv xduiglb kr  tnw jpf ma"//q&z
//char R[] = "yhesocvxduiglbkrqtnwjpfmaz";//q&z
char R[] = "yhesocvxduiglbkrztnwjpfmaq";//q&z
char a[200];
int main()
{
	int T;
	scanf("%d",&T);
	fgets(a, 150, stdin);
	int c=0;
	while(T--)
	{
		c++;
		cout << "Case #"<<c<<": ";
		fgets(a, 150, stdin);
		if(a[strlen(a)-1]=='\n')
			a[strlen(a)-1] = 0;
		int Len = strlen(a);
		for(int i=0;i<Len;++i)
		{
			if(a[i]<='z' && a[i]>='a')
				cout << R[a[i]-'a'];
			else
				cout << a[i];
		}
		cout << endl;
	}
}
