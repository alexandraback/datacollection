#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argv, char** argc)
{
    fstream fin, fout;
    fin.open(argc[1], ios::in);
    fout.open(argc[2], ios::out);
    int numCase;
    fin>>numCase;
    string str;
    char tmp; bool done;
    for( int i=0; i<numCase; ++i ){
        fin>>str;
        done = 0;
        for( int count=0; !done; ++count ){
            for( int j=0; j<str.length(); ++j ){
                if( j == str.length()-1 ) {
                    done = 1;
                    if( str[0]=='+' ) fout<<"Case #"<<i+1<<": "<<count<<endl;
                    else fout<<"Case #"<<i+1<<": "<<count+1<<endl;
                }
                else { 
                    if( str[j] != str[j+1] ){
                        for( int k=0; k<=(j/2); ++k ){
                            tmp = str[k];
                            str[k] = ( str[j-k]=='+' )? '-':'+';
                            str[j-k] = ( tmp=='+')? '-':'+';
                        }
                        break;
                    }
                }
            }
        }
    }
    fin.close();
    fout.close();
}
