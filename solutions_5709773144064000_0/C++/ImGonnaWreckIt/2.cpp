#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<math.h>
#include <iomanip>

using namespace std;

int main()
{
	int i,j,k;
	int T;
	double C,F,X,cur,limit;
	double min_time,cur_ans,cur_speed;
	int flag[17];
	ifstream ip("B-small-attempt0.in");;
	ofstream op("output.txt");
	
	limit=pow(10,-6);
	//limit=-1*limit;
	cout<<limit<<"\n";
	ip>>T;
	for(k=1;k<=T;k++)
	{
		op<<"Case #"<<k<<": ";
		ip>>C>>F>>X;
		min_time=X/2;
		cur_ans=C/2;
		cur_speed=2+F;
		while(1)
		{
		      if(k==2)
			cout<<min_time<<"\t"<<cur_ans<<"\t"<<cur_ans+X/cur_speed<<"\t"<<cur_speed<<"\n";
		      if(cur_ans+X/cur_speed-min_time>0 || min_time-cur_ans+X/cur_speed<limit)
			break;
		      min_time=cur_ans+X/cur_speed;
		      cur_ans=cur_ans+C/cur_speed;
		      cur_speed=cur_speed+F;		
		}
		op<<setprecision(11)<<min_time<<"\n";		
	}
	return 0;
}
