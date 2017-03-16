#include <vector>
#include <fstream>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#define eps=1e-8
using namespace std;

//correct

struct level{
    int onestar;
    int twostar;
};
vector <level> levels;
bool used[2][1000];



bool mysort(level a,level b){
    if (a.twostar!=b.twostar)return (a.twostar<b.twostar);
    return (a.onestar<b.onestar);
}

int main(){
    ofstream fout ("B-small-attempt1.out");
    ifstream fin ("B-small-attempt1.in");

int testcases;
fin>>testcases;

for (int tests=1;tests<=testcases;tests++){
    memset(used,0,sizeof(used));
    levels.clear();
int n;
fin>>n;

for (int i=0;i<n;i++){
    level temp;
    fin>>temp.onestar;
    fin>>temp.twostar;
    levels.push_back(temp);
   // cout<<levels[i].onestar<<"-"<<levels[i].twostar<<endl;
}
sort(levels.begin(),levels.end(),mysort);
int stars=0;
int totalused=0;
int lv2done=0;
int thistime=0;
int lasttime=-1;
here:
    //cout<<stars<<endl;
   
    if (lv2done==n)goto thispoint;
   // cout<<"!";
    if (lasttime==stars){
        fout<<"Case #"<<tests<<": Too Bad"<<endl;
         //system("pause");
        continue;
        
    }
    lasttime=thistime;
    lasttime=stars;
    cout<<"!";
for (int i=0;i<n;i++){
    cout<<"!";
    
    if (used[1][i])continue;
    
    
    if (levels[i].twostar<=stars){
       stars+=2;
    
        used[0][i]=1;
        used[1][i]=1;
        totalused++;
        lv2done++;
        cout<<levels[i].onestar<<" "<<levels[i].twostar<<endl;
        goto here;
}
}

    for (int i=0;i<n;i++){
        if (used[0][i])continue;
        if (used[1][i])continue;
        if (levels[i].onestar<=stars){
            cout<<levels[i].onestar<<" "<<levels[i].twostar<<endl;
            stars++;
            totalused++;
            used[0][i]=1;
            goto here;
        }
        
    }
    goto here;
    


thispoint:
cout<<"Case #"<<tests<<": "<<totalused<<endl;
fout<<"Case #"<<tests<<": "<<totalused<<endl;
} 

//system("pause");
return 0;
}
