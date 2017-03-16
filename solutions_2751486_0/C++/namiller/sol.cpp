//
//  main.cpp
//  number1
//
//  Created by Nolan Miller on 5/12/13.
//  Copyright (c) 2013 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <sstream>	//string manipulation
#include <vector>	//dynamic arrays
#include <algorithm>//useful algorithms (sort) etc
#include <climits>	//data type cap info
#include <cmath>    //mathematical operations
#define min(A,B) (((A)>(B))?(B):(A))
#define max(A,B) (((A)<(B))?(B):(A))


using namespace std;
bool vowel(char in){
    if(in == 'a')
        return 1;
    if(in == 'e')
        return 1;
    if(in == 'i')
        return 1;
    if(in == 'o')
        return 1;
    if(in == 'u')
        return 1;

    return 0;
}
void printVect(vector<int> in){
    for (int i =0; i<in.size(); i++) {
        cout.width(3);
        cout<<in[i]<<" ";
    }
    cout<<endl;
}
void print1d(bool* array,int l){
    for(int i =0;i<l;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

bool nextNgood(bool* name, int start, int n){
    for (int i = start; i<start+n; i++) {
        if (name[i] == false) {
            return false;
        }
    }
    return true;
}

int doit(bool* name, int len, int n){
    // if next n letters are 1 mark point
    vector<int> locations;
    locations.push_back(-1);
    for (int i = 0 ; i<=len-n; i++) {
        if (nextNgood(name, i, n)) {
            locations.push_back(i);
        }
    }
    
    //for each location, right range * left range
    //also for every pair
    //also for...
    int ways = 0;
    int num = int(locations.size())-1; // minus 1 for the zero start
    locations.push_back(len-n+1);
    
//    printVect(locations);
//    cout<<num<<endl;

    for (int i = 1; i<=num; i++) {
        for (int ii = 1; ii+i<=num+1; ii++) {//check off by ones...
//            cout<<"i,ii"<<i<<","<<ii<<endl;
            ways+=(locations[ii]-locations[ii-1])*(locations[ii+i]-locations[ii+i-1]);
//            cout<<(locations[ii]-locations[ii-1])<<","<<(locations[ii+i]-locations[ii+i-1])<<endl;
        }
    }
    
    
    return ways;
}



int main(int argc, const char * argv[])
{
    int length;
    cin>>length;
    bool * name;
    string sname;
    int n;
for (int it=0; it<length; it++) {
    cin>>sname;
    cin>>n;
    name = new bool[sname.length()];
    for (int i=0; i<sname.length(); i++) {
        name[i] = !vowel(sname[i]);
    }
//    print1d(name, int(sname.length()));
    
    int ans = doit(name,int(sname.length()),n);
    
    cout<<"Case #"<<it+1<<": "<<ans<<endl;
}
    
}


