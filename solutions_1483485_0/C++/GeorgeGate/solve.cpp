#include <fstream>
#include <string>

using namespace std;

const char map[256]={0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,121,104,101,115,111,99,118,120,100,117,105,103,108,98,107,114,122,116,110,119,106,112,102,109,97,113,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const long MAXLEN=1000;

int main()
{
    const char filename[256]="A-small-attempt0";
    char input[256]="data\\";
    char output[256]="data\\";
    strcat(strcat(input,filename),".in");
    strcat(strcat(output,filename),".out");
    ifstream fin (input);
    ofstream fout (output);
    
    long n;
    char str[MAXLEN];
    fin >>n;
    fin.ignore();
    for (long i=1;i<=n;++i)
    {
        fin.getline(str,MAXLEN,'\n');
        long len=strlen(str);
        for (long j=0;j<len;++j)
            str[j]=map[str[j]];
        fout <<"Case #" <<i <<": " <<str <<endl;
    }
        
    return 0;
}


