#include <iostream>
#include <fstream>

using namespace std;

string defaultInName("in.txt");
string defaultOutName("out.txt");
const int primeListSize=10000;
unsigned long long listOfPrimes[primeListSize];

void file2File(string inName, string outName);
void initPrimeList();
void nextCoin(int coinLng, bool * coinVal, long * divis);
unsigned long long convertToBase(bool * data, int lng, int base);
unsigned long long getDivisor(unsigned long long in);

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
	
	cout << "initing prime list...\n";
	initPrimeList();
	cout << "prime list created\n\n";
	
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
		int coinLng; //N
		int coinNum; //J
		
		inFile >> coinLng;
		inFile >> coinNum;
		
		long divis[9];
		bool * coinVal=new bool[coinLng];
		
		for (int j=0; j<coinLng; ++j)
			coinVal[j]=1;
		
		outFile << "Case #" << i+1 << ":\n";
		
		for (int j=0; j<coinNum; ++j)
		{
			nextCoin(coinLng, coinVal, divis);
			
			cout << "found coin\n";
			
			for (int k=coinLng-1; k>=0; --k)
				outFile << (coinVal[k]?"1":"0");
			
			for (int k=0; k<9; ++k)
				outFile << " " << divis[k];
			
			outFile << "\n";
		}
		
		delete[] coinVal;
	}
	
	inFile.close();
	outFile.close();
	
	cout << "\nall cases saved, program done\n";
}

void initPrimeList()
{
	int i=2, j=0;
	
	while (j<primeListSize)
	{
		bool isPrime=1;
		
		for (int k=2; k<=i/2; ++k)
		{
			if (!(i%k))
			{
				isPrime=0;
				break;
			}
		}
		
		if (isPrime)
		{
			//cout << i << " is prime\n";
			listOfPrimes[j]=i;
			++j;
		}
		
		++i;
	}
}

void nextCoin(int coinLng, bool * coinVal, long * divis)
{
	while (1)
	{
		int i=0;
		
		//cout << "advancing coin val...\n";
		
		do
		{
			++i;
			if (i>=coinLng-1)
			{
				cout << "overflow (one at the beginning is ok, but more means coins are repeating)\n";
				break;
			}
			coinVal[i]=!coinVal[i];
			
		} while (!coinVal[i]);
		
		bool isValid=1;
		
		for (int i=2; isValid && i<=10; ++i)
		{
			if (!(divis[i-2]=getDivisor(convertToBase(coinVal, coinLng, i))))
				isValid=0;
		}
		
		if (isValid)
			return;
	}
}

unsigned long long convertToBase(bool * data, int lng, int base)
{
	unsigned long long out=0;
	
	for (int i=lng-1; i>=0; --i)
		out=out*base+(long long)data[i];
	
	return out;
}

//this is not a true prime test, it will return prime if input is not divisible by anything on the list of primes
//returns 0 if it can't find a divisor (this may or may not mean its really prime
unsigned long long getDivisor(unsigned long long in)
{
	for (int i=0; i<primeListSize && listOfPrimes[i]<in; ++i)
	{
		if (!(in%listOfPrimes[i]))
			return listOfPrimes[i];
	}
	
	return 0;
}


