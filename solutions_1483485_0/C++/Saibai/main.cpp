//
//  main.cpp
//  Speaking in Tongues
//
//  Created by Sebastian Grail on 14/04/12.
//  Copyright (c) 2012 Sebastian Grail. All rights reserved.
//

#include <iostream>
#include <fstream>

char charTable[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

using namespace std;
int main (int argc, const char * argv[])
{
	
	
	ifstream input;
	ofstream output;
	
	string line;
	
	input.open("/Users/sgrail/Desktop/A-small-attempt0.in.txt");
	output.open("/Users/sgrail/Desktop/results.txt");

	getline(input,line);
	int numberOfTestCases = atoi(line.c_str());

	
	for (int i=0; i<numberOfTestCases; i++)
	{
		getline(input, line);
		output << "Case #" << i+1 << ": ";
		for (int i=0; i<line.length(); i++)
		{
			if (line[i] == ' ')
				output << ' ';
			else
				output << charTable[line[i]-'a'];
		}
		output << endl;
	}
	
	
	input.close();
	output.close();
	
    return 0;
}

