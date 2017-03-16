//
//  b.cpp
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
    
    int K, L, S;
    fin >> K >> L >> S;
    string k; fin >> k;
    string l; fin >> l;
    
    int o = (int)l.size();
    for (int i = 1; i < l.size(); i++)
    {
        bool match = true;
        for (int j = 0; j < l.size() - i; j++)
        {
            if (l[j] != l[i + j]) { match = false; break;}
        }
        
        if (match) { o = i; break; }
    }
    
    int b = 1 + ((S - L) / o);
    
    int freq[26] = {0};
    for (int i = 0; i < k.length(); i++) freq[k[i]-'A']++;

    double pl[100] = {0};
    pl[L - 1] = ((double)freq[l[L-1]-'A']) / K;
    for (int i = (int)l.length() - 2; i >= 0; i--) pl[i] = pl[i+1] * ((double)freq[l[i]-'A']) / K;
    
    if (pl[0] == 0.0) b = 0;
    
    double cpl[100] = {0};
    for (int i = o; i < L; i += o) cpl[i] = pl[L - i];
    
    double p[100] = {0};
    p[0] = pl[0];
    
    for (int i = 1; i <= S - L; i++)
    {
        double ccp = 1.0;
        for (int j = L-1; j > 0; j--)
        {
            int ii = i - j;
            if (ii < 0) break;
            p[i] += ccp * (p[ii] * cpl[j]);
            ccp *= (1 - p[ii]);
        }
        
        p[i] += ccp * p[0];
    }
    
    double expected = 0.0;
    for (int i = 0; i <= S - L; i++) expected += p[i];
    fout << ((double)b) - expected << endl;
}








