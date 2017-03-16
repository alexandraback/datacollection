#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

int main(int argc, const char **argv){
	ifstream input;
	ofstream output;
	input.open(argv[1]);
	output.open(argv[2]);
	if(!input.is_open() || !output.is_open()){
		exit(0);	
	}
	int numcase;
	input >> numcase;
	for(int t = 0; t < numcase; t ++){
		int A, N;
		input >> A >> N;
		vector<int> arr(N, 0);
		for(int i = 0; i < N; i ++){
			input >> arr[i];
		}
		int result = N;
		if(A > 1){
			sort(arr.begin(), arr.end());
			cout << endl;
			vector<int> op_num(N, 0);
			int sum = A;
			int start = 0;
			int count = 0;
			while(start < N){
				if(sum > arr[start]){
					sum = sum + arr[start];
					op_num[start] = count;
					start ++;
				}
				else{
					sum = sum * 2 - 1;
					count ++;		
				}
			}
			vector<int> op_num0(N, 0);
			for(int i = N - 1; i >= 0; i --){
				op_num0[i] = N - 1 - i;
			}
			for(int i = 0; i < N; i ++){
				if(result > op_num0[i] + op_num[i]){
					result = op_num0[i] + op_num[i];
				}
			}
		}
		output << "Case #" << t + 1 << ": " << result << endl;
	}
	input.close();
	output.close();
	return 0;
}
