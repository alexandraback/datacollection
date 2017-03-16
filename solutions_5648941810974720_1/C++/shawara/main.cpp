#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define X first
#define Y sencond

int main()
{
    /**
    z=0
    w=2

    u=4
    g=8
    h=3
    x=6
    s=7
    v=5
    i=9
    n=1
    */

freopen("A-large (2).in","rt",stdin);
freopen("out.txt","wt",stdout);

    int t;
    cin>>t;
    for(int j=1; j<=t; j++){
        map<char,int> m;
        string s="",ss;
        cin>>ss;
        for(int i=0 ; i<ss.size(); i++){
            m[ss[i]]++;
        }

        /// zeros;
        for(int i=0; i<m['Z']; i++)s+='0';
        int k=m['Z'];
        m['Z']=0;
        m['E']-=k;
        m['R']-=k;
        m['O']-=k;

        /// TWO
         for(int i=0; i<m['W']; i++)s+='2';
         k=m['W'];
        m['W']=0;
        m['T']-=k;
        m['O']-=k;




          /// FOUR
         for(int i=0; i<m['U']; i++)s+='4';
         k=m['U'];
        m['U']=0;
        m['F']-=k;
        m['O']-=k;
        m['R']-=k;



           /// EIGHT
         for(int i=0; i<m['G']; i++)s+='8';
         k=m['G'];
        m['G']=0;
        m['E']-=k;
        m['I']-=k;
        m['T']-=k;
        m['H']-=k;


           /// THREE
         for(int i=0; i<m['H']; i++)s+='3';
         k=m['H'];
        m['H']=0;
        m['T']-=k;
        m['R']-=k;
        m['E']-=(2*k);

           /// SIX
         for(int i=0; i<m['X']; i++)s+='6';
         k=m['X'];
        m['X']=0;
        m['S']-=k;
        m['I']-=k;

            /// SEVEN
         for(int i=0; i<m['S']; i++)s+='7';
         k=m['S'];
        m['S']=0;
        m['V']-=k;
        m['N']-=k;
        m['E']-=(2*k);


            /// FIVE
         for(int i=0; i<m['V']; i++)s+='5';
         k=m['V'];
        m['V']=0;
        m['F']-=k;
        m['I']-=k;
        m['E']-=k;


            /// NINE
         for(int i=0; i<m['I']; i++)s+='9';
         k=m['I'];
        m['I']=0;
        m['N']-=k;
        m['N']-=k;
        m['E']-=k;



        for(int i=0; i<m['O']; i++)s+='1';


        sort(s.begin(),s.end());
        cout<<"Case #"<<j<<": "<<s<<endl;
    }

    return 0;
}
