#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char H[27];
int main()
{
	H['a'-'a']='y';
	H['b'-'a']='h';
	H['c'-'a']='e';
	H['d'-'a']='s';
	H['e'-'a']='o';
	H['f'-'a']='c';
	H['g'-'a']='v';
	H['h'-'a']='x';
	H['i'-'a']='d';
	H['j'-'a']='u';
	H['k'-'a']='i';
	H['l'-'a']='g';
	H['m'-'a']='l';
	H['n'-'a']='b';
	H['o'-'a']='k';
	H['p'-'a']='r';
 	H['q'-'a']='z';
	H['r'-'a']='t';
	H['s'-'a']='n';
	H['t'-'a']='w';
	H['u'-'a']='j';
	H['v'-'a']='p';
	H['w'-'a']='f';
	H['x'-'a']='m';
	H['y'-'a']='a';
	H['z'-'a']='q';

	int T;
	cin>>T;
       char str[150];
       for(int j=1;j<=T;j++)
	{
		

		scanf(" %[^\n]s",str);
		cout<<"Case #"<<j<<": ";
		for(int i=0;str[i]!=0;i++)
		{
			if(str[i]==' ')
				cout<<str[i];
			else
				cout<<H[str[i]-'a'];
		}
		cout<<endl;
	}


	return 0;
}

