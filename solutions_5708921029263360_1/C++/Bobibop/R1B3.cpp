#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

vector<vector<int> > fileToVectorVectorInt(string filename) {
    std::vector<vector<int> > v;
    char *buf = (char*)malloc(1024*sizeof(char));
    size_t n;
    if (FILE *fp = fopen(filename.c_str(), "r"))
    {
        while (getline(&buf, &n, fp) > 0) {
            istringstream iss(buf);
            vector<string> tokens{istream_iterator<string>{iss},
                                  istream_iterator<string>{}};
            vector<int> x(tokens.size());
            transform(tokens.begin(), tokens.end(), x.begin(), [](string a) {return stoi(a);});
            v.push_back(x);
        }
        fclose(fp);
    }
    return v;
}

string makeOut(vector<vector<int> > &in) {
    string out = to_string(in.size()) + "\n";
    for (std::vector<vector<int> >::iterator i = in.begin(); i != in.end(); ++i)
    {
        out += to_string(i->at(0)) + " " + to_string(i->at(1)) + " " + to_string(i->at(2)) + "\n";
    }
    return out;
}

vector<vector<int> > makeJP(int J, int P, int S, int K) {
    vector<vector<int> > out;
    for (int i = 0; i < J; ++i)
    {
        for (int j = 0; j < P; ++j)
        {
            for (int k = 0; k < min(K,S); ++k)
            {
                out.push_back(vector<int>({i+1,j+1,((i+j+k) % S)+1}));
            }
        }
    }
    return out;
}

string f(vector<int> x) {
    vector<vector<int> > out = makeJP(x[0],x[1],x[2],x[3]);

    return makeOut(out);
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage : " << argv[0] << " <filename>" << endl;
        exit(1);
    }

    string filename = string(argv[1]);
    vector<vector<int> > input = fileToVectorVectorInt(filename);

    for (int i = 0; i < input[0][0]; ++i)
    {
        cout << "Case #" << (i+1) << ": " << f(input[i+1]);
    }

    exit(0);
}