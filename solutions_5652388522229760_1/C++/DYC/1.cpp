#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ifstream fin("in1");
    ofstream fout("out1");
    int T, N;

    fin >> T;
    for (int i = 1; i <= T; i++){
        fin >> N;
        if (N == 0)
            fout << "Case #" << i << ": INSOMNIA" << endl;
        else {
            int n = N;
            vector<bool> v(10, true);
            int count = 0;
            deque<int> o;
            while (n > 0){
                o.push_front(n % 10);
                n /= 10;
            }
            o.push_front(0);
            deque<int> r(o.size(), 0);
            while (true){
                for (int j = r.size() - 1; j > 0; j--){
                    r[j] += o[j];
                    if (r[j] >= 10){
                        r[j - 1]++;
                        r[j] -= 10;
                    }
                    if (v[r[j]]){
                        count++;
                        v[r[j]] = false;
                    }
                }
                if (r[0] != 0 && v[r[0]]){
                    count++;
                    v[r[0]] = false;
                }
                if (count == 10){
                    int sol = 0;
                    for (int j = 0; j < r.size(); j++){
                        sol *= 10;
                        sol += r[j];
                    }
                    fout << "Case #" << i << ": " << sol << endl;
                    break;
                }
            }
        }
    }

    fin.close();
    fout.close();
}
