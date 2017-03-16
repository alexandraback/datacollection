#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int div3(int n)
{
	int result = n/3;
	if (n%3 > 0) result++;

	return result;
}

int surprising_div3(int n)
{
	int result = n/3;
	if (n%3 > 0) result++;
	if (n>0 && (n%3 == 0 || n%3 == 2)) result++;

	return result;
}

int can_increase(int n)
{
	if (n>0 && (n % 3 == 0 || n % 3 == 2))
		return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2){
		cout << "Argument error!" << endl;
		return 1;
	}
	ifstream fin(argv[1]);
	if (fin.fail()){
		cout << "File open error" << endl;
		return 1;
	}

	int T;
	int i;
	fin >> T;
	for (int a=1;a<=T;a++){
		int N, S, P;
		vector<int> list;
		fin >> N >> S >> P;
		for (i=0;i<N;i++){
			int tmp;
			fin >> tmp;
			list.push_back(tmp);
		}
		sort(list.begin(), list.end(), greater<int>());
		//input end
		int result_count = 0;

		for (i=0;i<N;i++){
			if (div3(list[i]) >= P){
				//cout << "div3" << endl;
				result_count++;
			}
			else if (S > 0 && surprising_div3(list[i]) >= P){
				//cout << "increase" << endl;
				result_count++;
				S--;
			}
		}
		cout << "Case #" << a << ": " << result_count << endl;
		
	}
	
	return 0;
}