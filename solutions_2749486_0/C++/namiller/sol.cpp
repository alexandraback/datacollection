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





int main(int argc, const char * argv[])
{
    int length;
    cin>>length;
    int x,y;
    for (int it=0; it<length; it++) {
        cin>>x;
        cin>>y;
        string ans;
        
        for (int i = 0; i<abs(x); i++) {
            if (x>0) {
                ans.append("WE");
            }
            else
                ans.append("EW");
        }
        for (int i = 0; i<abs(y); i++) {
            if (y>0) {
                ans.append("SN");
            }
            else
                ans.append("NS");
        }
        
        cout<<"Case #"<<it+1<<": "<<ans<<endl;
    }
    
}


