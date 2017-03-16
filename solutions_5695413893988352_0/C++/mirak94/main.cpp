#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n,m;

int T;
string c,j;
string r1,r2;
int cur_min=1000000000;
void solve(int idx, string s1, string s2){
    if(idx==c.length()){
        int ci = atoi(s1.c_str());
        int cj = atoi(s2.c_str());
        if (abs(ci-cj)<cur_min) {
            cur_min=abs(ci-cj);
            r1=s1,r2=s2;
        }
        return ;
    }
    if (s1[idx]=='?'&&s2[idx]=='?') {
        for (char a ='0'; a<='9'; a++) {
            for (char b ='0'; b<='9'; b++) {
                s1[idx]=a;
                s2[idx]=b;
                solve(idx+1, s1,s2);
            }
        }
    }else if(s1[idx]=='?'){
        for (char b ='0'; b<='9'; b++) {
            s1[idx]=b;
            solve(idx+1, s1, s2);
        }
    }else if(s2[idx]=='?'){
        for (char b ='0'; b<='9'; b++) {
            s2[idx]=b;
            solve(idx+1, s1, s2);
        }
    }else{
        solve(idx+1, s1, s2);
    }
}
int main(){
    freopen("/Users/Masoud/Desktop/B-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/Masoud/Desktop/out.txt", "w", stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        char str1[100],str2[100];
        scanf("%s %s",str1,str2);
        c=str1,j=str2;
        cur_min=1000000000;
        solve(0, c, j);
        cout << "Case #"<<t<<": "<<r1<<" "<<r2<<endl;
    }
    return 0;
}

