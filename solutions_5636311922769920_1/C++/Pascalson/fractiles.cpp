#include<iostream>
#include<fstream>

using namespace std;

int main(int argv, char** argc)
{
    fstream fin, fout;
    fin.open(argc[1], ios::in);
    fout.open(argc[2], ios::out);
    int numCase;
    fin>>numCase;
    int k, c, s;
    int checkNum;
    unsigned long index;

    for( int i=0; i<numCase; ++i ){
        fin>>k>>c>>s;
        index = 1;
        fout<<"Case #"<<i+1<<":";
        if( k > c*s ) {
            fout<<" IMPOSSIBLE";
        }
        else if( c>=k ) {
            for( int j=1; j<=k; ++j ){
                index = (index-1)*k+j;
            }
            fout<<' '<<index;
        }
        else if( c>1 ){
            checkNum = k/c;
            for( int j=0; j<checkNum; ++j ){
                index = j*c+1;
                for( int t=2; t<=c; ++t ){
                    index = (index-1)*k+(j*c+t);
                }
                fout<<' '<<index;
            }
            if( k%c != 0 ){
                index = k-c+1;
                for( int t=2; t<=c; ++t ){
                    index = (index-1)*k+(k-c+t);
                }
                fout<<' '<<index;
            }
        }
        else {
            for( int j=1; j<=k; ++j ){
                fout<<' '<<j;
            }
        }
        fout<<endl;
    }

    fin.close();
    fout.close();
}
