/*
ID: zhaojm_1
PROG: A
LANG: C++
*/
#include <iostream>
#include <fstream>
//#include <algorithm>

using namespace std;

#define SUBMIT
#define DSP(X)
#   define DV(Var) cout<<#Var<<"="<<Var<<' '
#ifdef SUBMIT
    ofstream fout ("A.out");ifstream fin ("A.in");
#   define cin fin
#   define cout fout
#endif

const char rmap[26]={
    'y','h','e','s','o','c','v',
    'x','d','u','i','g','l','b',
    'k','r','z','t','n','w','j',
    'p','f','m','a','q'};
char s[255];

int main()
{
    int T;
    cin>>T;cin.getline(s,255);
    for(int t=1;t<=T;++t)
    {
        cin.getline(s,255);
        for(int i=0;s[i];++i)
        {
            if((s[i]>='a')&&(s[i]<='z'))
                s[i]=rmap[s[i]-'a'];
        }
        cout<<"Case #"<<t<<": "<<s<<endl;
    }

    return 0;
}
