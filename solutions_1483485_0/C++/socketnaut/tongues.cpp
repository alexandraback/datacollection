#include<fstream>
#include<string>
using namespace std;

ifstream fin("tongues.in");
ofstream fout("tongues.out");

int T;
char s[128];
string r = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
    fin >> T; fin.getline(s,128);
    for(int t=0; t<T; t++){
        fin.getline(s, 128);
        fout << "Case #" << t+1 << ": ";
        for(int a=0; s[a]!=0; a++){
            if(s[a]==' ') fout << s[a];
            else fout << r[s[a]-'a'];
        }
        fout << endl;
    }
    return 0;
}
