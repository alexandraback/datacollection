#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool check_all_good(vector<int> &c, vector<int> &bffs, int &index){
    if(bffs[c[0]-1] != c[c.size()-1] && bffs[c[0]-1] != c[1]){
        index = 0;
        return false;
    }
    for(int i = 1; i < c.size()-1; ++i){
        if(bffs[c[i]-1] != c[i-1] && bffs[c[i]-1] != c[i+1]){
            index = i;
            return false;
        }
    }
    if(bffs[c[c.size()-1]-1] != c[c.size()-2] && bffs[c[c.size()-1]-1] != c[0]){
        index = c.size()-1;
        return false;
    }
    return true;
}

int main()
{
    ifstream input_file;
    input_file.open("C-small-attempt1.in", ifstream::in);
    ofstream output_file;
    output_file.open("C-small-attempt1-output.txt", ofstream::out);

    string temp;
    getline(input_file, temp);

    int caso = 1;
    while(getline(input_file, temp)){
        int N = std::stoi(temp, 0, 10);

        vector< int > bffs;

        getline(input_file, temp);
        stringstream ss;
        ss << temp;
        string t;
        while(getline(ss, t, ' ')){
            bffs.push_back(std::stoi(t, 0, 10));
        }

        /*for(int i = 0; i < bffs.size(); ++i){
            cout << bffs[i] << " ";
        }
        cout << endl;*/

        long cant_combinaciones = 1;
        for(long i = N; i > 1; --i){
            cant_combinaciones *= i;
        }
        //cout << cant_combinaciones << endl;

        vector<int> combinacion;
        for(int i = 1; i <= N; ++i){
            combinacion.push_back(i);
        }
        sort(combinacion.begin(), combinacion.end());

        /*for(int j = 0; j < combinacion.size(); ++j){
            cout << combinacion[j] << " ";
        }
        cout << endl;*/
        int maximo = 0;
        for(long i = 0; i < cant_combinaciones; ++i){
            next_permutation(combinacion.begin(), combinacion.end());
            /*for(int j = 0; j < combinacion.size(); ++j){
                cout << combinacion[j] << " ";
            }
            cout << endl;*/
            vector<int> ccombinacion = combinacion;
            int index;
            while(!check_all_good(ccombinacion, bffs, index) && ccombinacion.size() > 0 && ccombinacion.size() > maximo){
                ccombinacion.erase(ccombinacion.begin()+index);
            }

            if(ccombinacion.size() > maximo){
                maximo = ccombinacion.size();
                if(maximo == N){
                    break;
                }
            }
        }

        output_file << "Case #" << caso << ": " << maximo << endl;
        ++caso;
    }

    input_file.close();
    output_file.close();
    return 0;
}
