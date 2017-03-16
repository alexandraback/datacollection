#include <iostream>
#include<vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for(int k=0; k<t; k++)
    {
        string s;
        cin >> s;
        int count[26]={0};
        for(char c : s){
            count[c-'A']++;
        }
        vector<int> result;
        while(count['Z'-'A']>0){
            result.push_back(0);
            count['Z'-'A']--;
            count['E'-'A']--;
            count['R'-'A']--;
            count['O'-'A']--;
        }
        while(count['W'-'A']>0){
            result.push_back(2);
            count['T'-'A']--;
            count['W'-'A']--;
            count['O'-'A']--;
        }
        while(count['U'-'A']>0){
            result.push_back(4);
            count['F'-'A']--;
            count['O'-'A']--;
            count['U'-'A']--;
            count['R'-'A']--;
        }
        while(count['F'-'A']>0){
            result.push_back(5);
            count['F'-'A']--;
            count['I'-'A']--;
            count['V'-'A']--;
            count['E'-'A']--;
        }
        while(count['X'-'A']>0){
            result.push_back(6);
            count['S'-'A']--;
            count['I'-'A']--;
            count['X'-'A']--;
        }
        while(count['S'-'A']>0){
            result.push_back(7);
            count['S'-'A']--;
            count['E'-'A']--;
            count['V'-'A']--;
            count['E'-'A']--;
            count['N'-'A']--;
        }
        while(count['G'-'A']>0){
            result.push_back(8);
            count['E'-'A']--;
            count['I'-'A']--;
            count['G'-'A']--;
            count['H'-'A']--;
            count['T'-'A']--;
        }
        while(count['I'-'A']>0){
            result.push_back(9);
            count['N'-'A']--;
            count['I'-'A']--;
            count['N'-'A']--;
            count['E'-'A']--;
        }
        while(count['O'-'A']>0){
            result.push_back(1);
            count['O'-'A']--;
            count['N'-'A']--;
            count['E'-'A']--;
        }
        while(count['T'-'A']>0){
            result.push_back(3);
            count['T'-'A']--;
            count['H'-'A']--;
            count['R'-'A']--;
            count['E'-'A']--;
            count['E'-'A']--;
        }
        sort(result.begin(), result.end());
        cout << "Case #" << k+1 << ": ";
        for(int item : result){
            cout << item;
        }
        cout << endl;
    }
    return 0;
}
