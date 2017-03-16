#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int case_id=0;case_id<T;case_id++)
	{
		long long N;
		int digit_find[10];
		for(int i=0;i<10;i++)
			digit_find[i]=0;
		cin>>N;
		long long number=N;
		bool find_all=true;
		while(1)
		{
			long long temp=number;
			while(temp>=10)
			{
				digit_find[temp%10]=1;
				temp/=10;
			}
			digit_find[temp%10]=1;

			find_all=true;
			for(int j=0;j<10;j++)
				find_all=find_all && digit_find[j];
			if(number==0)
				break;
			if(find_all)
				break;
			number+=N;
		}
		if(find_all)
			cout<<"Case #"<<case_id+1<<": "<<number<<endl;
		else
			cout<<"Case #"<<case_id+1<<": INSOMNIA"<<endl;
	}
	return 0;	
}