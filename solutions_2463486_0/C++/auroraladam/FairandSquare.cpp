#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

int main(int argc, const char **argv){
	long long fairsqarr[] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};
	int num = 39;
	ifstream input;
	ofstream output;
	input.open(argv[1]);
	output.open(argv[2]);
	if(!input.is_open() || !output.is_open()){
		exit(0);	
	}
	int numcase;
	input >> numcase;
	for(int i = 0; i < numcase; i ++){
		long long A, B;
		input >> A >> B;
		int start = 0;
		int end = num - 1;
		int mid;
		while(start <= end){
			mid = (start + end) / 2;
			if(B > fairsqarr[mid]){
				start = mid + 1;
			}
			else if(B < fairsqarr[mid]){
				end = mid - 1;
			}
			else{
				start = mid;
				end = start - 1;
			}
		}
		if(fairsqarr[start] == B){
			start ++;
		}
		int result = start;
		start = 0;
		end = num - 1;
		while(start <= end){
			mid = (start + end) / 2;
			if(A > fairsqarr[mid]){
				start = mid + 1;
			}
			else if(A < fairsqarr[mid]){
				end = mid - 1;
			}
			else{
				start = mid;
				end = start - 1;
			}
		}
		result = result - start;
		output << "Case #" << i + 1 << ": " << result << endl;
	}
	input.close();
	output.close();
	return 0;
}
