#include<iostream>
#include <fstream>

using namespace std;

double probabilidades[20005];

int abs(int a) {
    return a>0?a:-a;
}

double prob(int N, int X,int Y) {
    double prob=0;
    int suma=abs(X)+abs(Y);
    int sum1=(suma*(suma-1))/2;
    if(N<=sum1) {
        prob=0;
    }
    else {
        int sum=((suma+1)*(suma+2))/2;
        if(N>=sum) {
            prob=1.0;
        }
        else {
            N-=sum1;
            double inicio=1.0;
            for(int i=0; i<suma+1;i++) {
                inicio/=2;
                probabilidades[i]=inicio;
            }
            if(N>=suma+1) {
                if(X) {
                    N-=suma;
                    if(Y<N) {
                        prob=1.0;
                    }
                    else {
                        for(int i=0; i<(suma-Y);i++) {
                            prob+=probabilidades[i];
                        }
                    }
                }
            }
            else {
                for(int i=Y; i<N;i++) {
                    prob+=probabilidades[i];
                }
            }

        }
    }
    return prob;
}

int main() {
    int T, caso=0, opciones, N, X, Y; //Opciones es la cantiad de respuestas posibles.
    string pos[100]; //Las distintas respuestas que hay.
    ofstream myfile;
    ifstream myReadFile;
    myReadFile.open("B-small-attempt0 (1).in");
    myfile.open ("Boutput.txt");
    myReadFile>>T;
    while(T--) {
        myReadFile>>N>>X>>Y;
        caso++;
        myfile<<"Case #"<<caso<<": "<<prob(N,X,Y)<<endl;
    }
    myfile.close();
    return 0;
}
