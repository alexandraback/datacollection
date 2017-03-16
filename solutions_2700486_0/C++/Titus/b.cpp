#include <algorithm>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

typedef unsigned char byte;
typedef unsigned int uint;

vector<long> piles(1001);

double komb(long N, long K){
    double sum=1;
    for(long i=0; i<K; ++i){
        sum *= (N-i)/(K-i);
    }
    return sum;
}

void precomp(){
    piles[1] = 1;
    for(int i=2; i<1001; ++i){
        piles[i] = piles[i-1] + 4*(i-1) + 1;
    }
    /*
    for(int i=1; i<1001; ++i){
        cout << piles[i] << ", ";
    }
    cout << '\n';
    */
}

void solve(){
    long N, X, Y;
    cin >> N >> X >> Y;
    X = abs(X);
    if(N == 1 && (X != 0 || Y != 0)){
        cout << 0;
        return;
    }
    auto low = lower_bound(piles.begin(), piles.end(), N);
    if(*low == N){
        long int pos = low - piles.begin();
        if(X+Y < 2*pos){
            //cout << "1" << '\n';
            cout << 1;
        }
        else{
            //cout << "2" << '\n';
            cout << 0;
        }
    }
    else{
        long place = (*low) - (*(low-1));
        long fall = N - (*(low-1));
        long side = (place-1)/2;
        int h = low - piles.begin() - 1;
        if(X+Y < 2*h){
            //cout << "3" << '\n';
            cout << 1;
        }
        else if(X+Y > 2*h){
            //cout << "4" << '\n';
            cout << 0;
        }
        else{
            if(X == 0){
                //cout << "5" << '\n';
                cout << 0;
            }
            else if(side <= fall){
                long gr = fall-side;
                if(Y < gr){
                    //cout << "6" << '\n';
                    cout << 1;
                }
                else{
                    Y = Y-gr+1;
                    fall = fall - 2*gr;
                    double sum = 0;
                    for(int i=Y; i<=fall; ++i){
                        sum += komb(fall, i);
                    }
                    sum = sum / (1 << fall);
                    //cout << "7" << '\n';
                    cout << sum;
                }
            }
            else{
                Y = Y+1;
                if(Y > fall){
                    //cout << "8" << '\n';
                    cout << 0;
                }
                else{
                    double sum = 0;
                    for(int i=Y; i<=fall; ++i){
                        sum += komb(fall, i);
                    }
                    sum = sum / (1 << fall);
                    //cout << "9" << '\n';
                    cout << sum;
                }
            }
        }
    }
}

int main(){
    precomp();
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        cout << "Case #" << t << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}
