#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void minusOne(int letter[], char ch) {
    letter[ch-'A']--;
}

int main() {
    int t, n ;
    int ca = 1;
    char str[300];
    scanf("%d", &t);
    int letter[26];
    int num[10];
    int i,j;
    while (ca <= t) {
        cout<<"Case #"<<ca<<": ";
        scanf("%s", str);
        for (i=0; i<26; i++) letter[i] = 0;
        for (i=0; i<10; i++) num[i] = 0;
        for (i=0; str[i] != 0; i++) {
            letter[str[i]-'A']++;
        }
        while(letter['Z'-'A']!=0) {
            num[0]++;
            minusOne(letter, 'Z');
            minusOne(letter, 'E');
            minusOne(letter, 'R');
            minusOne(letter, 'O');
        }
        while(letter['X'-'A']!=0) {
            num[6]++;
            minusOne(letter, 'S');
            minusOne(letter, 'I');
            minusOne(letter, 'X');
        }
        while(letter['G'-'A']!=0) {
            num[8]++;
            minusOne(letter, 'E');
            minusOne(letter, 'I');
            minusOne(letter, 'G');
            minusOne(letter, 'H');
            minusOne(letter, 'T');
        }
        while(letter['W'-'A']!=0) {
            num[2]++;
            minusOne(letter, 'T');
            minusOne(letter, 'O');
            minusOne(letter, 'W');
        }
        while(letter['U'-'A']!=0) {
            num[4]++;
            minusOne(letter, 'F');
            minusOne(letter, 'O');
            minusOne(letter, 'U');
            minusOne(letter, 'R');
        }
        while(letter['F'-'A']!=0) {
            num[5]++;
            minusOne(letter, 'F');
            minusOne(letter, 'I');
            minusOne(letter, 'V');
            minusOne(letter, 'E');
        }
        while(letter['S'-'A']!=0) {
            num[7]++;
            minusOne(letter, 'S');
            minusOne(letter, 'E');
            minusOne(letter, 'V');
            minusOne(letter, 'E');
            minusOne(letter, 'N');
        }
        while(letter['S'-'A']!=0) {
            num[7]++;
            minusOne(letter, 'S');
            minusOne(letter, 'E');
            minusOne(letter, 'V');
            minusOne(letter, 'E');
            minusOne(letter, 'N');
        }
        while(letter['R'-'A']!=0) {
            num[3]++;
            minusOne(letter, 'T');
            minusOne(letter, 'H');
            minusOne(letter, 'R');
            minusOne(letter, 'E');
            minusOne(letter, 'E');
        }
        while(letter['O'-'A']!=0) {
            num[1]++;
            minusOne(letter, 'O');
            minusOne(letter, 'N');
            minusOne(letter, 'E');
        }
        while(letter['N'-'A']!=0) {
            num[9]++;
            minusOne(letter, 'N');
            minusOne(letter, 'I');
            minusOne(letter, 'N');
            minusOne(letter, 'E');
        }
        for (i=0; i<10; i++) {
            while (num[i] != 0) {
                num[i]--;
                cout<<i;
            }
        }
        cout<<endl;
        ca++;
    }
    return 0;
}

