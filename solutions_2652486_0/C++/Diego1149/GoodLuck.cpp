#include<iostream>
#include <fstream>
using namespace std;

int main() {
    int T, caso=0, R,N,M,K, productos[12], mult[9], temp, cont, prob[9], sumatotal, cont2; //Opciones es la cantiad de respuestas posibles.
    ofstream myfile;
    ifstream myReadFile;
    myReadFile.open("C-small1.in");
    myfile.open ("Coutput.txt");
    myReadFile>>T;
    myReadFile>>R;
    myReadFile>>N; //Cantidad de numeros
    myReadFile>>M;  // de 2 a M
    myReadFile>>K;  // K productos
    caso++;
    myfile<<"Case #"<<caso<<":"<<endl;
    while(R--) {
        sumatotal=0;
        cont=0;
        for(int i=2; i<=M; i++) {
            mult[i]=0;
            prob[i]=0;
        }
        for(int i=0; i<K; i++) {
            myReadFile>>productos[i];
            for(int j=M; j>=2; j--) {
                temp=0;
                while(productos[i]%j==0) {
                    productos[i]/=j;
                    temp++;
                    sumatotal++;
                    prob[j]++;
                }
                if(temp>mult[j]) {
                    cont-=mult[j];
                    mult[j]=temp;
                    cont+=temp;
                }
            }
        }
        cont2=cont;
        for(int i=2; i<=M; i++) {
            cout<<mult[i]<<" ";
            if(cont<=N||i!=4) {
                while(mult[i]) {
                    myfile<<i;
                    cont2--;
                    mult[i]--;
                }
            }
        }
        cout<<cont2<<endl;
        if(sumatotal) {
            for(int i=M; i>=2; i--) {
                prob[i]=(prob[i]*cont)/sumatotal;
                while(prob[i]&&cont2) {
                    myfile<<i;
                    cont2--;
                    prob[i]--;
                }
            }
            while(cont2) {
                cont2--;
                myfile<<2;
            }
        }
        else {
            for(int i=0; i<N; i++) {
                myfile<<2;
            }
        }
        myfile<<endl;
    }
    myfile.close();
    return 0;
}
