/* 
 * File:   main.cpp
 * Author: eajisah
 *
 * Created on April 27, 2013, 6:33 AM
 */

#include <cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
#include<list>
#include<cctype>  //They check whether the character passed as parameter belongs to a certain category also lower to upper conversion done
#include<ciso646> //This header defines eleven macro constants with alternative spellings for those C++ operators not supported by the ISO646 standard character set
#include<climits>
#include<cmath>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<vector>
#define FT(t,n) for(int t=1;t<=n;t++)
#define FR(i,n) for(int i=0;i<n;i++)
#define RFR(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    freopen("A-small.in","r",stdin);
    freopen("A-small.out","w",stdout);
    long test,r,t,area;
    //double area,pi=3.14;
    cin>>test;
    FT(tt,test){
        cin>>r;
        cin>>t;
        long ctr=0;
        while(t>0){
            area=((r+1)*(r+1))-(r*r);
            //long div = area;
            t-=area;
            r+=2;
            //cout<<t<<endl;
            if(t>=0)
                ctr++;
        }
        cout<<"Case #"<<tt<<": "<<ctr<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

