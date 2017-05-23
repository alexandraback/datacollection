#include <iostream>
#include <fstream>
#include <cmath>
#include <map>


using namespace std;

int main(int argc, char* argv[])
{
	ifstream in("l.in");
	ofstream out("l.out");
	cin.sync_with_stdio(false);
	int N,A,B,actual,mult,mod,test,digitos,solution,caso=1;
	map<int,bool> soluciones;
	in>>N;
	while(N--)
	{
		in>>A >>B;
		solution=0;
		for(actual=A;actual<B;actual++)
		{
			test=actual;
			digitos=(int) log10((double)test)+1;
			mult=pow((double)10, digitos-1);
			soluciones.clear();
			for(int i=1;i<digitos;i++)
			{
				mod=test%10;
				test=(int) (test/10) + (mod *mult );
				if( (test >A) && (test<=B) && (test > actual)  )
				{
					soluciones[test]=true;

				}

			}
			solution+=soluciones.size();
		}
		out<<"Case #"<<caso<<": "<<solution<<'\n';
		caso++;
	}
	return 0;
}

