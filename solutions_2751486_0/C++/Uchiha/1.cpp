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
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int a,n,t;
    cin>>t;
    for(int k=0;k<t;k++){
        string s;
       cin>>s;
        cin >> n;
        int c=0;
        for(int i=0;i<s.size();i++){
            string s1="";
            for(int j=i;j<s.size();j++){
                s1 += s[j];
                replace(s1.begin(),s1.end(),'a',' ');
                replace(s1.begin(),s1.end(),'e',' ');
                replace(s1.begin(),s1.end(),'i',' ');
                replace(s1.begin(),s1.end(),'o',' ');
                replace(s1.begin(),s1.end(),'u',' ');
                stringstream ss(s1);
                string s2;
                while(ss>>s2){
                    if(s2.size()>=n){
                        c++;
                        break;
                    }
                }

            }
        }
        cout<<"Case #"<<k+1<<": "<<c<<endl;
    }

  return 0;
}
