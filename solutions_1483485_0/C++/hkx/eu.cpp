#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);freopen("out.txt","w",stdout);
	char str[1000];
	int T,cas=0;
	scanf("%d\n",&T); 
	while(T--)
	{
		cas++;
		printf("Case #%d: ",cas);
		gets(str);
		//puts(str);
		int i;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='a') cout<<"y";
			else if(str[i]=='b') cout<<"h";
			else if(str[i]=='c') cout<<"e";
			else if(str[i]=='d') cout<<"s";
			else if(str[i]=='e') cout<<"o";
			else if(str[i]=='f') cout<<"c";
			else if(str[i]=='g') cout<<"v";
			else if(str[i]=='h') cout<<"x";
			else if(str[i]=='i') cout<<"d";
			else if(str[i]=='j') cout<<"u";
			else if(str[i]=='k') cout<<"i";
			else if(str[i]=='l') cout<<"g";
			else if(str[i]=='m') cout<<"l";
			else if(str[i]=='n') cout<<"b";
			else if(str[i]=='o') cout<<"k";
			else if(str[i]=='p') cout<<"r";
			else if(str[i]=='q') cout<<"z";
			else if(str[i]=='r') cout<<"t";
			else if(str[i]=='s') cout<<"n";
			else if(str[i]=='t') cout<<"w";
			else if(str[i]=='u') cout<<"j";
			else if(str[i]=='v') cout<<"p";
			else if(str[i]=='w') cout<<"f";
			else if(str[i]=='x') cout<<"m";
			else if(str[i]=='y') cout<<"a";
			else if(str[i]=='z') cout<<"q";
			else cout<<str[i];
		}
		//for(i=0;str[i]!='\0';i++) cout<<str[i];
		cout<<endl;
	} 
	return 0;
} 
