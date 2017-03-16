#include<iostream>
#include<string>
using namespace std;

char k1[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
char k2[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char k3[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
char v1[] = "our language is impossible to understand";
char v2[] = "there are twenty six factorial possibilities";
char v3[] = "so it is okay if you want to just give up";

char key[255] = {};

char strin[100][200] = {};
char strout[100][200] = {};

void print_key()
{
	char ch;
	for(ch = 'a'; ch<='z';++ch) cout<<ch;cout<<endl;
	for(ch = 'a'; ch<='z';++ch)
	{
		cout<<key[ch];
	}
	cout<<endl;
}

void init_key()
{
	int i;
	for(i = 0; k1[i]!='\0'; ++i)
	{
		if(k1[i]>='a'&&k1[i]<='z'){
			key[k1[i]] = v1[i];
		}
	}
	
	for(i = 0; k2[i]!='\0'; ++i)
	{
		if(k2[i]>='a'&&k2[i]<='z'){
			key[k2[i]] = v2[i];
		}
	}

	for(i = 0; k3[i]!='\0'; ++i)
	{
		if(k3[i]>='a'&&k3[i]<='z'){
			key[k3[i]] = v3[i];
		}
	}
	key['q'] = 'z';
	key['z'] = 'q';
}

void read_line(char* s)
{

}

int main()
{
	init_key();

	freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
	
	int i,j,n;
	scanf("%d\n",&n);
	for(i = 0; i<n;++i)
	{
		gets(strin[i]);
		for(j=0;strin[i][j]!='\0';++j)
		{
			if(strin[i][j]>='a'&&strin[i][j]<='z'){
				strout[i][j] = key[strin[i][j]];
			}else{
				strout[i][j] = strin[i][j];
			}
		}
		strout[i][j] = '\0';
		printf("Case #%d: %s\n",i+1, strout[i]);
	}

	//system("pause");
	return 0;
}