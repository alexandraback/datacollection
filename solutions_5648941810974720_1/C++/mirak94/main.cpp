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
string nums[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int main(){
    freopen("/Users/Masoud/Desktop/A-large.in.txt", "r", stdin);
    freopen("/Users/Masoud/Desktop/out.txt", "w", stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        char str[2100];
        scanf("%s",str);
        string s = str;
        int cnt [100];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<s.length();i++){
            cnt[s[i]]++;
        }
        string res ="";
        while (cnt['Z']) {
            res+="0";
            for(int i=0;i<nums[0].length();i++){
                cnt[nums[0][i]]--;
            }
        }
        while (cnt['W']) {
            res+="2";
            for(int i=0;i<nums[2].length();i++){
                cnt[nums[2][i]]--;
            }
        }
        while (cnt['U']) {
            res+="4";
            for(int i=0;i<nums[4].length();i++){
                cnt[nums[4][i]]--;
            }
        }
        while (cnt['X']) {
            res+="6";
            for(int i=0;i<nums[6].length();i++){
                cnt[nums[6][i]]--;
            }
        }
        while (cnt['G']) {
            res+="8";
            for(int i=0;i<nums[8].length();i++){
                cnt[nums[8][i]]--;
            }
        }
        while (cnt['O']) {
            res+="1";
            for(int i=0;i<nums[1].length();i++){
                cnt[nums[1][i]]--;
            }
        }
        while (cnt['F']) {
            res+="5";
            for(int i=0;i<nums[5].length();i++){
                cnt[nums[5][i]]--;
            }
        }
        while (cnt['S']) {
            res+="7";
            for(int i=0;i<nums[7].length();i++){
                cnt[nums[7][i]]--;
            }
        }
        while (cnt['H']) {
            res+="3";
            for(int i=0;i<nums[3].length();i++){
                cnt[nums[3][i]]--;
            }
        }
        while (cnt['I']) {
            res+="9";
            for(int i=0;i<nums[9].length();i++){
                cnt[nums[9][i]]--;
            }
        }
        sort(res.begin(), res.end());
        cout << "Case #"<<t<<": "<<res<<endl;
    }
    return 0;
}

