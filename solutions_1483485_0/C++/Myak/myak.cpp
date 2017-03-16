#include <iostream>

using namespace std;

char mas[]={'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
char s[111]={0};

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n;
	cin >> n;
	getchar();
	for (int i=1; i<=n; i++)
	{
		cout << "Case #" << i << ": ";
		gets(s);
		int len=strlen(s);
		for (int j=0; j<len; j++)
		{
			if (s[j]>='a' && s[j]<='z')
				cout << mas[s[j]-'a'];
			else
				cout << s[j];
		}
		cout << "\n";
	}
	return 0;
}