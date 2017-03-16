//
//  main.cpp
//  Round-2-B-Prob1
//
//  Created by Nolan Miller on 5/4/13.
//  Copyright (c) 2013 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <sstream>	//string manipulation
#include <vector>	//dynamic arrays
#include <algorithm>//useful algorithms (sort) etc
#include <climits>	//data type cap info
#include <cmath>    //mathematical operations
#define min(A,B) (((A)>(B))?(B):(A))

using namespace std;

void printVect(vector<int> in){
    for (int i =0; i<in.size(); i++) {
        cout.width(3);
        cout<<in[i]<<" ";
    }
    cout<<endl;
}

int sum(vector<int>&motes){
    int ans=0;
    for (int i =0 ; i<motes.size(); i++) {
        ans+=motes[i];
    }
    return ans;
}

void expand(vector<int>& motes, int &user){
    while (!motes.empty()&&motes[0]<user) {
        user+=motes[0];
        motes.erase(motes.begin());
    }
}
int noRemCalc(vector<int> array,int user){
    expand(array, user);
    int ops=0;
    while (!array.empty()) {
        array.insert(array.begin(), user-1);
        ops++;
        expand(array, user);
    }
    return ops;
}

int calculate(vector<int>& motes,int user){

    expand(motes, user);
    int ans = int(motes.size());
    int ops = 0;
    
    if (user==1) {
        return int(motes.size());
    }
    while (!motes.empty()) {
        ans = min(noRemCalc(motes, user)+ops,ans);
        motes.pop_back();
        ops++;
    }
    //remove last element
    //run
    //if needed insert user-1 in clutch
    //run etc
    //calculate ops without removing anything else
    //goback to begining and try with removing one more
    

    return ans;
    
}



int main(int argc, const char * argv[])
{
    int length;
cin>>length;
//data members here
    int sz;
    int usersz;
    int ans;
    for (int it=0; it<length; it++) {
        cin>>usersz;
        cin>>sz;
        vector<int> array;
        int tmp;
        for (int i=0; i<sz; i++) {
            cin>>tmp;
            array.push_back(tmp);
        }
        sort(array.begin(), array.end());
        ans = calculate(array, usersz);
        
        cout<<"Case #"<<it+1<<": "<<ans<<endl;
    }

    return 0;
}


