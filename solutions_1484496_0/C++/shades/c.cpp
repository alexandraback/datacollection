#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
int main()
{
	int tttt;
	cin>>tttt;
	map<int,int> mymap;
	for(int ttt=1;ttt<=tttt;ttt++)
	{
		mymap.clear();
		cout<<"Case #"<<ttt<<":\n";
		int a[20];
		cin>>a[0];
		for(int i=0;i<20;i++)
			cin>>a[i];
		for(int i=1;i<=((1<<20)-1);i++)
		{
			int sum=0;
			for(int j=0;j<20;j++)
			{
				if((i&(1<<j))!=0)
					sum+=a[j];
			}
	//		cout<<"sum "<<sum<<endl;
			if(mymap[sum]==0)
				mymap[sum]=i;
			else
			{
				for(int j=0;j<20;j++)
					if((i&(1<<j))!=0)
						cout<<a[j]<<" ";
				cout<<endl;
				for(int j=0;j<20;j++)
					if((mymap[sum]&(1<<j))!=0)
						cout<<a[j]<< " " ;
				cout<<endl;
			break;
			}

		}



	}

}
