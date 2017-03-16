#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int case_id=0;case_id<T;case_id++)
	{
		int K,C,S;
		cin>>K>>C>>S;

		int faster=min(K,C);
		faster-=faster%2;
		faster/=2;
		if(2*min(S,faster)+max(S-faster,0)<K)
			cout<<"Case #"<<case_id+1<<": IMPOSSIBLE"<<endl;
		else
		{
			cout<<"Case #"<<case_id+1<<":";
			for(int i=0;i<min(S,faster);i++)
			{
				if(K-2*(i+1)<0)
					break;
				long long ans;
				ans=(i+1)*2+2*i*K;
				cout<<" "<<ans;
			}
			for(int i=0;i<max(S-faster,0);i++)
			{
				if(K-2*min(S,faster)-i-1<0)
					break;
				long long ans;
				ans=min(S,faster)*2+i+1;
				cout<<" "<<ans;
			}
			cout<<endl;
		}
	}
	
	return 0;	
}