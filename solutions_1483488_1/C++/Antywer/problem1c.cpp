#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int rotate_int( const int number, const int index )
{
    char buffera[10];
    char bufferb[10];
    sprintf(buffera, "%d", number);
    int str_len = strlen(buffera);
    for ( int i = 0; i < str_len; ++i )
    {
        bufferb[i] = buffera[(i+index)%str_len];
    }
    bufferb[str_len] = 0;
    return atoi(bufferb);
}

int main( void )
{
    // Open file.
    ifstream in_file("C-large.in", ios_base::in);
    
    // Read number of test cases.
    string line;
    getline(in_file, line, '\n');
    int test_cases = atoi(line.c_str());
    
    // Handle each case.
    int lower_bound, upper_bound;
    for ( int case_index = 0; case_index < test_cases; ++case_index )
    {
        getline(in_file, line, '\n');
        sscanf(line.c_str(), "%d %d", &lower_bound, &upper_bound);
        
        // Find pairs.
        int pairs = 0;
        for ( int a = lower_bound; a < upper_bound; ++a )
        {
            int rot_index = 1;
            int a_rot = rotate_int(a, rot_index);
            while ( a_rot != a )
            {
                if ( (a_rot > a) && (a_rot <= upper_bound) )
                {
                    ++pairs;
                }
                
                ++rot_index;
                a_rot = rotate_int(a, rot_index);
            }
        }
        
        // Done.
        cout << "Case #" << case_index + 1 << ": " << pairs << endl;
    }
        
    return 0;
}