#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <istream>
#include <unordered_map>

using namespace std;

/*static bool cmp(vector<int> a, vector<int> b){
	if (a[2] < b[2]) return true;
	else if (a[2]>b[2]) return false;
	else{
		if (a[0] < b[0]) return true;
		else if (a[0] > b[0]) return false;
		else{
			if (a[1] < b[1]) return true;
			else if (a[1] > b[1]) return false;
			else
				return true;
		}
	}
}
*/
int main()
{
	int numCases;
	cin >> numCases;
	//numCases = 1;
	for (int i = 0; i<numCases; i++)
	{
		string c_str, j_str;
		//c_str = "?2?"; 
		//j_str = "??3";
		cin >> c_str >> j_str;
		int length = c_str.size();

		vector<int> c_nums, j_nums, c_nums_tmp, j_nums_tmp;

		if (c_str[0] != '?')
			c_nums.push_back(c_str[0] - '0');
		else{
			for (int j = 0; j < 10; j++)
				c_nums.push_back(j);
		}
		for (int j = 1; j < length; j++){
			c_nums_tmp.clear();
			if (c_str[j] != '?'){		
				for (int m = 0; m < c_nums.size(); m++){
					int tmp = c_nums[m];
					tmp = tmp * 10 + (c_str[j] - '0');
					c_nums_tmp.push_back(tmp);
				}
			}
			else{
				for (int m = 0; m < c_nums.size(); m++){
					for (int n = 0; n < 10; n++){
						int tmp = c_nums[m];
						tmp = tmp * 10 + n;
						c_nums_tmp.push_back(tmp);
					}
				}
			}
			swap(c_nums, c_nums_tmp);
		}

		if (j_str[0] != '?')
			j_nums.push_back(j_str[0] - '0');
		else{
			for (int j = 0; j < 10; j++)
				j_nums.push_back(j);
		}

		for (int j = 1; j < length; j++){
			j_nums_tmp.clear();
			if (j_str[j] != '?'){
				for (int m = 0; m < j_nums.size(); m++){
					int tmp = j_nums[m];
					tmp = tmp * 10 + (j_str[j] - '0');
					j_nums_tmp.push_back(tmp);
				}
			}
			else{			
				for (int m = 0; m < j_nums.size(); m++){					
					for (int n = 0; n < 10; n++){
						int tmp = j_nums[m];
						tmp = tmp * 10 + n;
						j_nums_tmp.push_back(tmp);
					}
				}
			}
			swap(j_nums, j_nums_tmp);
		}

		vector<vector<int>> difference;
		for (int j = 0; j < c_nums.size(); j++){
			for (int k = 0; k < j_nums.size(); k++){
				vector<int> tmp(3, 0);
				tmp[1] = c_nums[j];
				tmp[2] = j_nums[k];
				tmp[0] = abs(tmp[1] - tmp[2]);
				difference.push_back(tmp);
			}
		}

		sort(difference.begin(), difference.end());

		string c_str_out = to_string(difference[0][1]);
		string j_str_out = to_string(difference[0][2]);

		int c_length = c_str_out.size();
		int j_length = j_str_out.size();
		while (c_length < length){
			c_str_out = '0' + c_str_out;
			c_length++;
		}
		while (j_length < length){
			j_str_out = '0' + j_str_out;
			j_length++;
		}

		cout << "Case #" << i + 1 << ": " << c_str_out <<" " << j_str_out << endl;
	}

	return 0;
}