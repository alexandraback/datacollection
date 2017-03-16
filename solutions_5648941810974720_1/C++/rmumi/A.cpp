#include <bits/stdc++.h>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;

string svi[]={
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T;
    scanf("%d",&T);
    string s;
    for(int CASE=1;CASE<=T;CASE++)
    {
        //this is horrible, but just saving time...
        printf("Case #%d: ",CASE);
        map<char,int> mapa;
        map<int,int> koliko;
        cin>>s;
        for(char x:s)mapa[x]++;
        if(mapa.count('X'))
        {
            int z=mapa['X'];
            koliko[6]+=z;
            for(char x:svi[6])mapa[x]-=z;
        }
        if(mapa.count('Z'))
        {
            int z=mapa['Z'];
            koliko[0]+=z;
            for(char x:svi[0])mapa[x]-=z;
        }
        if(mapa.count('W'))
        {
            int z=mapa['W'];
            koliko[2]+=z;
            for(char x:svi[2])mapa[x]-=z;
        }
        if(mapa.count('G'))
        {
            int z=mapa['G'];
            koliko[8]+=z;
            for(char x:svi[8])mapa[x]-=z;
        }
        if(mapa.count('T'))
        {
            int z=mapa['T'];
            koliko[3]+=z;
            for(char x:svi[3])mapa[x]-=z;
        }
        if(mapa.count('R'))
        {
            int z=mapa['R'];
            koliko[4]+=z;
            for(char x:svi[4])mapa[x]-=z;
        }
        if(mapa.count('S'))
        {
            int z=mapa['S'];
            koliko[7]+=z;
            for(char x:svi[7])mapa[x]-=z;
        }
        if(mapa.count('V'))
        {
            int z=mapa['V'];
            koliko[5]+=z;
            for(char x:svi[5])mapa[x]-=z;
        }
        if(mapa.count('O'))
        {
            int z=mapa['O'];
            koliko[1]+=z;
            for(char x:svi[1])mapa[x]-=z;
        }
        if(mapa.count('I'))
        {
            int z=mapa['I'];
            koliko[9]+=z;
            for(char x:svi[9])mapa[x]-=z;
        }
        for(auto x: koliko)
        {
            for(int j=0;j<x.yy;j++)
                printf("%c",x.xx+'0');
        }
        putchar('\n');
    }
    return 0;
}
