#include<cstdio>
#include<algorithm>
using namespace std;

int t;
char str[30][110];
char map[128];

int freq[128];
void count(char *s)
{
	for(;*s;s++) freq[*s]++;
}

const char word[]="airtonslcupmdhgbfvwkxzj";

void printfreq()
{
	FILE *fout=fopen("map.txt","w");
	pair<int,char> a[26];
	int tot=0;
	for(int i='a';i<='z';i++)
	{
		tot+=freq[i];
		a[i-'a']=make_pair(freq[i],i);
	}
	sort(a,a+26);
	int p=0;
	for(int i=25;i>=0;i--)
	{
		if(!map[a[i].second]) map[a[i].second]=word[p++];
		fprintf(fout,"%c %c %lf\n",a[i].second,map[a[i].second],(double)a[i].first/tot*100);
	}
	fclose(fout);
}

int main()
{
	map['a']='y';
	map['o']='e';
	map['z']='q';

	scanf("%d ",&t);
	for(int i=0;i<t;i++)
	{
		gets(str[i]);
		count(str[i]);
	}

	printfreq();
	return 0;
}

