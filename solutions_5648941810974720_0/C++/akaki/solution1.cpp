#include <bits/stdc++.h>

using namespace std;

int i,j,k,l,m,n,t;
string s;
string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int letters[26];
int answer[10];
int dd;
int b[10];

int main(){
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int test = 0; test < t; test++){
        cout << "Case #"<< test+1 << ": ";
            cin >> s;
            memset(letters, 0, sizeof(letters));
            memset(answer, 0, sizeof(answer));   
            memset(b, 0, sizeof(b));               
            l = s.size();         
            for (j = 0; j < l; j++){
                letters[s[j] - 'A']++;
            }
            int zeros = letters['Z' - 'A'];
            b[0] += zeros;
            l -= 4 * zeros;
            letters['Z' - 'A'] -= zeros; 
            letters['E' - 'A'] -= zeros; 
            letters['R' - 'A'] -= zeros; 
            letters['O' - 'A'] -= zeros;         
            int twos = letters['W' - 'A'];
            b[2] += twos;
            l -= 3 * twos;            
            letters['T' - 'A'] -= twos; 
            letters['W' - 'A'] -= twos; 
            letters['O' - 'A'] -= twos;           
            int fours = letters['U' - 'A'];
            b[4] += fours;
            l -= 4 * fours;                        
            letters['F' - 'A'] -= fours; 
            letters['O' - 'A'] -= fours; 
            letters['U' - 'A'] -= fours;          
            letters['R' - 'A'] -= fours;                                                                                       
            int sixes = letters['X' - 'A'];
            b[6] += sixes;
            l -= 3 * sixes;                        
            letters['S' - 'A'] -= sixes; 
            letters['I' - 'A'] -= sixes; 
            letters['X' - 'A'] -= sixes; 
            int eights = letters['G' - 'A'];
            b[8] += eights;
            l -= 5 * eights;                        
            letters['E' - 'A'] -= eights; 
            letters['I' - 'A'] -= eights; 
            letters['G' - 'A'] -= eights; 
            letters['H' - 'A'] -= eights;   
            letters['T' - 'A'] -= eights;     
            
            int sevens = letters['S' - 'A'];
            b[7] += sevens;
            l -= 5 * sevens;                        
            letters['S' - 'A'] -= sevens; 
            letters['E' - 'A'] -= sevens; 
            letters['V' - 'A'] -= sevens; 
            letters['E' - 'A'] -= sevens;   
            letters['N' - 'A'] -= sevens;
            
            int fives = letters['F' - 'A'];
            b[5] += fives;
            l -= 4 * fives;                        
            letters['F' - 'A'] -= fives; 
            letters['I' - 'A'] -= fives; 
            letters['V' - 'A'] -= fives; 
            letters['E' - 'A'] -= fives;   

            int nines = letters['I' - 'A'];
            b[9] += nines;
            l -= 4 * nines;                        
            letters['N' - 'A'] -= nines; 
            letters['I' - 'A'] -= nines; 
            letters['N' - 'A'] -= nines; 
            letters['E' - 'A'] -= nines;
            
            int ones = letters['O' - 'A'];
            b[1] += ones;
            l -= 3 * ones;                        
            letters['O' - 'A'] -= ones; 
            letters['N' - 'A'] -= ones; 
            letters['E' - 'A'] -= ones; 

            int threes = l / 5;
            b[3] += threes;
                           
            for (j = 0; j < 10; j++){
                for (k = 0; k < b[j]; k++){
                    cout << j;
                }
            }
            cout << "\n";                                                                                       
    }
    return 0;
}
