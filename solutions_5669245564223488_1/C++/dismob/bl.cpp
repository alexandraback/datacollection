#include <iostream>

#include <vector>
#include <string>
#include <sstream>

#include <utility>
#include <algorithm>

using namespace std;

template< typename T >
std::string ToString( const T& v )
{
  std::ostringstream oss;
  oss << v;
  return oss.str();
}


const long long mod =1000000007;

int tests;

int n;
vector<string> cars;

vector<int> oc, ocs, enc;
vector<int> st, ed;
vector<int> v;
vector<pair<int,int>> ss;
vector<int> used_for_connect;
vector<int> red;

int main()
{
	cin >> tests;
	oc.resize( 256 );
	ocs.resize( 256 );
	enc.resize( 256 );
	used_for_connect.resize( 256 );

	for( int curTest=0; curTest<tests; ++curTest )
	{

		cin >> n;
		cars.resize( n );
		st = ed = vector<int>( n );
		for( int i=0; i<n; ++i )
		{
			cin >> cars[i];
			st[i] = cars[i][0];
			ed[i] = cars[i][cars[i].size()-1];
		}

		vector<int> p( n );
		for( int i=0; i<n; ++i ) p[i] = i;

		bool ok =true;
		{
			for( int i=0; i<30; ++i )
			{
				oc[i] = enc[i] =0;
			}
			for( int i=0; (i<n)&&ok; ++i )
			{
				for( int j=0; j<30; ++j )
				{
					ocs[j] =0;
				}
				int prev =-1, pprev =-1;
				for( int j=0; (j<cars[p[i]].size())&&ok; ++j )
				{
					const auto c =cars[p[i]][j];
					if ( prev!=c && pprev!=-1 )
					{
						++enc[prev-'a'];
					}
					if ( prev != c )
					{
						if ( ocs[c-'a'] )
						{
							ok =false;
							//cout << "ocsrej" << endl;
							break;
						}
						++oc[c-'a'];
						++ocs[c-'a'];
						pprev = prev;
						prev =c;
					}
				}
			}
			for( int i=0; i<30; ++i )
			{
				if ( enc[i] && oc[i]>1 )
				{
					ok =false;
					//cout << "encrej:" << (char)(i+'a') << endl;
					break;
				}
			}
		}
		for( int i=0; i<n; ++i ) for( int j=i+1; j<n; ++j )
		{
				// connectable together
			if ( st[i]!=ed[i] && st[i]==ed[j] && ed[i]==st[j] )
			{
				//cout << "htrej" << endl;
				ok =false;
				break;
			}
				// dual connectable
			if ( st[i]!=ed[i] && st[j]!=ed[j] && ( st[i]==st[j] || ed[i]==ed[j] ) )
			{
				ok =false;
				break;
			}
		}

		long long res =0;
		if ( ok )
		{
			for( int i=0; i<256; ++i )
			{
				oc[i] =0;
			}

			v = vector<int>( n, 1 );
			used_for_connect = vector<int>( 256, 0 );
			res =1LL;
			ss.clear();

			for( int i=0; i<n; ++i )
			{
				if ( !v[i] ) continue;
					// search mergeable with no cost
				if ( st[i]==ed[i] )
				{
					++oc[st[i]];
					res *= oc[st[i]];
					res %= mod;
					if ( oc[st[i]] > 1 )
					{
						v[i] =0;
						continue;
					}
				}
					// search connectable path
				bool found =false;
				for( int j=0; j<ss.size(); ++j )
				{
					if ( ed[i] == ss[j].first )
					{
						++used_for_connect[ed[i]];
						ss[j].first =st[i];
						found =true;
						break;
					}
					if ( st[i] == ss[j].second )
					{
						++used_for_connect[st[i]];
						ss[j].second =ed[i];
						found =true;
						break;
					}
				}
				if ( !found )
				{
					ss.push_back( make_pair( st[i], ed[i] ) );
				}
			}
				// merge them
			const auto kShrink =ss.size();
			for( int tlt=0; tlt<kShrink+1; ++tlt )
			{
				for( int i=0; i<ss.size(); ++i ) for( int j=i+1; j<ss.size(); ++j )
				{
					if ( ss[i].first==ss[j].second )
					{
						++used_for_connect[ss[i].first];
						ss[i].first = ss[j].first;
						ss.erase( ss.begin()+j );
						break;
					}
					if ( ss[i].second==ss[j].first )
					{
						++used_for_connect[ss[i].second];
						ss[i].second = ss[j].second;
						ss.erase( ss.begin()+j );
						break;
					}
				}
			}
				// erase redundunt
			for( auto it=ss.begin(); it!=ss.end(); )
			{
				if ( it->first==it->second && used_for_connect[it->first] )
				{
					it = ss.erase( it );
					continue;
				}
				++it;
			}
				// calc left order
			//cout << "leftset:" << ss.size() << endl;
			for( int i=0; i<ss.size(); ++i )
			{
				//cout << "lefti:" << (char)(ss[i].first) << ":" << (char)(ss[i].second) << endl;
				res *= (long long)( i+1 );
				res %= mod;
			}
			res %= mod;
		}

		cout << "Case #" << (curTest+1) << ": ";
		cout << res;
		cout << endl;
	}

	return 0;
}

