#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <functional>
#include <numeric>

using namespace std;
int globalF= 0;
bool IsSame (pair<int, vector<int> > a)
{
	return (a.first == globalF);
}
int main(int argc, char * argv[])
{
	ifstream fin("input.txt"); 
	if(!fin.good())
	{
		cout << "opps" << endl;
	}
	string str;
	getline(fin, str);
	
	const int N = atoi(str.c_str());
	cout << N << endl;
	ofstream fout("output.txt");
	for( int aaa = 0; aaa < N ; aaa++)
	{
	cout << "ITER: " << aaa << endl;
		getline(fin, str);
		istringstream iss(str);
		int T;
		iss >> T;
		vector<int> list_num;
		for(int bbb = 0; bbb < T; bbb++)	
		{
			int B;
			iss >> B;
			list_num.push_back(B);
		}

		vector<pair<int, vector<int> > > sums;
		for(int bbb = 1; bbb< T; bbb++)
		{
			vector<int> ip(T, 0);
			for(int ccc = 0; ccc < bbb; ccc++)
			{
				ip[T - 1 - ccc] = 1;
			}
			bool flag_per = true;
			while(flag_per)
			{
				int temp_sum = inner_product(list_num.begin(), list_num.end(), ip.begin(), 0);
				globalF = temp_sum;
				//vector<int>::iterator find_res = find(sums.begin(), sums.end(), temp_sum);
				vector<pair<int, vector<int> > >::iterator find_res = find_if(sums.begin(), sums.end(), IsSame);
				if(find_res == sums.end())
				{
					
					sums.push_back(pair<int, vector<int> >(temp_sum, ip));
					flag_per = next_permutation(ip.begin(), ip.end());
				}
				else
				{
					//exit loop
					bbb= T;
					flag_per = false;

					fout << "Case #" << aaa+1 << ":\n";
					cout << temp_sum;
					for(vector<int>::iterator it_ip = ip.begin(), it_ln = list_num.begin(); it_ip < ip.end(); it_ip++, it_ln++)
					{
						if(*it_ip)
						{
							fout << *it_ln << " ";
						}
					}
					fout << endl;
					for(vector<int>::iterator it_ip = find_res->second.begin(), it_ln = list_num.begin(); it_ip < find_res->second.end(); it_ip++, it_ln++)
					{
						if(*it_ip)
						{
							fout << *it_ln << " ";
						}
					}
					fout << endl;
					break;	
				}
			}
		}

	}	

	fin.close(); fout.close();
	return 0;
}
