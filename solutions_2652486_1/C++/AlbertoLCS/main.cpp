#include <iostream>
#include <fstream>

using namespace std;

int N, M, K, num;

void check (int n, int &dos, int &tres, int &cinco, int &siete)
{
    if(n == 1){
        cout << "aqui" << endl;
        return;
    }
    while(n%2 == 0){
        n = n/2;
        dos++;
    }
    while(n%3 == 0){
        n = n/3;
        tres++;
    }
    while(n%5 == 0){
        n = n/5;
        cinco++;
    }
    while(n%7 == 0){
        n = n/7;
        siete++;
    }
}
int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int casos, R, dos, tres, cinco, siete, TWO;
    in >> casos >> R >> N >> M >> K;
    out << "Case #1: " << endl;
    for(int i = 1; i <= R; i++){
        dos = 0;
        tres = 0;
        cinco = 0;
        siete = 0;
        for(int j = 0; j < K; j++){
            in >> num;
            int d=0, t=0, c=0, s=0;
            check(num,d,t,c,s);
            dos = max(d,dos);
            tres = max(t,tres);
            cinco = max(c,cinco);
            siete = max(s,siete);
        }
        for(int x = 0; x < cinco; x++)
            out << 5;
        for(int x = 0; x < siete; x++)
            out << 7;
        int seis = min(tres,dos);
        seis = seis*3/5;
        for(int x = 0; x < seis; x++)
            out << 6;
        tres -= seis;
        dos -= seis;
        for(int x = 0; x < tres; x++)
            out << 3;
        TWO = N-tres-cinco-seis-siete;
        if(TWO == dos)
            for(int x = 0; x < TWO; x++)
                out << 2;
        else if(dos > TWO){
            int ocho = 0;
            while(dos > TWO){
                ocho++;
                dos -= 3;
                TWO--;
            }
            dos += 3;
            ocho--;
            TWO++;
            if(dos > TWO){
                out << 4;
                TWO--;
            }
            for(int x = 0; x < TWO; x++)
                out << 2;
            for(int x = 0; x < ocho; x++)
                out << 8;
        }
        else{
            for(int x = 0; x < TWO; x++)
                out << 2;
        }
        out << endl;
    }
    return 0;
}
