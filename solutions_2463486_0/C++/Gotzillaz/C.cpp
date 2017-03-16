#include<cstdio>
#include<cmath>
bool palin[10000]={false};

//Generate Palindrome
void genPalin()
{
	for(int i=0;i<10;i++)
	{
		palin[i] = true;
		palin[i*10+i] = true;
	}
	for(int i=10;i<1000;i++)
	{
		palin[i*10+(i/10)] = true;
	}
}

//Check Fair and Square Palindrome
bool chkFnP(double num)
{
	if(!palin[(int)num])
		return false;
	if(fmod(sqrt(num),1)!=0)
		return false;
	int sq = (int)sqrt(num);
	if(palin[sq])
		return true;
	else
		return false;
}
int main()
{
	int tt = 1;
	int testcase;
	int a,b,count;
	genPalin();
	scanf("%d",&testcase);
	while(tt<=testcase)
	{
		count = 0;
		scanf("%d%d",&a,&b);
		for(int i=a;i<=b;i++)
		{
			if(chkFnP((double)i))
				count++;
		}
		printf("Case #%d: %d\n",tt,count);
		tt++;
	}
	return 0;
}