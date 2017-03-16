#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("../../../output.txt");
ifstream fin("../../../input.txt");

vector<string> digits;

int vals[26];
vector<int> lis;

int update(string s, int idx, int num)
{
    int ret = vals[idx];
    
    for(int i=0; i<s.size(); i++)
    {
        vals[s[i]-'A']-=ret;
    }
    
    for(int i=0; i<ret; i++)
    {
        lis.push_back(num);
    }
    
    return ret;
}


int main(void)
{
    digits.push_back("ZERO");
    digits.push_back("ONE");
    digits.push_back("TWO");
    digits.push_back("THREE");
    digits.push_back("FOUR");
    digits.push_back("FIVE");
    digits.push_back("SIX");
    digits.push_back("SEVEN");
    digits.push_back("EIGHT");
    digits.push_back("NINE");
    int ttt;
    fin >> ttt;
    int ct = 0;
    string s;
    
    cout.precision(9);
    fout.precision(9);
    
    cout << "HELLO" <<  " " << ttt << endl;
    
    
    
    while(ttt>0)
    {
        ct++;
        ttt--;
        
        int n,i,j,k;
        
        
        
        string s;
        fin >> s;
        
        
        memset(vals,0,sizeof(vals));
        lis.clear();
        
        for(i=0; i<s.size(); i++)
        {
            vals[s[i]-'A']++;
        }
        
        update(digits[8],6,8);
        update(digits[0],25,0);
        update(digits[6],23,6);
        update(digits[3],7,3);
        update(digits[2],22,2);
        update(digits[4],20,4);
        update(digits[7],18,7);
        update(digits[5],21,5);
        update(digits[9],8,9);
        update(digits[1],13,1);
        
        
        sort(lis.begin(),lis.end());
        
        
        cout << "Case #" << ct << ": ";
        fout << "Case #" << ct << ": ";
        
        for(i=0; i<lis.size(); i++)
        {
            cout << lis[i];
            fout << lis[i];
        }
        
        
        
        fout << endl;
        cout << endl;
        
    }
    
    
    return 0;
}

