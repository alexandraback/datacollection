#include <bits/stdc++.h>
using namespace std;

int t;
int n[100];
string s;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d\n",&t);
    for(int k = 0; k < t; k++){
        cin >> s;
        vector<int> d(10);
        for(char i : s){
            n[i]++;
        }
        while(n['Z']){
            d[0]++;
            n['Z']--;
            n['E']--;
            n['R']--;
            n['O']--;
        }
        while(n['X']){
            d[6]++;
            n['S']--;
            n['I']--;
            n['X']--;
        }
        while(n['W']){
            d[2]++;
            n['T']--;
            n['W']--;
            n['O']--;
        }
        while(n['G']){
            d[8]++;
            n['E']--;
            n['I']--;
            n['G']--;
            n['H']--;
            n['T']--;
        }
        while(n['S']){
            d[7]++;
            n['S']--;
            n['E']--;
            n['V']--;
            n['E']--;
            n['N']--;
        }
        while(n['V']){
            d[5]++;
            n['F']--;
            n['I']--;
            n['V']--;
            n['E']--;
        }
        while(n['F']){
            d[4]++;
            n['F']--;
            n['O']--;
            n['U']--;
            n['R']--;
        }
        while(n['O']){
            d[1]++;
            n['O']--;
            n['N']--;
            n['E']--;
        }
        while(n['T']){
            d[3]++;
            n['T']--;
            n['H']--;
            n['R']--;
            n['E']--;
            n['E']--;
        }
        while(n['N']){
            d[9]++;
            n['N']--;
            n['I']--;
            n['N']--;
            n['E']--;
        }
        cout << "Case #" << k+1 << ": ";
        for(int i = 0; i <= 9; i++){
            while(d[i]){
                d[i]--;
                cout << i;
            }
        }
        cout << endl;
    }
}