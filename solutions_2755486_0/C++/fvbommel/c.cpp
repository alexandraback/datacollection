#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

struct Tribe
{
    unsigned long day;
    int n_attacks;
    int west, east;
    unsigned long strength;
    unsigned delta_day;
    long delta_pos;
    unsigned long delta_strength;
};

istream& operator>>( istream& stream, Tribe& t )
{
    return stream >> t.day >> t.n_attacks >> t.west >> t.east >> t.strength
                  >> t.delta_day >> t.delta_pos >> t.delta_strength;
}

bool operator<( const Tribe& l, const Tribe& r )
{
    return l.day > r.day;
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
    
    map<int, unsigned long> height;
    vector<Tribe> tribes;
    
    for (int i = 0 ; i < T ; i++)
    {
        int N;
        input >> N;
        cout << "# " << N << endl;
        
        height.clear();
        tribes.resize( N );
        
        for (int j = 0; j < N ; j++)
        {
            input >> tribes[ j ];
        }
        
        make_heap( tribes.begin(), tribes.end() );
        
        //~ cout << "Case #" << (i+1) << ": ";
        output << "Case #" << (i+1) << ": ";
        
        unsigned long long result = 0;
        
        while( !tribes.empty() )
        {
            map<int, unsigned long> new_height = height;
            
            unsigned long day = tribes.front().day;
            
            while( !tribes.empty() && tribes.front().day == day )
            {
                Tribe tribe = tribes.front();
                
                cout << "Day " << tribe.day << '\n';
                
                bool breach = false;
                for( long pos = tribe.west ; pos < tribe.east ; pos++ )
                {
                    if( height[ pos ] < tribe.strength )
                    {
                        breach = true;
                        new_height[ pos ] = max( new_height[ pos ], tribe.strength);
                    }
                }
                
                if( breach )
                {
                    result++;
                }
                
                pop_heap( tribes.begin(), tribes.end() );
                tribes.pop_back();
                
                //~ cout << "#tribes after pop: " << tribes.size() << '\n';
                
                if( --tribe.n_attacks > 0 )
                {
                    tribe.strength += tribe.delta_strength;
                    tribe.day += tribe.delta_day;
                    tribe.west += tribe.delta_pos;
                    tribe.east += tribe.delta_pos;
                    
                    tribes.push_back( tribe );
                    push_heap( tribes.begin(), tribes.end() );
                    //~ cout << "#tribes after push: " << tribes.size() << '\n';
                }
            }
            height = new_height;
        }
        
        
        output << result << '\n';
        
        cout << "Success!\n";
        cout << "Case #" << (i+1) << ": " << ' ' << result << endl;
    }
    
    cout << endl;
}