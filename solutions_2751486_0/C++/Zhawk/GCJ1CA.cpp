#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#define LL long long int

using namespace std;

char str[1000005];
int voice[100005];
bool check(char s)
{
	if(s=='a')
		return false;
	if(s=='e')
		return false;
	if(s=='i')
		return false;
	if(s=='o')
		return false;
	if(s=='u')
		return false;
	return true;
}
int main(void)
{
	int vn;
	int T;
	int L,n;
	scanf("%d",&T);
	int i,j,k;
	for(i=1;i<=T;i++)
	{
		scanf("%s %d",str,&n);
		L = strlen(str);
		memset(voice,0,sizeof(voice));
		vn  = 0;
		for(j=0;j<L;j++)
		if(check(str[j]))
			voice[vn++] = j;
		
		LL 	sum = 0;
		LL pt = 0;
		LL cur = 0;
		LL lastend = 0;
		for(j=0;j<vn;)
		{
			if(voice[j+n-1] != voice[j]+n-1)
			{
				j++;
			}
			else
			{
				
				cur = voice[j];
				sum += (cur-lastend+1)*(L-(cur+n)+1);
				lastend = cur+1;
				j++;
			}
		}
		printf("Case #%d: %lld\n",i,sum);
	}



	return 0;
}
