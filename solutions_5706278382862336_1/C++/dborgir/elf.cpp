#include<iostream>
#include<cstdio>

using namespace std;

int main () {
   int T; cin >> T;
   for (int t = 0; t < T; t++) {
       string str;
       cin >> str;
            
       long long p = 0, q = 0;
       bool first = true;
       for (int i = 0; i < str.size(); i++) {
           if (str[i] == '/') {
               first = false;
               continue;           
           }
           
           if (first == true) {
               p = p * 10 + str[i] - '0';          
           } else q = q * 10 + str[i] - '0';          
       }  
       
       cout << p << " " << q << endl;
       
       long long div = q;
       while ((div > 1) && (div % 2 == 0))
           div >>= 1;
       
       if (p % div != 0) {
           cout << "Case #" << t + 1 << ": impossible" << endl;   
           continue;  
       }        
       
       p /= div, q /= div;
       while (q != (1ll << 40))
           p <<= 1, q <<= 1;
           
       for (int i = 40; i > -1; i--)
           if (p & (1ll << i)) {
               cout << "Case #" << t + 1 << ": " << (40 - i) << endl;      
               break;
           }      
   }
}
