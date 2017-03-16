#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

void intToVector(int inputNumb, list<int> &outputVec);
int vectorToInt(list<int> inputVec);
int main()
{
    ifstream input;		
	input.open("C:\\codejam\\probC\\input.txt", ifstream::in);
	ofstream output;
	output.open("C:\\codejam\\probC\\output.txt");
	string currentLine;
	string outputLine;
	int A, B, n, m, numberOfPairs; 
	int lineNumber = 0;
	string numb;
	getline(input, numb);
	lineNumber = atoi(numb.c_str());
	for(int i = 1; i < lineNumber+1; ++i)
	{
		input >> A;
		input >> B;
		cout<<A<<" "<<B<<endl;
		numberOfPairs = 0;
		ostringstream oss;
		oss << i;
		string result = oss.str();
		outputLine = "Case #" + result + ": ";
		for(n = A; n != B; ++n)
		{
			ostringstream oss;
			oss << n;
			string strNumber = oss.str();
			int size = strNumber.size();
			map<int, bool> pairs;
			for(int i = 0; i != size; ++i)
			{
				strNumber+= strNumber[0];
				strNumber.erase(strNumber.begin());
				m = atoi(strNumber.c_str());
				if(m > n && m <= B && pairs.count(m) ==0 )
				{
					++numberOfPairs;
					pairs[m] = true;					
				}
			}
		}
		ostringstream oss2;
		oss2 << numberOfPairs;
		outputLine += oss2.str();
		output<<outputLine<<endl;
	}
	input.close();
	output.close();
    return 0;
}
void intToVector(int inputNumb, list<int> &outputVec)
{
	outputVec.clear();
	cout<<"intToVector "<<inputNumb<<"\t";
	int rest = inputNumb%10;
	outputVec.push_back(rest);
	inputNumb = inputNumb/10;
	while(rest > 0)
	{
		rest = inputNumb%10;
		
		outputVec.push_back(rest);
		inputNumb = inputNumb/10;
	}
	while(outputVec.back() == 0)
		outputVec.pop_back();
	list<int>::iterator it;
	for ( it=outputVec.begin() ; it != outputVec.end(); it++ )
	{
		cout<<*it;
	}
	cout<<endl;
}
int vectorToInt(list<int> inputVec)
{
	int outputInt = 0;
	int currentPower = 1;
	list<int>::iterator it;
	for ( it=inputVec.begin() ; it != inputVec.end(); it++ )
	{
		outputInt += currentPower*(*it);
		currentPower *= 10;
	}
	cout<<"vectorToInt "<<outputInt<<endl;
	return outputInt;
}