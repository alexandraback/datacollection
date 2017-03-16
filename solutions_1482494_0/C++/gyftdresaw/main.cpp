/*
 * File:   main.cpp
 * Author: herman
 *
 * Created on April 27, 2012, 8:31 PM
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

ifstream infile;
ofstream outfile;

bool compare_pairs(pair<int,int> p1, pair<int,int> p2){
    return (p1.second < p2.second);
}

/*
 *  kingdom rush
 */
int main(int argc, char** argv) {
    infile.open("input.txt");
    outfile.open("output.txt");

    int trials;
    infile >> trials;
    for (int i = 0; i < trials; i++){
        int N;
        infile >> N;
        vector< pair<int,int> > lvals;
        bool onestar[N];
        bool twostar[N];
        for (int j = 0; j < N; j++){
            int a,b;
            infile >> a;
            infile >> b;
            lvals.push_back(make_pair(a,b));
            onestar[j] = false;
            twostar[j] = false;
        }

        // sort lvals
        stable_sort(lvals.begin(),lvals.end(),compare_pairs);
        
        int ctotal = 0;
        int nleft = N;
        bool possible = true;
        int nlevels = 0;
        while (nleft > 0 && possible){
            bool found = false;
            // try for two stars
            for (int j = 0; j < N; j++){
                if (!twostar[j]){
                    if (ctotal >= lvals[j].second){
                        // take it
                        if (!onestar[j])
                            ctotal += 2;
                        else
                            ctotal += 1;
                        twostar[j] = true;
                        onestar[j] = true;
                        nleft -= 1;
                        found = true;
                        break;
                    }
                }
            }
            if (!found){
                // look in one stars
                // traverse lvals backwards big b to small b
                for (int k = N-1; k >= 0; k--){
                    if (!onestar[k]){
                        if (ctotal >= lvals[k].first){
                            // take it
                            ctotal += 1;
                            onestar[k] = true;
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (found)
                nlevels++;
            possible = found;
        }

        if (possible){
        cout << "Case #" << (i+1) << ": " << nlevels << endl;
        outfile << "Case #" << (i+1) << ": " << nlevels << endl;
        } else {
        cout << "Case #" << (i+1) << ": " << "Too Bad" << endl;
        outfile << "Case #" << (i+1) << ": " << "Too Bad" << endl;
        }
        
    }

    infile.close();
    outfile.close();

    return (EXIT_SUCCESS);
}

