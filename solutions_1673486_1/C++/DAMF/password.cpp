
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
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
    int num_cases;
    input_file >> num_cases;

   
    //string current_string;
    // Eat the line that had the number of lines
    //getline( input_file, current_string );

    for (int i=0; i<num_cases; i++)
    {
        int distance_in, password_length;
        input_file >> distance_in >> password_length;
        double probabilities[distance_in];
        for (int j=0; j<distance_in; j++)
        {
            input_file >> probabilities[j];
        }

        double ev_hitting_enter = password_length+2;
        //vector<double> ev_backspace;
        double ev_keepgoing = password_length+1;
        double prob_right_so_far = 1;
        double best_answer = ev_hitting_enter;

        for (int j=0; j<distance_in; j++)
        {
            prob_right_so_far *= probabilities[j];
            //ev_backspace.push_back( distance_in - j + ev_keepgoing );
            if (distance_in - j + ev_keepgoing < best_answer)
            {
                best_answer = distance_in - j + ev_keepgoing;
            }
//cout << "backspace " << distance_in - j << " would have been " << distance_in - j + ev_keepgoing << endl;
            ev_keepgoing = prob_right_so_far*(password_length-(j+1)+1)+
                           (1-prob_right_so_far)*(2*password_length-(j+1)+2);
        }
        if (ev_keepgoing < best_answer)
        {
            best_answer = ev_keepgoing;
        }
//cout << "keepgoing would have been " << ev_keepgoing << endl;
        cout << "Case #" << i+1 << ": ";
        cout << fixed << setprecision(6) << best_answer << endl;
    }

    input_file.close();

    return 0;

}
