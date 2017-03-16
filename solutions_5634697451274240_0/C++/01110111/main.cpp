#include <iostream>
#include <fstream>

using namespace std;

string defaultInName("in.txt");
string defaultOutName("out.txt");

void file2File(string inName, string outName);
void str2Bools(string in, bool * ary, int * length);
int runTestCase(bool * data, int num);

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
		string inStr;
		inFile >> inStr;
		bool data[200];
		int num=200;
		str2Bools(inStr, data, &num);
		int ans=runTestCase(data, num);
		outFile << "Case #" << i+1 << ": " << ans << "\n";
		cout << "Case #" << i+1 << ", input: " << inStr << ", output: " << ans << "\n";
	}
	
	inFile.close();
	outFile.close();
	
	cout << "\nall cases saved, program done\n";
}

void str2Bools(string in, bool * ary, int * length)
{
	int i=0;
	
	while (i<*length && (unsigned)i<in.size())
	{
		ary[i]=in.c_str()[i]=='+';
		++i;
	}
	
	if (i==*length)
		cout << "input too long for array\n";
	
	*length=i;
}

int runTestCase(bool * data, int num)
{
	int flips=0;
	for (int i=num-1; i>=0; --i)
	{
		if (!data[i])
		{
			++flips;
			for (int j=0; j<=i; ++j)
				data[j]=!data[j];
		}
	}
	
	return flips;
}


