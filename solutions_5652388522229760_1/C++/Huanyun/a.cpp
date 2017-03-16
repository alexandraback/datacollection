#include <iostream>
#define DEBUG 0

using namespace std;

typedef unsigned long long verylong;

int main(){

    int kase;
    cin >> kase;
    for (int k = 1; k <= kase; k++){
        
        int seen[10] = {0};
        verylong num = 0;
        cin >> num;
        
        if (num == 0){
            cout << "Case #" << k << ": " << "INSOMNIA" << endl;
            continue;
        }

        verylong tmp = num;
        int digit = 0;
        int seens = 0;
        while (tmp){
            tmp = tmp / 10;
            digit ++;
        }
        if (DEBUG)
            cout << "Number " << num << " has digits " << digit << endl;
        tmp = num;
        verylong top = num;

        for (int i = 0; i < digit * 2; i++)
            top *= 10;

        if (DEBUG)
            cout << "Number " << num << " has top " << top << endl;
        while (tmp <= top){
            verylong t = tmp;
            while ( t) {
                if ( !seen[t%10] ){
                    seen[t%10] = 1;
                    seens++;
                    if (DEBUG)
                        cout << tmp << " seen " << t%10 << endl;
                }
                t /= 10;
            }
            if (seens == 10)
                break;
            tmp += num;
       }
       if (seens == 10)
            cout << "Case #" << k << ": " << tmp << endl;
       else
            cout << "Case #" << k << ": " << "INSOMNIA" << endl;
    }
    return 0;
}
