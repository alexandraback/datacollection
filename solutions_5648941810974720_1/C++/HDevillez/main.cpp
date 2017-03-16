#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <cctype>
#include <iomanip>
#include <list>
#include <cstring>

#define INF 2000000000
#define ull double
#define vi vector<int>
#define vii vector<ii>

#define UNVISITED 0
#define OPENED 1
#define CLOSED 2

#define NBNODE 2000


using namespace std;


map <char, int> letters;


string numbers[10] = {"ZERO", "FOUR", "TWO", "SIX", "EIGHT", "THREE", "ONE", "FIVE", "SEVEN", "NINE"};

int mapInt[10] = {0,4,2,6,8,3,1,5,7,9};
int rep[10];

int main () {  

    int nCase;
    scanf("%d", &nCase);
    
    cin.ignore();

    for(int iCase= 0; iCase < nCase; iCase++) {
    
        string s;
        getline(cin, s);

        for(int i= 0; i < s.size(); i++) {
            letters[s[i]]++;
        }
        
        for(int i= 0; i < 10; i++) {
            int nb = 0;
            while(true) {
                vector <char> toRestore;
                bool fail = false;

                for(int j = 0; j < numbers[i].size(); j++) {
                    if(letters[numbers[i][j]] > 0) {
                        letters[numbers[i][j]]--;
                        toRestore.push_back(numbers[i][j]);
                    }
                    else {
                        fail = true;
                        break;
                    }
                    
                } 
            
                if(fail) {
                    for(int j = 0; j < toRestore.size(); j++) {
                        letters[toRestore[j]]++;
                    }
                    rep[i] = nb;
                    break;
                }
                nb++;
            }

        
        }
        vector <int> tab;
        for(int i = 0; i < 10; i++) {
            if(rep[i] > 0) {
                for(int j= 0; j < rep[i]; j++) {
                    tab.push_back(mapInt[i]);
                }
               
            }
        }
        sort(tab.begin(), tab.end());

        printf("Case #%d: ", iCase+1);
        for(int i= 0; i < tab.size(); i++) {
            printf("%d", tab[i]);       
        }
        printf("\n");

    }
      
        
    
    return 0;
}
