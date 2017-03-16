#include <iostream>
#include <fstream>
#include <string>

#define REP(i,n) for(int i = 0;i<(n);++i)

using namespace std;

string ans;
int N;
string temp;
int change[26];
int fchange[26];

int main()
{
    ifstream fintemp("temp");
    ifstream fin("A-small-attempt5.in");
    ofstream fout("A-small-attempt5.out");

    fchange['y'-'a']='a'-'a';
    fchange['e'-'a']='o'-'a';
    fchange['q'-'a']='z'-'a';
    fchange['z'-'a']='q'-'a';
    string ori,afc;
    fintemp>>afc>>ori;
    REP(i,ori.size())
    {
        change[ori[i]-'a']=afc[i]-'a';
        fchange[afc[i]-'a']=ori[i]-'a';
    }

    fin>>N;
    getline(fin,temp);
    REP(T,N)
    {
        ans = "";
        temp = "";
        getline(fin,temp);
        REP(i,temp.size())
        {
            ans.push_back(temp[i]==' '?' ':(fchange[temp[i]-'a']+'a'));
        }

        fout<<"Case #"<<T+1<<": "<<ans<<endl;
    }
    return 0;
}
