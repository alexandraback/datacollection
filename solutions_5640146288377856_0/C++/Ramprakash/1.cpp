#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		int r,c,w,answer;
		cin>>r>>c>>w;
		answer = r*(c/w)+w;
		if(c%w==0)answer--;
		cout<<"Case #"<<k<<": "<<answer<<endl;
	}
	return 0;
}