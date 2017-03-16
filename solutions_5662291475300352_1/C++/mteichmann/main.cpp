//
//  main.cpp
//  hello1
//
//  Created by Marvin Teichmann on 12.04.14.
//  Copyright (c) 2014 mteichmann. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <assert.h>

using namespace std;

bool init();

void readarray(vector<int>& v);
void readarray(vector<double>& v);

void printarray(vector<int>& v);
void printarray(vector<double>& v);
void print(int _case);


ifstream ifile;
ofstream ofile;

stringstream out;


struct hiker{
    double pos;
    double speed;
};

double reaches_end(hiker a) {
    return (1-a.pos/360)*a.speed;

}


struct hiker_less {
    bool operator ()(hiker const& a, hiker const& b) const {
        if (reaches_end(a) > reaches_end(b)) return true;
        return false;
    }
};

double slow_cuts_fast(hiker fast, hiker slow) {
    double new_pos = fast.pos - 360;
    double mypos = slow.pos + fast.speed * (slow.pos -new_pos) / (slow.speed- fast.speed);
    return mypos;
}

bool slow_cuts_fast_early(hiker fast, hiker slow) {
    double new_pos = fast.pos - 360;
    if(slow.speed == fast.speed) {
        return false;
    }
    if(fast.speed > slow.speed) {
        return false;
    }
    double mypos = slow.pos + fast.speed * (slow.pos -new_pos) / (slow.speed- fast.speed);
    if(mypos > 360) {
        return false;
    }else{
        return true;
    }
}

int num_slow_cuts_fast(hiker fast, hiker slow) {
    double new_pos = fast.pos - 360;
    if(slow.speed == fast.speed) {
        return 0;
    }
    if(fast.speed > slow.speed) {
        return 0;
    }
    double mypos = slow.pos + fast.speed * (slow.pos -new_pos) / (slow.speed- fast.speed);
    if(mypos > 360) {
        return 0;
    }else{
        double dist = -fast.speed * (slow.pos - 360) / (slow.speed- fast.speed);
        return floor((360 - mypos) / dist+0.00000000001) + 1; //TODO!!!!
    }
}

int num_cuts(int pos_hiker_vector, std::vector<hiker>& hikers) {
    int num_cuts = 0;
    for(int j = hikers.size()-1; j > pos_hiker_vector; --j) {
        num_cuts += num_slow_cuts_fast(hikers[j], hikers[pos_hiker_vector]);
    }
    return num_cuts;
}


int main(int argc, const char * argv[])
{
    string line;
    int cases;
    int size;
    
    if(!init() ) {
        cerr << "Error during initialization \n";
        return 1;
    }
    
    ifile>>cases;
    cout << cases << endl;
    getline(ifile,line);
    for(int case_ = 1; case_ <= cases; ++case_){
        out.str("");
        cout << "\nBegin with Case #" << case_ << ": \n";

        int groups;
        ifile>>groups;
        std::cout << "groups: " << groups << endl;
        int pos;
        int speed;
        int group_size;

        std::vector<hiker> hikers;

        for(int i = 0; i < groups; ++i) {
            ifile >> pos;
            ifile >> group_size;
            ifile >> speed;

            for(int j=0; j < group_size; ++j) {
                hiker h = {pos,speed+j};
                hikers.push_back(h);
            }
        }

        sort(hikers.begin(),hikers.end(),hiker_less());

        int min_meets = hikers.size();

        for(int i = 0; i < hikers.size(); ++i) {
            int my_meets = i + num_cuts(i,hikers);
            if(my_meets < min_meets) {
                min_meets = my_meets; 
            }
        }

        out << min_meets;

        print(case_);
    }
    
        
    
    ifile.close();
    ofile.close();
    return 0;
}


bool init() {
    ifile.open("../input.in");
    ofile.open("../output");
    
    cout.precision(12);
    ofile.precision(12);
    out.precision(12);
    
    if(!ifile.is_open()) {
        
    }
    
    return true;
}

void readarray(vector<int>& v) {
    string line;
    getline(ifile,line);
    stringstream tok(line);
    int read;
    while(tok >> read) {
        v.push_back(read);
    }
}

void readarray(vector<double>& v) {
    string line;
    getline(ifile,line);
    stringstream tok(line);
    double read;
    while(tok >> read) {
        v.push_back(read);
    }
}

void print(int _case){
    string output = out.str();
    
    ofile << "Case #" << _case << ": " << output  << "\n";
    cout  << "Case #" << _case << ": " << output  << "\n";
    
    
}

void printarray(vector<int>& v) {
    for(size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
}


void printarray(vector<double>& v) {
    for(size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

struct comb {
    bool operator() (int i,int j) { return (i<j);}
    bool operator() (double i,double j) { return (i<j);}
    bool operator() (string i,string j) { return true;}
} mycomb;