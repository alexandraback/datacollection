#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#if 1
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

//~ typedef number<cpp_int_backend<128,333, unsigned_magnitude,checked>
typedef cpp_int int_t;
#else
typedef unsigned long long int_t;
#endif

// Truncated square root.
int_t sqrt( int_t x )
{
    int_t low = 1, high = x;
    int_t mid, sq;
    while ( high - low > 1 )
    {
        mid = (low+high) / 2;
        
        sq = mid*mid;
        if ( sq == x )
        {
            low = mid;
            break;
            
        }
        else if ( sq < x )
            low = mid;
        else
            high = mid;
        
        //~ cout << low << " <= sqrt(" << x << ") <= " << high << endl;
    }
    //~ cout << "sqrt(" << x << ") = " << low << endl;
    return low; // low == high here.
}

int_t pali( int_t x, int skip = 0 )
{
    stringstream ss;
    ss << x;
    const string& nw = ss.str();
    ss << string(nw.rbegin()+skip, nw.rend());
    
    int_t result;
    ss >> result;
    return result;
}

bool is_pali( const int_t& x )
{
    stringstream ss;
    ss << x;
    const string& num = ss.str();
    
    size_t digits = num.size();
    size_t half = digits / 2;
    
    for( int i = 0 ; i < half; i++ )
    {
        if (num[i] != num[digits-1-i])
            return false;
    }
    return true;
}

int main( int argc, const char** argv ) {
    const char* filename = "sample.in";
    if (argc >= 2)
        filename = argv[ 1 ];
    
    ifstream input( filename );
    ofstream output( (string(filename) + ".out").c_str() );
    
    int T;
    input >> T;
    cout << T << endl;
    
    for (int i = 0 ; i < T ; i++)
    {
        //~ cout << "Case #" << (i+1) << endl;
        int_t A, B;
        input >> A >> B;
        //~ cout << "# " << A << " " << B << endl;
        
        int_t counter = 0;
        int_t first = 1;
        int_t cur = 1;
        for (int_t x = first ; cur*cur <= B ; x++)
        {
            cur = pali(x, 1);
            int_t other = pali(x);
            //~ cout << x << " ==> " << cur << '(' << (cur*cur) << ") / " << other << '(' << (other*other) << ')' << endl;
            //~ cout << "> " << (cur*cur) << " / " << (other*other) << endl;
            
            int_t sq = cur*cur;
            if (A <= sq && sq <= B && is_pali(sq))
            {
                counter++;
            }
            
            sq = other*other;
            if (A <= sq && sq <= B && is_pali(sq))
            {
                counter++;
            }
        }
        cout << "Case #" << (i+1) << ": " << counter << '\n';
        output << "Case #" << (i+1) << ": " << counter << '\n';
    }
    
    cout << endl;
}