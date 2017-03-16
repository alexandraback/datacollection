#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string name("C-large");
	ifstream in;
	ofstream out;
	int nbCases = 0; // size of the sets loaded

	int R, C, M;
	vector<vector<char> > grid;
	// Variables end -------------------------------------------------------------------------

	in.open((name + ".in").c_str());
	out.open((name + ".out").c_str()); // flux opening

	if(!(in.is_open() && out.is_open()))
	{
		cerr << "> one of the file could not be loaded" << endl;
	}

	in >> nbCases; // getting case number

	for(int i=1;i<=nbCases;i++)
	{
		in >> R >> C >> M;

		int curR = R, curC = C, curM = M;
		int freeC = curR * curC - curM;

		if(!(freeC == 1 || R == 1 || C == 1))
		{
			if( ((R == 2 || C == 2) && M % 2 == 1) ||
			    freeC == 2 || freeC == 3 || freeC == 5 || freeC == 7)
			{
				out << "Case #" << i << ":" << endl << "Impossible" << endl; // starts at 1
				continue;
			} // testing impossible cases
		}

		grid.resize(R);
		for(unsigned int j=0; j<grid.size(); ++j)
		{
			grid[j].resize(C);
			for(unsigned int k=0; k < grid[j].size(); ++k)
				grid[j][k] = '.';
		}
		grid[0][0] = 'c';
		// grid initialized

		while(curM - min(curR, curC) >= 0)
		{
			if(curR >= curC)
			{
				for(int j=0; j < curC; ++j)
					grid[curR - 1][j] = '*';
				curM-= curC; // there ic curC mines on the row removed
				curR--;
			}
			else
			{
				for(int j=0; j < curR; ++j)
					grid[j][curC - 1] = '*';
				curM-= curR; // same story
				curC--;
			}
		}
		//cout << "still " << curM << " mines " << curR << " " << curC << endl;

		// putting the last mines on the last row(s)
		int j = curR - 1, k = curC - 1;
		while(curM > 0)
		{
			if(k == 1) // we can't put a mine on the second row, it would remove acces to a cell
			{ // we will put this mine (it is the last one if it exists) on the previous row
				j--;
				k = curC - 1;
			}
			grid[j][k] = '*';
			curM--;
			k--;
		}

		out << "Case #" << i << ":" << endl; // starts at 1
		for(unsigned int j = 0; j < grid.size(); ++j)
		{
			for(unsigned int k = 0; k < grid[j].size(); ++k)
				out << grid[j][k];
			out << endl;
		}
	}

    in.close();
    out.close();
    cout << "Appuyez sur ENTER pour continuer" << endl;
    cin.get();
    return 0;
}
