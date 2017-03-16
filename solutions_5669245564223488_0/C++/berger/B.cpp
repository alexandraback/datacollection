#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cassert>

#define MOD 1000000007

using namespace std;

int n;
string strings[100];
int letterTiles[26];
int appears[26];
int isBetweenLetter[26];
int isStartLetter[26];
int isEndLetter[26];

int findStart(int l) {
    int i;
    for (i = 0; i < n; i++)
        if (strings[i][0]-'a' == l)
            return strings[i][strings[i].length()-1]-'a';
    return i;
}

int main() {
    int T, TT;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        scanf("%d", &n);
        
        fprintf(stderr, "%d ", T);
        
        int i, j;
        char temp[200];
        for (i = 0; i < n; i++) {
            scanf("%s", temp);
            strings[i] = temp;
        }
        
        for (i = 0; i < 26; i++) {
            letterTiles[i] = 0;
            appears[i] = 0;
            isBetweenLetter[i] = 0;
            isStartLetter[i] = 0;
            isEndLetter[i] = 0;
        }
        
        bool possible = true;
        
        //find out which things are only the same letter
        for (i = 0; i < n; i++) {
            for (j = 0; j < strings[i].length(); j++)
                if (strings[i][j] != strings[i][0])
                    break;
            if (j == strings[i].length()) {
                letterTiles[strings[i][0] - 'a']++;
                appears[strings[i][0] - 'a']++;
                n--;
                swap(strings[i], strings[n]);
                i--;
            }
        }
        
        //now go through and count the number of things each letter appears in
        for (i = 0; i < n; i++) {
            int appearsNow[26] = {0};
            appearsNow[strings[i][0] - 'a']++;
            for (j = 1; j < strings[i].length(); j++) {
                if (appearsNow[strings[i][j]-'a'] && strings[i][j] != strings[i][j-1])
                    possible = false;
                appearsNow[strings[i][j] - 'a']++;
            }
            int startLetter = strings[i][0]-'a';
            int endLetter = strings[i][strings[i].length()-1] - 'a';
            for (j = 0; j < 26; j++) {
                if  (appearsNow[j] && j != startLetter && j != endLetter)
                    isBetweenLetter[j]++;
                if (appearsNow[j])
                    appears[j]++;
            }
            isStartLetter[startLetter]++;
            isEndLetter[endLetter]++;
        }
        
        if (!possible) {
            printf("0\n");
            continue;
        }
        
        //not possible if some letter is a between letter in more than one string, a start letter in more than one thing, 
        //a start/end letter and a between letter, an end letter in more than one thing
        for (i = 0; i < 26; i++) {
            //if (appears[i]) {
            //    printf("%c: %d %d %d %d %d\n", i+'a', appears[i], isBetweenLetter[i], isStartLetter[i], isEndLetter[i], letterTiles[i]);
            //}
            if (isBetweenLetter[i] > 1)
                possible = false;
            if (isBetweenLetter[i] && (isStartLetter[i] || isEndLetter[i] || letterTiles[i]))
                possible = false;
            if (isStartLetter[i] > 1)
                possible = false;
            if (isEndLetter[i] > 1)
                possible = false;
        }
        
        if (!possible) {
            printf("0\n");
            continue;
        }
        
        //check for cycles
        for (i = 0; i < 26; i++) {
            if (!isEndLetter[i] || !isStartLetter[i])
                continue;
            int c = findStart(i);
            while (isStartLetter[c]) {
                if (c == i) {
                    possible = false;
                    break;
                }
                c = findStart(c);
            }
        }
        
        if (!possible) {
            printf("0\n");
            continue;
        }
                
        
        
        //now simply pair up all starts and ends, include things that have neither, then the answer is factorialling everything
        int chunks = n;
        for (i = 0; i < 26; i++)
            if (isStartLetter[i] && isEndLetter[i])
                chunks--;
        for (i = 0; i < 26; i++)
            if (letterTiles[i] && appears[i] == letterTiles[i])
                chunks++;
        assert (chunks <= 26);
        
        //finally the answer
        long long ans = 1;
        for (i = 1; i <= chunks; i++) {
            ans *= i;
            ans = ans % MOD;
        }
        for (i = 0; i < 26; i++) {
            if (letterTiles[i]) {
                for (j = 1; j <= letterTiles[i]; j++) {
                    ans *= j;
                    ans = ans % MOD;
                }
            }
        }
        
        printf("%lld\n", ans);
                
            
    }
}