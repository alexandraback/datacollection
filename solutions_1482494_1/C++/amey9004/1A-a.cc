#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

#define ll long long int
using namespace std;



int main (){
  int t;
  scanf("%d",&t);
  int m = t;
  while(t--){
      bool bad = false;
      int n, count=0, stars=0;
      cin>>n;
      int a[n][2];
      int ach[n];
      for(int i=0; i<n; i++){
        cin>>a[i][0];
        cin>>a[i][1];
        ach[i] = 0;
      }
/*      for(int i=0; i<n; i++){
        cout<<a[i][0]<<" ";
        cout<<a[i][1]<<endl;
      }*/
      int done = 0;
      while(done < n){
//         int min1, min0;
        bool found = false;
        for(int j=0; j<n; j++){
          if(ach[j] < 2 && a[j][1] <= stars){
//             cout<<" reuirement : "<<a[j][1]<<" current : "<<stars<<"ach : "<<ach[j]<<endl;
            found = true;
            count++;
            done++;
            if(ach[j] == 0) {
              stars += 2;
//               cout<<"incremented from 0 to  2 at : "<<j<<" stars : "<<stars<<"count : "<<count<<endl;
            }
            else {
              stars++;
//               cout<<"incremented from 1 to 2 at : "<<j<<" stars : "<<stars<<"count : "<<count<<endl;
            }
            ach[j] = 2;
          }
        }
        if(!found){
//           priority_queue<int> q;
          int max = -1;
          int index = -1;
          for(int j=0; j<n; j++){
            if(ach[j] == 0){
              if(a[j][0] <= stars){
                if(a[j][1] > max){
                  max = a[j][1];
                  index = j;
                }
              }
            }
          }
          if(index == -1){
            bad = true;
            break;
          }
          else{
            ach[index] = 1;
            count++;
            stars++;
//             cout<<"incremented from 0 to 1 at "<<index<<" stars : "<<stars<<"count : "<<count<<endl;
          }
        }
      }
      if(!bad)
        cout<<"Case #"<<m-t<<": "<<count<<endl;
      else
        cout<<"Case #"<<m-t<<": Too Bad"<<endl;
    }
  return 0;
}