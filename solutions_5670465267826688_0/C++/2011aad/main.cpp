#include <iostream>
#include <fstream>

using namespace std;

char multiply(char a, char b){
    if(a=='1'){
        switch(b){
            case '0':return '0';
            case '1':return '1';
            case 'i':return 'i';
            case 'j':return 'j';
            case 'k':return 'k';
            case 'x':return 'x';
            case 'y':return 'y';
            case 'z':return 'z';
        }
    }

    if(a=='0'){
        switch(b){
            case '0':return '1';
            case '1':return '0';
            case 'i':return 'x';
            case 'j':return 'y';
            case 'k':return 'z';
            case 'x':return 'i';
            case 'y':return 'j';
            case 'z':return 'k';
        }
    }
    if(a=='i'){
        switch(b){
            case '0':return 'x';
            case '1':return 'i';
            case 'i':return '0';
            case 'j':return 'k';
            case 'k':return 'y';
            case 'x':return '1';
            case 'y':return 'z';
            case 'z':return 'j';
        }
    }

    if(a=='j'){
        switch(b){
            case '0':return 'y';
            case '1':return 'j';
            case 'i':return 'z';
            case 'j':return '0';
            case 'k':return 'i';
            case 'x':return 'k';
            case 'y':return '1';
            case 'z':return 'x';
        }
    }

    if(a=='k'){
        switch(b){
            case '0':return 'z';
            case '1':return 'k';
            case 'i':return 'j';
            case 'j':return 'x';
            case 'k':return '0';
            case 'x':return 'y';
            case 'y':return 'i';
            case 'z':return '1';
        }
    }

    if(a=='x'){
        switch(b){
            case '0':return 'i';
            case '1':return 'x';
            case 'i':return '1';
            case 'j':return 'z';
            case 'k':return 'j';
            case 'x':return '0';
            case 'y':return 'k';
            case 'z':return 'y';
        }
    }

    if(a=='y'){
        switch(b){
            case '0':return 'j';
            case '1':return 'y';
            case 'i':return 'k';
            case 'j':return '1';
            case 'k':return 'x';
            case 'x':return 'z';
            case 'y':return '0';
            case 'z':return 'i';
        }
    }

    if(a=='z'){
        switch(b){
            case '0':return 'k';
            case '1':return 'z';
            case 'i':return 'y';
            case 'j':return 'i';
            case 'k':return '1';
            case 'x':return 'j';
            case 'y':return 'x';
            case 'z':return '0';
        }
    }

    return '1';
}

int main()
{
    ifstream infile("C-small-attempt0.in");
    ofstream outfile("C-small-attempt0.out");
    int T,L,X,n,counter;
    string str,tmp;
    char ch;
    infile>>T;
    for(int i=1;i<=T;i++){
        infile>>L>>X;
        infile>>str;
        if(L*X<3){
            outfile<<"Case #"<<i<<": NO"<<endl;
            continue;
        }
        counter = 0;
        tmp = "";
        for(int j=0;j<X;j++)
            tmp = tmp + str;

        ch = '1';
        for(n=0;n<X*L;n++){
            ch = multiply(ch,tmp[n]);
            if(ch=='i'){
                counter++;
                break;
            }
        }

        ch = '1';
        for(n++;n<X*L;n++){
            ch = multiply(ch,tmp[n]);
            if(ch=='j'){
                counter++;
                break;
            }
        }

        ch = '1';
        for(n++;n<X*L;n++){
            ch = multiply(ch,tmp[n]);
        }

        if(ch=='k' && counter==2) outfile<<"Case #"<<i<<": YES"<<endl;
        else outfile<<"Case #"<<i<<": NO"<<endl;
    }
    return 0;
}
