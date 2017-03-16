#include <iostream>
#include <fstream>
#include <string>

#define BUFFER_SIZE 128

using namespace std;

int main(int argc, char** argv)
{
	int i = 0;
	int j = 0;
	int count = 0;
	char map[] = "yhesocvxduiglbkrztnwjpfmaq";
	char buffer[BUFFER_SIZE];
	ifstream inFile("A-small-attempt0.in");
	ofstream outFile("result.out");
	inFile >> count;
	inFile.getline(buffer, BUFFER_SIZE);
	for (i=0;i<count;i++)
	{
		outFile<<"Case #"<<i+1<<": ";
		inFile.getline(buffer, BUFFER_SIZE);
		for (j=0;j<strlen(buffer);j++)
		{
			if (buffer[j]!=' ')
			{
				buffer[j] = map[buffer[j]-'a'];
			}
		}
		outFile<<buffer<<endl;
	}
	return 0;
}