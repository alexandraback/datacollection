/*
  Dijkstra problem solver -- for the ijk, Code Jam Problem

 */

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::fscanf;

class Quaternian {
private:
    map<vector<string>, string> mult_matrix;
    map<string, string> dict_of_mult_strings;
    map<vector<string>, string> div_matrix;
    vector<string> possible_values;

public:
    void init(void);
    void clear(void);
    string change_q_sign(string);
    string multiply_q_pair(string, string);
    string divide_left_q_pair(string, string);
    string divide_left_q_pair_lookup(string, string);
    string multiply_q_string(string);
};

void Quaternian::init() {
    vector<string> pair(2);
    pair[0] = "1";
    pair[1] = "1"; mult_matrix[pair] = "1";
    pair[1] = "i"; mult_matrix[pair] = "i";
    pair[1] = "j"; mult_matrix[pair] = "j";
    pair[1] = "k"; mult_matrix[pair] = "k";
    pair[0] = "i";
    pair[1] = "1"; mult_matrix[pair] = "i";
    pair[1] = "i"; mult_matrix[pair] = "-1";
    pair[1] = "j"; mult_matrix[pair] = "k";
    pair[1] = "k"; mult_matrix[pair] = "-j";
    pair[0] = "j";
    pair[1] = "1"; mult_matrix[pair] = "j";
    pair[1] = "i"; mult_matrix[pair] = "-k";
    pair[1] = "j"; mult_matrix[pair] = "-1";
    pair[1] = "k"; mult_matrix[pair] = "i";
    pair[0] = "k";
    pair[1] = "1"; mult_matrix[pair] = "k";
    pair[1] = "i"; mult_matrix[pair] = "j";
    pair[1] = "j"; mult_matrix[pair] = "-i";
    pair[1] = "k"; mult_matrix[pair] = "-1";
    
    //Initializing a few of the easy strings
    dict_of_mult_strings["iiii"] = "1";
    dict_of_mult_strings["jjjj"] = "1";
    dict_of_mult_strings["kkkk"] = "1";
    
    //Setting up the string of allowed values
    vector<string> tmp_string(8);
    tmp_string[0] = "1";
    tmp_string[1] = "i";
    tmp_string[2] = "j";
    tmp_string[3] = "k";
    tmp_string[4] = "-1";
    tmp_string[5] = "-i";
    tmp_string[6] = "-j";
    tmp_string[7] = "-k";
    possible_values = tmp_string;
    
    //Setting up the division matrix
    for(int i=0; i<8; i++) {
        pair[0] = possible_values[i];
        for(int j=0; j<0; j++) {
            pair[1] = possible_values[j];
            div_matrix[pair] = divide_left_q_pair(pair[0], pair[1]);
        }
    }
}

void Quaternian::clear() {
    map<string, string>  temp_map;
    dict_of_mult_strings = temp_map;
    
    //Initializing a few of the easy strings
    dict_of_mult_strings["iiii"] = "1";
    dict_of_mult_strings["jjjj"] = "1";
    dict_of_mult_strings["kkkk"] = "1";
}

string Quaternian::change_q_sign(string q) {
    if (q[0] == '-') {
        q.erase(q.begin());
        return (q);
    } else {
        return ("-" + q);
    }
}

string Quaternian::multiply_q_pair(string q1, string q2) {
    int num_negs = 0;
    if (q1[0] == '-') {
        num_negs += 1;
        q1.erase(q1.begin());
    }
    if (q2[0] == '-') {
        num_negs += 1;
        q2.erase(q2.begin());
    }
    vector<string> pair(2);
    pair[0] = q1; pair[1] = q2;
    string q3 = mult_matrix[pair];
    if (num_negs == 1) {
        return change_q_sign(q3);
    } else {
        return q3;
    }
}

string Quaternian::divide_left_q_pair(string q_denom, string q) {
    string q3;
    for(int i=0; i<8; i++) {
        if ( multiply_q_pair(q_denom, possible_values[i]) == q ) {
            return possible_values[i];
        }
    }
    
    return q3;
}

string Quaternian::divide_left_q_pair_lookup(string q_denom, string q) {
    vector<string> pair(2);
    pair[0] = q_denom; pair[1] = q;
    return div_matrix[pair];
}

string Quaternian::multiply_q_string(string some_string) {
    if(some_string.size() <= 1) {
        return some_string;
    }
    if( some_string.size() == 2 ) {
        return multiply_q_pair(some_string.substr(0,1), some_string.substr(1,1));
    }
    //cout << "okay" << endl;
    if ( dict_of_mult_strings.count(some_string) == 1 ) {
        //cout << "match" << endl;
        return dict_of_mult_strings[some_string];
    } else {
        //cout << "no match" << " " << some_string.size() << endl;
        string q1, q2, result;
        int mid = some_string.size() / 2;
        q1 = multiply_q_string(some_string.substr(0,mid));
        q2 = multiply_q_string(some_string.substr(mid,some_string.size()-mid));
        result = multiply_q_pair(q1, q2);
        dict_of_mult_strings[some_string] = result;
        //cout << "bah" << endl;
        return result;
    }
}

void read_input(string filename, int &num_cases, vector<string> &d_strings) {
    ifstream input;
    input.open(filename);
    string myline;
    getline(input, myline);
    num_cases = stoi(myline);
    
    int place=0, place_end = 0;
    int num_chars, num_reps;
    vector<string> new_strings(num_cases);
    for(int i=0; i<num_cases; i++) {
        getline(input, myline);
        place_end = myline.find(" ");
        num_chars = stoi(myline.substr(0,place_end));
        num_reps = stoi(myline.substr(place_end+1,myline.size()-place_end-1));
        if(num_reps > 6) {
            num_reps = num_reps % 4;
            if (num_reps < 3) { num_reps += 4; }
        }
        new_strings[i] = "";
        getline(input, myline);
        for(int j=0; j<num_reps; j++) {
            new_strings[i] += myline;
        }
    }
    
    input.close();
    d_strings = new_strings;
}

void write_output(string filename, vector<bool> yesno) {
    ofstream output;
    output.open(filename);
    for(int i=0; i<yesno.size(); i++) {
        output << "Case #" << i+1 << ": ";
        if(yesno[i]) {
            output << "YES";
        } else {
            output << "NO";
        }
        output << endl;
    }
    output.close();
}

bool test_for_jk(string some_string, Quaternian &q_stuff) {
    if(some_string.size() < 2) {
        return false;
    }

    string current_q = some_string.substr(0,1);
    string last_q = q_stuff.multiply_q_string(some_string.substr(1,some_string.size()-1));
    string moving_char = "";
    for(int i=0; i<some_string.size(); i++) {
        //cout << "        Inner " << i << endl;
        if (some_string.size() -i -1 <= 0) {
            return false;
        }
        if(i > 0) {
            moving_char = string(1, some_string[i]);
            current_q = q_stuff.multiply_q_pair(current_q, moving_char); //some_string.substr(i,1));
            //last_q = q_stuff.divide_left_q_pair_lookup(moving_char, last_q);
        }
        
        if( current_q == "j") {
            return true;
            /*if( last_q == "k") {
                return true;
            }*/
        }
    }
    
    return false;
}

bool test_for_ijk(string some_string, Quaternian &q_stuff) {
    if(some_string.size() < 3) {
        return false;
    }
    
    if( q_stuff.multiply_q_string(some_string) != "-1" ) {
        //If it's equivalent to ijk, then it has to be equivalent to -1, too
        return false;
    }
    
    //Loop through, looking for substrings that reduce to i
    string current_q = some_string.substr(0,1);
    for(int i=0; i<some_string.size(); i++) {
        if( some_string.size() - i - 2 <= 0) {
            return false;
        }
        if (i > 0) {
            current_q = q_stuff.multiply_q_pair(current_q, some_string.substr(i,1));
        }
        //cout << "    " << some_string.substr(0,i+1) << " to " << current_q << endl;
        if(current_q == "i") {
            if( test_for_jk(some_string.substr(i+1,some_string.size()-i-1), q_stuff) ) {
                return true;
            }
        }
    }
    
    return false ;
}

vector<bool> test_all_for_ijk(vector<string> d_strings) {
    vector<bool> yesno(d_strings.size());
    
    
    Quaternian q_stuff; q_stuff.init();
    
    cout << "Q stuff generated" << endl;
    
    for(int i=0; i<d_strings.size(); i++) {
        cout << "Now working on: " << i+1 << endl;
        yesno[i] = test_for_ijk(d_strings[i], q_stuff);
        q_stuff.clear();
    }
    
    return yesno;
}

int main(int argc, char **argv) {
    string filename = argv[1];
    
    int num_cases;
    vector<string> d_strings;
    
    read_input(filename, num_cases, d_strings);
    
    cout << "Input read" << endl;
    
    vector<bool> yesno = test_all_for_ijk(d_strings);
    
    write_output("output.txt", yesno);
}
