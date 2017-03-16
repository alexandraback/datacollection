#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
using namespace std;

int arr[10000];
using namespace std;

int main()
{
	int t;
	freopen("C:\\Users\\Gaurav\\Desktop\\uu.in","r",stdin);
    freopen("C:\\Users\\Gaurav\\Desktop\\output.txt","w",stdout);
    int i,j;
	scanf("%d",&t);
	int ca=0;
	while(t--)
	{
		ca++;
		int d;
		scanf("%d",&d);
		priority_queue<int> pq;
		for(i=0;i<d;i++){
			scanf("%d",&arr[i]);
			pq.push(arr[i]);
		}
		int min=10000000;
		for(i=1;i<=1000;i++){
			int cur=0;
			for(j=0;j<d;j++){
				if(arr[j]%i==0)
					cur=cur+arr[j]/i-1;
				else
					cur=cur+arr[j]/i;
			}
			cur=cur+i;
			if(cur<min)
				min=cur;
		}
		printf("Case #%d: %d\n",ca,min);
	}
	return 0;
}