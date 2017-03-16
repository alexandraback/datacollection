#include <iostream>
#include <vector>

using namespace std;

int main(){

int T, i, j, A, B, K, res;
cin >> T;
for(int caso=1;caso<=T;caso++)
{
    cout << "Case #" << caso << ": ";
    cin >> A >> B >> K;
    res = 0;

    for(i=0;i<A;i++)
        for(j=0;j<B;j++)
            if( (i&j) < K )
                res++;

    cout << res << endl;
}

return 0;
}

