//
//  a.cpp
//  CodeJam15_1C
//
//  Created by Ahmed Mohammed on 5/10/15.
//  Copyright (c) 2015 Akhmed. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

void precalc();
void solve_case(uint64_t case_no, ifstream &fin, ofstream &fout);

int main(int argc, const char * argv[])
{
    if (argc < 3) { printf("Usage: %s <input file> <output file>\n", argv[0]); exit(1);}
    
    ifstream fin(argv[1], ios::in|ios::ate);
    if (!fin.is_open()) { printf("Unable to open input file\n"); exit(1);}
    fin.seekg(0);
    
    ofstream fout(argv[2], ios::out|ios::ate);
    if (!fout.is_open()) { printf("Unable to open output file\n"); exit(1);}
    fout.seekp(0);
    
    fout.precision(7);
    fout.setf(ios::fixed);
    
    // solve cases
    uint64_t case_count; fin >> case_count;
    precalc();
    for (uint64_t case_no = 0; case_no < case_count; case_no++) solve_case(case_no + 1, fin, fout);
    
    fin.close();
    fout.close();
    
    return 0;
}






void precalc()
{
    
}


void solve_case(uint64_t case_no, ifstream &fin, ofstream &fout)
{
    fout << "Case #" << case_no << ": ";
    cout << "Solving " << case_no << endl;
    
    int R, C, W;
    fin >> R >> C >> W;
    
    int result = (C == 1) ? R : (R * (C / W)) + W - ((C % W) ? 0 : 1);
    fout << result << endl;
}








