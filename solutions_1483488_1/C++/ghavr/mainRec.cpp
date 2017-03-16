#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int base[8];


vector<string> split(string sent)
{
	if(sent.size() < 1)
		return vector<string>();
	vector<string> answer;
//	answer.resize(3);
	
	int start = 0, end = 0;
	char delim = ' ';
	
	while( (end = sent.find(delim, start)) != string::npos)
	{
		answer.push_back(sent.substr(start, end-start));
		start = end + 1;
	}
	answer.push_back(sent.substr(start, sent.size()-start));
	return answer;
}


int recyc(int number, int bs)
{
	int lastD = number % 10;
	return lastD * base[bs] + number / 10;
}


int getBase(int val)
{
	if(val < 1)
		return 0;
	for(int i = 2; i < 8; i++)
	{
		if(val < base[i])
			return i-1;
	}
	return 7;
}


int twotimes(int number, int bs)
{
	return number*(1 + base[bs+1]);
}

int threetimes(int number, int bs)
{
	return number*(1 + base[bs+1] * (1 + base[bs+1]));
}



int main()
{
	freopen("input.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	base[0] = 0;
	base[1] = 1;
	base[2] = 10;
	base[3] = 100;
	base[4] = 1000;
	base[5] = 10000;
	base[6] = 100000;
	base[7] = 1000000;
	
	string wrkLine;
	
	int testNumb;
	getline(cin, wrkLine);
	testNumb = atof(wrkLine.c_str());
	
	for(int i = 0; i < testNumb; ++i)
	{
		int A, B;
		int count = 0;
//		int countX = 0;

		getline(cin, wrkLine);
		vector<string> splited = split(wrkLine);
		A = atof(splited[0].c_str());
		B = atof(splited[1].c_str());
		int digA = getBase(A);
		int digB = getBase(B);

		for(int j = A; j < B; ++j)
		{
			int bs = getBase(j);
			int curJ = j;
//			map<int, int> ans;

			for(int k = 1; k < bs; ++k)
			{
				curJ = recyc(curJ, bs);
				if(j < curJ && curJ <= B)
				{
					
//					ans[curJ];
					count++;
				}
			}
//			countX += ans.size();
		}


		int count2 = 0;
			for(int j = 10; j < 100; ++j)
			{
				//concat once
				int jj = twotimes(j, 2);
				int curJ = recyc(jj, 4);
				
				if(A <= jj && jj < curJ && curJ <= B)
				{
					++count2;
				}
			}

		int count3 = 0, count4 = 0;
			for(int j = 10; j < 100; ++j)
			{
				//concat twice
				int jjj = threetimes(j, 2);
				int curJ = recyc(jjj, 6);
				
				if(A <= jjj && jjj < curJ && curJ <= B)
				{
					++count3;
				}
			}
			
			for(int j = 100; j < 1000; ++j)
			{
				//concat once
				int jj = twotimes(j, 3);
				int curJ = jj;
				
				for(int k = 1; k < 3; ++k)
				
				{
					curJ = recyc(curJ, 6);
					if(A <= jj && jj < curJ && curJ <= B)
					{
						++count4;
					}
				}
			}

		count -= count2 + 2 * count3 + count4;
		cout << "Case #" << i+1 << ": "  << count << endl;
		
	}
	
	return 0;
}