#include<iostream>
#include<fstream>
using namespace std;

int main(){

	ifstream ifile;
	ofstream ofile;

	ifile.open("A-large.in");
	ofile.open("outputA_Large.out");

	int total_test_cases = 0;
	int input_R=0;
	int input_C = 0;
	int input_W = 0;
	int count = 0;
	int initial = 0;
	ifile >> total_test_cases;

	for (int case_no = 1; case_no <= total_test_cases; case_no++)
	{
		count = 0;

		ifile >> input_R;
		ifile >> input_C;
		ifile >> input_W;

		initial = input_W;

		while (initial <= input_C){
			count++;
			initial += input_W;
		}
		initial -= input_W;
//		initial++;
		count *= input_R;
		if(initial <input_C){
			count++;
		}
		count += (input_W - 1);

		ofile << "Case #" << case_no << ": " << count << endl;
	}
}