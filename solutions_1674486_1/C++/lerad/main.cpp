/* 
 * File:   main.cpp
 * Author: Folker Hoffmann
 *
 * Created on 24 de marzo de 2012, 21:43
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 
 */

vector< vector<int> > edges;

inline void handleProblemNr(int nr, ifstream &in, ofstream &out) {
    int numClasses;
    in >> numClasses;
    edges.resize(numClasses);

    for(int i=0; i<numClasses; i++) {
        int M,e;
        in >> M;
        edges[i] = vector<int>(M);
        
        for(int j=0; j<M; j++) {
            in >> e;
            edges[i][j] = e-1; // Count goes from 1 to n
        }
    }

    bool diamond = false;
    for( int i=0; i<numClasses; i++) {

        queue<int> q;
        for(int j=0; j<edges[i].size(); j++)
            q.push(edges[i][j]);
        
        vector<bool> marked(numClasses, false);
        marked[i] = true;
        // BFS:

        while(!q.empty()) {
            int next = q.front();

            q.pop();
            
            if(marked[next]) {
            
                diamond = true;
                break;
            }
            else {
                
                marked[next] = true;
                
                for(int j=0; j<edges[next].size(); j++)
                    q.push(edges[next][j]);
            }
        }
    }
    
    out << "Case #" << nr << ": ";
    if(diamond) 
        out << "Yes";
    else
        out << "No";
    out << endl;
}

int main(int argc, char** argv) {
    int numTestCases;
    ifstream in("input.in");
    ofstream out("output.out");
    
    in >> numTestCases;
    
    for(int test=0; test < numTestCases; test++) {
        cout << "Handle problem #" << (test+1) << " ..." << endl;
        handleProblemNr(test+1, in, out);
    }
    
    return 0;
}

