/* 
 * File:   main.cpp
 * Author: eajisah
 *
 * Created on April 27, 2013, 8:01 AM
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
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int test,r,n,m,k,set[10000];
    cin>>test;
    FT(t,test){
        
        cin>>r;
        cin>>n;
        cin>>m;
        cin>>k;
        cout<<"Case #"<<t<<": "<<endl;
        FR(i,r){
            FR(j,k){
                cin>>set[j];
            }
            int max=set[0];
            FR(l,k){
                if(set[l]>max)
                    max=set[l];
            }
            int ct=0;
            
            for(int f=m;f>=2;f--){
                if(max%f==0 && ct<n){
                  max=max/f;
                  cout<<f;
                  ct++;
                }
                if(max==1 && ct<n){
                    cout<<2;
                    ct++;
                }
                
            }
            
            cout<<endl;
        }
        
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

