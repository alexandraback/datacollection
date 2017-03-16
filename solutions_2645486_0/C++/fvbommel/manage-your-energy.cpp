#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

// map energy left to max value and energy left for each item
typedef pair<long, int> Result;
typedef map<int, Result > Map;
vector<Map> buffer;
int max_energy;
int recovery_rate;
vector<int> v;

Result solve( int last_item, int energy )
{
    Map::iterator it = buffer.at( last_item ).find(energy);
    if (it != buffer[last_item].end() )
    {
        cout << "Buffered: " << last_item << " @ " << energy << " = " << it->second.first << " *" << it->second.second << '\n';
        return it->second;
    }
    
    cout << "Computing: " << last_item << " @ " << energy << '\n';
    int value = v[last_item];
    
    long gain = 0;
    long energy_left = energy;
    
    if( last_item +1 == buffer.size() )
    {
        gain = energy * value;
        energy_left = 0;
    }
    else
    {
        for( int e = 0 ; e <= energy; e++ )
        {
            Result r = solve( last_item+1, min(max_energy, recovery_rate+energy-e) );
            r.first += e*value;
            //~ cout << "$$ " << last_item << " @ " << energy << '/' << energy << " = " << r.first << " *" << r.second << '\n';
            if( gain < r.first )
            {
                gain = r.first;
                energy_left = r.second;
            }
        }
    }
    
    cout << "$ " << last_item << " @ " << energy << " = " << gain << " *" << energy_left << '\n';
    
    Result r = make_pair( gain, energy_left );
    buffer[ last_item ][ energy ] = r;
    return r;
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
        int E, R, N;
        input >> E >> R >> N;
        cout << "# " << E << " " << R << " " << N << endl;
        
        v.clear();
        v.reserve(N);
        
        for( int j = 0 ; j < N ; j++ )
        {
            int x;
            input >> x;
            v.push_back( x );
        }
        
        //~ cout << "Case #" << (i+1) << ": ";
        output << "Case #" << (i+1) << ": ";
        
        max_energy = E;
        recovery_rate = min(R, E);
        buffer.clear();
        buffer.resize(N);
        
        Result r = solve( 0, max_energy );
        
        long sol = r.first;
        
        
        output << sol << '\n';
        
        cout << "Success!\n";
        cout << "Case #" << (i+1) << ": " << sol << endl;
    }
    
    cout << endl;
}