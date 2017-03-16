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
        const int N = atoi(data[0].c_str());
        vector<int> a(N, 0), b(N, 0);
        for (int j = 0; j < N; ++j)
        {
            data = Utils::split_string(lines[index++]);
            a[j] = atoi(data[0].c_str());
            b[j] = atoi(data[1].c_str());
        }
        int stars = 0, tries = 0;
        bool found = true;
        cout << "Game " << t << endl;
        while (found)
        {
            found = false;
            for (int i = 0; i < N; ++i)
                if (b[i] != -1 && b[i] <= stars)
                {
                    //play that level
                    tries++;
                    stars++;
                    b[i] = -1;
                    if (a[i] != -1)
                        stars++;
                    a[i] = -1;
                    found = true;
                    //cout << "   Played " << i << " 2 stars, gain:" <<  stars << endl;
                    break;
                }
            //find an uppropriate level
            if (!found)
            {
                int b_ = 0;
                int i_ = -1;
                for (int i = 0; i < N; ++i)
                    if (a[i] != -1 && a[i] <= stars && b[i] > b_)
                    {
                        i_ = i;
                        b_ = b[i];
                    }
                if (i_ != -1)
                {
                        //play that level
                        tries++;
                        stars++;
                        a[i_] = -1;
                        found = true;
                        //cout << "   Played " << i_ << " 1 stars, gain:" <<  stars << endl;
                }
            }
            if (stars == 2 * N)
            {
                found = true;
                break;
            }
            if (!found)
            {
                //cout << "   Failed to find with " << stars << " stars" << endl;
            }
        }
        
        if (found)
            res << "Case #" << t + 1 << ": " << tries << endl;
        else
            res << "Case #" << t + 1 << ": Too Bad" << endl;
    }
    res.close();
    
    return 0;
}


