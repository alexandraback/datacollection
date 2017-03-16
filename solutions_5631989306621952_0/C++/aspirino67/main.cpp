#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input_file;
    input_file.open("A-small-attempt0.in", ifstream::in);
    ofstream output_file;
    output_file.open("A-small-output.txt", ofstream::out);

    string temp;
    getline(input_file, temp);

    int caso = 1;
    while(getline(input_file, temp)){
        string result = "";
        result += temp[0];
        for(int i = 1; i < temp.length(); ++i){
            char c = temp[i];
            if(c >= result[0]){
                string t = c + result;
                result = t;
            } else {
                result += c;
            }
        }
        output_file << "Case #" << caso << ": " << result << endl;
        ++caso;
    }

    input_file.close();
    output_file.close();
    return 0;
}
