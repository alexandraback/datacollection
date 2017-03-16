
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

long rotate_longeger( long target, long biggest_power_of_ten )
{
    long low_digit = target%10;
    return (target/10) + low_digit*biggest_power_of_ten;
    
}


long maximize_box_count( long curr_box_batch, long curr_box_pos,
                        long curr_toy_batch, long curr_toy_pos,
                        long num_box_batches, long * box_types, long * box_counts,
                        long num_toy_batches, long * toy_types, long * toy_counts)
{
//cout << "Current box batch is " << curr_box_batch << " and current position is " << curr_box_pos << endl;
//cout << "Current toy batch is " << curr_toy_batch << " and current position is " << curr_toy_pos << endl;
    if ((curr_box_batch >= num_box_batches) ||
        (curr_toy_batch >= num_toy_batches))
    {
//cout << "STOP" << endl;
        return 0;
    }
/*
cout << box_counts[curr_box_batch] - curr_box_pos << " " << box_types[curr_box_batch]+1 << " ";
for (long i=curr_box_batch+1; i<num_box_batches; i++)
{
  cout << box_counts[i] << " " << box_types[i]+1 << " ";
}
cout << endl;
cout << toy_counts[curr_toy_batch] - curr_toy_pos << " " << toy_types[curr_toy_batch]+1 << " ";
for (long i=curr_toy_batch+1; i<num_toy_batches; i++)
{
  cout << toy_counts[i] << " " << toy_types[i]+1 << " ";
}
cout << endl;
*/
    // If the current batches are matches
    if (box_types[curr_box_batch] == toy_types[curr_toy_batch])
    {
        long num_remaining_boxes = box_counts[curr_box_batch] - curr_box_pos;
        long num_remaining_toys = toy_counts[curr_toy_batch] - curr_toy_pos;
        long num_sent;
        if (num_remaining_boxes > num_remaining_toys)
        {
            curr_box_pos += num_remaining_toys;
            curr_toy_pos = 0;
            curr_toy_batch++;
            num_sent = num_remaining_toys;
        }
        else if (num_remaining_toys > num_remaining_boxes) 
        {
            curr_toy_pos += num_remaining_boxes;
            curr_box_pos = 0;
            curr_box_batch++;
            num_sent = num_remaining_boxes;
        }
        else // They're equal
        {
            curr_toy_pos = curr_box_pos = 0;
            curr_toy_batch++;
            curr_box_batch++;
            num_sent = num_remaining_toys;
        }
//cout << "Sending " << num_sent << endl;
        return num_sent + maximize_box_count( curr_box_batch, curr_box_pos,
                                              curr_toy_batch, curr_toy_pos, 
                                              num_box_batches, 
                                                     box_types, box_counts,
                                              num_toy_batches, 
                                                     toy_types, toy_counts);
    }
    else
    {
//cout << "BRANCH" << endl;
//cout << "keep_boxes" << endl;
        long keep_box_val = maximize_box_count( curr_box_batch, curr_box_pos,
                                               curr_toy_batch+1, 0,
                                               num_box_batches, 
                                                      box_types, box_counts,
                                               num_toy_batches, 
                                                      toy_types, toy_counts);
//cout << "keep_toys" << endl;
        long keep_toy_val = maximize_box_count( curr_box_batch+1, 0,
                                               curr_toy_batch, curr_toy_pos,
                                               num_box_batches, 
                                                      box_types, box_counts,
                                               num_toy_batches, 
                                                      toy_types, toy_counts);
        if (keep_box_val > keep_toy_val)
        {
            return keep_box_val;
        }
        else
        {
            return keep_toy_val;
        }
    }
}

int main( long argc, char ** argv )
{
    fstream input_file;
    input_file.open( argv[1] );
    long num_lines;
    input_file >> num_lines;

   
    //string current_string;
    // Eat the line that had the number of lines
    //getline( input_file, current_string );

    for (long i=0; i<num_lines; i++)
    {
        long num_box_batches, num_toy_batches;
        input_file >> num_box_batches >> num_toy_batches;
        long box_types[num_box_batches];
        long box_counts[num_box_batches];
        long toy_types[num_toy_batches];
        long toy_counts[num_toy_batches];
        for (long j=0; j<num_box_batches; j++)
        {
            input_file >> box_counts[j] >> box_types[j];
            box_types[j]--;
        }
        for (long j=0; j<num_toy_batches; j++)
        {
            input_file >> toy_counts[j] >> toy_types[j];
            toy_types[j]--;
        }

        long total = maximize_box_count( 0, 0, 0, 0, 
                                        num_box_batches, box_types, box_counts,
                                        num_toy_batches, toy_types, toy_counts);
        cout << "Case #" << i+1 << ": " << total << endl;
    }

    input_file.close();

    return 0;

}
