#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int t = 0;
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");
	if (fin.good())
	{
		int arr[][4] = { { 1, 2, 3, 4 }, {2, -1, 4, -3 }, { 3,-4, -1, 2 }, { 4, 3, -2, -1 } };
		fin >> t;
		for (size_t i = 0; i < t; i++)
		{
			int L = 0, M = 0;
			string s = "";
			string is = "";
			string pr;
			fin >> L;
			fin >> M;
			fin >> s;
			for (size_t j = 0; j < M; j++)
			{
				is += s;
			}
			if (is.length() < 3)
				pr = "NO";
			else if (is.length() == 3){
				if (is[0] == 'i')
					if (is[1] == 'j')
						if (is[2] == 'k')
							pr = "YES";
						else
							pr = "NO";
					else
						pr = "NO";
				else
					pr = "NO";
			}
			else{
				bool ii, jj, kk;
				ii = jj = kk = false;
				string res = "";
				int decode = 1;
				for (size_t j = 0; j < is.length(); j++)
				{
					if (is[j] == 'i'){
						if (decode < 0){
							decode = arr[(decode*-1) - 1][1];
							decode *= -1;
						}
						else
							decode = arr[decode - 1][1];
					}
					else if (is[j] == 'j')
					{
						if (decode < 0){
							decode = arr[(decode*-1) - 1][2];
							decode *= -1;
						}
						else
							decode = arr[decode - 1][2];
					}
					else if (is[j] == 'k')
					{
						if (decode < 0){
							decode = arr[(decode*-1) - 1][3];
							decode *= -1;
						}
						else
							decode = arr[decode - 1][3];
					}

					if (!ii && decode == 2){
						ii = true;
						decode = 1;
					}
					else if (ii && !jj && decode == 3){
						jj = true;
						decode = 1;
					}
				}
				if (decode == 4)
					kk = true;
				if (ii && jj && kk)
					pr = "YES";
				else
					pr = "NO";
			}

				
		
			fout << "Case #" << i + 1 << ": " <<pr<< endl;

		}
		fin.close();
		fout.close();
	}

	return 0;
}