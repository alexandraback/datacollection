#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <fstream>
#include <vector>
// #include <iostream>

using namespace std;
void sort(double a[], int start, int end) {
	if(start >= end) return;
	int index = rand()%(end - start + 1) + start;
	double val = a[index];
	a[index] = a[end];
	a[end] = val;
	int nextToPut = start;
	int nextToJudge = start;
	while(nextToJudge <= end) {
		if(a[nextToJudge] <= val) {
			if(nextToJudge != nextToPut) {
				double temp = a[nextToPut];
				a[nextToPut] = a[nextToJudge];
				a[nextToJudge] = temp;
			}
			nextToPut ++;
		}
		nextToJudge ++;
	}
	sort(a, nextToPut, end);
	sort(a, start, nextToPut - 2);
}
int findLarger(vector<double> &b, double target) {
	int low = 0;
	int high = b.size()-1;
	while(low <= high) {
		int mid = (low + high)/2;
		if(b[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return low;
}
int main(int argc, char* argv[]) {
	if(argc < 2) {
		printf("No input file\n");
		return -1;
	}
	ifstream input;
	input.open(argv[1]);
	ofstream output;
	output.open("output");
	
	// number of cases
	int caseNum = 0;
	input>>caseNum;
	int counter = 0;
	while(counter < caseNum) {
		int blockNum;
		input>>blockNum;
		double* a = new double[blockNum];
		double* b = new double[blockNum];
		for(int i = 0; i < blockNum; i ++) {
			input>>a[i];
		}
		for(int i = 0; i < blockNum; i ++) {
			input>>b[i];
		}
		sort(a, 0, blockNum-1);
		sort(b, 0, blockNum-1);
		if(a[0] > b[blockNum-1]) {
			output<<"Case #"<<counter+1<<": "<<blockNum<<" "<<blockNum<<endl;
		}
		else if(a[blockNum-1] < b[0]) {
			output<<"Case #"<<counter+1<<": "<<0<<" "<<0<<endl;
		}
		else {
			vector<double> b2;
			for(int i = 0; i < blockNum; i ++) {
				b2.push_back(b[i]);
			}
			int r1 = 0;
			int b1Start = 0;
			int b1End = blockNum-1;
			for(int i = 0; i < blockNum; i ++) {
				if(a[i] < b[b1Start]) {
					b1End--;
				}
				else {
					r1++;
					b1Start++;
				}
			}
			int r2 = 0;
			for(int i = 0; i < blockNum; i ++) {
				int index = findLarger(b2, a[i]);
				if(index >= b2.size()) {
					//cout<<"remove begin "<<index<<' '<<a[i]<<' ';
					r2 ++;
					b2.erase(b2.begin());
				}
				else{
					//cout<<"remove index "<<index<<' '<<a[i]<<' ';
					b2.erase(b2.begin()+index);
				}
				/*cout<<"b2 ";
				for(int j = 0; j < b2.size(); j ++) {
					cout<<b2[j]<<' ';
				}
				cout<<endl;*/
			}
			output<<"Case #"<<counter+1<<": "<<r1<<" "<<r2<<endl;
		}
		delete [] a;
		delete [] b;
		counter ++;
	}
	input.close();
	output.close();
	return 0;
}