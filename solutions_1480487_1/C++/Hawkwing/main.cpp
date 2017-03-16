/*
 * File:   main.cpp
 * Author: hawkwing
 *
 * Created on May 5, 2012, 9:09 AM
 */

#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	ifstream in("/home/hawkwing/Desktop/CJ_1B/A/A-large.in");
	ofstream out("/home/hawkwing/Desktop/CJ_1B/A/A-large.out");
	int T;
	in >> T;
	for(int i=0;i<T;i++){
		int N;
		in >> N;
		vector<int> contestants;
		vector<double> percent;
		int sum=0;
		for(int j=0;j<N;j++){
			int temp;
			in >> temp;
			contestants.push_back(temp);
			sum+=contestants[j];
		}
		for(int j=0;j<N;j++){
			percent.push_back((2.0/N-double(contestants[j])/sum)*100);
		}
		int n=N;
		int s=sum;
		vector<int> removed;
		for(int j=0;j<N;j++){
			if(percent[j]<0){
				percent[j]=0;
				removed.push_back(j);
				n-=1;
				s-=contestants[j];
			}
		}
		bool c=false;
		for(int j=0;j<N;j++){
			for(int k=0;k<removed.size();k++){
				if(j==removed[k]){
					c=true;
				}
			}
			if(c){
				c=false;
				continue;
			}
			percent[j]=((s+sum)/double(n)-contestants[j])/double(sum);
		}
		out << "Case #" << i+1 << ":";
		for(int j=0;j<N;j++){
			out << " " << setprecision(11) << percent[j]*100;
		}
		out << "\n";
	}
	return 0;
}