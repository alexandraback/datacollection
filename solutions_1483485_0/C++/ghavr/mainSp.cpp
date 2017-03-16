#include <iostream>
#include <string>
#include <map>

using namespace std;



int main()
{
	freopen("input.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	string cif = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string real = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

	map<char, char> gmap;
	
	for(int i = 0; i < cif.size(); ++i)
		gmap[cif[i]] = real[i];

	gmap['z'] = 'q';

	/*
	//from here we can easily derive that 'z' letter is the only 
	//contained neither in example samples nor in text above 
	//it is the image of the only rested letter 'q'
	map<char, char> revMap;
	for(map<char, char>::iterator iter = gmap.begin(); iter != gmap.end(); ++iter)
		revMap[(*iter).second] = (*iter).first;
	*/
	gmap['q'] = 'z';

	string wrkLine;	
	int testNumb;
	getline(cin, wrkLine);
	testNumb = atof(wrkLine.c_str());
	
	for(int i = 0; i < testNumb; ++i)
	{
		getline(cin, wrkLine);
		
		cout << "Case #" << i+1 << ": ";
		for(int j = 0; j < wrkLine.size(); ++j)
			cout << gmap[wrkLine[j]];
		
		cout << endl;
	}


	return 0;
}