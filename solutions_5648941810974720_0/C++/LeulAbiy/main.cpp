#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ifstream file_reader("small_input.in");
    ofstream file_writer("small_output.txt");
    int t;
    file_reader >> t;

    for(int c = 1; c<=t; ++c)
    {
        string s;
        file_reader >> s;
        map<char, int> frequency;
        frequency['E'] = 0;
        frequency['F'] = 0;
        frequency['G'] = 0;
        frequency['H'] = 0;
        frequency['O'] = 0;
        frequency['R'] = 0;
        frequency['S'] = 0;
        frequency['T'] = 0;
        frequency['V'] = 0;
        frequency['W'] = 0;
        frequency['X'] = 0;
        frequency['Z'] = 0;
        for(int i = 0; i<s.size(); ++i)
            frequency[s[i]]+=1;
        string digits = "";
        //First phase
        for(int i = 0; i<frequency['Z']; ++i)
        {
            digits+='0';
            --frequency['E'];
            --frequency['R'];
            --frequency['O'];
        }
        for(int i = 0; i<frequency['W']; ++i)
        {
            digits+='2';
            --frequency['T'];
            --frequency['O'];
        }
        for(int i = 0; i<frequency['U']; ++i)
        {
            digits+='4';
            --frequency['F'];
            --frequency['O'];
            --frequency['R'];
        }
        for(int i = 0; i<frequency['X']; ++i)
        {
            digits+='6';
            --frequency['S'];
            --frequency['I'];
        }
        for(int i = 0; i<frequency['G']; ++i)
        {
            digits+='8';
            --frequency['E'];
            --frequency['I'];
            --frequency['H'];
            --frequency['T'];
        }

        //Second Phase
        for(int i = 0; i<frequency['O']; ++i)
            digits += '1';
        for(int i = 0; i<frequency['H']; ++i)
            digits += '3';
        for(int i = 0; i<frequency['S']; ++i)
            digits += '7';
        for(int i = 0; i<frequency['F']; ++i)
        {
            digits += '5';
            --frequency['I'];
        }
        for(int i = 0; i<frequency['I']; ++i)
            digits+='9';
        sort(digits.begin(), digits.end());
        file_writer << "Case #" << c << ": " << digits << endl;
    }
}
