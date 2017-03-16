#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int T;
  cin>>T;
	for (int t = 0;t<T;t++)
	{
		cout<<"Case #"<<t+1<<": ";
		int A;
		int B;
		cin>>A>>B;
		double probs[A+2];
		double pro[A+1];
		double ans[5];
		for (int i = 0;i<A;i++)
			cin>>probs[i];
		pro[0] = 1;
		for (int i = 1;i<A+1;i++)
		{
			pro[i] = pro[i-1]*probs[i-1];
			//cout<<pro[i]<<endl;

		}
		ans[0] = 1+B+1;
		for (int i = 0;i<A+1;i++)
		{
		 // cout<<endl<<endl<<i<<endl;
			//cout<<pro[A-i]<<' '<<(i+i+B-A+1)<<' '<<(i+i+B-A+1+B+1)<<endl;
			ans[i+1] = pro[A-i]*(i+i+B-A+1)+(1.0-pro[A-i])*(i+i+B-A+1+B+1);
			//cout<<ans[i+1]<<endl;
		}

		
		
		double answer = 1+B+1;
		for (int i = 0;i<A+2;i++)
		{
			//cout<<ans[i]<<endl;
			answer = min(answer,ans[i]);
		}
		cout<< fixed << setprecision(6)<<answer<<endl;
	}
	return 0;
}
