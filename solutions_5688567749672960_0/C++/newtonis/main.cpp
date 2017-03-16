#include <iostream>
#include <cmath>
using namespace std;

long Flip(long number){
    long newnumber = 0;
    long value = log(number) / log(10);

    while (number > 0){
        newnumber += number%10 * pow(10,value);
        number /= 10;
        value --;
    }
    //cout<<newnumber<<endl;
    return newnumber;
}
long solution(long N);

void solve(int x);
void psol(int x,int value){
    cout << "Case #"<<x<<": " << value <<endl;
}

int main() {
    freopen("input.in","r",stdin);
    freopen("output.out","w+",stdout);

    int T; cin>>T;
    for (int x = 1;x <= T;x++){
        solve(x);
    }
}

void solve(int x){
    long N; cin>>N;

    /*if (N < 21){
        psol(x,N); return;
    }
    if (N < 31){
        psol(x,N - 21 + 12 + 1); return;
    }
    if (N < 41){
        psol(x,N - 31 + 12 + 2); return;
    }
    if (N < 51){
        psol(x,N - 41 + 12 + 3); return;
    }
    if (N < 61){
        psol(x,N - 51 + 12 + 4); return;
    }*/


    int value = 1;
    int pasos = 1;

    while (1){
        if (value == N){
            break;
        }
        int flip = Flip(value);

        if (flip > value +1 and flip < N){
            value = flip;
        }else{
            value ++;
        }
        pasos ++;
    }

    cout<<"Case #"<<x<<": "<<pasos<<endl;
}
