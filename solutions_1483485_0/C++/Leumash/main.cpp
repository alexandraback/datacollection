#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void loadTranslator(char trans []);

int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    char junk;
    int number_of_test_cases;
    char translation[128];
    string temp;
    fin.open("Asmallattempt.in");
    fout.open("answer.in");
    fin>>number_of_test_cases;
    fin.get(junk);
    loadTranslator(translation);
    for(int i=0; i <number_of_test_cases; i++)
    {
        getline(fin, temp);
        for(int j=0; j<temp.size(); j++)
        {
            temp[j] = translation[temp[j]];
        }
        fout<<"Case #"<<(i+1)<<": "<<temp<<endl;
        //cout<<"Case #"<<(i+1)<<": "<<temp<<endl;
    }
    fin.close();
    fin.clear();
    fout.close();
    fout.clear();
    system("PAUSE");
    return EXIT_SUCCESS;
}

void loadTranslator(char trans [])
{
    trans['a'] = 'y';
    trans['b'] = 'h';
    trans['c'] = 'e';
    trans['d'] = 's';
    trans['e'] = 'o';
    trans['f'] = 'c';
    trans['g'] = 'v';
    trans['h'] = 'x';
    trans['i'] = 'd';
    trans['j'] = 'u';
    trans['k'] = 'i';
    trans['l'] = 'g';
    trans['m'] = 'l';
    trans['n'] = 'b';
    trans['o'] = 'k';
    trans['p'] = 'r';
    trans['q'] = 'z';
    trans['r'] = 't';
    trans['s'] = 'n';
    trans['t'] = 'w';
    trans['u'] = 'j';
    trans['v'] = 'p';
    trans['w'] = 'f';
    trans['x'] = 'm';
    trans['y'] = 'a';
    trans['z'] = 'q';
    trans[' '] = ' ';
}
