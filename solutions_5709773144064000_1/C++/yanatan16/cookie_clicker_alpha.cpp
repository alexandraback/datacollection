// CodeJam 2014
// Author: Jon Eisen
// Round: Qualifier
// Problem: B - Cookie Clicker Alpha

// Run with
// gcc-4.7 file.cpp -lstdc++.6 -std=c++11 && ./a.out problem.in && a.out file.in

#include <time.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <regex>
#include <math.h>
#include <exception>

using namespace std;

string join(vector<string> v, string d) {
    stringstream ss;
    for (vector<string>::iterator it = v.begin(); it < v.end(); it++) {
        if (it > v.begin()) ss << d;
        ss << *it;
    }
    return ss.str();
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

string parseAndSolve(istream & input) {
    double c, f, x, rate = 2, total = 0;
    input >> c >> f >> x;

    while ((x/rate) > (c/rate + x/(rate+f))) {
        total += c/rate;
        rate += f;
    }
    total += x/rate;

    char buff[100];
    sprintf(buff, "%.7f", total);
    return string(buff);
}

void run(string inf, string outf) {
    ifstream finput(inf.c_str());
    ofstream foutput(outf.c_str());

    int ncases;
    finput >> ncases;

    for (int i = 0; i < ncases; i++) {
        string solu = parseAndSolve(finput);
        stringstream outline;
        outline << "Case #" << (i+1) << ": " << solu << endl;

        cout << outline.str();
        foutput << outline.str();
    }

    finput.close();
    foutput.close();
}

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cout << "usage: " << argv[0] << " problem.in [problem.out]";
        return 1;
    }

    string infile = argv[1];
    string outfile = regex_replace(infile, regex("\\..*$"), string(".out"));

    if (argc > 2) {
        outfile = argv[2];
    }

    run(infile, outfile);
    return 0;
}