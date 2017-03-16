#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("a1.in");
ofstream fout("a_cheat.txt");

const int maxs = 1000010;
int pow10[9];
int len[maxs+10],ff[maxs+10],from[maxs+10],q[maxs+10],qh,qe;
bool flag;
int flip(int x) {
    if (x<10) return x;
    int j=0;
    while (pow10[j]<x) j++;
    return (flip(x/10)+(x%10)*pow10[j-1]);
    };
int main() {
    pow10[0]=1;
    for (int i=1;i<9;i++) pow10[i]=pow10[i-1]*10;
    for (int i=0;i<maxs+10;i++) {len[i]=maxs;ff[i] = flip(i);}
    len[0] = 0;
    qe=0;q[0]=0;
    for (int i=0;i<1000001;i++)
    {
        int j=q[i];
        int k=j+1;
        if (len[k]==maxs) {
            qe++;
            q[qe]=k;
            len[k]=len[j]+1;
        }
        k=flip(j);
        if (len[k]==maxs) {
            qe++;
            q[qe]=k;
            len[k]=len[j]+1;
        }
    }
    cout << "counting complete" << endl;
    int t;
    fin >> t;
    for (int i=0;i<t;i++)
        {
            int s;
            fin >> s;
            fout << "Case #" << i+1 << ": " << len[s] << endl;
        }
    fin.close();
    fout.close();
};
