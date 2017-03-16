#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int T;
string name;
int n;
//long long d[1000002];

bool iscon(char a) {
    return a != 'a' && a != 'e' && a != 'i' &&
    a != 'o' && a != 'u';
}

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    
    fin >> T;
    
    for(int ct = 1; ct <= T; ct++) {
        fin >> name >> n;
        //memset(d,0,sizeof(d));
        
        queue<bool> fifo;
        long long queue_cnt = 0;
        long long queue_con = 0;
        long long sum = 0;
        long long cur_cnt = 0;
        int cur = 0;
        while(cur < name.length()) {
            if(iscon(name[cur])) {
                fifo.push(true);
                queue_con++;
            } else {
                fifo.push(false);
                queue_con = 0;
            }
            if(queue_con == n) {
                while(fifo.size() > n - 1) {
                    fifo.pop();
                    cur_cnt++;
                }
                queue_con = n - 1;
            }
            sum += cur_cnt;
            //cout << cur << " " << cur_cnt << endl;
            cur++;
        }
        fout << "Case #" << ct << ": " << sum << endl;
        //cout << "Case #" << ct << ": " << sum << endl;
    }
    
    
    return 0;
}
