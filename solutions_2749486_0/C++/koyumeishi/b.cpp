#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
#define REP(i,n) for (int i=0; i<n; i++)
using namespace std;



int main(int argc, char *argv[]){
	int testcase=0;	//Nth test
	int T;	//testcase
	cout << "input file: " << argv[1] << endl;
	ifstream inputfile(argv[1]);
	ofstream outputfile("output.txt");
	
	inputfile >> T;
	
	REP(i,T){
		int X,Y;
		testcase++;
		inputfile >> X >> Y;
		int mx=0,my=0;
		string result;
		
		while(mx != X){
			if(mx > X){
				mx--;
				result += "EW";
			}else if(mx < X){
				mx++;
				result += "WE";
			}
		}
		while(my != Y){
			if(my > Y){
				my--;
				result += "NS";
			}else if(my < Y){
				my++;
				result += "SN";
			}
		}
		
		
		cout << "Case #" << testcase << ": " << result << endl;
		outputfile << "Case #" << testcase << ": " << result << endl;
	}
	return 0;
}