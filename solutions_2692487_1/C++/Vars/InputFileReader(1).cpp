#include "StdAfx.h"
#include "InputFileReader.h"

using namespace std;

InputFileReader::InputFileReader(string fileName)
: m_fileName(fileName)
, fileOut ("C:\\jam.out")
{
}

InputFileReader::~InputFileReader(void)
{
   fileOut.close();
}

// memory opt
void InputFileReader::readFile()
{
	ifstream file (m_fileName.c_str());

	while (!file.eof())
	{
      m_testCaseCount = 0;
		readValue(file, m_testCaseCount);
		for (int  i = 0; i <  m_testCaseCount; i++)
		{
			readTestCase(file, fileOut, i);
		}
		fileOut.close();
		file.close();
	}
}


void InputFileReader::readTestCase( ifstream & file, ofstream & fileOut, int i ) 
{
	int limit;
	readValue(file, limit);

	int inputSize;
   readValue(file, inputSize);
	
   vector<int> inputVtr;
   readValue(file, inputVtr);

	for (int  j = 0; j <  inputSize-1; j++)
	{
		for (int  k = j + 1;  k < inputSize;  k++)
		{
			if ((inputVtr[j]+inputVtr[k]) == limit)
			{
				fileOut << "Case #"<< i+1 << ": " << j+1 << " " << k+1 << endl;
				j = inputSize;
				break;
			}
		}
	}
}
