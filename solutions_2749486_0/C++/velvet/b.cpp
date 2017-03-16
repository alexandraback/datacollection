#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int x,y;
void calc()
{
	string ret;
	if (x>0)
		for (int i=0;i<x;i++) printf("WE");
	else if (x<0)
		for (int i=0;i<-x;i++) printf("EW");

	if (y>0)
		for (int i=0;i<y;i++) printf("SN");
	else if (y<0)
		for (int i=0;i<-y;i++) printf("NS");
}
int main()
{
	int T;
	cin>>T;
	for (int run=1;run<=T;run++)
	{
		cin>>x>>y;
		printf("Case #%d: ",run);
		calc();
		cout<<endl;
	}
	return 0;
}
