#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

ofstream out("tttt");

char a[5000];
int nr[200];

void sol() {
    int i;
    memset(nr, 0, sizeof(nr));
    cin >> a;

    for(i = 0; a[i]; ++i) {
        nr[a[i]]++;
    }

    vector<int> rez;


    while(nr['X']) {

        nr['S']--;
        nr['I']--;
        nr['X']--;
        rez.push_back(6);
    }
    while(nr['S']) {

        nr['S']--;
        nr['E']--;
        nr['V']--;
        nr['E']--;
        nr['N']--;
        rez.push_back(7);
    }
    while(nr['V']) {

        nr['F']--;
        nr['I']--;
        nr['V']--;
        nr['E']--;
        rez.push_back(5);
    }
    while(nr['Z']) {

        nr['Z']--;
        nr['E']--;
        nr['R']--;
        nr['O']--;
        rez.push_back(0);
    }
    while(nr['W']) {

        nr['T']--;
        nr['W']--;
        nr['O']--;
        rez.push_back(2);
    }
    while(nr['G']) {

        nr['E']--;
        nr['I']--;
        nr['G']--;
        nr['H']--;
        nr['T']--;
        rez.push_back(8);
    }
    while(nr['H']) {

        nr['T']--;
        nr['H']--;
        nr['R']--;
        nr['E']--;
        nr['E']--;
        rez.push_back(3);
    }
        while(nr['R']) {

        nr['F']--;
        nr['O']--;
        nr['U']--;
        nr['R']--;
        rez.push_back(4);
    }
        while(nr['O']) {

        nr['O']--;
        nr['N']--;
        nr['E']--;
        rez.push_back(1);
    }

    while(nr['I']) {

        nr['N']--;
        nr['I']--;
        nr['N']--;
        nr['E']--;
        rez.push_back(9);
    }


    sort(rez.begin(), rez.end());
    for(i = 0; i < rez.size(); ++i)
        out << rez[i];

}

int main() {
    freopen("ttt", "r", stdin);
    //freopen("tttt", "w", stdout);

    int t, a = 0;
    cin >> t;

    while(t--) {
        ++a;
        out << "Case #" << a << ": ";
        sol();
        out << "\n";

        printf("Test %d\n", a);
    }

    return 0;
}
