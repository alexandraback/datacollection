//  jama
//
//  Created by Serhiy Semenyuk on 14.04.12.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <math.h>
using namespace std;


typedef vector<string> vector_string;

namespace Utils
{
    vector_string split_string(string& data)
    {
        vector_string result;
        //add apendix tab for normal parsing
        data += " ";
        int start_pos = 0, end_pos = 0;
        while ((end_pos = data.find(" ", start_pos)) != string::npos)
        {
            result.push_back(data.substr(start_pos, end_pos - start_pos));
            start_pos = end_pos + 1;
        }
        return result;
    }
}

int main (int argc, const char * argv[])
{
    vector_string lines;
    ifstream dat ("test.in");
    if (dat.is_open())
    {
        string line;
        while (dat.good())
        {
            getline (dat, line);
            if (line.empty())
                continue;
            lines.push_back(line);
        }
        dat.close();
    }  
    lines.erase(lines.begin()); //drop firts line with number
    cout << "Loaded " << lines.size() << " lines" << endl;
    
    ofstream res("test.out");
    for (int i = 0, ci = lines.size(); i < ci; ++i)
    {
        int number = 0;
        vector_string data = Utils::split_string(lines[i]);
        const int A = atoi(data[0].c_str());
        const int B = atoi(data[1].c_str());
        
        //find number of digits and first digit power
        int size = 0;
        int multi = 1;
        int num = A;
        while ((num = num / 10) > 0) 
        {
            size++;
            multi *= 10;
        }
        for (num = A; num < B; ++num)
        {
            int test = num;
            set<int> tries;
            for (int j = 0; j < size; ++j)
            {
                test = (test % 10) * multi + test / 10;
                if (num < test && test <= B && tries.find(test) == tries.end())
                {
                    number++;
                    tries.insert(test);
                }
            }
        }
        
        res << "Case #" << i + 1 << ": " << number << endl;
    }
    res.close();
    
    return 0;
}

