
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

struct city
{
public:
	city( int index, int zip )
		: index_( index ), zip_( zip ), state_( 0 ) {}

	int index_;
	int zip_;
	mutable int state_;
};

typedef vector< city* > cities_type;
typedef vector< city* > adj_list_elem_type;
typedef vector< adj_list_elem_type > adj_list_type;

int get_smallest_city( const cities_type& cities )
{
	int r = -1;
	int r_zip = 1000000000;
	for ( int i = 0; i < (int)cities.size(); ++i )
		if ( cities[ i ]->state_ == 0 && cities[ i ]->zip_ < r_zip ) {
			r_zip = cities[ i ]->zip_;
			r = cities[ i ]->index_;
		}
	return r;
}

bool is_connected( const cities_type& cities, const adj_list_type& adj_list )
{
	int s = -1;
	for ( int i = 0; i < (int)cities.size(); ++i )
		if ( cities[ i ]->state_ == 1 ) {
			s = i;
			break;
		}
	if ( s == -1 )
		return false;
	queue< int > q;
	vector< bool > m( cities.size(), false );
	q.push( s );
	m[ s ] = true;
	while ( ! q.empty() ) {
		int u = q.front();
		q.pop();
		for ( int j = 0; j < (int)adj_list[ u ].size(); ++j ) {
			int v = adj_list[ u ][ j ]->index_;
			if ( cities[ v ]->state_ != 2 ) {
				if ( ! m[ v ] ) {
					q.push( v );
					m[ v ] = true;
				}
			}
		}
	}
	for ( int i = 0; i < (int)m.size(); ++i )
		if ( m[ i ] == false && cities[ i ]->state_ != 2 )
			return false;
	return true;
}

void solve_from( vector< int >& path, const cities_type& cities, const adj_list_type& adj_list )
{
	int min_zip = 2000000;
	int min_zip_city = -1;
	std::vector< int > path_rev;
	while ( true ) {
		int smallest_city = get_smallest_city( adj_list[ path.back() ] );
		if ( smallest_city != -1 && cities[ smallest_city ]->zip_ < min_zip ) {
			min_zip = cities[ smallest_city ]->zip_;
			min_zip_city = path.back();
		}
		if ( path.size() == 1 )
			break;
		assert( cities[ path.back() ]->state_ == 1 );
		cities[ path.back() ]->state_ = 2;
		if ( ! is_connected( cities, adj_list ) ) {
			cities[ path.back() ]->state_ = 1;
			break;
		}
		path_rev.push_back( path.back() );
		path.pop_back();
	}
	while ( true ) {
		if ( path.back() == min_zip_city )
			break;
		if ( path_rev.empty() )
			break;
		//assert( ! path_rev.empty() );
		path.push_back( path_rev.back() );
		path_rev.pop_back();
		cities[ path.back() ]->state_ = 1;
	}
	if ( min_zip_city != -1 ) {
		int smallest_city = get_smallest_city( adj_list[ path.back() ] );
		path.push_back( smallest_city );
		cities[ smallest_city ]->state_ = 1;
		cout << cities[ smallest_city ]->zip_ << flush;
		solve_from( path, cities, adj_list );
		cities[ smallest_city ]->state_ = 2;
	}
}

void solve( const cities_type& cities, const adj_list_type& adj_list )
{
	int city_idx = get_smallest_city( cities );
	vector< int > path;
	path.push_back( city_idx );
	cities[ city_idx ]->state_ = 1;
	cout << cities[ city_idx ]->zip_;
	solve_from( path, cities, adj_list );
	cities[ city_idx ]->state_ = 2;
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		int n, m;
		cin >> n >> m;
		cities_type cities;
		adj_list_type adj_list;
		adj_list.resize( n );
		for ( int i = 0; i < n; ++i ) {
			int zip;
			cin >> zip;
			cities.push_back( new city( i, zip ) );
		}
		for ( int j = 0; j < m; ++j ) {
			int a, b;
			cin >> a >> b;
			--a;
			--b;
			adj_list[ a ].push_back( cities[ b ] );
			adj_list[ b ].push_back( cities[ a ] );
		}
		cout << "Case #" << t << ": ";
		solve( cities, adj_list );
		cout << endl;
	}
	return 0;
}
