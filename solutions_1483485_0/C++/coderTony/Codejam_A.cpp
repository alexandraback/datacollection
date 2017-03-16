//acm header include 
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

//Input 
//3
//ejp mysljylc kd kxveddknmc re jsicpdrysi
//rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
//de kr kd eoya kw aej tysr re ujdr lkgc jv
//
//
//
//--------------------------------------------------------------------------------
//
//
//Output  
//Case #1: our language is impossible to understand
//Case #2: there are twenty six factorial possibilities
//Case #3: so it is okay if you want to just give up



char table[36] = "yhesocvxduiglbkrztnwjpfmaq";
//char a[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv", 
	 //b[] = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
//"abcdefghijklmnopqrstuvwxyz"
//"yhesocvxduiglbkrztnwjpfmaq";
int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//for (int i=0; i<sizeof(a); ++i) if(a[i] != ' ') table[a[i]] = b[i];

	int T;
	char x[120];
	scanf("%d", &T);
	cin.getline(x, 120);
	for (int t=1; t<=T; ++t)
	{
		cin.getline(x, 120);
		printf("Case #%d: ", t);
		for (int i=0; i<120 && x[i] != 0; ++i)
		{
			if (!isalpha(x[i])) printf(" ");
			else printf("%c", table[x[i]-'a']);
		}
		printf("\n");
	}
}
