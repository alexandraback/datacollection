#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int start[2];
int speed[2];
int nn[2];


int check(){
	double time = (360-(double)start[0])/(double)speed[0];
	double time1 = (720-(double)start[1])/(double)speed[1];
	
	if(time >= time1)
		return 1;

	double time2 = (360-(double)start[1])/(double)speed[1];
	double time3 = (720-(double)start[0])/(double)speed[0];
	
	if(time2 >= time3)
		return 1;

	return 0;
}

int main()
{
	int n,N;
	ifstream fin("C-small-1-attempt5.in");
	//ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;

	for(n=0;n<N;n++){
		int num;
		fin>>num;
		int size = num;
		for(int i=0;i<num;i++){
			fin>>start[i]>>nn[i]>>speed[i];
			if(nn[i] == 2){
				start[i+1] = start[i];
				speed[i+1] = speed[i] + 1;
				size++;
			}
		}
		int count = check();
		fout<<"Case #"<<n+1<<": "<<count<<endl;
	}


	return 0;
}


//fout.setf(ios::fixed);
//fout.precision(6);