#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>

using namespace std;




int main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		printf("Case #%d: ",t+1);
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);

		if(n<=2 or m<=2)
		{
			printf("%d\n",k);
			continue; 
		}
		if(m<n)
		{
			int t = m;
			m = n;
			n = t;
		}
		if(k<5)
			{printf("%d\n",k);continue;}

		int max_area = (n-2)*(n-2)+4*(n-2), max_length = n-2;
		if(k<=max_area){
			int l = 0;
			for(int i=1;(i+4)*i<=k;i++)
			{
				l = i;
			}
			if(k>=(l+1)*l+2*l+2*(l+1))
			{
				int left = (k-((l+1)*l+2*l+2*(l+1)));
				//printf("A %d %d\n",left);
				if(left>0)
					printf("%d\n",2*l+2*(l+1)+1);
				else if (left == 0)
					printf("%d\n",2*l+2*(l+1));
			}
			else
			{
				int left = (k-(l*l+4*l));
				//printf("B %d\n",left);
				
				if(left>0)
					printf("%d\n",4*l+1);
				else if(left==0)
					printf("%d\n",4*l);
			}
		}
		else if(k<=(m-2)*(n-2)+2*(m-2)+2*(n-2)){
			int l = 0;
			for(int i=max_length;max_length*i+2*i+2*max_length<=k;i++)
				l = i;
			int left = k-(2*max_length+2*l+l*max_length);
			if(left>0)
				printf("%d\n",2*max_length+2*l+1);
			else
				printf("%d\n",2*max_length+2*l);
		}
		else{
			printf("%d\n",2*(m-2)+2*(n-2)+k-((m-2)*(n-2)+2*(m-2)+2*(n-2)));
		}
		
	}
	return 0;
}