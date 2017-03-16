#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<io.h>
#include<ios>
#include <iostream>
#include<fstream>
using namespace std;

#define MAX_FILE_LENGTH 40
#define MAX_LINE_LENGTH 200

void printfile(string filename, string lines[], int size);

int main(int argc, char* argv[])
{
	string s[3],t[3];
	s[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	s[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	s[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

	t[0] = "our language is impossible to understand";
    t[1] = "there are twenty six factorial possibilities";
    t[2] =  "so it is okay if you want to just give up";

	char mapping[26];
	int b[26];
	memset(b, 0, sizeof(b));

	for (int i=0;i<3;i++){
		string source = s[i];
		string terminal = t[i];
		for (int j = 0; j< source.length(); j++){
			int value = source[j];
			if (value!=32){
				mapping[value-97] = terminal[j];
				b[terminal[j]-97] = 1;
			}
		}	
	}
	
	mapping[25]='q'; mapping[16]='z';
	for (int i = 0;i <26 ; i++)
		printf("%c --> %c\n", char(97+i), mapping[i]);	
	
	string lines[MAX_FILE_LENGTH];
	string outlines[MAX_FILE_LENGTH];
	
	ifstream fin;
	fin.open("A-small-attempt1.in");
	
	int i = 0;

	while(!fin.eof()){
		char thisline[MAX_LINE_LENGTH];
		fin.getline(thisline, MAX_LINE_LENGTH);
		lines[i] = string(thisline);
		i = i + 1;
	}
		
	int size = atoi(lines[0].c_str());

	for (int i=1;i<=size;i++){
		string thisline = lines[i];			
		for (int j=0;j<thisline.length();j++)
		  if ((thisline[j]-97>=0)&&(thisline[j]-97<=25))
		    thisline[j] = mapping[thisline[j]-97];		
		char* str =  new char[100];
		itoa(i, str, 10);
		outlines[i - 1] = "Case #"+string(str)+": "+thisline;
	}

	printfile("A-small-attempt1.out", outlines, size);
	
	return 0;
}

void printfile(string filename, string lines[], int size)
{	//string is filename, lines is string arry, n is integer.
	ofstream fout;
	fout.open(filename);	

	for (int i=0; i < size; i++)
	{
		string thisline = lines[i];
		fout << thisline.c_str() <<endl;		
	}
	fout.close();		
}