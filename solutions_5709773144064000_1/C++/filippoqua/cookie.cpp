#include <fstream>
#include <iomanip>

using namespace std;

double ti(double s, double ve)
{return s/ve;}

int main()
{
	int T;
	double c,f,x,tim,v;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> T;
	for(int i=1; i<=T; i++)
	{
		in >> c >> f >> x;
		tim=0;
		v=2;
		out << "Case #" << i << ": ";
		while(true)
		{
			
			if(ti(x,v)>ti(c,v)+ti(x,v+f))
			{
				tim+=ti(c,v);
				v+=f;
			}
			else
			{
				tim+=ti(x,v);
				break;
			}
		}
		out.precision(7);
		out << fixed << tim;
		out << endl;
	}
	return 0;
}
