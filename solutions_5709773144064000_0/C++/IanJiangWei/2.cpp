#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double speedupTime(double c,double f,double x,double &speed,double &already_time)
{
	already_time+=(c/speed);
	speed+=f;
	return already_time+x/speed;
}

double deal(double c,double f,double x)
{
	double now_speed=2;
	double min_time=x/now_speed;
	double already_time=0;
	double s_time=speedupTime(c,f,x,now_speed,already_time);
	while(s_time<min_time)
	{
		min_time=s_time;
		s_time=speedupTime(c,f,x,now_speed,already_time);
	}
	return min_time;	
}

int main()
{
	int cas_num;
	ifstream infile("B-small-attempt0 (1).in");
	ofstream outfile("bresult.txt");
	infile>>cas_num;
	double c,f,x;
	outfile.setf(ios::fixed);
	for (int i=0;i<cas_num;i++)
	{
		infile>>c>>f>>x;
		outfile<<"Case #"<<i+1<<": "<<setprecision(7)<<deal(c,f,x)<<endl;
	}

	outfile.close();
	infile.close();
	return 0;
}