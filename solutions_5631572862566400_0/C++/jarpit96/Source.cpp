#include <iostream>

using namespace std;

struct bff_struct
{
	int val;       //index of bff
	bool status;  //1 means in the circle
};

int main() 
{
	int t, n, left_element = 0, right_element = 0, temp=0, flag=0, count = 0;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		count = flag = 0;
		cin>>n;
		bff_struct bff[n+1];
		for(int j=1; j<=n; j++)
		{
			cin>>bff[j].val;
			bff[j].status = 0;
		}
		
		bff[1].status = 1;
		bff[bff[1].val].status = 1;
		left_element = 1;
		right_element = bff[1].val;
	
		while(1)
		{
			if(bff[bff[right_element].val].status == 0)
			{
				bff[bff[right_element].val].status = 1;
				temp = bff[right_element].val;
				right_element = temp;
			}
			
			else break;
		}
		
		while(1)
		{
			if(bff[bff[left_element].val].status == 0)
			{
				bff[bff[left_element].val].status = 1;
				temp = bff[left_element].val;
				left_element = temp;
			}
			
			else break;
		}
		
		while(1)
		{
			
			flag = 0;
			
			for(int a=1; a<=n; a++)
			{
				if(bff[a].val == right_element && bff[a].status == 0)
				{
					bff[a].status = 1;
					right_element = a;
					flag = 1;
					break;
				}
			}
			
			if(flag == 0)
			{
				break;
			}
			
		}
		
		
		while(1)
		{
			
			flag = 0;
			
			for(int b=1; b<=n; b++)
			{
				if(bff[b].val == left_element && bff[b].status == 0)
				{
					bff[b].status = 1;
					left_element = b;
					flag = 1;
					break;
				}
			}
			
			if(flag == 0)
			{
				break;
			}
			
		}		
		
		
		for(int c=1; c<=n; c++)
		{
			if(bff[c].status == 1)
			{
				count++;
			}
		}
		
		cout<<"Case #"<<i+1<<": "<<count<<endl;
		
	}
	return 0;
}