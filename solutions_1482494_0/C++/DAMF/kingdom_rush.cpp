
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef struct level {
    int number;
    int one_star;
    int two_star;
    int stars_achieved;
} level;

bool one_star_comparison (level * a, level * b)
{
    return (a->one_star > b->one_star);
}
bool two_star_comparison (level * a, level * b)
{
    return (a->two_star > b->two_star);
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
    vector<level *> by_two_star;
    vector<level *> by_one_star;

    for (int i=0; i<num_cases; i++)
    {
        int num_levels;
        input_file >> num_levels;
        for (int j=0; j<num_levels; j++)
        {
            level * current_level = (level *) malloc( sizeof( level ) );
            input_file >> current_level->one_star >> current_level->two_star;
            current_level->number = j;
            current_level->stars_achieved = 0;
            by_two_star.push_back( current_level );
            by_one_star.push_back( current_level );
        }

        sort( by_two_star.begin(), by_two_star.end(), two_star_comparison );
        sort( by_one_star.begin(), by_one_star.end(), one_star_comparison );

        int total_stars = 0;
        int total_levels = 0;

        while (total_stars < 2*num_levels)
        {
//cout << "Starting the while loop" << endl;
            // Clean up the end of our two star vector if necessary
            while (by_two_star.size() &&
                   (by_two_star.back()->stars_achieved == 2))
            {
                by_two_star.pop_back();
            }
            // Clean up the end of our one star vector if necessary
            while (by_one_star.size() &&
                   (by_one_star.back()->stars_achieved >= 1))
            {
                by_one_star.pop_back();
            }
            
//cout << "Got this far!" << endl;       
            // See if we can do a two star
            if (by_two_star.back()->two_star <= total_stars)
            {
//cout << "Got into the two star case" << endl;
                total_stars += 2-by_two_star.back()->stars_achieved;
                by_two_star.back()->stars_achieved = 2;
                total_levels++;
//cout << "Just completed " << by_two_star.back()->number << " with 2 stars" << endl;
//cout << "Total stars is now " << total_stars << endl;
                by_two_star.pop_back();
//cout << "Got out of the two star case" << endl;
            }
            else if (by_one_star.back()->one_star <= total_stars)
            {
//cout << "Got into the one star case" << endl;
                by_one_star.back()->stars_achieved = 1;
                total_stars += 1;
                total_levels++;
//cout << "Just completed " << by_one_star.back()->number << " with 1 stars" << endl;
//cout << "Total stars is now " << total_stars << endl;
                by_one_star.pop_back();
//cout << "Got out of the one star case" << endl;
            }
            else
            {
                break;
            }
        }
        if (total_stars == 2*num_levels)
        { 
            cout << "Case #" << i+1 << ": " << total_levels << endl;
        }
        else
        { 
            cout << "Case #" << i+1 << ": Too Bad" << endl;
        }
    }

    input_file.close();

    return 0;

}
