#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>

int main(int argc, char *argv[])
{
	std::ifstream read("B-small-attempt0.in");
	std::ofstream write("B-small-attempt0.out");
	int num=0;
	read >> num;
	double sec,farm,goal;
	for (int i=0;i<num;i++)
	{
		double persec=2.0;
		double timeToWin=0.0;
		double sumToBuyFarms=0.0;
		read >> std::fixed >> std::setprecision(7) >> farm >> sec >> goal;
		timeToWin=goal/persec;
		while((sumToBuyFarms + farm/persec + (goal)/(persec+sec))<timeToWin)
		{
			timeToWin=(sumToBuyFarms + farm/persec + (goal)/(persec+sec));
			sumToBuyFarms+=farm/persec;
			persec+=sec;
		}
		write << "Case #" << std::setprecision(7)  << std::fixed << i+1 << ": " << (double)timeToWin <<std::endl;
	}
	return 0;
}

