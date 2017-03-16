#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <iostream>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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


using namespace std;


vector <string> train;
vector <bool> used;
vector <int> big;
long long counter;
bool alltogether(string str){
     /*for (char a = 'a';a<='z';a++){
     bool ok = true;
     bool found = false;
     for (int i=0;i<str.size();i++){
         if (str[i]!=a)continue;
         if (!found){
         found = true;
         continue;
         }
         if (found && str[i-1]!=a)return false;
         
    }
     
     }
     return true; */
     bool seen[26];
     for (int i=0;i<26;i++)seen[i]=0;
     for (int i=0;i<str.size();i++){
         if (!seen[str[i]-'a']){
         seen[str[i]-'a']=1;
         int j=0;
         while (i+j<str.size() && str[i]==str[i+j]){j++;i++;}
         i--;
         continue;
         }
         else return false;
         
     }
     return true;
     
}
void dfs(string end){
     //cout<<end<<endl;
     for (int i=0;i<used.size();i++){
         if (used[i]==0)break;
         if (i==used.size()-1){
         string ans;
         for (int i=0;i<train.size();i++){
             ans += train[big[i]];
         
         }
         /*for (int i=1;i<ans.size();i++){
             //if (ans[i]!=ans[i-1])break;
             if (!alltogether(ans))break;
             if (i==ans.size()-1)counter++;
             }*/
             if (!alltogether(ans))return;
             else counter++;
         
         return;
         }
         }
     for (int i=0;i<train.size();i++){
         if (used[i])continue;
         //if (train[i][0] == end[end.size()-1]){
         big.push_back(i);
         used[i]=true;
         dfs(train[i]);
         used[i]=false;
         big.pop_back();
                         
        // }
         
     }
     
     
}
/*
0-1
1-6
2-6
3-7
4-5
5-1
6-7
7-3
8-8
*/
ifstream fin("B-small-attempt1.in");
//ifstream fin("B.in");
ofstream fout("B.out");
int main(){
int t;
fin>>t;
for (int tests=0;tests<t;tests++){
    cout<<tests;

counter = 0;
int n;
fin>>n;
cout<<"-"<<n<<endl;
string trains[n];
used.clear();
train.clear();
big.clear();
for (int i=0;i<n;i++){
    string temp;
    used.push_back(0);
    fin>>temp;
    train.push_back(temp);
    trains[i]=temp;
}
/*for (int i=0;i<n;i++){
   // cout<<"Start with:"<<train[i]<<endl;
    big.push_back(i);
    used[i]=1;
    dfs(train[i]);
    used[i]=0;
    big.pop_back();
}*/
 do {
              string ans;
         for (int i=0;i<n;i++){
             ans += train[i];
         }
         if (alltogether(ans))counter++;
    //std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } while ( std::next_permutation(trains,trains+n) );



fout<<"Case #"<<tests+1<<": "<<counter<<endl;

}

//system("pause");
return 0;
}
