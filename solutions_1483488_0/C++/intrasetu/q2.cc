#include<iostream>
using namespace std;
main()
{
	int T,j,k;
	int A,B;
	cin>>T;
	int power[]={0,1,10,100,1000,10000,100000,1000000};

	for(int i=0;i<T;i++)
	{
		cin>>A>>B;
		//finding number of digits
		int tmp=A;
		int num_dig=0;
		while(tmp!=0)
		{
			num_dig++;
			tmp/=10;
		}
		//number of digits found
		int factor=power[num_dig];
		int count=0;

		for(j=A;j<=B;j++)
		{
			int num=j;
			int flag[num_dig];
			int local_count=0;
			for(k=1;k<num_dig;k++)
			{
				int rem=num/factor;
				num%=factor;
				num*=10;
				num+=rem;
				if(num>j && num<=B)
				{
					int dum=1;
					for(int l=0;l<local_count;l++)
					{
						if(num==flag[l])
						{
							dum=0;
							break;
						}
					}
					if(dum)
					{
					count++;
					flag[local_count++]=num;
					}
					
				}

			}
		}

		cout<<"Case #"<<i+1<<": "<<count<<endl;
	}
	return 0;
}
