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

map <double, double> notPrime;
int length;

string toBinary(double n) {

    int i = length-1;
    double one = 1;
    
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

double power(int a, int b) {
    double mult = 1;
    
    for(int i= 0; i < b; i++) mult *= a;
    
    return mult;
}

double convertTo(string b, int base) {
    
    double a = 0;
    
    for(int i= length-1; i >= 0; i--) {
        if(b[length-1-i] == '1') a += power(base,i);   
    }        

    return a;

}

int isPrime(double n) {

    if(n%2 == 0) return 2;
    for(double i= 3; i<= sqrt(n); i+=2) {
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
      
        double one = 1;
        for(double i = (one << (length-1))+1; i < (one << length) && compt < nbJamCoin; i+=2) {
            bool fail = false;
            
            string bin = toBinary(i);
            vector <double> tab;

            for(int j= 2; j <= 10 && !false; j++) {
                double result = convertTo(bin, j);
                

                double fact;

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
