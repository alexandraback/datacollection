#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=110;

int main()
{
	freopen("B-small.in","r",stdin);
	freopen("output.txt","w+",stdout);
	int cas, c;
	int i;
	int num, s_num, p;
	int min1, min2, ans;
	int left, right;
	scanf("%d",&cas);
	c=1;
	while(c<=cas)
	{
		int tot_point[N];
		ans=0;
		memset(tot_point, 0, sizeof(tot_point));
		scanf("%d%d%d",&num,&s_num,&p);
		for(i=0;i<num;i++)
		{
			scanf("%d",tot_point+i);
			tot_point[i]-=p;
		}
		sort(tot_point, tot_point+num);
		if(2*p-4>=0)
			min1=2*p-4;
		else
			min1=0;
		if(2*p-2>=0)
			min2=2*p-2;
		else
			min2=0;
		right=num-1;
		while(right>=0&&tot_point[right]>=min2)
		{			
			right--;
		}		
		left=right;
		while(left>=0&&tot_point[left]>=min1)
		{
			left--;
		}
		left++;
		if(s_num>=right-left+1)
			ans=num-left;
		else		
			ans=num-right-1+s_num;
		printf("Case #%d: %d\n",c,ans);
		c++;
	}
	return 0;
}
