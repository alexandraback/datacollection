/*Consonants*/

#include<cstdio>
#include<set>
#include<cstring>

using namespace std;

char str[1000005];
int seq[1000005];
set<int> start_points;

bool isconsonent(char);

int main()
{
	int i,j,length,n,T;
	long long count;
	set<int>::iterator iter;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		start_points.clear();
		scanf("%s %d",str,&n);
		length=strlen(str);
		if(isconsonent(str[0]))
			seq[0]=1;
		else
			seq[0]=0;
		for(j=0;j<length;j++)
		{
			if(isconsonent(str[j]))
				seq[j]=seq[j-1]+1;
			else
				seq[j]=0;
		}
		for(j=0;j<length;j++)
			if((seq[j]>=1) && (j+n<=length) && (seq[j+n-1]-seq[j]==n-1))
				start_points.insert(j);
		count=0;
		for(j=0;j<length;j++)
		{
			if(start_points.find(j)!=start_points.end())
				count+=(length-j)-n+1;
			else
			{
				iter=start_points.lower_bound(j);
				if(iter!=start_points.end())
					count+=(length-j)-((*iter)-j+n)+1;
			}
		}
		printf("Case #%d: %lld\n",i,count);
	}
	return 0;
}

bool isconsonent(char ch)
{
	if((ch!='a') && (ch!='e') && (ch!='i') && (ch!='o') && (ch!='u'))
		return true;
	else
		return false;
}