// B

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int k, l, s;
char key[105];
string target;
double alpha[26];
double dp[105];

int prefix()
{
    int p = 1;
    bool pre = false;
    while ( p < target.length() && !pre )
    {
        pre = true;
        for ( int i = 0; i < target.length() - p; i++ )
        {
            if ( target[i] != target[i + p] ) pre = false;
        }
        if ( !pre ) p++;
    }
    return p;
}

int main()
{
    ifstream fin ("B-small-attempt1.in");
    ofstream fout ("B-small.txt");
    cout.precision(7);
    fout.precision(7);
    int t;
    fin >> t;
    for ( int h = 0; h < t; h++ )
    {
        fin >> k >> l >> s;
        for ( int i = 0; i < 26; i++ ) alpha[i] = 0;
        char c;
        for ( int i = 0; i < k; i++ )
        {
            fin >> c;
            int let = (int) ( c - 'A' );
            alpha[let] += 1 / (double) k;
        }
        fin >> target;
        bool not_alpha = false;
        for ( int i = 0; i < l; i++ )
        {
            if ( alpha[(int) (target[i] - 'A')] < 0.0000001 ) not_alpha = true;
        }
        if ( not_alpha )
        {
            fout << "Case #" << h + 1 << ": " << 0.0 << endl;
            continue;
        }
        int p = prefix();
        for ( int i = 0; i < target.length(); i++ ) dp[i] = 0;
        dp[target.length()] = 1;
        for ( int i = 0; i < target.length(); i++ ) dp[target.length()] *= alpha[(int) (target[i] - 'A')];
        double pre = 1;
        for ( int i = 0; i < p; i++ ) pre *= alpha[(int) (target[i] - 'A')];
        double suf = dp[l] / pre;
        for ( int i = target.length() + 1; i <= s; i++ )
        {
            dp[i] = 0;
            double prod = 1 - pre;
            for ( int j = 1; i - j * p >= 0 && l - j * p > -1 * p; j++ )
            {
                dp[i] += prod * dp[i - j * p];
                prod *= pre;
            }
            dp[i] += dp[l] + pre * dp[i - p];
        }
        fout << "Case #" << h + 1 << ": " << fixed << ( 1 + ( s - l ) / p ) - dp[s] << endl;
    }
    return 0;
}
