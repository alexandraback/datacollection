#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>


using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main ()
{
	ifstream input;
	ofstream output;
	input.open("in.txt");
	output.open("out.txt");
	int test,tests;
	input >> tests;
	printf("%d", tests);
	forn (test,tests)
	{	
		string word;
		input >>  word;
		char first;
		char last;
		string final;
		final = final + word[0];
		first = word[0];
		forn(i, word.length()-1)
		{
			char present = word[i+1];
			if (present >= first)
			{
				final = present + final;
				first = present;
			}
			else
				final = final + present;
		}
		output << "Case #"<< test+1 << ": " << final << "\n";
	}
}		
		
		
