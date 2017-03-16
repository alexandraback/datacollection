#include <iostream>
#include <fstream>
using namespace std;

char b['z'];
string str;
long t;

int main(){
    ifstream f1("A-small-attempt1.in");
    ofstream f2("A.txt");
b['y']='a';
b['n']='b';
b['f']='c';
b['i']='d';
b['c']='e';
b['w']='f';
b['l']='g';
b['b']='h';
b['k']='i';
b['u']='j';
b['o']='k';
b['m']='l';
b['x']='m';
b['s']='n';
b['e']='o';
b['v']='p';
b['z']='q';
b['p']='r';
b['d']='s';
b['r']='t';
b['j']='u';
b['g']='v';
b['t']='w';
b['h']='x';
b['a']='y';
b['q']='z';
    f1>>t;
    getline(f1,str);
    for (long i=0;i<t;i++){
        getline(f1,str);
       // cout<<str<<endl;
        for (long j=0;j<str.size();j++) str[j]=b[str[j]];
        f2<<"Case #"<<i+1<<": "<<str<<endl;
    }
    f1.close();
    f2.close();
    //system("pause");
    return 0;
}

