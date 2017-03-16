#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("A-small-attempt2.in");
    ofstream fout("fout.out");

    int T, cas = 0;
    fin >> T;
    while(T --> 0){
        cas++;
        int n, now, need;
        fin >> n;
        now = 0;
        need = 0;
        for(int i = 0; i <= n; ++i){
            char ch;
            fin >> ch;
            int m = ch - 48;
            if(now >= i){
                now += m;
            }
            else{
                need += i - now;
                now = i + m;
            }
        }
        fout << "Case #" << cas << ": "<< need << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
