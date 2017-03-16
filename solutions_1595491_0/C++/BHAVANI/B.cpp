//
//  B.cpp
//  DESIGN
//
//  Created by Shankar, Penumaka Bhavani on 4/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
// v total sums , s is sum, 
map < int, vector < vector <int> > > mHash[2];
int f(int n , int s, int p ,vector <int> v )
{
    // have only those which are less than p in a set without using s
    vector <int> lessThanP;
    int ret = 0;
    for ( int i = 0 ; i < v.size(); i++) 
    {
        vector < vector <int> > tV = mHash[0][v[i]];
        bool BlessThanP = true;;
        for ( int j = 0 ; j < tV.size(); j++ )
        {
            if ( tV[j][0] >= p )
            {
                BlessThanP = false;
            }
        }
        ret++;
        if (BlessThanP)
        {
            ret--;
            lessThanP.push_back(v[i]);
        }
    }
    for ( int i =0 ; i < lessThanP.size();i++)
    {
        if ( s == 0 )
        {
            break;
        }
        vector < vector <int> > tV = mHash[1][lessThanP[i]];
        bool BlessThanP = true;
        for ( int j = 0 ; j < tV.size(); j++ )
        {
            if ( tV[j][0] >= p )
            {
                BlessThanP = false;
            }
        }
        if( !BlessThanP )
        {
            ret++;
            s--;
        }
    }
    cout << ret << endl;
}
int check(int x,int y, int z, int val)
{
    return ((x-y) <= val) && ((y-z) <= val) && ((x-z)<= val );
}
void preprocess()
{
    for ( int i = 0 ; i <= 10; i++ )
    {
        for ( int j = 0; j <= i; j++ )
        {
            for ( int k = 0; k <= j; k++ )
            {
                if ( check(i,j,k, 1) )
                {
                    vector <int> sTmp;
                    sTmp.push_back(i); sTmp.push_back(j); sTmp.push_back(k);
                    if ( mHash[0].count(i+j+k) == 0 )
                    {
                        vector< vector< int> > v;
                        mHash[0][i+j+k] = v;
                    }
                    
                    mHash[0][i+j+k].push_back(sTmp);
                }
                else if ( check(i,j,k, 2) )
                {
                    vector <int> sTmp;
                    sTmp.push_back(i); sTmp.push_back(j); sTmp.push_back(k);
                    
                    if ( mHash[1].count(i+j+k) == 0 )
                    {
                        vector< vector< int> > v;
                        mHash[1][i+j+k] = v;
                    }
                    mHash[1][i+j+k].push_back(sTmp);
                }
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    preprocess();
    for ( int i = 0 ;i < t; i++ )
    {
        cout << "Case #"<<(i+1)<<": ";
        int n,s,p;
        vector <int> v;
        cin >> n >> s >> p;
        for ( int i  = 0 ; i < n; i++ )
        {
            int u;
            cin  >> u;
            v.push_back(u);
        }
        f(n,s,p,v);
    }
}
