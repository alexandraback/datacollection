//
//  main.cpp
//  test
//
//  Created by Shreyas Sinha on 09/04/16.
//  Copyright © 2016 Shreyas Sinha. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

int t,n,num;

int main() {
    ifstream infile;
    ofstream outfile;
    
    infile.open("B-large.in");
    outfile.open("output.in");
    infile>>t;
    for(int y=1;y<=t;y++){
        infile>>n;
        outfile<<"Case #"<<y<<": ";
        multiset<int> s;
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<n;j++){
                infile>>num;
                multiset<int>::iterator r=s.find(num);
                if(r!=s.end()){
                    s.erase(r);
                }
                else{
                    s.insert(num);
                }
            }
        }
        for(multiset<int>::iterator c=s.begin();c!=s.end();c++){
            outfile<<(*c)<<" ";
        }
        outfile<<"\n";
        
    }
    return 0;
}
