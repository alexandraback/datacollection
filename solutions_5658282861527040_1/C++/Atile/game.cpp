#include <iostream>
#include <vector>

using namespace std;

int main(){

long long int T, i, j, A, B, K, res;
cin >> T;
for(long long int caso=1;caso<=T;caso++)
{
    cout << "Case #" << caso << ": ";
    cin >> A >> B >> K;
    long long int menor = (A<B?A:B);
    menor = menor < K ? menor : K;
    long long int mayor = A > B ? A : B;
    long long int menab = A < B ? A : B;
    res = menor*mayor;

    for(i=menor;i<menab;i++)
        for(j=0;j<mayor;j++)
            if( (i&j) < K )
                res++;

    cout << res << endl;
}

return 0;
}

