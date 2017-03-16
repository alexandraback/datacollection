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
    string s;

    cin>>s;

    char out [2010];

    int curr=1001;
    int nextl=curr-1;
    int nextr=curr+1;
    int size=s.size();

    out[curr]=s[0];


    forn (i, s.size()-1){

      if(s[i+1]>=out[nextl+1]) {
        out[nextl]=s[i+1];
        nextl--;
      }
      else {
        out[nextr]=s[i+1];
        nextr++;
      }

    }


    cout<< "Case #"<<i+1<<": ";

    for (int i=nextl+1; i<nextr; i++){
      cout<<out[i];
    }
    cout<<endl;

  }
  return 0;

  }
