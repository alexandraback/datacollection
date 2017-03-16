#include <bits/stdc++.h>
#define mp      make_pair
#define pb      push_back
#define N       20

using namespace std;

int main(){
    freopen( "B-small-attempt1.in", "rt", stdin );
    freopen( "output.txt", "wt", stdout );
    int T, cases = 0;
    cin >> T;

    while( T-- ){
        string coders, jammers;
        cin >> coders >> jammers;

        for( int i = 0; i < coders.size(); ++i ){
            if( coders[i] == '?' && jammers[i] != '?' )
                coders[i] = jammers[i];
            else if( coders[i] != '?' && jammers[i] == '?' )
                jammers[i] = coders[i];
        }

        bool c = false, j = false;
        int lenght = coders.size();

        int i;
        for ( i = 0; i < lenght; ++i )
            if( coders[i] != '?' )
                break;

        if( i > 0 && i < lenght ){
            if( abs( coders[i] - jammers[i] ) > 5 ){
                if ( coders[i] > jammers[i] ) {
                    coders[i-1] = '0';
                    jammers[i-1] = '1';
                    c = true;
                }
                else if ( coders[i] < jammers[i] ) {
                    coders[i-1] = '1';
                    jammers[i-1] = '0';
                    j = true;
                }
            }
            else
                coders[i-1] = jammers[i-1] = '0';
        }

        for( int j = 0; j < i-1; ++j )
            coders[j] = jammers[j] = '0';

        if( i == lenght )
            coders[i-1] = jammers[i-1] = '0';

        for( i = i + 1; i < coders.size(); ++i ){
            if( coders[i] == '?' && jammers[i] == '?' ){
                if( coders[i-1] == jammers[i-1] && ( !c && !j ))
                    coders[i] = jammers[i] = '0';
                else {
                    if( c ){
                        coders[i] = '9';
                        jammers[i] = '0';
                    }
                    else if ( j ){
                        coders[i] = '0';
                        jammers[i] = '9';
                    }
                    else{
                        if( coders[i-1] < jammers[i-1] ){
                            coders[i] = '9';
                            jammers[i] = '0';
                        }
                        else if( coders[i-1] > jammers[i-1] ){
                            coders[i] = '0';
                            jammers[i] = '9';
                        }
                    }
                }
            }
        }

        cout << "Case #" << ++cases << ": " << coders << ' ' << jammers << '\n';
    }
}

