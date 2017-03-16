#include<iostream>
#include<fstream>
using namespace std;

fstream a;
bool kwota[100];
int nominaly[100];
bool zrobione[100];

int main()
{
    a.open("wyjscie.txt", ios::out);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        fill(kwota, kwota+90, false);
        int c, d, v;
        cin>>c>>d>>v;
        for(int j=0; j<d; j++) cin>>nominaly[j];
        kwota[0]=true;
        for(int k=0; k<d; k++)
        {
        for(int j=0; j<v; j++)
        {
            if(kwota[j] && !zrobione[j])
            {
                if(!kwota[j+nominaly[k]]) zrobione[j+nominaly[k]]=true;
                kwota[j+nominaly[k]]=true;
            }
        }
        fill(zrobione, zrobione+90, false);
        }
        int wynik=0;
        for(int j=1; j<=v; j++)
        {
            if(!kwota[j])
            {
                wynik++;
            for(int k=0; k<v; k++)
            {
                if(!zrobione[k] && kwota[k])
                {
                    if(!kwota[k+j])zrobione[k+j]=true;
                    kwota[k+j]=true;
                }
            }
            fill(zrobione, zrobione+90, false);
            }
        }
        a<<"Case #"<<i<<": "<<wynik<<"\n";
    }
}
