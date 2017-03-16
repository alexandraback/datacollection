#include<iostream>
using namespace std;
main()
{
	int T,j,k,N,S,p,factor,splfactor;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N>>S>>p;
		factor=3*p-2;
		if(factor<0)factor=0;
		splfactor=factor-2;
		if(splfactor<0)
		{		
			if(factor==1)
			splfactor=1;
			else
			splfactor=0;
		}
		int count=0,num;
		//cout<<factor<<endl;
		for(j=0;j<N;j++)
		{
			cin>>num;
			if(num>=factor)count++;
			else if(S>0)
			{
				if(num>=splfactor)
				{
				S--;
				count++;
				}
			}
		}

		cout<<"Case #"<<i+1<<": "<<count<<endl;
	}
	return 0;
}
