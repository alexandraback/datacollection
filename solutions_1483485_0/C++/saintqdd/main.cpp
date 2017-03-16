#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int mp[26];
int mp2[26];
char in1[200];
char in2[200];
void init()
{
mp[0]=24;
mp[1]=13;
mp[2]=5;
mp[3]=8;
mp[4]=2;
mp[5]=22;
mp[6]=11;
mp[7]=1;
mp[8]=10;
mp[9]=20;
mp[10]=14;
mp[11]=12;
mp[12]=23;
mp[13]=18;
mp[14]=4;
mp[15]=21;
mp[16]=25;
mp[17]=15;
mp[18]=3;
mp[19]=17;
mp[20]=9;
mp[21]=6;
mp[22]=19;
mp[23]=7;
mp[24]=0;
mp[25]=16;
for(int i=0;i<26;i++)
{
	mp2[mp[i]] = i;
}
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("b.txt","w",stdout);
	int T;
	init();
	scanf("%d",&T);
	getchar();
	for(int j=1;j<=T;j++)
	{
		gets(in1);
		int n = strlen(in1);
		for(int i=0;i<n;i++)
		{
			if(in1[i]!=' ' )
			{
				in2[i] = mp2[in1[i]-'a']+'a';
			}
			else
				in2[i] = ' ';
		}
		in2[n] = 0;
		printf("Case #%d: %s\n",j,in2);
	}
	return 0;
}