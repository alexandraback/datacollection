#include <iostream>

using namespace std;

int counts(int j,int p,int s,int k)
{
	int q=j/k;
	int count=0;
			int q1=p/k;

			int n=0;
			while(n<q){
				for (int a = 0; a < k; a++)
				{
					int n1=0;
					while(n1<q1){
						for (int b = 0; b < k; b++)
						{
							for (int c = 0; c < k; c++)
							{
								count++;// cout<<a+1+n*k<<' '<<b+1+(n+n1)*k<<' '<<c+1+(n+n1)*k<<endl;
							}
						}
						n1++;
					}
					for (int b = q1*k; b < p; b++)
					{
						for (int c = 0; c < k && c < s-q1*k; c++)
						{
							count++;// cout<<a+1+n*k<<' '<<b+1+n*k<<' '<<c+1+q1*k+n*k<<endl;
						}
					}
				}
				n++;
			}

			for (int a = q*k; a < j; a++)
			{
				int n1=0;
					while(n1<q1){
						for (int b = 0; b < k; b++)
						{
							for (int c = 0; c < k; c++)
							{
								count++;// cout<<a+1<<' '<<b+1+(n1)*k<<' '<<c+1+(q+n1)*k<<endl;
							}
						}
						n1++;
					}
					for (int b = q1*k; b < p; b++)
					{
						for (int c = 0; c < k && c < s-q1*k-q*k; c++)
						{
							count++;// cout<<a+1<<' '<<b+1<<' '<<c+1+q1*k+q*k<<endl;
						}
					}
			}
			return count;
}

int main()
{
	int t;
	cin>>t;
	for (int i = 0; i < t; i++)
	{
		int j,p,s,k;
		cin>>j>>p>>s>>k;
		cout<<"Case #"<<i+1<<": ";
		if (s<=k)
		{
			cout<<s*p*j<<endl;
			for (int a = 0; a < j; a++)
			{
				for (int b = 0; b < p; b++)
				{
					for (int c = 0; c < s; c++)
					{
						cout<<a+1<<' '<<b+1<<' '<<c+1<<endl;
					}
				}
			}
		}
		else if (p<=k)
		{
			cout<<k*p*j<<endl;
			for (int a = 0; a < j; a++)
			{
				for (int b = 0; b < p; b++)
				{
					for (int c = 0; c < k; c++)
					{
						cout<<a+1<<' '<<b+1<<' '<<c+1<<endl;
					}
				}
			}
		}
		else if (j<=k)
		{
			int q=p/k;
			if(s-q*k>=k)
				cout<<j*(q*k*k+(p-q*k)*k)<<endl;
			else
				cout<<j*(k*q*k+(p-q*k)*(s-q*k))<<endl;
			
			for (int a = 0; a < j; a++)
			{
				int n=0;
				while(n<q)
				{
					for (int b = 0; b < k; b++)
					{
						for (int c = 0; c < k; c++)
						{
							cout<<a+1<<' '<<b+1+(n)*k<<' '<<c+1+(n)*k<<endl;
						}
					}
					n++;
				}

				for (int b = q*k; b < p; b++)
				{
					for (int c = 0; c < k && c < s-q*k; c++)
					{
						cout<<a+1<<' '<<b+1<<' '<<c+1+q*k<<endl;
					}
				}
			}
		}
		else
		{
			int q=j/k;
			int q1=p/k;
			cout<<counts(j,p,s,k)<<endl;
			int n=0;
			while(n<q){
				for (int a = 0; a < k; a++)
				{
					int n1=0;
					while(n1<q1){
						for (int b = 0; b < k; b++)
						{
							for (int c = 0; c < k; c++)
							{
								cout<<a+1+n*k<<' '<<b+1+(n+n1)*k<<' '<<c+1+(n+n1)*k<<endl;
							}
						}
						n1++;
					}
					for (int b = q1*k; b < p; b++)
					{
						for (int c = 0; c < k && c < s-q1*k; c++)
						{
							cout<<a+1+n*k<<' '<<b+1+n*k<<' '<<c+1+q1*k+n*k<<endl;
						}
					}
				}
				n++;
			}

			for (int a = q*k; a < j; a++)
			{
				int n1=0;
					while(n1<q1){
						for (int b = 0; b < k; b++)
						{
							for (int c = 0; c < k; c++)
							{
								cout<<a+1<<' '<<b+1+(n1)*k<<' '<<c+1+(q+n1)*k<<endl;
							}
						}
						n1++;
					}
					for (int b = q1*k; b < p; b++)
					{
						for (int c = 0; c < k && c < s-q1*k-q*k; c++)
						{
							cout<<a+1<<' '<<b+1<<' '<<c+1+q1*k+q*k<<endl;
						}
					}
				/*
				for (int b = 0; b < p-q*k && b < k; b++)
				{
					for (int c = 0; c < k && c < s-q*k; c++)
					{
						cout<<a+1<<' '<<b+1+q*k<<' '<<c+1+q*k<<endl;
					}
				}*/
			}	
			
		}
		// cout<<"Case #"<<i<<": "<<endl;
	}
	return 0;
}