#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <fstream>

using namespace std;

void solve(string s, int &difference, int &c, int &j, string &result)
{
    for(int i = 0; i<s.size(); ++i)
    {
        if(s[i]=='?')
        {
            for(int k = 0; k<=9; ++k)
            {
                s[i] = '0'+k;
                solve(s, difference, c, j, result);
                s[i] = '?';
            }
        }
        else if(i==s.size()-1)
        {
            //Compare difference
            bool skip = false;
            for(int k = 0; k<s.size(); ++k)
                if(s[k]=='?')
                {
                    skip = true;
                    break;
                }
            if(skip)
                continue;
            string s1 = s.substr(0, s.size()/2);
            string s2 = s.substr(s.size()/2, s.size());

            istringstream buffer(s1);
            int val1, val2;
            buffer >> val1;
            istringstream buffer_0(s2);
            buffer_0 >> val2;

            if(difference==-1)
            {
                result=s;
                c = val1;
                j = val2;
                difference = abs(val1-val2);
            }

            else if(abs(val1-val2)<difference)
            {
                result = s;
                c = val1;
                j = val2;
                difference = abs(val1-val2);
            }
            else if(abs(val1-val2)==difference)
            {
                if(val1<c)
                {
                    result = s;
                    c = val1;
                    j = val2;
                }
                else if(c==val1)
                {
                    if(val2<j)
                    {
                        result = s;
                        j = val2;
                    }
                }
            }
        }
    }
    return;
}

int main()
{
    ifstream file_reader("small_input.in");
    ofstream file_writer("small_output.txt");
    int t;
    file_reader >> t;

    for(int c = 1; c<=t; ++c)
    {
        string s = "";
        bool first_half = false, secnd_half = false;
        string temp;
        file_reader >> temp;
        if(temp == "???")
            first_half = true;
        s+=temp;
        file_reader >> temp;
        if(temp=="???")
            secnd_half = true;
        s+=temp;

        if(first_half)
        {
            if(secnd_half)
            {
                file_writer << "Case #" << c << ": " << "000 000" << endl;
                continue;
            }
            else
            {
                for(int k = 0; k<temp.size(); ++k)
                    if(temp[k]!='?')
                        s[k] = temp[k];
            }
        }
        else if(secnd_half)
        {
            for(int k = 0; k<s.size()/2; ++k)
                if(s[k]!='?')
                    s[(s.size()/2)+k] = s[k];
        }

        string result = "";
        int a = -1, b = -1, d = -1;
        solve(s, a, b, d, result);
        file_writer << "Case #" << c << ": " << result.substr(0, result.size()/2) << " " << result.substr(result.size()/2, result.size()) << endl;
    }
}
