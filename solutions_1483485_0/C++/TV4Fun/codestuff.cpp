#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char translate(char input)
{
    const char* letters = "yhesocvxduiglbkrztnwjpfmaq";
    if ('a' <= input && input <= 'z')
    {
        return letters[input - 'a'];
    }
    else
        return input;
}
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " filename" << endl;
        return -1;
    }

    ifstream infile(argv[1]);

    int total;
    infile >> total;

    string str;
    getline(infile,str);

    for (int i = 0; i < total; ++i)
    {
        getline(infile,str);
        cout << "Case #" << i + 1 << ": ";
        for (string::iterator it = str.begin(); it != str.end(); ++it)
        {
            cout << translate(*it);
        }
        cout << endl;
    }
    infile.close();
}