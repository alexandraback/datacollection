#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<queue>

using namespace std;

int T;
string baca;
queue<string> bfs;
int jarak[11][1024];
bool sudah[11][1024];

int kode(string s) {
    int nilai = 0;
    for (int i=0;i<s.length();++i) {
        nilai = 2*nilai+((s[i]=='+')?1:0);
    }
    return nilai;
}

string pancake_flip(string s,int idx) {
    string hasil = s;
    for (int i=0;i<idx;++i) hasil[idx-1-i] = (s[i]=='+')?'-':'+';
    return hasil;
}

int main() {
    memset(sudah,0,sizeof(sudah));
    for (int i=1;i<=10;++i) {
        string mulai = "";
        for (int j=0;j<i;++j) mulai += '+';
        bfs.push(mulai);
        
        sudah[i][kode(mulai)] = true;
        while (!bfs.empty()) {
            string s = bfs.front();
            bfs.pop();
            for (int j=1;j<=i;++j) {
                string temp = pancake_flip(s,j);
                if (!sudah[i][kode(temp)]) {
                    sudah[i][kode(temp)] = true;
                    bfs.push(temp);
                    jarak[i][kode(temp)] = jarak[i][kode(s)]+1;
                }
            }
        }
    }

    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        cin>>baca;
        printf("Case #%d: %d\n",l,jarak[baca.length()][kode(baca)]);
    }
    return 0;
}
