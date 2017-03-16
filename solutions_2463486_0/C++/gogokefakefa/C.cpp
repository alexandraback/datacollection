#include <iostream>
#include <vector>
using namespace std;

vector < long long > x;

int solve(){
    long long A, B, res = 0;

    cin >> A >> B;

    for ( int i = 0; i < x.size(); ++i )
        if ( x[i] > B )
            break;
        else
            if ( x[i] >= A )
                ++res;

    return res;
}

int palindrome ( long long x ){
    string str;

    while ( x ){
        str += ( (char)(x % 10) );
        x /= 10;
    }

    for ( int i = 0; i < str.size(); ++i )
        if ( str[i] != str[ (int)str.size() - 1 - i] )
            return 0;
    return 1;
}

void init(){
    for ( long long i = 1; i * i <= 1e14; ++i )
        if ( palindrome ( i ) && palindrome ( i * i ) )
            x.push_back ( i * i );
}

int main(){
    int N;

    cin >> N;

    init();

    for ( int i = 1; i <= N; ++i )
        cout << "Case #" << i << ": " << solve() << endl;
}
