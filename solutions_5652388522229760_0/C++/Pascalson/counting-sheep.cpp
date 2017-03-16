#include<iostream>
#include<fstream>
using namespace std;

int main(int argv, char** argc)
{
    fstream fin, fout;
    fin.open(argc[1], ios::in);
    fout.open(argc[2],ios::out);
    int numCase;
    fin>>numCase;
    bool digit [10];
    int init, number, tmp;
    for( int i=0; i<numCase; ++i){
        for( int j=0; j<10; ++j ){
            digit[j] = 0;
        }
        fin>>init;
        if( init == 0 ){
            fout<<"Case #"<<i+1<<": "<<"INSOMNIA"<<endl;
            continue;
        }
        number = init;
        while(true){
            tmp = number;
            while(tmp!=0){
                digit[tmp%10] = 1;
                tmp = tmp/10;
            }

            bool sum = 1;
            for( int j=0; j<10; ++j ){
                sum = sum & digit[j];
            }
            if( sum == 1 ) {
                fout<<"Case #"<<i+1<<": "<<number<<endl;
                break;
            }
            number += init;
        }
    }
    fin.close();
    fout.close();
}
