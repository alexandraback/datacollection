#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    vector<string> inputs;
    vector<string> outputs;
    inputs.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
    inputs.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    inputs.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
    outputs.push_back("our language is impossible to understand");
    outputs.push_back("there are twenty six factorial possibilities");
    outputs.push_back("so it is okay if you want to just give up");
    vector<char> mapping(256, '\0');
    assert(inputs.size() == outputs.size());
    for(size_t i = 0; i < inputs.size(); i++){
        assert(inputs[i].size() == outputs[i].size());
        for(size_t j = 0; j < inputs[i].size(); j++){
            mapping[inputs[i][j]] = outputs[i][j];
        }
    }
    mapping['q'] = 'z';
    mapping['z'] = 'q';
    mapping[' '] = ' ';
    string line;
    getline(cin, line);
    stringstream sst(line);
    size_t T = 0;
    sst >> T;
    for(size_t t = 1; t <= T; t++){
        string line;
        getline(cin, line);
        string decoded;
        for(size_t i = 0; i < line.size(); i++){
            decoded += mapping[line[i]];
        }
        cout << "Case #" << t << ": " << decoded << endl;
    }
    return 0;
}

