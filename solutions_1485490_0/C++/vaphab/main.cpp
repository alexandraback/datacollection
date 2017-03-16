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


long long max(long long l, long long b){
    return (l>b) ? l:b;
}

vector<pair<long long,int> > toy;
vector<pair<long long,int> > box;

int N,M;

long long dp(int n,long long leftn, int m, long long leftm){
    long long score=0;
    if(box[n].second!=toy[m].second){
        if(n+1<N) score = max(score,dp(n+1,box[n+1].first,m,leftm));
        if(m+1<M) score = max(score,dp(n,leftn,m+1,toy[m+1].first));
    }else{
        if(leftn<leftm){
            if(n+1<N) score = max(score,leftn + dp(n+1,box[n+1].first,m,leftm-leftn));
            else score = max(score,leftn);
        }else if(leftm<leftn){    
            if(m+1<M) score = max(score,leftm + dp(n,leftn-leftm,m+1,toy[m+1].first));
            else score = max(score,leftm);
        }else{
            if(n+1<N && m+1<M) score = max(score,leftn + dp(n+1,box[n+1].first,m+1,toy[m+1].first));
            else score = max(score,leftm);
        }
    }
    return score;
}

int main(int argc, const char * argv[])
{
    cout << "Project B " << sizeof(long long) << endl; 
    ifstream input("/Users/vajda/Desktop/prog/googleCodeJamB/b/input.txt");
    ofstream output("/Users/vajda/Desktop/prog/googleCodeJamB/b/output.txt");
    int T;
    input >> T;
    for(int t=0;t<T;t++){
        cout << "Case: " <<  t+1 << endl;
        output << "Case #" << t+1 << ": ";
        
        input >> N >> M;
        toy.resize(M);
        box.resize(N);
        for(int n=0;n<N;n++){
            long long db;
            int type;
            input >> db >> type;
            box[n] = make_pair<long long, int>(db,type);
        }
        for(int m=0;m<M;m++){
            long long db;
            int type;
            input >> db >> type;
            toy[m] = make_pair<long long, int>(db,type);
        }
    
        long long count = dp(0,box[0].first,0,toy[0].first);
            
        output << count << endl;
        cout << count << endl;
    }
    input.close();
    output.close();
    
    return 0;
}

