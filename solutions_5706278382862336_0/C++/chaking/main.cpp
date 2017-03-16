#include <iostream>

using namespace std;

int input();
int process();
int printResult();

int result;
int resultCase;
enum ResultCase{
    POSSIBLE,
    IMPOSSIBLE
};
int N;
long long int P, Q;

int main ( void ){
    int i;
    int count;

    cin >> count;

    for( i = 0; i < count; i++ ){
        input();
        process();
        cout << "Case #" << i + 1 << ": ";
        printResult();
    }

    return 0;
}

int input(){
    scanf( "%lld/%lld", &P, &Q );

    return 0;
}

int process(){
    int i, j;
    result = 0;
    resultCase = POSSIBLE;

    for( i = 0; i < 40; i++ ){
        P = P * 2;
        //cout << "P:" << P << " i:" << i << endl;
        if( P >= Q ) {
            if( result == 0 ) result = i + 1;
            P = P - Q;
            if( P == 0 ) return 0;
        }
    }

    resultCase = IMPOSSIBLE;

    return 0;
}

int printResult(){
    int i;
    
    if( resultCase == IMPOSSIBLE ) cout << "impossible";
    else cout << result;

    cout << endl;
    
    return 0;
}
