#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    // N diamond, pair<X,Y>, posibblity
    vector< map<pair<int,int>, double> >  m(21);
    
    m[1][pair<int,int>(0,0)] = 1.0;
    
    m[2] = m[2-1]; 
    m[2][pair<int,int>(2,0)] += 0.5;
    
    m[3] = m[3-1]; 
    m[3][pair<int,int>(2,0)] += 0.5*0.5;
    m[3][pair<int,int>(1,1)] += 0.5*0.5;
    
    m[4] = m[4-1]; 
    m[4][pair<int,int>(2,0)] = 1;
    m[4][pair<int,int>(1,1)] = 0.5;
    
    m[5] = m[5-1]; 
    m[5][pair<int,int>(2,0)] = 1;
    m[5][pair<int,int>(1,1)] = 1;
    
    m[6] = m[6-1]; 
    m[6][pair<int,int>(0,2)] = 1;
    
    int i;
    for(i=7;i<14;i++) {
        m[i] = m[i-1]; 
        m[i][pair<int,int>(4,0)] += max(0.0,pow(0.5,i-6));
        if(i-6-1>0) 
            m[i][pair<int,int>(3,1)] += max(0.0,pow(0.5,i-6-1));
        if(i-6-2>0) 
            m[i][pair<int,int>(2,2)] += max(0.0,pow(0.5,i-6-2));
        if(i-6-3>0) 
            m[i][pair<int,int>(1,3)] += max(0.0,pow(0.5,i-6-3));
    }
    
    i=14;
    m[i] = m[i-1]; 
    m[i][pair<int,int>(0,4)] = 1.0;
    m[i][pair<int,int>(3,1)] = 1.0;
    m[i][pair<int,int>(2,2)] = 1.0;
    m[i][pair<int,int>(3,1)] = 1.0;
    
    i=15;
    m[i] = m[i-1]; 
    m[i][pair<int,int>(3,0)] = 1.0;
    
    for(i=16;i<=20;i++) {
        m[i] = m[i-1]; 
        m[i][pair<int,int>(6,0)] += max(0.0,pow(0.5,i-15));
        if(i-15-1>0) 
        m[i][pair<int,int>(5,1)] += max(0.0,pow(0.5,i-15-1));
        if(i-15-2>0) 
        m[i][pair<int,int>(4,2)] += max(0.0,pow(0.5,i-15-2));
        if(i-15-3>0) 
        m[i][pair<int,int>(3,3)] += max(0.0,pow(0.5,i-15-3));
        if(i-15-4>0) 
        m[i][pair<int,int>(2,4)] += max(0.0,pow(0.5,i-15-4));
        if(i-15-5>0) 
        m[i][pair<int,int>(1,5)] += max(0.0,pow(0.5,i-15-5));
    }
    
    for(int i=4;0 && i<=20;i++) {
        cout << "i: " << i << endl;
        for(map<pair<int,int>, double>::iterator it=m[i].begin();it!=m[i].end();it++) {
            cout << it->first.first << "," << it->first.second << " " << it->second << endl;
        }
    }

    int test_cases=0;
    cin >> test_cases;
    for(int test_case=1;test_case<=test_cases;test_case++) {
        int N, X, Y;
        cin >> N >> X >> Y;
        printf("Case #%d: %6f\n",test_case,m[N][pair<int,int>(abs(X),abs(Y))]);
        //cout << "Case #" << test_case << ": " << m[N][pair<int,int>(X,Y)] << endl;
    }
    return 0;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 et: */
