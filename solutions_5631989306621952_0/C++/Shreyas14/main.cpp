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
using namespace std;

typedef long long ll;

ll t;

int main() {
    ifstream infile;
    ofstream outfile;
    string s;
    infile.open("A-small-attempt0.in");
    outfile.open("output.in");
    infile>>t;
    for(int y=1;y<=t;y++){
        outfile<<"Case #"<<y<<": ";
        infile>>s;
        list<char> l;
        l.push_back(s[0]);
        for (int i=1; i<s.size(); i++) {
            if(l.front()<=s[i]){
                l.push_front(s[i]);
            }
            else{
                l.push_back(s[i]);
            }
        }
        for (list<char>::iterator r=l.begin(); r!=l.end(); r++) {
            outfile<<(*r);
        }
        outfile<<"\n";
        
    }
    return 0;
}
