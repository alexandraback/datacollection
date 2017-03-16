#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

//Code jam 1C problem c
int main( int argc, char * argv[] )
{
	//Find out how many test cases there are
	unsigned int nInputs = 0;
	cin >> nInputs;
	//cout << nInputs << " tests" << endl;

	//Loop over all inputs
	for ( unsigned int inputIndex = 0; inputIndex < nInputs; ++inputIndex )
	{
		//Read input
		int jacketNumber, pantsNumber, shirtNumber, pairMax;
		cin >> jacketNumber >> pantsNumber >> shirtNumber >> pairMax;
		//cout << "input: " << jacketNumber << ", " << pantsNumber<< ", " << shirtNumber << ", " << pairMax << endl;

		//Make jacket/pants pairs (always have fewest of jackets, then pants)
		vector< vector< unsigned int > > outfits;
		map< pair< unsigned int, unsigned int >, unsigned int > jsPairCounts;
		map< pair< unsigned int, unsigned int >, unsigned int > psPairCounts;
		for ( unsigned int jacketIndex = 0; jacketIndex < jacketNumber; ++jacketIndex )
		{
			for ( unsigned int pantsIndex = 0; pantsIndex < pantsNumber; ++pantsIndex )
			{
				unsigned int jpPairCount = 0;
				for ( unsigned int shirtIndex = 0; shirtIndex < shirtNumber; ++shirtIndex )
				{
					//Check for jacket/pants limit
					if ( jpPairCount == pairMax )
					{
						//cout << "jp max hit: " << jacketIndex << ", " << pantsIndex << endl;
						break;
					}

					//Check for jacket/shirt limit
					auto jsPair = make_pair( jacketIndex, shirtIndex );
					auto searchResult = jsPairCounts.find( jsPair );
					if ( searchResult != jsPairCounts.end() && searchResult->second == pairMax )
					{
						//cout << "js max hit: " << jacketIndex << ", " << shirtIndex << endl;
						continue;
					}

					//Check for pants/shirt limit
					auto psPair = make_pair( pantsIndex, shirtIndex );
					searchResult = psPairCounts.find( psPair );
					if ( searchResult != psPairCounts.end() && searchResult->second == pairMax )
					{
						//cout << "ps max hit: " << pantsIndex << ", " << shirtIndex << endl;
						continue;
					}

					//Store outfit
					outfits.push_back( { jacketIndex, pantsIndex, shirtIndex } );
					jpPairCount++;
					jsPairCounts[ jsPair ]++;
					psPairCounts[ psPair ]++;
				}
			}
		}

		//Print output
		cout << "Case #" << inputIndex + 1 << ": " << outfits.size() << endl;
		for ( vector< unsigned int > outfit : outfits )
		{
			cout << outfit[0] + 1 << " " << outfit[1] + 1 << " " << outfit[2] + 1 << endl;
		}
	}

	return 0;
}
