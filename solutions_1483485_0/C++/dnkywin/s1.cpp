#include<fstream>
#include<string>
#include<iostream>
using namespace std;

int main(){
    ifstream in("s1.in"); ofstream out("s1.out");

    char s[27]="yhesocvxduiglbkrztnwjpfmaq";
//              abcdefghijklmnopqrstuvwxyz

    int N;
    in>>N;
    string str (30,'*'); char c;
    getline(in,str);
    for (int i=0;i<N;i++){
        out<<"Case #"<<i+1<<": ";
        getline(in,str);
        for (int j=0;((str[j]-'a'>=0) && (str[j]-'z'<=0)) || (str[j]==' '); j++){
            if ((str[j]-'a'>=0) && (str[j]-'z'<=0)){
                cout<<str[j];
                str[j]=s[str[j]-'a'];
            }
        }
            out<<str<<"\n";

    }
        return 0;
}
