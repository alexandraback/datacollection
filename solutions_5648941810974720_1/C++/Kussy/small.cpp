#include<iostream>
using namespace std;

int A[300];


void dec( string w) {
    for(int i=0; i<w.length(); i++)
        A[ w[i] ]--;
    return;
}

int main() {
    int T;
    cin>>T;
    for(int tt=1; tt<=T; tt++) {
        int R[10];
        for(int i=0; i<300; i++)
            A[i]=R[i%10]=0;

        cout<<"Case #"<<tt<<": ";
        string s;
        cin>>s;
        for(int i=0; i<s.length(); i++)
            A[ s[i] ]++;
        while(A['Z'] > 0) {
            R[0]++;
            dec("ZERO");
        }
        while(A['W'] > 0) {
            R[2]++;
            dec("TWO");
        }
        while(A['U'] > 0) {
            R[4]++;
            dec("FOUR");
        }
        while(A['X'] > 0) {
            R[6]++;
            dec("SIX");
        }
        while(A['F'] > 0) {
            R[5]++;
            dec("FIVE");
        }
        while(A['G'] > 0) {
            R[8]++;
            dec("EIGHT");
        }
        while(A['V'] > 0) {
            R[7]++;
            dec("SEVEN");
        }
        while(A['O'] > 0) {
            R[1]++;
            dec("ONE");
        }
        while(A['H'] > 0) {
            R[3]++;
            dec("THREE");
        }
        while(A['N'] > 0) {
            R[9]++;
            dec("NINE");
        }
        for(int i=0; i<10; i++)
            while(R[i] > 0) {
                cout<<i;
                R[i]--;
            }
        cout<<endl;
    }
    return 0;
}
