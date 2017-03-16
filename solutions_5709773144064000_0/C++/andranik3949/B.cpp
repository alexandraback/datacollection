#include <fstream>
#include <iomanip>
using namespace std;

const double eps = 1e-10;

int main()
{
	ifstream cin("B-small-attempt0.in");
	ofstream cout("B-small-attempt0.out");
	int num;
	cin >> num;
	for ( int i = 0; i < num; i++ )
	{
		bool enough = false;
		double cost, farmProd, goal, seconds = 0., currProd = 2.;
		cin >> cost >> farmProd >> goal;
		if( goal - cost < eps )
		{
			seconds = goal / 2;
			enough = true;
		}
		while ( !enough )
		{
			seconds += cost / currProd;
			if( !( (goal - cost) / currProd - goal / ( currProd + farmProd ) < eps ) )
				currProd += farmProd;
			else
			{
				seconds += (goal - cost) / currProd;
				enough = true;
			}
		}
		cout << setprecision(7) << fixed << "Case #" << i + 1 << ": " << seconds << endl; 
	}
	return 0;
}