//Time:4/14/2012
//Author:PiAnte28
//Language:C++
//For Google Code Jam Speaking in Tongues
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

char rec[30];

int main()
{
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	rec[25]='a';
	rec[14]='b';
	rec[6]='c';
	rec[9]='d';
	rec[3]='e';
	rec[23]='f';
	rec[12]='g';
	rec[11]='i';
	rec[21]='j';
	rec[15]='k';
	rec[13]='l';
	rec[24]='m';
	rec[19]='n';
	rec[5]='o';
	rec[22]='p';
	rec[16]='r';
	rec[4]='s';
	rec[18]='t';
	rec[10]='u';
	rec[7]='v';
	rec[20]='w';
	rec[8]='x';
	rec[1]='y';
	
	rec[2]='h';
	rec[17]='z';
	rec[26]='q';
	int tt,hehe;
	scanf("%d\n",&tt);hehe=tt;
	while (tt--)
	{
	    string temp;
		getline(cin,temp);
		printf("Case #%d: ",hehe-tt);
		for (int i=0;i<=temp.size()-1;i++)
		if (temp[i]==' ') printf(" ");else printf("%c",rec[temp[i]-'a'+1]);
		printf("\n");
	}
	return 0;
}
