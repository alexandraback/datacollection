#include <iostream>
#include <cstring>
#include <deque>
#include <cstdio>
using namespace std;
int main()
{
	freopen("Cin.in","r",stdin);
	freopen("Cout.txt","w",stdout);
	int T,N,M,K;
	cin>>T;
	for(int x=0;x<T;x++)
	{
		cin>>N>>M>>K;
		printf("Case #%d: ",x+1);
		//cout<<N<<endl;
		int i=-min(-M,-N);
		N=min(M,N),M=i;
		//cout<<N<<" "<<M<<endl;
		if(N<3)
			cout<<K<<endl;
		else if(N==3)
		{
			if(M==3)
			{
				if(K<=4)
					cout<<K<<endl;
				else 
					cout<<K-1<<endl;
			}
			if(M==4)
			{
				if(K<=4)
					cout<<K<<endl;
				else if(K>=5&&K<=7)
					cout<<K-1<<endl;
				else
					cout<<K-2<<endl;
			}
			if(M==5)
			{
				if(K<=4)
					cout<<K<<endl;
				else if(K>=5&&K<=7)
					cout<<K-1<<endl;
				else if(K>=8&&K<=10)
					cout<<K-2<<endl;
				else
					cout<<K-3<<endl;
			}
			if(M==6)
			{
				if(K<=4)
					cout<<K<<endl;
				else if(K>=5&&K<=7)
					cout<<K-1<<endl;
				else if(K>=8&&K<=10)
					cout<<K-2<<endl;
				else if (K>=11&&K<=13)
					cout<<K-3<<endl;
				else
					cout<<K-4<<endl;
			}
		}
		else if (N==4)
		{
			if(M==4)
			{
				if(K<=4)
					cout<<K<<endl;
				else if(K>=5&&K<=7)
					cout<<K-1<<endl;
				else if(K>=8&&K<=9)
					cout<<K-2<<endl;
				else if (K>=10&&K<=11)
					cout<<K-3<<endl;
				else
					cout<<K-4<<endl;
			}
			if(M==5)
			{
				if(K<=4)
					cout<<K<<endl;
				else if(K>=5&&K<=7)
					cout<<K-1<<endl;
				else if(K>=8&&K<=9)
					cout<<K-2<<endl;
				else if (K>=10&&K<=11)
					cout<<K-3<<endl;
				else if(K>=12&&K<=13)
					cout<<K-4<<endl;
				else if(K>=14&&K<=15)
					cout<<K-5<<endl;
				else
					cout<<K-6<<endl;
			}
		}
	}
	return 0;
}
