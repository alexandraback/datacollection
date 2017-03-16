#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
	int case_number;
	ifstream ifs("B-large.in");
	ofstream ofs("out.txt");
	ifs >>case_number;
	double farm;
	double extra_get;
	double aim;
	double time;
	double farm_time;
	double rest_time;
	double get;
	for(int cases = 1; cases <= case_number; cases ++)
	{
		ifs>>farm>>extra_get>>aim;
		get = 2;
		time = 0;
		while(1)
		{
			farm_time = farm/get;
			rest_time = aim / get;
			if(farm_time + aim / (extra_get + get) < rest_time)
			{
				get += extra_get;
				time += farm_time;
			}
			else
			{
				time += rest_time;
				break;
			}
		}
		ofs<<"Case #"<<cases<<": "<< fixed<<setprecision(7)<<time<<endl;
	}
}