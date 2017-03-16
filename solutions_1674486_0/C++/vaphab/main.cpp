//
//  main.cpp
//  d
//
//  Created by Peter Vajda on 4/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;

const double EPSILON = 0.0001;

bool compDouble(double a, double b)
{
    return fabs(a - b) < EPSILON;
}


vector<vector<int> > G;
vector<int> V;
int M;
int N;

bool dfs(int from, int n){
    if(V[n]==1) return true;
    V[n]=1;
    for(int i=0; i<N; i++){
        if(i!=n && i!=from && G[i][n]==1){
            if(dfs(n,i)==true) return true;
        }
    }
    return false;
}


int main(int argc, const char * argv[])
{
    ifstream input("/Users/vajda/Desktop/prog/googleCodeJamB/a/input.txt");
    ofstream output("/Users/vajda/Desktop/prog/googleCodeJamB/a/output.txt");
    int T;
    input >> T;
    for(int i=0;i<T;i++){
        cout << "Case: " <<  i+1 << endl;
        output << "Case #" << i+1 << ": ";
        
        
        input >> N;
        G.clear();
        V.clear();
        V.resize(N);
        G.resize(N);
        for(int n=0;n<N;n++){
            V[n]=0;
            G[n].resize(N);
            input >> M;
            for(int j=0;j<M;j++){
                int m;
                input >> m;
                m--;
                G[n][m]=1;
            }
        }
        
        bool result = false;
        for(int n=0;n<N;n++){
            V.clear();
            V.resize(N);
            if(dfs(-1,n)==true){
                result = true;
                break;
            }
        }
        
        output <<  ((result) ? "Yes" : "No") << endl;
        cout <<  ((result) ? "Yes" : "No") << endl;    
        
    }
    input.close();
    output.close();
    
    return 0;
}

