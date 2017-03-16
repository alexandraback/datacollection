#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
using namespace std;


int main(){
    int t, TC=1;
    string s;
    int digits[11], letters[30], menor;

    scanf("%d", &t);

    while(t--){
        memset(digits, 0, sizeof digits);
        memset(letters, 0, sizeof letters);

        cin >> s;

        for(int i = 0 ; s[i] ; i++){
            letters[s[i]-'A']++;
        }

        if(letters['Z' - 'A'] != 0 && letters['E' - 'A'] != 0 && letters['R' - 'A'] != 0 && letters['O' - 'A']){
            //digits[0] = letters['Z' - 'A'];
            menor = min(min(letters['Z' - 'A'], letters['E' - 'A']), min(letters['R' - 'A'], letters['O' - 'A']));
            digits[0] = menor;
            letters['E' - 'A'] -= menor;
            letters['R' - 'A'] -= menor;
            letters['O' - 'A'] -= menor;
            letters['Z' - 'A'] -= menor;
        }

        if(letters['W' - 'A'] != 0){
            menor = min(min(letters['T' - 'A'], letters['W' - 'A']), letters['O' - 'A']);
            digits[2] = menor;
            //digits[2] = letters['W' - 'A'];
            letters['T' - 'A'] -= menor;
            letters['O' - 'A'] -= menor;
            letters['W' - 'A'] -= menor;
        }

        if(letters['U' - 'A'] != 0){
            menor = min(min(letters['F' - 'A'], letters['O' - 'A']), min(letters['U' - 'A'], letters['R' - 'A']));
            digits[4] = menor;
            letters['F' - 'A'] -= menor;
            letters['O' - 'A'] -= menor;
            letters['R' - 'A'] -= menor;
            letters['U' - 'A'] -= menor;
        }

        if(letters['V' - 'A'] != 0){
            menor = min(min(letters['F' - 'A'], letters['I' - 'A']), min(letters['V' - 'A'], letters['E' - 'A']));
            digits[5] = menor;
            letters['F' - 'A'] -= menor;
            letters['I' - 'A'] -= menor;
            letters['E' - 'A'] -= menor;
            letters['V' - 'A'] -= menor;
        }

        if(letters['X' - 'A'] != 0){
            menor = min(min(letters['S' - 'A'], letters['I' - 'A']), letters['X' - 'A']);
            digits[6] = menor;
            letters['S' - 'A'] -= menor;
            letters['I' - 'A'] -= menor;
            letters['X' - 'A'] -= menor;
        }

        if(letters['G' - 'A'] != 0){
            menor = min(min(letters['E' - 'A'], letters['I' - 'A']), min(letters['G' - 'A'], letters['H' - 'A']));
            menor = min(menor, letters['T'-'A']);
            digits[8] = menor;
            letters['E' - 'A'] -= menor;
            letters['I' - 'A'] -= menor;
            letters['H' - 'A'] -= menor;
            letters['T' - 'A'] -= menor;
            letters['G' - 'A'] -= menor;
        }


        /// only O
        if(letters['O' - 'A'] != 0 && letters['N' - 'A'] != 0 && letters['E' - 'A'] != 0){
            menor = min(min(letters['O' - 'A'], letters['N' - 'A']), letters['E' - 'A']);
            digits[1] = menor;
            letters['N' - 'A'] -= menor;
            letters['E' - 'A'] -= menor;
            letters['O' - 'A'] -= menor;
        }

        if(letters['T' - 'A'] != 0 && letters['H' - 'A'] != 0 && letters['R' - 'A'] != 0 && letters['E' - 'A'] != 0){
            menor = min(min(letters['T' - 'A'], letters['H' - 'A']), min(letters['R' - 'A'], letters['E' - 'A']));
            digits[3] = menor <= letters['E'-'A']/2 ? menor : letters['E'-'A']/2;
            letters['H' - 'A'] -= menor;
            letters['R' - 'A'] -= menor;
            letters['E' - 'A'] -= menor;
            letters['E' - 'A'] -= menor;
            letters['T' - 'A'] -= menor;
        }

        if(letters['S' - 'A'] != 0 && letters['E' - 'A'] != 0 && letters['V' - 'A'] != 0 && letters['N' - 'A'] != 0){
            digits[7] = letters['S' - 'A'];
            menor = min(min(letters['S' - 'A'], letters['E' - 'A']), min(letters['V' - 'A'], letters['N' - 'A']));
            digits[7] = menor <= letters['E'-'A']/2 ? menor : letters['E'-'A']/2;
            letters['E' - 'A'] -= menor;
            letters['V' - 'A'] -= menor;
            letters['E' - 'A'] -= menor;
            letters['N' - 'A'] -= menor;
            letters['S' - 'A'] -= menor;
        }

        if(letters['N' - 'A'] != 0 && letters['I' - 'A'] != 0 && letters['N' - 'A'] != 0 && letters['E' - 'A'] != 0){
            menor = min(min(letters['N' - 'A'], letters['I' - 'A']), letters['E' - 'A']);
            digits[9] = menor <= letters['N'-'A']/2 ? menor : letters['N'-'A']/2;
            //letters['I' - 'A'] -= letters['N' - 'A'];
            //letters['E' - 'A'] -= letters['N' - 'A'];
            //letters['N' - 'A'] = 0;
        }

        printf("Case #%d: ", TC++);
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0 ; j < digits[i] ; j++){
                printf("%d", i);
            }
        }
        printf("\n");



    }

    return 0;
}
