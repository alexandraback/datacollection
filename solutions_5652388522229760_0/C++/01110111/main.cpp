#include <iostream>
#include <fstream>

using namespace std;

string defaultInName("in.txt");
string defaultOutName("out.txt");

void file2File(string inName, string outName);
void runToNum(int maxVal);
int runTestCase(int n);

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

void runToNum(int maxVal)
{
	cout << "running...\n";
	
	for (int i=0; i<maxVal; ++i)
	{
		int ans=runTestCase(i);
		if (ans==-1)
			cout << "input: " << i << ", output: " << (ans<0?"INSOMNIA":to_string(ans)) << "\n";
	}
	
	cout << "all done\n";
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
		int inNum;
		inFile >> inNum;
		int ans=runTestCase(inNum);
		outFile << "Case #" << i+1 << ": " << (ans<0?"INSOMNIA":to_string(ans)) << "\n";
		cout << "Case #" << i+1 << ", input: " << inNum << ", output: " << ans << "\n";
	}
	
	inFile.close();
	outFile.close();
	
	cout << "\nall cases saved, program done\n";
}

int runTestCase(int n)
{
	bool dig[10];
	
	for (int i=0; i<10; ++i)
		dig[i]=0;
	
	long i=1;
	
	while (1)
	{
		long v=n*i; //value
		
		long t=v; //temp
		
		while (t)
		{
			dig[t%10]=1;
			t/=10;
		}
		
		bool done=1;
		
		for (int i=0; i<10; ++i)
		{
			if (!dig[i])
				done=0;
		}
		
		if (done)
			return v;
		
		if (i>10000000)
			return -1;
		
		++i;
	}
}

