#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define MP(x,y) make_pair(x,y)

bool static comparedesc(const long &stud1, const long &stud2){
    return stud1 > stud2;
}

int main(){
    int t ;
    cin >> t;
    for(int _t=1; _t<=t; _t++){
        printf("Case #%d: ", _t);
        vector<int> count(256, 0);
        string s;
        cin >> s;
        vector<int> nums;
        for(int i=0; i<s.length(); i++){
            count[s[i]] += 1;
        }
        while(count['Z']>0){
            count['Z']--;
            count['E']--;
            count['R']--;
            count['O']--;
            nums.push_back(0);
        }
        while(count['W']>0){
            count['T']--;
            count['W']--;
            count['O']--;
            nums.push_back(2);
        }
        while(count['U']>0){
            count['F']--;
            count['O']--;
            count['U']--;
            count['R']--;
            nums.push_back(4);
        }
        while(count['X']>0){
            count['S']--;
            count['I']--;
            count['X']--;
            nums.push_back(6);
        }
        while(count['G']>0){
            count['E']--;
            count['I']--;
            count['G']--;
            count['H']--;
            count['T']--;
            nums.push_back(8);
        }
        while(count['F']>0){
            count['F']--;
            count['I']--;
            count['V']--;
            count['E']--;
            nums.push_back(5);
        }
        while(count['S']>0){
            count['S']--;
            count['E']--;
            count['V']--;
            count['E']--;
            count['N']--;
            nums.push_back(7);
        }
        while(count['O']>0){
            count['O']--;
            count['E']--;
            count['N']--;
            nums.push_back(1);
        }
        while(count['N']>0){
            count['N']--;
            count['I']--;
            count['N']--;
            count['E']--;
            nums.push_back(9);
        }
        while(count['T']>0){
            count['T']--;
            count['H']--;
            count['R']--;
            count['E']--;
            count['E']--;
            nums.push_back(3);
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
            cout << nums[i];
        cout << endl;
    }
    return 0;
}