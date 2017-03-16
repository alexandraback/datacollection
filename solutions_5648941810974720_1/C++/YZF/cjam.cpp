#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void sub(std::map<unsigned char, int>& ds, string n)
{
    for(unsigned char t : n) {
        ds[t]--;
    }
}

string phone(std::map<unsigned char, int>& ds)
{
    string result = "";
    vector<string> numbers{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    bool more = false;
    do {
        more = false;
        if(ds['Z']) {
            result += "0";
            sub(ds, numbers[0]);
            more = true;
        } else if(ds['X']) {
            result += "6";
            sub(ds, numbers[6]);
            more = true;
        } else if(ds['S']) {
            result += "7";
            sub(ds, numbers[7]);
            more = true;
        } else if(ds['G']) {
            result += "8";
            sub(ds, numbers[8]);
            more = true;
        } else if(ds['W']) {
            result += "2";
            sub(ds, numbers[2]);
            more = true;
        } else if(ds['V']) {
            result += "5";
            sub(ds, numbers[5]);
            more = true;
        } else if(ds['U']) {
            result += "4";
            sub(ds, numbers[4]);
            more = true;
        } else if(ds['R']) {
            result += "3";
            sub(ds, numbers[3]);
            more = true;
        } else if(ds['O']) {
            result += "1";
            sub(ds, numbers[1]);
            more = true;
        } else if(ds['N']) {
            result += "9";
            sub(ds, numbers[9]);
            more = true;
        }
    } while(more);
    return result;
}

int main()
{
    ifstream testcase("example.txt");
    ofstream result("result.out");

    int ncases;
    testcase >> ncases;

    for(int c = 0; c < ncases; ++c) {
        std::string digits;
        std::map<unsigned char, int> ds;
        for(unsigned char i=0; i<128; ++i) {
            ds[i] = 0;
        }
        testcase >> digits;
        for(unsigned char d : digits) {
            ds[d]++;
        }
        string pn = phone(ds);
        sort(pn.begin(), pn.end());
        result << "Case #" << c+1 << ": " << pn << endl;
    }
}
