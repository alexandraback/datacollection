#include <iostream>
#include <cmath>
using namespace std;



void main(){
	//Input 3 of testcases
	int T;
	cin >> T;

	int D; //diners
	int * P; //Plates of Pancakes
	int y; //time to eat pancakes
	int Pmax; //maximum pancakes on plate in a testcase
	int ymin; //minimum completion time for a testcase
	for (int t = 1; t <= T; t++)
	{	
		//Get inputs for testcase
		cin >> D;
		P = new int[D];
		Pmax = 0;
		for (int d = 0; d < D; d++){
			cin >> P[d];
			if (P[d]>Pmax)Pmax = P[d]; //Set maximum pancakes
		}

		ymin = Pmax;
		for (int p = 1; p<Pmax; p++)
		{
			y = p;
			for (int d = 0; d < D; d++){
				y += (int)ceil(((double)P[d]) / (double)p) - 1;
			}
			if (y < ymin)ymin = y;
			
		}
		cout << "Case #" << t << ": " << ymin << endl;
	}


}