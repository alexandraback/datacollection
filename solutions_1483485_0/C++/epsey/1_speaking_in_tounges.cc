
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>

const int ALPHABET_LEN = 26;

char translations[ALPHABET_LEN];	//index is (n-'a'), so 'a' is 0, 'b' is 1, etc...


const char* encodedSamples[] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv",
	"y qee",
	"z"	//I'm a bad person
};

const char* decodedSamples[] = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up",
	"a zoo",
	"q"
};


void ProcessKnownSamples()
{
	assert(sizeof(encodedSamples) == sizeof(decodedSamples));
	for (int i = 0; i < sizeof(encodedSamples)/sizeof(const char*); i++)
	{
		for (int x = 0; encodedSamples[i][x] != '\0' && decodedSamples[i][x] != '\0'; x++)
		{
			if (encodedSamples[i][x] == ' ')
				continue;

			if (translations[encodedSamples[i][x]-'a'] != decodedSamples[i][x] && 
				translations[encodedSamples[i][x]-'a'] != 0)
			{
				printf("FUCK! Translation not one to one");
				exit(1);
			}

			translations[encodedSamples[i][x]-'a'] = decodedSamples[i][x];
		}
	}
}

void PrintStats()
{
	int numTranslated = 0;
	for (int i = 0; i < ALPHABET_LEN; i++)
	{
		if (translations[i] != 0)
		{
			numTranslated++;
		}
	}
	printf("%d of %d translated\n", numTranslated, ALPHABET_LEN);
}

void Translate(int caseNum, std::string text)
{
	//translate inplace
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] != ' ')
		{
			text[i] = translations[text[i]-'a'];
		}
	}
	printf("Case #%d: %s\n", caseNum+1, text.c_str());
}


int main()
{
	//use initial data to make as many mappings as possible
	for (int i = 0; i < ALPHABET_LEN; i++)
	{
		translations[i] = 0;
	}
	ProcessKnownSamples();


	//do the input thing
	int numberOfInputs;
	std::string text;
	std::vector<std::string> textVector;
	std::cin >> numberOfInputs;
	getline(std::cin, text); //get the stupid fucking newline
	for (int i = 0 ; i < numberOfInputs; i++)
	{
		getline(std::cin, text);
		textVector.push_back(text);
	}

	for (int i = 0; i < textVector.size(); i++)
	{
		Translate(i, textVector[i]);
	}

	return 0;
}
