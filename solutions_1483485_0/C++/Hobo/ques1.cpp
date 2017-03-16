#include<fstream>
using namespace std;
int main()
{
    char s[200];
    int t,l,p=1,i;
    ifstream fin("A-small-attempt1.in");
    ofstream fout("output.txt");
    char ch[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
    fin>>t;
    fin.get();
    while(t--)
    {
              fin.getline(s,200,'\n');
              l=strlen(s);
              fout<<"Case #"<<p<<": ";
              for(i=0;i<l;i++)
              {
                              if(s[i]==32)
                              fout<<s[i];
                              else
                              fout<<ch[s[i]-97]; 
                              }
                              fout<<endl;
                              p++;
              }
              return 0;
              }
    
