
#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct state
{
	state( int x_, int y_, int s_ )
		: x(x_), y(y_), s(s_) {}

	state( const state& prev_state, char dir )
	{
		x = prev_state.x;
		y = prev_state.y;
		s = prev_state.s + 1;
		path.reserve( prev_state.path.size() + 1 );
		path = prev_state.path;
		if ( dir == 'N' ) {
			y += s;
		}
		else if ( dir == 'S' ) {
			y -= s;
		}
		else if ( dir == 'E' ) {
			x += s;
		}
		else if ( dir == 'W' ) {
			x -= s;
		}
		path.push_back( dir );
	}

	int x;
	int y;
	int s;
	std::string path;
};

std::string solve( int X, int Y )
{
	queue< state > q;
	q.push( state( 0, 0, 0 ) );
	set< pair< int, int > > s;
	s.insert( make_pair( 0, 0 ) );
	while ( true ) {
		state curr_state = q.front();
		q.pop();
		if ( curr_state.x == X && curr_state.y == Y ) {
			return curr_state.path;
		}
		char* dirs = "NSEW";
		for ( int i = 0; i < 4; ++i ) {
			state ns = state( curr_state, dirs[ i ] );
			if ( s.count( make_pair( ns.x, ns.y ) ) == 0 ) {
				q.push( ns );
				s.insert( make_pair( ns.x, ns.y ) );
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for ( int tc = 1; tc <= T; ++tc ) {
		int X, Y;
		cin >> X >> Y;
		cout << "Case #" << tc << ": " << solve( X, Y ) << endl;
	}
	return 0;
}
