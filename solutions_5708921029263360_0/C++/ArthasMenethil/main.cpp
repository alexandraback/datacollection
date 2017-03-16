#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
using namespace std;

int ca[10][10];
int cb[10][10];
int main() {
    int t;
    cin >> t;
    for(int v=0; v < t; v++){
        int j,p,s,k;
        cin >> j>>p>>s>>k;
        if(k >= s && k >= p && k >= j){
            cout << "Case #" << v + 1 << ": " << j*p*s << endl;
            for(int a =0; a < j; a++)
                for(int b =0; b < p; b++){
                    for(int c =0; c < s; c++){
                        cout << a+1 << " " << b+1 << " " << c+1 << endl;
                    }
                }
        }else{
            int res = 0;
            for(int a =0; a < 10; a++)
                for(int b =0; b < 10; b++){
                    ca[a][b]  = 0;
                    cb[a][b]  = 0;
                }
            for(int a =0; a < j; a++){
                for(int b =0; b < p; b++){
                    int countz = 0;
                    for(int c =0; c < s; c++){
                        if(ca[a][c] >= k || cb[b][c] >=k)
                            continue;
                        if(countz >= k)
                            continue;
                        ca[a][c]++;
                        cb[b][c]++;
                        countz++;
                        res++;
                    }
                }
            }

            cout << "Case #" << v + 1 << ": " << res << endl;
            for(int a =0; a < 10; a++)
                for(int b =0; b < 10; b++){
                    ca[a][b]  = 0;
                    cb[a][b]  = 0;
                }
            for(int a =0; a < j; a++){
                for(int b =0; b < p; b++){
                    int countz = 0;
                    for(int c =0; c < s; c++){
                        if(ca[a][c] >= k || cb[b][c] >=k)
                            continue;
                        if(countz >= k)
                            continue;
                        ca[a][c]++;
                        cb[b][c]++;
                        countz++;
                        cout << a+1 << " " << b+1 << " " << c+1 << endl;
                    }
                }
            }
        }
    }

}
