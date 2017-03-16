#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
	ifstream ifs("A-small-attempt0.in");
	ofstream ofs("ans_a_1.txt");

	int cc;
	ifs >> cc;
	for(int loop=0;loop<cc;loop++){
		int r,t;
		ifs >> r >> t;
		int count = 0;
		while(true){
			int uset = (r+1)*(r+1) - r*r;
			if(t >= uset){
				count++;
				t -= uset;
				r += 2;
			}else{
				break;
			}
		}
		ofs << "Case #" << (loop+1) << ": " << count << endl;
	}
	ofs.close();
}