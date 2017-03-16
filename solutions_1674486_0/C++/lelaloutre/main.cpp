#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include <iterator>

using namespace std;


bool tryit(int s, const vector< set<int> >& inh)
{
	bool diamond = false;
	
	set<int> start;
	set<int> end;

	start.clear();
	start.insert(s);
	
	end.clear();
		
	while(!start.empty() && !diamond)
	{
		int it = *start.begin();
				
		for(unsigned int j = 0; j<inh.size(); j++)
		{
			if( inh[j].count(it) > 0 ) // j inherits from it
			{
				if( end.count(j) > 0 ) diamond = true;
				
				end.insert(j);
				start.insert(j);
			}
		}
		start.erase(it);
	}
	
	return diamond;
};

int main (int argc, const char * argv[])
{
	ifstream inf("in.dat");
    ofstream outf("out.dat");
    
    if ( !inf || !outf ) {
        cout << "Argh...\n";
        return 1;
    }
	
	int nTest;
	inf >> nTest;

	for ( int i = 0 ; i < nTest ; i++ ) 
	{		
		vector< set<int> > inh;
		vector< int > zero;
		bool diamond = false;
	
		int n = 0;
		inf >> n;
		
		for ( int j = 0 ; j < n ; j++ )
		{
			int m = 0;
			inf >> m;
			
			if( m == 0 ) 
				zero.push_back(j);
			
			set<int> temp;
			temp.clear();
			
			int t = 0;
			
			for ( int k = 0 ; k < m ; k++ )				
			{
				inf >> t;	
				temp.insert(t-1);
			}
			inh.push_back(temp);
		}
		
		for( unsigned int j = 0 ; j < zero.size() ; j++ )
		{
			diamond = tryit(zero[j], inh);
			if(diamond) break;
		}
		
		outf << "Case #" << (i+1)<< ": ";
		if(diamond) outf << "Yes\n";
		else outf << "No\n";
	}
	
    return 0;
}



