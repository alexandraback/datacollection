
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
int look_for_double_parent( int child_id, int *num_inheritances, int * inheritances )
{
//cout << "Looking at ID " << child_id << endl;
    int reachable[1001];

    for (int i=0; i<1001; i++)
    {
        reachable[i] = 0;
    }
    reachable[child_id] = 1;

    vector<int> unprocessed;
    unprocessed.push_back( child_id );
    while (unprocessed.size())
    {
        int curr_id = unprocessed.back();
//cout << "Tool off " << curr_id << endl;
        unprocessed.pop_back();
        int curr_num_inh = num_inheritances[curr_id];
        for (int i=0; i<curr_num_inh; i++)
        {
            int curr_inh = inheritances[curr_id*11 + i];
            if (reachable[curr_inh])
            {
                return true;
            }
            else
            {
                reachable[curr_inh] = 1;
                unprocessed.push_back( curr_inh );
//cout << "Added " << curr_inh << endl;
            }
        }
    }
    return false;
}    
    

int main( int argc, char ** argv )
{
    fstream input_file;
    input_file.open( argv[1] );
    int num_lines;
    input_file >> num_lines;

   
    //string current_string;
    // Eat the line that had the number of lines
    //getline( input_file, current_string );

    for (int i=0; i<num_lines; i++)
    {
        int num_classes;
        int answer = 0;
        input_file >> num_classes;
        int num_inheritances[num_classes];
        int inheritances[1001][11];
        for (int j=0; j<num_classes; j++)
        {
            input_file >> num_inheritances[j];
            for (int k=0; k<num_inheritances[j]; k++)
            {
                input_file >> inheritances[j][k]; 
                inheritances[j][k]--;
            }
        }

        for (int j=0; j<num_classes; j++)
        {
            answer = look_for_double_parent( j, &num_inheritances[0], &inheritances[0][0] );
            if (answer)
            {
                break; 
            }
        }

        if (answer)
        {
            cout << "Case #" << i+1 << ": Yes" << endl;
        }
        else
        {
            cout << "Case #" << i+1 << ": No" << endl;
        }
    }

    input_file.close();

    return 0;

}
