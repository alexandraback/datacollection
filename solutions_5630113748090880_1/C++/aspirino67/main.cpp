#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

int find_smallest(vector< vector<int>* > &v, int j){
    int index = 0;
    for(int i = 0; i < v.size(); ++i){
        if(v[i][j] < v[index][j]){
            index = i;
        }
    }
    return index;
}

int main()
{
    ifstream input_file;
    input_file.open("B-large.in", ifstream::in);
    ofstream output_file;
    output_file.open("B-large-output.txt", ofstream::out);

    string temp;
    getline(input_file, temp);

    int caso = 1;
    while(getline(input_file, temp)){
        int N = std::stoi(temp, 0, 10);
        vector< vector<int>* > lineas;
        for(int i = 0; i < 2*N-1; ++i){
            getline(input_file, temp);
            vector<int> *linea = new vector<int>;
            stringstream ss;
            ss << temp;
            string t;
            while(getline(ss, t, ' ')){
                linea->push_back(std::stoi(t, 0, 10));
            }
            lineas.push_back(linea);
        }

        map<int, int> paridad;
        for(int i = 0; i < lineas.size(); ++i){
            for(int j = 0; j < lineas[i]->size(); ++j){
                int num = lineas[i]->at(j);
                if(paridad.find(num) != paridad.end()){
                    paridad[num] += 1;
                } else {
                    paridad[num] = 1;
                }
            }
        }

        vector<int> finales;
        for(std::map<int,int>::iterator it=paridad.begin(); it!=paridad.end(); ++it){
            if(it->second % 2 != 0){
                finales.push_back(it->first);
            }
        }

        std::sort(finales.begin(), finales.end());
        output_file << "Case #" << caso << ": ";
        for(int i = 0; i < finales.size(); ++i){
            output_file << finales[i] << " ";
        }
        output_file << endl;
        ++caso;
    }

    input_file.close();
    output_file.close();
    return 0;
}
