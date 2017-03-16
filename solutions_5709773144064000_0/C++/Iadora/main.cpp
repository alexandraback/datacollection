#include<iostream>
#include<fstream>
#include <math.h>

using namespace std;

int main(int argc, char** argv){

	if(argc<3){

		return -1;
	}

	ifstream fichier_input(argv[1], ios::in);
	ofstream fichier_output(argv[2], ios::out);
	fichier_output.precision(15);
	
	if(!fichier_input){

		cout <<"ERROR"<<endl;
		return -1;
	}

	int n_step;
	fichier_input>> n_step;

	for(int step=1; step <=n_step; step++){

		double C, F, X;

		fichier_input >> C >> F >> X;

		double crit_v = X/C -2/F;
		int n_crit = (int) crit_v;

		if(floor(crit_v)==crit_v){

			n_crit-=1;
		}

		if(X<=C || F<0){

			n_crit=0;
		}

		double t =X/(2+n_crit*F);
		for(int i=0; i< n_crit; i++){

			t += C/(2+i*F);
		}

		fichier_output << "Case #" << step << ": " << t<<endl;
		cout << t <<endl;
	}

	fichier_input.close();
	fichier_output.close();

	return 0;
}
