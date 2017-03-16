#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;


bool my_func( pair <int, int> a, pair <int, int> b )
{
	if( b.second < a.second )
		return true;
	if( a.first > b.first )
		return true;
	return false;
}


int main()
{
int t,M;
cin>>t;
M = t;
while( t-- )
{
	int n;
	cin>>n;
	vector <int> as(n);
	vector <int> bs(n);
	vector < pair <int, int> > cs(n);
	vector <int> mask(n,0);
	vector <int> is_one_done(n,0);
	vector <int> pair_to_i(n,0);
	vector <int> i_to_pair(n,0);

	for( int i = 0; i < n; i++ )
	{
		scanf("%d %d", &as[i], &bs[i] );
		cs[i].first = as[i];
		cs[i].second = bs[i];
	}
	
//	sort( cs.begin() , cs.end(), my_func );


	for( int i=0; i < n-1; i++ )
	{
		pair <int, int> gmin = cs[i];
		int gpt = i;

	//	cout<<"GMIN:"<<gmin.first<<" "<<gmin.second<<endl;

		for( int j = i+1; j < n; j++ )
		{
			if( ( cs[j].second < gmin.second ) || (cs[j].second == gmin.second && cs[j].first > gmin.first ) )
			{
				gmin = cs[j];
				gpt = j;
	//			cout<<"YES"<<endl;
			}
		}
		swap( cs[i].first, cs[gpt].first );
		swap( cs[i].second, cs[gpt].second );
	}
		
/*
	for( int i=0;i<n;i++)
	{
		cout<<"Fir:"<<cs[i].first <<" Sec:"<<cs[i].second<<endl;
	}
*/

	vector <int> tm(n,0);

	for( int i = 0 ; i < n; i++)
	{
		int tptr = 0;
		while( cs[i].first != as[tptr] || cs[i].second != bs[tptr] || tm[tptr] == 1 )
			tptr++;
		pair_to_i[i] = tptr;
		i_to_pair[tptr] = i;
	}


	int ptr = 0;
	int cur_star = 0;
	int solvable = 1;
	int acount = 0;

	while( ptr < n )
	{
		if( cs[ptr].second <= cur_star )
		{
			cur_star += 2 - is_one_done[ptr];
			mask[ pair_to_i[ptr] ] = 1;
			ptr++;
			acount++;
		}
		else
		{
			int tptr = 0;
			while( ( mask[tptr] == 1 || as[tptr] > cur_star ) && tptr < n )
				tptr++;
			
			if( tptr == n )
			{
				solvable = 0;
				break;
			}

			cur_star++;
			mask[tptr] = 1;
			is_one_done[ i_to_pair[tptr] ] = 1;
			acount++;
		}
	}

	cout<<"Case #"<<M-t<<": ";
	if( solvable == 0 )
		cout<<"Too Bad"<<endl;
	else
		cout<<acount<<endl;
}
return 0;
}








