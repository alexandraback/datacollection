#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

char a[] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
    ifstream fin("test.in");
    ofstream fout("ans.out");
    int n;
    fin >> n;        
    string s;
    getline(fin,s);
    for(int i = 1;i <= n;++i){
        getline(fin,s);
        fout << "Case #" << i << ": ";
        for(int i = 0;i < s.length();++i)
            if(s[i] == ' ')
                fout << " ";
            else
                fout << a[s[i] - 'a'];
        fout << endl;
    }
    system("pause");
    return 0;    
}
