#include <iostream>
#include <fstream>

using namespace std;

string defaultInName("in.txt");
string defaultOutName("out.txt");

void file2File(string inName, string outName);
void runTestCase(int seqLng, int cmplx, int students, long long * tiles, int * searchNum);

int main(int argc, char * * args)
{
	string inName, outName;
	
	if (argc>=2)
		inName.assign(args[1]);
	else
		inName.assign(defaultInName);
	
	if (argc>=3)
		outName.assign(args[2]);
	else
		outName.assign(defaultOutName);
	
	//runToNum(10000000);
	file2File(inName, outName);
	
	return 0;
}

void file2File(string inName, string outName)
{
	ifstream inFile;
	
	while (1)
	{
		if (!inName.compare("quit") || !inName.compare("exit") || !inName.compare("q"))
		{
			cout << "quiting without doing anything\n";
			return;
		}
		
		inFile.open(inName);
		
		if (!inFile.good())
		{
			cout << "failed to open '" << inName << "', type in filename or type 'quit' to exit:\n> ";
			cin >> inName;
		}
		else
		{
			cout << "successfully loaded '" << inName << "'\n";
			break;
		}
	}
	
	ofstream outFile;
	
	outFile.open(outName);
	
	if (!outFile.good())
	{
		cout << "issue with output file, quitting\n";
		return;
	}
	
	int iters;
	
	inFile >> iters;
	
	cout << "\nrunning through cases:\n";
	
	for (int i=0; i<iters; ++i)
	{
		int seqLng, cmplx, students;
		inFile >> seqLng;
		inFile >> cmplx;
		inFile >> students;
		long long * tiles=new long long[students]; //tiles to search
		int searchNum=0; //the logical size of tiles[]
		runTestCase(seqLng, cmplx, students, tiles, &searchNum);
		outFile << "Case #" << i+1 << ":";
		if (searchNum>0)
		{
			for (int j=0; j<searchNum; ++j)
			{
				outFile << " " << tiles[j]+1;
			}
		}
		else
		{
			outFile << " IMPOSSIBLE";
		}
		outFile << "\n";
	}
	
	inFile.close();
	outFile.close();
	
	cout << "\nall cases saved, program done\n";
}

void runTestCase(int seqLng, int cmplx, int students, long long * tiles, int * searchNum)
{
	int i=0, j=0;
	
	while (i<seqLng)
	{
		tiles[j]=0;
		
		for (int k=0; k<cmplx; ++k)
		{
			tiles[j]=tiles[j]*seqLng+i;
			++i;
			if (i>=seqLng)
				break;
		}
		
		++j;
		
		if (j>students)
		{
			*searchNum=0;
			return;
		}
	}
	
	*searchNum=j;
}

