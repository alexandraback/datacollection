#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;

set<pii> travelers;
set<int> speeds;
int N;
int calc()
{
	
	int spds[2],pos[2];
	
	int p=0;
	
	
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int di,hi,mi;
		cin>>di>>hi>>mi;
		for(int j=0;j<hi;j++)
		{
			travelers.insert(make_pair(mi+j,di));
			speeds.insert(mi+j);
			
			spds[p]=mi+j;
			pos[p]=di;
			p++;
		}
	}
	//int minc=travelers.size();
	//if(speeds.size()==1)return 0;
	//if(minc>=3)return -1;
	
	if(spds[1]>spds[0])
	{
		int tmp=spds[0];spds[0]=spds[1];spds[1]=tmp;
		tmp=pos[0];pos[0]=pos[1];pos[1]=tmp;
	}
	cerr<<"spds:"<<spds[0]<<":"<<spds[1]<<endl;
	cerr<<"pos:"<<pos[0]<<":"<<pos[1]<<endl;
	
	double time0=(360.0-pos[0])/(360.0)*spds[0];
	double time1=(360.0-pos[1])/(360.0)*spds[1];
	cerr<<"time01:"<<time0<<":"<<time1<<endl;
	if(time0<time1)return 0;
	double time2=(720.0-pos[1])/(360.0)*spds[1];
	
	cerr<<"time02:"<<time0<<":"<<time2<<endl;
	if(time0>time2)return 1;
	return 0;
}

int main()
{
	
	//cout<<calc();return 0;
	int N;cin>>N;
	for(int i=0;i<N;i++)
		cout<<"Case #"<<(i+1)<<": "<<calc()<<endl;
	return 0;
}