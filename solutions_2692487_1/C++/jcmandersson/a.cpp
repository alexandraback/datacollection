#include <iostream>

using namespace std;

int get_low(int l[], int size){
    int low = 0;
    for(int i = 1; i < size; ++i){
        if((l[i] < l[low] && l[i] != 0) || l[low] == 0){
            low = i;
        }
    }
    return low;
}

int main(int argc, char *argv[])
{
    int t = 0;
    cin >> t;

    for(int i = 1; i <= t; ++i){

        int a,b,antal,svar = 0;
        cin >> a >> b;
        int n[b];
        for(int j = 0; j < b; ++j){
            cin >> n[j];
        }
        antal = 0; svar = 0; int abs = 0;
        while(antal<b){
            int low = get_low(n, b);
            if(a > n[low]){
                a += n[low];
                n[low] = 0;
                antal++;
            }else if(a == 1){
                svar = b;
                break;
            }else{
                int a_t = 0;
                while(a <= n[low]){
                    a = a*2-1;
                    a_t++;
                }
                if(a_t < b-antal){
                    svar += a_t;
                }else{
                    svar += b-antal;
                    break;
                }
            }
        }

        if(svar > b){
            svar = b;
        }

        cout << "Case #" << i << ": ";
        cout << svar;
        cout << endl;
    }

    return 0;
}
