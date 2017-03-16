#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
using namespace std;
typedef string Str;
map<Str,int>Mem1,Mem2;
vector<Str>Vecta,Vecta2;
int main()
{
    std:ios::sync_with_stdio(false);
    //input.tie();
    //output.tie();
    ifstream input;
    input.open("inp.txt");
    ofstream output;
    output.open("out.txt");
    int T;
    input>>T;
    for (int i=0 ; i<T ; i++)
    {
        output<<"Case #"<<i+1<<": ";
        int N;
        input>>N;
        for (int j=0 ; j<N ; j++)
        {
            string a,b;
            input>>a>>b;
            Vecta.push_back(a);
            Mem1[a]+=1;
            Vecta2.push_back(b);
            Mem2[b]+=1;
        }
        int Ans=0;
        for (int j=0 ; j<N ; j++)
        {
            if(Mem1[Vecta[j]]>1 && Mem2[Vecta2[j]]>1)
            {
                Ans++;
                Mem1[Vecta[j]]--;
                Mem2[Vecta2[j]]--;
            }
        }
        output<<Ans<<endl;
    }
}
