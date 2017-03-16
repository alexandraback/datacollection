#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;
char a[500];
int b[500];
int main()
{
	ifstream ifile,ifile1;
	ofstream ofile;
	int i,j,y,n;
	char x;
	/*ofile.open("1.txt");
	n=0;
	while(1)
	{
		cin>>x;
		if (x=='1') break;
		a[++n]=x;
		
	}
	y=0;
	while(1)
	{
		cin>>x;
		if (x=='1') break;
		y++;
		b[a[y]-'a'+1]=x;
	}
	b[17]=26+'a'-1;
	b[26]=17+'a'-1;
	for(i=1;i<=26;i++)
		ofile<<i<<"  "<<b[i]-'a'+1<<endl;
	ofile.close();*/
	int t;
	ifile.open("A-small-attempt0.in");
	ifile1.open("1.txt");
	ofile.open("2.txt");
	ifile>>t;
	char s[100],s1;
	for(i=1;i<=26;i++)
		ifile1>>y>>b[i];
	ifile1.close();
	while(1)
	{
	  ifile.get(s1);
	  if (s1==10) break;
	}
	for(i=1;i<=t;i++)
	{
		ofile<<"Case #"<<i<<": ";
		
		while(1)
		{
			ifile.get(s1);
			if (s1==10) 
			{
				ofile<<endl;
				break;
			}
			if (s1==' ') 
			{
				ofile<<' ';
				continue;
			}
			ofile<<char(b[s1-'a'+1]+'a'-1);
		}
		//ifile>>s;
	}
	ifile.close();
	ofile.close();
	return 0;
}
