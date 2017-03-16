#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
	int t,cas=0;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++cas<<": ";
		int n;
		cin>>n;
		double naomi[n],ken[n];
		for(int i=0;i<n;i++)
			cin>>naomi[i];
		for(int i=0;i<n;i++)
			cin>>ken[i];
		int ans1=-1;
		int ans2=n+1,c;
		bool f =true;
		sort(naomi,naomi+n);
		sort(ken,ken+n);
//		for(int i=0;i<n;i++)
//			cout<<naomi[i]<<" ";
//		cout<<endl;
//		for(int i=0;i<n;i++)
//			cout<<ken[i]<<" ";
//		cout<<endl;
		//(0.05,0.06) (0.13,0.15) (0.31,0.81) (0.34,0.87) (0.48,0.9) (0.92,0.16) 

		do {
			c=0;
			for(int i=0;i<n;i++)
				if(naomi[i]>ken[i])
					c++;
			if(c<ans2)
				ans2=c;
			if(c>ans1)
				ans1=c;
	//		if(c==2 && f)
	//		{
	//			for(int i=0;i<n;i++)
	//				cout<<"("<<naomi[i]<<","<<ken[i]<<") ";
	//			cout<<endl;
	//			f=false;
	//			cout<<"*"<<c<<endl;
	//		}
		} while (next_permutation(ken,ken+n) );
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}