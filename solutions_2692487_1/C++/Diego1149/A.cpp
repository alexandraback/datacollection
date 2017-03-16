#include<iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int mini(int a, int b) {
    return a<b?a:b;
}

vector<int> motes;
int N;

int check(int pos, int A) {
    while(pos<motes.size()&&A>motes[pos]) {
        A+=motes[pos];
        pos++;
    }
    int temp=A;
    int tempcont=0;
    if(pos<motes.size()) {
        while(tempcont<N-pos&&motes[pos]>=temp) {
            temp+=temp-1;
            tempcont++;
        }
        cout<<temp<<" "<<tempcont<<" "<<N<<" "<<pos<<endl;
        if(tempcont>=N-pos) {
            return N-pos;
        }
        return mini(tempcont+check(pos,temp), N-pos);
    }
    return 0;

}


int main() {
    int T, caso=0, opciones, A, dummy, cont; //Opciones es la cantiad de respuestas posibles.
    string pos[100]; //Las distintas respuestas que hay.
    ofstream myfile;
    ifstream myReadFile;
    myReadFile.open("A-large (1).in");
    myfile.open ("Aoutput.txt");
    myReadFile>>T;
    while(T--) {
        motes.clear();
        myReadFile>>A>>N;
        for(int i=0; i<N; i++) {
            myReadFile>>dummy;
            motes.push_back(dummy);
        }
        sort(motes.begin(), motes.end());
        caso++;                        cout<<"FDAS";

        myfile<<"Case #"<<caso<<": "<<check(0,A)<<endl;
    }
    myfile.close();
    return 0;
}
