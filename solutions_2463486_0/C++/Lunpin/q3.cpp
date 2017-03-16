#include<iostream>
#include<cmath>
using namespace std;

bool isPalindromes ( long long x ) {
     /* interger to reverse array */
     char a[20]={};
     int len=0, half_len;
     bool pal=1;
     while (x>0) {
         a[len++] = (x%10)+'0';
         x = x/10;
     }
     half_len = len/2;
     /* check whether Palindromes */
     for (int i=0; i<half_len; i++) {
         if (a[i] != a[len-i-1]) {
             pal = 0; 
             break; 
         }
     }
     return pal;
}

int main () {
    int T;
    cin >> T;
    for (int cas=1; cas<=T; cas++) {
        int count=0;
        long long A, B, lowBound, upBound, I;
        cin >> A >> B;
        lowBound = (long long) sqrt(A);
        upBound = (long long) (sqrt(B)+1);
        /* Search */
        for (long long i=lowBound; i<upBound; i++) {
            if (isPalindromes(i)) {
                I = i*i;
                if (I>=A && I<=B && isPalindromes(I)) {
                    count++;
                }
            }
        }
        /* End */
        cout << "Case #" << cas << ": " << count << "\n";
    }
    //system("pause");   
}
