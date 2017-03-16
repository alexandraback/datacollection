#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int t,T,N;
    ifstream fin;
    ofstream fout;
    fin.open("in.txt",ios_base::in);
    fout.open("out.txt",ios_base::out);
    fin>>T;
    for(int t = 1; t <= T;t++) {
        fin>>N;
        if(N == 0){
            fout<<"Case #"<<t<<": INSOMNIA"<<endl;
        }
        else {
            vector<bool> digits(10, false);
            bool done = false;
            int tmp = N;
            while (!done) {
                int x = tmp;
                while (x) {
                    digits[x % 10] = true;
                    x /= 10;
                }
                done = true;
                for (int i = 0; i < 10; i++) {
                    if (!digits[i]) {
                        done = false;
                        break;
                    }
                }
                if (!done) {
                    tmp = tmp + N;
                }
            }
            fout<<"Case #"<<t<<": "<<tmp<<endl;
        }
    }

    fin.close();
    fout.close();

}