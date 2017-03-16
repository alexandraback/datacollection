
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

int rotate_integer( int target, int biggest_power_of_ten )
{
    int low_digit = target%10;
    return (target/10) + low_digit*biggest_power_of_ten;
    
}

int main( int argc, char ** argv )
{
    fstream input_file;
    input_file.open( argv[1] );
    int num_lines;
    input_file >> num_lines;

   
    string current_string;
    // Eat the line that had the number of lines
    //getline( input_file, current_string );

    for (int i=0; i<num_lines; i++)
    {
        int A, B;
        input_file >> A >> B;
        if (A > B)
        {
            int temp = B;
            B = A;
            A = temp;
        }
        int biggest_power_of_ten = 1000000;
        while (biggest_power_of_ten > A)
        {
            biggest_power_of_ten /= 10;
        }
    
        int total = 0;
        for (int j=A; j<B; j++)
        {
            set<int> rotations;
            int rotated_integer = j;
            while (j != (rotated_integer = 
                          rotate_integer( rotated_integer, 
                                                       biggest_power_of_ten )))
            {
                rotations.insert( rotated_integer );
            }

            set<int>::iterator it;
            for (it=rotations.begin(); it != rotations.end(); it++)
            {
                if (((*it) > j) && ((*it) <= B))
                {
                    total++;
                }
            }
            
        }
        cout << "Case #" << i+1 << ": " << total << endl;
    }

    input_file.close();

    return 0;

}
