#include <bits/stdc++.h>

using namespace std;

int number[10];

int main(){
    freopen( "A-small-attempt0.in", "rt", stdin );
    freopen( "output.txt", "wt", stdout );
    int T, cases = 0;
    cin >> T;

    while( T-- ){
        string s, out, aux;
        cin >> s;

        memset( number, 0, sizeof number );
        map<char, int> letter;

        for( int i = 0; i < s.size(); ++i )
            ++letter[s[i]];


        while( letter['Z'] > 0 ){
            ++number[0];
            --letter['Z'];
            --letter['E'];
            --letter['R'];
            --letter['O'];
        }

        while( letter['W'] > 0 ){
            ++number[2];
            --letter['T'];
            --letter['W'];
            --letter['O'];
        }

        while( letter['U'] > 0 ){
            ++number[4];
            --letter['F'];
            --letter['O'];
            --letter['U'];
            --letter['R'];
        }

        while( letter['G'] > 0 ){
            ++number[8];
            --letter['E'];
            --letter['I'];
            --letter['G'];
            --letter['H'];
            --letter['T'];
        }

        while( letter['X'] > 0 ){
            ++number[6];
            --letter['S'];
            --letter['I'];
            --letter['X'];
        }

        while( letter['H'] > 0 ){
            ++number[3];
            --letter['T'];
            --letter['H'];
            --letter['R'];
            --letter['E'];
            --letter['E'];
        }

        while( letter['O'] > 0 ){
            ++number[1];
            --letter['O'];
            --letter['N'];
            --letter['E'];
        }

        while( letter['H'] > 0 ){
            ++number[3];
            --letter['T'];
            --letter['H'];
            --letter['R'];
            --letter['E'];
            --letter['E'];
        }

        while( letter['F'] > 0 ){
            ++number[5];
            --letter['F'];
            --letter['I'];
            --letter['V'];
            --letter['E'];
        }

        while( letter['V'] > 0 ){
            ++number[7];
            --letter['S'];
            --letter['E'];
            --letter['V'];
            --letter['E'];
            --letter['N'];
        }

        while( letter['N'] > 0 ){
            ++number[9];
            --letter['N'];
            --letter['I'];
            --letter['N'];
            --letter['E'];
        }

        for( int i = 0; i < 10; ++i )
            for( int j = 0; j < number[i]; ++j )
                out += (char)( i + 48 );

        cout << "Case #" << ++cases << ": " << out << '\n';
    }
}
