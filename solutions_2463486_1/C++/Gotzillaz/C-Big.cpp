#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

long long palin[50000000]={0};
long long point = 0;
//Generate Palindrome
void looping(long long i)
{
	long long tmp = i;
	long long pal = i;
	while(tmp>0)
	{
		pal*=10;
		pal+=tmp%10;
		tmp/=10;
	}
	//if(pal<10000000)
	//printf("ggg%I64dggg",pal);
	char a;
	//scanf("%c",&a);
	palin[point] = pal;
	point++;
	//palin[pal]=true;
	pal = i;
	tmp = i/10;
	while(tmp>0)
	{
		pal*=10;
		pal+=tmp%10;
		tmp/=10;
	}
	palin[point] = pal;
	point++;
	//palin[pal]=true;
}

void genPalin()
{
	for(long long i=1;i<10;i++)
	{
		palin[point] = i;
		palin[point+1] = i*10+i;
		point+=2;
		//palin[i] = true;
		//palin[i*10+i] = true;
	}
	//printf("aa");
	for(long long i=10;i<10000;i++)
	{
		//palin[i*10+(i/10)] = true;
		looping(i);
		//printf("%I64d ",i);
	}
}

//Check Fair and Square Palindrome
long long chkFnP(long long fr,long long bk)
{
	long long count = 0;
	long long i = 0;
	while(palin[i]*palin[i]<fr)
		i++;
	while(palin[i]*palin[i]<=bk)
	{
		//printf("-%I64d-\n",palin[i]);
		long long tmp = palin[i]*palin[i];
		long long pal = 0;
		while(tmp>0)
		{
			pal*=10;
			pal+=tmp%10;
			tmp/=10;
		}
		if(pal == palin[i]*palin[i])
			count++;
		i++;
	}
	return count;
}

int main()
{
	long long tt = 1;
	long long testcase;
	long long a,b,count;
	genPalin();
	sort(palin,palin+point);
	//printf("==%I64d==",palin[point-1]);
	scanf("%I64d",&testcase);
	while(tt<=testcase)
	{
		//count = 0;
		scanf("%I64d%I64d",&a,&b);
		count = chkFnP(a,b);
		printf("Case #%I64d: %I64d\n",tt,count);
		tt++;
	}
	return 0;
}