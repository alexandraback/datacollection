#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

int T;
int diam;
vector<vector<int> > links;
queue<int> q;
int used[1003];
int n, tot;

int main() {
   int i, j, k;
   
   cin>>T;
   for(i=0; i<T; i++) {
      cout<<"Case #"<<i+1<<": ";
      
      diam=0;
      cin>>n;
      
      for(j=0; j<n; j++) {
         vector<int> currList;
         int curr;
         cin>>tot;
         for(k=0; k<tot; k++) { cin>>curr; currList.push_back(curr-1); }
         links.push_back(currList);
      }
      
      for(j=0; j<n; j++) {
         for(k=0; k<n; k++) used[k]=0;
         while(!q.empty()) q.pop();
         
         //cout<<"j: "<<j<<endl;
         
         q.push(j);
         while(!q.empty()) {
            int curr;
            curr = q.front();
            q.pop();
            //cout<<curr<<" ";
            if(used[curr]) { diam=1; break; }
            used[curr]=1;
            for(k=0; k<links[curr].size(); k++) {
               q.push(links[curr][k]);
            }
            //cout<<diam<<endl;
            if(diam) break; 
         }
         if(diam) break;   
      }

      if(diam) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;

      while(!q.empty()) q.pop();
      for(j=0; j<n; j++) links[j].clear();
      links.clear();

   }

   return 0;

}
