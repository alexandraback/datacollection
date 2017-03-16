#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <functional>
#include <deque>
#include <algorithm> 

#define PI 6*asin( 0.5 )
typedef long long LL;

using namespace std;

int solv(string translation,int j,string test){
    ofstream ofs("ans.txt",ios::app|ios::ate);
    
    int len=test.size();
    cout<<"Case #"<<j+1<<": ";
    ofs<<"Case #"<<j+1<<": ";

    //cout<<test<<endl;
    for (int i =0 ; i<len; i++) {
        if (test[i]==' ') {
            cout<<' ';
            ofs<<' ';

        }else{
            cout<<translation[test[i]-97];
            ofs<<translation[test[i]-97];
        }
    }
    
    cout<<endl;
    ofs<<endl;
            
           
    return 0;
}

int main(){

    int t;cin>>t;
    cin.get();

    string translation("yhesocvxduiglbkrztnwjpfmaq");
    vector<string> tests;
    for (int i=0; i< t ; i++) {
        string buf;
        getline(cin,buf);
        tests.push_back(buf);
    }
    
    for (int i=0; i<t ; i++) {
        solv(translation,i,tests[i]);
    }
    
    return 0;
}