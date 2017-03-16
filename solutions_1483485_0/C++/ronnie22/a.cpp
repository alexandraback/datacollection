#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in ("A-small-attempt1.in");
    ofstream out ("output.txt");
    char go[101],*ing;
    int n,t;
    int dicv[26]={121,110,102,105,99,119,108,98,107,117,111,109,120,115,101,118,122,112,100,114,106,103,116,104,97,113};
    int dic[26]={121,104,101,115,111,99,118,120,100,117,105,103,108,98,107,114,122,116,110,119,106,112,102,109,97,113};
    in>>t;
    in.getline(go,101);
    n=in.gcount();
    for(int i=0;i<t;i++)
    {
         in.getline(go,101);
         n=in.gcount();
         free(ing);
         ing=(char*)malloc(n*sizeof(char));
         for(int j=0;j<n;j++)
         {
                 if(go[j]==32)
                 {
                      ing[j]=32;
                 }
                 else
                 {
                      ing[j]=dic[go[j]-97];
                 }
         }
         out<<"Case #"<<i+1<<": "<<ing<<endl;
    }
}
