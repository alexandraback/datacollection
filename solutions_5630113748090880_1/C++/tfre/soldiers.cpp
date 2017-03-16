#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back


int main(){
  int t;
  //int app[10]={0};

  cin>>t;


  forn (i,t){

    int n;
    cin>>n;
    int heights[2600]={0};

    int apple;

    forn (i,2*n-1){
      forn (j,n){
        cin>>apple;
        heights[apple]++;

        //cout<<"heig "<<heights[apple]<<"ap "<<apple<<endl;
      }
    }

    int miss[100];
    int lasmi=0;

    forn (i,2600){
      if (heights[i]%2!=0){
        miss[lasmi]=i;
        lasmi++;
        //cout<<"las "<<miss[lasmi-1]<<"i "<<i<<endl;
      }
    }


    sort (miss,miss+lasmi);


    cout<< "Case #"<<i+1<<": ";

    forn (i,lasmi){
      cout<<miss[i]<<" ";
    }
    cout<<endl;

  }
  return 0;

  }
