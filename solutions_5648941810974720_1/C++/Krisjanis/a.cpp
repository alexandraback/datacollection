#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>


using namespace std;

int T;

string s;

int lc[500];
int dc[10];

int main() {
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    cin>>T;
    for(int C=0;C<T;C++) {
        cin>>s;
        memset(lc,0,sizeof(lc));
        memset(dc,0,sizeof(dc));
        for(int i=0;i<s.length();i++) {
            lc[s[i]]++;
        }
        dc[6]=lc['X'];
        lc['S']-=dc[6];
        lc['I']-=dc[6];
        dc[4]=lc['U'];
        lc['F']-=dc[4];
        lc['O']-=dc[4];
        lc['R']-=dc[4];
        dc[2]=lc['W'];
        lc['T']-=dc[2];
        lc['O']-=dc[2];
        dc[5]=lc['F'];
        lc['I']-=dc[5];
        lc['V']-=dc[5];
        lc['E']-=dc[5];
        dc[7]=lc['V'];
        lc['S']-=dc[7];
        lc['E']-=2*dc[7];
        lc['N']-=dc[7];
        dc[0]=lc['Z'];
        lc['E']-=dc[0];
        lc['R']-=dc[0];
        lc['O']-=dc[0];
        dc[1]=lc['O'];
        lc['E']-=dc[1];
        lc['N']-=dc[1];
        dc[8]=lc['G'];
        lc['E']-=dc[8];
        lc['I']-=dc[8];
        lc['H']-=dc[8];
        lc['T']-=dc[8];
        dc[3]=lc['H'];
        dc[9]=lc['I'];


        cout<<"Case #"<<C+1<<": ";
        for(int i=0;i<10;i++) {
            for(int j=0;j<dc[i];j++)
                cout<<i;
        }
        cout<<endl;
    }
}
