#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<fstream>
#define ll long long
using namespace std;


int main () {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int x,y,t;
    cin>>t;
    for(int k=0;k<t;k++){
        string s="";
        cin >> x >>y;
        if(x>0){
            for(int i=0;i<x;i++)
                s+="WE";
        }
        if(x<0)
        {
            for(int i=0;i<abs(x);i++)
                s+="EW";
        }

        if(y>0){
            for(int i=0;i<abs(y);i++)
                s+="NS";
        }

        if(y<0){
            for(int i=0;i<abs(y);i++)
                s+="SN";
        }

        cout<<"Case #"<<k+1<<": "<<s<<endl;
    }


  return 0;
}
