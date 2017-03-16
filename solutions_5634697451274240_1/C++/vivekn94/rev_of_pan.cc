#include <iostream>
#include <fstream>

//int s[10];
//int temp[10];
int s[100];
int temp[100];

int isDone(int len) {
    int cnt = 0;
    for(int i = 0 ; i < len; i++) {
        if(s[i] == 1) cnt++;
    }
    if(cnt == len) return 1;
    else return 0;
}

int compute(int s[], int len) {
    int stop, flag, done = 0, i = 0, cnt = 0;
    if(s[0] == 1) flag = 1;
    else flag = 0;
    if(isDone(len) == 1) return 0;
    while(done == 0) {
        if(flag == 0) {
            while(s[i] == 0) {
                s[i] = 1;
                i++;
            }
            cnt++;
            flag = 1;
            i = 0;
        }
        else if(flag == 1) {
            while(s[i] == 1) {
                s[i] = 0;
                i++;
            }
            cnt++;
            flag = 0;
            i = 0;
        }
        if(isDone(len) == 1)
            return cnt;
    }
}

int main() {
    std::ifstream infile;
    infile.open("in2s.txt");
    std::ofstream outfile;
    outfile.open("out2s.txt");
    int t;
    infile >> t;
    std::string st;
    int len;
    for(int i = 0; i < t; i++) {
        infile >> st;
        len = st.length();
        for(int j = 0; j < len; j++) {
            if(st[j] == '+')
                s[j] = 1;
            else
                s[j] = 0;
        }
        if(len == 1) {
            if(s[0] == 1) {
                outfile << "Case #" << i+1 << ": 0\n";
            }
            else
                outfile << "Case #" << i+1 << ": 1\n";
        }
        else
            outfile << "Case #" << i+1 << ": " << compute(s, len) << "\n";
    }
    return 0;
}
