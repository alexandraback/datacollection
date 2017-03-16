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
#define ull unsigned long long int
#define vi vector<int>
#define vii vector<ii>

#define UNVISITED 0
#define OPENED 1
#define CLOSED 2

#define NBNODE 2000


using namespace std;

map <unsigned long long int, unsigned long long int> notPrime;
int length;

string toBinary(unsigned long long int n) {

    int i = length-1;
    unsigned long long int one = 1;
    
    string s = "";
    while(n > 0) {
        if(n >= (one<<i)) {
            
            s += '1';
            n -= (one<<i);
        
        }
        else s+= '0';
        i--;
    }
    return s;
}

unsigned long long int power(int a, int b) {
    unsigned long long int mult = 1;
    
    for(int i= 0; i < b; i++) mult *= a;
    
    return mult;
}

unsigned long long int convertTo(string b, int base) {
    
    unsigned long long int a = 0;
    
    for(int i= length-1; i >= 0; i--) {
        if(b[length-1-i] == '1') a += power(base,i);   
    }        

    return a;

}

int isPrime(unsigned long long int n) {

    if(n%2 == 0) return 2;
    for(unsigned long long int i= 3; i<= sqrt(n); i+=2) {
        if(n%i == 0 ) return i;
    }
    return -1;
}


int main () {  

    int nCase = 0;
    scanf("%d", &nCase);
    for(int iCase = 1; iCase <= nCase; iCase++) {    
       
        printf("Case #%d:\n", iCase);
        int nbJamCoin;
        scanf("%d %d", &length, &nbJamCoin);        

        int compt = 0;
      
        unsigned long long int one = 1;
        for(unsigned long long int i = (one << (length-1))+1; i < (one << length) && compt < nbJamCoin; i+=2) {
            bool fail = false;
            
            string bin = toBinary(i);
            vector <long long int> tab;

            for(int j= 2; j <= 10 && !false; j++) {
                unsigned long long int result = convertTo(bin, j);
                

                unsigned long long int fact;

                fact = isPrime(result);
                if(fact == -1) {
                    fail = true;
                }
                else {
                    tab.push_back(fact);
                }
            }

            if(!fail) {
                compt++;
                cout << bin << " ";
                for(int i= 0; i < 9; i++) {
                    cout << tab[i] << " ";
                }
                cout << endl;
            }
        } 


    }    
     
    
    return 0;
}
