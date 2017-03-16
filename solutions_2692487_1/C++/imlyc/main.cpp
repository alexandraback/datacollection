#include<iostream>
#include<fstream>
#include<stdint.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char ** argv) {
    //read
    ifstream file(argv[1]);
    //ifstream file("input.txt");
    ofstream ofile("output.txt");
    int T;
    file>>T;

    for(int i=0; i<T; i++) {
	long int s, num_motes;
	file >> s >> num_motes;
	vector<long int> mote_list(num_motes);
	for(long int j=0; j<num_motes; j++)
	    file >> mote_list[j];

	sort(mote_list.begin(), mote_list.end());

	long int min_num_op = num_motes;
	long int num_add = 0;
	long int num_delete = num_motes;


	for(long int j=0; j<num_motes; j++) {
	    if(s > mote_list[j] ) {
		s += mote_list[j];
		num_delete = num_motes-j-1;
	    } else {
		if(s == 1) break;
		s += s-1;
		num_add += 1;
		num_delete = num_motes-j-1;
		j--;
	    }




	    long num_op = num_add + num_delete;
	    
	    if(num_op < min_num_op)
		min_num_op = num_op;
	}

	//if(min_num_op == num_motes+1) min_num_op = 0;

	cout<< "Case #"<<i+1<<": "<<min_num_op<<endl;


    }
    return 0;
}
