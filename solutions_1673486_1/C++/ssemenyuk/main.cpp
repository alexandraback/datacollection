//
//  main.cpp
//  jam1
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
    vector_string split_string(string data)
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
    const int T = atoi(lines[0].c_str());
    cout << "Loaded " << T << " cases" << endl;
    
    int index = 1;
    ofstream res("test.out");
    for (int t = 0; t < T; ++t)
    {
        int number = 0;
        vector_string data = Utils::split_string(lines[index++]);
        int a = atoi(data[0].c_str());
        int b = atoi(data[1].c_str());
        data = Utils::split_string(lines[index++]);
        vector<double> p(a, 0);
        for (int i = 0; i < a; ++i)
            p[i] = atof(data[i].c_str());
        
        double corr = 1;
        for (int i= 0; i < a; ++i)
            corr *= p[i];
        //fill to the end
        double str = (b - a + 1) * corr + (b - a + 1 + b + 1) * (1- corr); 
        double min = str;
        
        //hit enter and retype
        str = 1 + b + 1;
        if (min > str)
            min = str;
        
        //hit back i times
        for (int s = 1; s <= a; ++s)
        {
            double corr = 1;
            for (int i = 0; i < a - s; ++i)
                corr *= p[i];
            double str = (2*s + b - a + 1) * corr + (2*s + b - a + 1 + b + 1) * (1- corr); 
            if (min > str)
                min = str;
        }
                
        res << "Case #" << t + 1 << ": " << fixed << setprecision (6) << min << endl;

    }
    res.close();
    
    return 0;
}


