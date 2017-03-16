
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map <char,char> lookup_table;

char plain_alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',' '};
char cipher_alphabet[27] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k', 'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g', 't', 'h', 'a', 'q',' '};

string decrypt( string cipher )
{
    for (int i=0; i<cipher.size(); i++)
    {
        cipher[i] = lookup_table[cipher[i]];
    }
    return cipher;
}
                                               

int main( int argc, char ** argv )
{
    fstream input_file;
    input_file.open( argv[1] );
    int num_lines;
    input_file >> num_lines;

    // Build our lookup table
    for (int i=0; i<27; i++)
    {
        lookup_table[cipher_alphabet[i]] = plain_alphabet[i];
    }
   
    string current_string;
    // Eat the line that had the number of lines
    getline( input_file, current_string );

    for (int i=0; i<num_lines; i++)
    {
        getline( input_file, current_string );
        current_string = decrypt( current_string );
        cout << "Case #" << i+1 << ": " << current_string << endl;
    }

    input_file.close();

    return 0;

}
