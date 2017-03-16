#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

const long READ_SIZE = 10000; // 100MB
const long WRITE_SIZE = 1000; // 1MB

class ProblemSolver
{
private:
    long testCaseNumber;
    char solutionLine[WRITE_SIZE];
    // problem members
    vector<string> lines;
public:
    void initializeValues(long t, vector<string> *list1)
    {
        this->testCaseNumber = t; // keep
        this->lines = *list1;
    }
    void printValues()
    {        
        for(int i = 0; i < lines.size(); i++)
        {
            cout << lines[i] << " ";
        }
        cout << endl;
    }
    char *printSolution()
    {
        return this->solutionLine;
    }
    void solve()
    {
        bool impossible = false;
        string s = lines.at(0);
        long long lineIndex = 0;        
        char line[1000];
        long long numerator, denominator;
        bool denom = false;
        for(long j = 0; j < s.length()+1; j++)
        {
            if(s[j] == '/' || s[j] == NULL)
            {
                line[lineIndex] = NULL;
                if(denom)
                {
                    denominator = atof(line);
                }
                else
                {
                    numerator = atof(line);
                }
                strcpy(line, "");
                lineIndex = 0;
                denom = true;
            }
            else
            {
                line[lineIndex] = s[j];
                lineIndex++;
            }            
        }

        
        double ratio = ((double)numerator / (double)denominator);

        // code check
        cout << numerator << " " << denominator << endl;
        cout << ratio << endl;

        /*
        if(denominator % 2)
        {
            cout << "imp" << endl;
            impossible = true;
        }
        */

        __int64 generations = 0;
        double one = 1.0;
        while(ratio < one && !impossible)
        {
            ratio *= 2;
            generations++;
        }

        double zero = 0.0;
        for(int i = 0; i < 40 - generations; i++)
        {
            double whole = floor(ratio);
            double decimal = ratio - whole;
            if(decimal > zero)
            {
                impossible = true;
            }
            else
            {
                impossible = false;
                break;
            }

            ratio *= 2;
        }

        cout << generations << endl;

        string sc = "Case #";
        char scs[50];
        sprintf(scs, "%d", this->testCaseNumber);
        sc += scs;
        sc += ": ";

        if(impossible)
        {
            sprintf(scs, "%s", "impossible");
        }
        else
        {
            sprintf(scs, "%d", generations);
        }
        sc += scs;

        //s += "\n";
        strcpy(this->solutionLine, sc.c_str());
    }
    void MAINE() // for testing
    {
        
    }
};

void readFile(char *fileName, char fileContents[][READ_SIZE]);
void writeFile(char *fileName, char fileContents[][WRITE_SIZE], long lines);
void printFileContents(char fileContents[][READ_SIZE], long lines);
long parseContents(char fileContents[][READ_SIZE], char printContents[][WRITE_SIZE]);

int main()
{
    static char input[READ_SIZE][READ_SIZE]; // looks like the input file wont be larger than what can fit in RAM
    char output[WRITE_SIZE][WRITE_SIZE];
    long testCases;

    readFile("file.in", input);
    //printFileContents(input, 10);
    testCases = parseContents(input, output);
    cout << "there were " << testCases << " test cases" << endl;
    writeFile("output.txt", output, testCases);
    return 0;
}

void readFile(char *fileName, char fileContents[][READ_SIZE])
{
    ifstream inFile(fileName);
	if(inFile.fail())
	{
		cout << "could not load file" << endl;
	}

	for(long i = 0; !inFile.eof(); i++)
	{
		inFile.getline(fileContents[i],READ_SIZE);
	}
	inFile.close();
}

void writeFile(char *fileName, char fileContents[][WRITE_SIZE], long lines)
{
    ofstream outFile(fileName);
    if (outFile.is_open())
    {
        for(long i = 0; i < lines; i++)
        {
            outFile.write(fileContents[i], strlen(fileContents[i]));
            outFile << "\n";
        }
        outFile.close();
    }
    else
    {
        cout << "could not save file" << endl;
    }
}

void printFileContents(char fileContents[][READ_SIZE], long lines)
{
    for(long i = 0; i < lines; i++)
    {
        cout << fileContents[i] << endl;
    }
}

long parseContents(char fileContents[][READ_SIZE], char printContents[][WRITE_SIZE])
{
    long testCases = atoi(fileContents[0]);
    ProblemSolver *ps = new ProblemSolver[testCases];
    //int t = 1; // test case number

    // i starts at 1 so watch for memory allocation errors
    for(long i = 1; i <= testCases; i++) // now i is an index
    {
    // load the test case
        long lineIndex = 0;        
        char line[1000];
        vector<string> list1;
    
        const long parseIndex1 = i;
        for(long j = 0; j < strlen( fileContents[parseIndex1] ) + 1; j++)
        {
            if(fileContents[parseIndex1][j] == ' ' || fileContents[parseIndex1][j] == NULL)
            {
                line[lineIndex] = NULL;
                list1.push_back(line);
                strcpy(line, "");
                lineIndex = 0;
            }
            else
            {
                line[lineIndex] = fileContents[parseIndex1][j];
                lineIndex++;
            }            
        }
    

    
        // code check
        /*
        char p1[50], p2[50], p3[50];
        sprintf(p1, "%.7f", cookieValues[0]);
        sprintf(p2, "%.7f", cookieValues[1]);
        sprintf(p3, "%.7f", cookieValues[2]);
        cout << p1 << " " << p2 << " " << p3 << " " << endl;
        */
        
    // solve it and print it

        // code check
        /*
        cout << "strings: " << numberOfStrings << endl;
        
        for(int i = 0; i < list1.size(); i++)
        {
            cout << list1[i] << " ";
        }
        cout << endl;
        */

        ps[i-1].initializeValues(i, &list1);
        //ps[i-1].printValues();
        
        ps[i-1].solve();
        //cout << ps[i-1].printSolution() << endl;
        strcpy(printContents[i-1], ps[i-1].printSolution());

        //t++;
        //if(t > testCases)
        //{
        //   break;
        //}
        
    } // to the next one
    //ps[1].MAINE();
    return testCases;
}