#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
	int casses;
	string valid[1000];
	ll validWeight[1000];
	ll numOfValid;
	ll k, s, l;
	string mKeyboard, targetWord;
	double maxBan;
	ll currentLength;
	double chanceOfThatWord;
	string currentString;
	cin >> casses;
	for( ll i = 0; i < casses; i++ )
	{
		numOfValid = 0;
		maxBan = 0.0;
		cin >> k >> l >> s;
		cin >> mKeyboard >> targetWord;
		for( ll j = 0; j < targetWord.size(); j++ )
		{
			for( ll k = 0; k < mKeyboard.size(); k++ )
			{
				if( targetWord.at(j) ==  mKeyboard.at(k) )
					break;
				if( k == mKeyboard.size() - 1 )
				{
					maxBan = -1;
				}
			}
		}
		if( maxBan == -1 )
		{
			cout << "Case #" << i + 1 << ": 0.0" << endl;
			continue;
		}
		currentString = targetWord;
		
		ll start = 0;
		for( currentLength = l; currentLength <= s; currentLength++ )
		{
			for( ll j = 0; j < targetWord.size(); j++ )
			{
				if( start + j >= currentString.size() )
				{
					currentString += targetWord.at(j);
				}
				if( currentString.at(start + j) != targetWord.at(j) )
					break;
				
				if( j == targetWord.size() - 1)
				{
					maxBan++;
					valid[numOfValid] = currentString;
					validWeight[numOfValid] = maxBan;
					numOfValid++;
				}
			}
			//currentString += targetWord.at( start % targetWord.size() );
			start++;
		}
		bool done[300];
		chanceOfThatWord = 0.0;
		ll occurance;
		double tempChance;
		for( ll l = numOfValid - 1; l < numOfValid; l++ )
		{
			tempChance = 1;
			for( ll m = 0; m < 300; m++ )
				done[m] = false;
			for( ll j = 0; j < valid[l].size(); j++ )
			{
				if( done[(int)valid[l].at(j)] )
					continue;
				//cerr << valid[l].at(j) << " ";
				done[(int)valid[l].at(j)] = true;
				occurance = 0;
				for( ll k = 0; k < mKeyboard.size(); k++ )
				{
					if( valid[l].at(j) ==  mKeyboard.at(k) )
						occurance++;
				}
				tempChance *= (double)(occurance) / mKeyboard.size();
			}
			//cerr  << valid[l] << endl;
			//tempChance = 1.0 - tempChance;
			cerr << validWeight[l] << endl;
			maxBan -= validWeight[l] * tempChance;
			chanceOfThatWord += tempChance;
		}
		cerr << endl;
		cout << "Case #" << i + 1 << ": " << maxBan << endl;
		
		
	}
	return 0;
}










