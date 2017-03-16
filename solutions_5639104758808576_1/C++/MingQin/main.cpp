/*
 * File:   main.cpp
 * Author: Ming Qin
 *
 * Created on February 27, 2015, 8:37 PM
 */

 //#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void assert(bool expression, int code = 0) {
    if (!expression) {
        cout << "assertion fail! Code=" << code << endl;
        system("pause");
        exit(-1);
    }
}

int minFriend(string s) {
    int sum = 0;
    int need = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (sum < i) {
            need += i - sum;
            sum = i;//force it to be i
        }
        sum += s[i]-'0';
    }
    return need;
}
/*
 *
 */
int main(int argc, char** argv) {
    cout << "Problem A. Standing Ovation" << endl;
    //idea: ignore the shyest person

    vector<string> strv;
    string str;
    int T;
    int shyest;

    fstream infile("in.txt");
    infile >> T;
    while (!infile.eof()) {
        str = "fake_string_by_Ming";
        infile >> shyest >> str;
        if (str == "fake_string_by_Ming") {
            cout << "Warning: empty line!!"<<endl;
            break;
        }
        assert(shyest + 1 == str.size(), 1);
        strv.push_back(str);
    }
    infile.close();
    assert(T == strv.size(), 2);

    ofstream outfile("out.txt");
    for (int i = 0; i < T; ++i) {
        outfile << "Case #" << i+1 << ": ";
        outfile << minFriend(strv[i]) << endl;
    }
    outfile.close();
    return 0;
}
