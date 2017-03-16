#include<stdio.h>
#include<set>
#include<string.h>
#include<vector>

using namespace std;

set<int> H;
char str[111];
char str1[111], str2[111];

vector<long long> S;

void Make(int x)
{
	int l1, l2;
	sprintf(str1,"%d",x);
	sprintf(str2,"%d",x);
	l1=0;
	l2=strlen(str2)-1;
	while(l1<l2)
	{
		char temp=str2[l1];
		str2[l1]=str2[l2];
		str2[l2]=temp;
		l1++;
		l2--;
	}
	sprintf(str,"%s%s",str1,str2);
	int temp;
	sscanf(str,"%d",&temp);
	if(temp > 10000000) return;
	if(temp < 0) fprintf(stderr,"-_-\n");
	H.insert(temp);
}

void Make(int x, int y)
{
	int l1, l2;
	sprintf(str1,"%d",x);
	sprintf(str2,"%d",x);
	l1=0;
	l2=strlen(str2)-1;
	while(l1<l2)
	{
		char temp=str2[l1];
		str2[l1]=str2[l2];
		str2[l2]=temp;
		l1++;
		l2--;
	}
	sprintf(str,"%s%d%s",str1,y,str2);
	int temp;
	sscanf(str,"%d",&temp);
	if(temp > 10000000) return;
	if(temp < 0) fprintf(stderr,"-_-\n");
	H.insert(temp);
}

int main(void)
{
	int l1, l2;

	for(l1=1;l1<=9;l1++) H.insert(l1);
	for(l1=1;l1<=999;l1++)
	{
		Make(l1);
		for(l2=0;l2<=9;l2++)
		{
			Make(l1, l2);
		}
	}

	set<int>::iterator it;
	for(it=H.begin();it!=H.end();++it)
	{
		long long val = (long long)(*it);
		val = val * val;
		sprintf(str,"%lld",val);
		l1 = 0;
		l2 = strlen(str) - 1;
		while(l1 < l2)
		{
			if(str[l1] != str[l2]) break;
			l1++;
			l2--;
		}
		if(l1 >= l2)
		{
			S.push_back(val);
		}
	}
	int N = (int)S.size();

	int T, l0;
	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{
		long long A, B;
		scanf("%lld %lld",&A,&B);
		int ret = 0;
		for(l1=0;l1<N;l1++) if(A <= S[l1] && S[l1] <= B) ret++;
		printf("Case #%d: %d\n",l0,ret);
	}
	return 0;
}
