#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> mul;
vector<bool> v;
int count;
int J;
ofstream fout;
string s;

void DFS(int l){
    if (count == J)
        return;
    if (l == mul.size() - 1){
        v.assign(v.size(), false);
        for (int i = 0; i < mul.size(); i++){
            if (mul[i])
                v[i] = v[i + 3] = true;
        }
        for (int i = 0; i < v.size(); i++)
            fout << v[i];
        fout << s << endl;
        count++;
        return;
    }

    DFS(l + 1);
    if ((l < 3 || mul[l - 3] == false) && l != mul.size() - 4){
        mul[l] = true;
        DFS(l + 1);
        mul[l] = false;
    }
}

int main(){
    ifstream fin("in3");
    fout.open("out3");
    for (int i = 2; i <= 10; i++)
        s += " " + to_string((int)pow(i, 3) + 1);

    int T, N;
    fin >> T;
    for (int i = 1; i <= T; i++){
        fout << "Case #" << i << ":" << endl;
        fin >> N >> J;
        count = 0;
        mul.assign(N - 3, false);
        mul[0] = mul[mul.size() - 1] = true;
        v.assign(N, false);
        DFS(1);
    }

    fin.close();
    fout.close();
    return 0;
}
