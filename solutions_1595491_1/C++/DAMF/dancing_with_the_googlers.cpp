
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


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
        int num_dancers, num_surprising_scores, threshold;
        input_file >> num_dancers >> num_surprising_scores >> threshold;
        int num_possible_surprising, num_possible_unsurprising;
        num_possible_surprising = num_possible_unsurprising = 0;
        for (int j=0; j<num_dancers; j++)
        {
            int score_total;
            input_file >> score_total;
            if (score_total >= threshold + 2*max(threshold-1,0))
            {
                num_possible_unsurprising++;
            }
            else if (score_total >= threshold + 2*max(threshold-2,0))
            {
                num_possible_surprising++;
            }
        }
        int max_possible = num_possible_unsurprising;
        max_possible += min( num_possible_surprising, num_surprising_scores );
        cout << "Case #" << i+1 << ": " << max_possible << endl;
    }

    input_file.close();

    return 0;

}
