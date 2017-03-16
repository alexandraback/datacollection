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
        const int N = atoi(data[0].c_str());
        int S = atoi(data[1].c_str());
        const int p = atoi(data[2].c_str());
        vector<int> sums;
        for (int j = 0; j < N; ++j)
            sums.push_back(atoi(data[3 + j].c_str()));
    
        for (int j = 0; j < N; ++j)
        {
            //count those which are bigger without surprise
            if (p + 2 * (p - 1) <= sums[j])
            {
                number++;
                continue;
            }
            //count those which are bigger with surprise
            if (S > 0 && (p + 2 * (p - 2 > 0 ? p - 2 : 0) <= sums[j]))
            {
                number++;
                S--; //reduce number of surprising
            }
        }

        res << "Case #" << i + 1 << ": " << number << endl;
    }
    res.close();
    
    return 0;
}

