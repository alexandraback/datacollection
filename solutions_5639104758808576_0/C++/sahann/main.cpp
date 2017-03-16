//
//  main.cpp
//  GCJ2015QualA
//
//  Created by Nagi Nahas on 4/11/15.

//
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
//#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <fstream>

using namespace std;

ifstream cin("/users/naginahas/Documents/A-small-attempt0.in");
ofstream cout("/users/naginahas/Documents/A-smallout.txt");

int main(int argc, const char * argv[])
{
    int T = 0;
    cin >> T;
    for(int t=0;t<T;t++){
        int n;
        cin >> n;n++;
        char c;
        vector <int> vi;
        for(int i=0;i<n;i++) {
            cin >> c;
            vi.push_back(c - '0');
            
        }
        int sum = vi[0];
        int req = 0;
        for(int i=1;i<n;i++){
            if(i > sum){
                req+=i-sum;
                sum = i;
            }
            sum += vi[i];
        }
        cout << "Case #"<< t+1 << ": " << req << endl;
    }
    return 0;
}

