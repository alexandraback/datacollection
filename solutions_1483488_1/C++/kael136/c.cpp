#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bitset>
#include <sstream>
using namespace std;

int count_rec(string a, string b);

std::string int_to_string(int i)
{
    std::stringstream ss;
    std::string s;
    ss << i;
    s = ss.str();

    return s;
}

int main()
{
	string a, b;
	fstream in_f, out_f;
	int t;
	in_f.open("C-large.in", fstream::in);
	out_f.open("c.out", std::ios_base::binary | std::ios_base::out );
	in_f >> t;
	
	for (int i = 1; i <=t; i++)
	{
		in_f >> a;
		in_f >> b;
		out_f << "Case #" << i << ": " << count_rec(a,b) << endl;
	}
	
	//cout << count_rec("1111", "2222") << endl;;
	return 0;
}

int count_rec(string a, string b)
{
	if (a.size() == 1)
		return 0;

	int i1 = atoi(a.c_str());
	int i2 = atoi(b.c_str());
	if(i1 >= i2)
		return 0;
	
	int count = 0;
	for (int i = i1; i < i2; i++)
	{
		string s = int_to_string(i);
		string tmp;
		int size = s.size();
		for(int j = 0; j < size; j++)
			tmp += s;
		//cout << tmp << endl;
		vector<int> check_dup;
		for(int j = 1; j < size; j++)
		{
			
			char buf[8];
			int l = tmp.copy(buf, size, (size-1)*j);
			
			buf[l] = '\0';
			//cout << buf << endl;
			int test = atoi(buf);
			
			if (test <= i2 && test > i)
			{
				if (check_dup.size() == 0)
				{
					//cout << "i is " << i << " and test is " << test << endl;
					count++;
					check_dup.push_back(test);
				}
				else
				{
					int v_size = check_dup.size();
					int k = 0;
					for (k = 0; k < v_size; k++)
					{
						if (test == check_dup[k])
							break;
					}
					if (k == v_size)
					{
						count++;
						check_dup.push_back(test);
					}
				}
			}
		}
	}
	return count;
}