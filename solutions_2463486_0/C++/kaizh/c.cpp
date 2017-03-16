#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool rec[1010]={false};

bool isPal(int x)
{
	if(x%10==0)return false;
	char buf[10];
	sprintf(buf,"%d",x);
	int low=0,high=strlen(buf)-1;
	while(low<high)
	{
		if(buf[low]!=buf[high])
			return false;
		low++;high--;
	}
	return true;
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i*i<=1000;i++)
		if(isPal(i)&&isPal(i*i))
			rec[i*i]=true;
	for(int t=1;t<=T;t++)
	{
		int A,B;
		int cnt=0;
		cin>>A>>B;
		for(int i=A;i<=B;i++)
			if(rec[i])
				cnt++;
		cout<<"Case #"<<t<<": "<<cnt<<endl;
	}
	return 0;
}
