#include<bits/stdc++.h>
using namespace std;

#define l long long

ifstream fin("input.txt");
ofstream fout("output.txt");

string num[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int charcount[300];
int main(){
    int t;cin>>t;
    for(int j=1;j<=t;j++){
        string s;cin>>s;

        memset(charcount,0,sizeof(charcount));
        for(int i=0;i<s.length();i++)charcount[s[i]]++;
        int ar[10];memset(ar,0,sizeof(ar));

        ar[0]=charcount['Z'];
        for(int i=0;i<num[0].length();i++)charcount[num[0][i]]-=ar[0];

        ar[2]=charcount['W'];
        for(int i=0;i<num[2].length();i++)charcount[num[2][i]]-=ar[2];

        ar[6]=charcount['X'];
        for(int i=0;i<num[6].length();i++)charcount[num[6][i]]-=ar[6];

        ar[4]=charcount['U'];
        for(int i=0;i<num[4].length();i++)charcount[num[4][i]]-=ar[4];

        ar[5]=charcount['F'];
        for(int i=0;i<num[5].length();i++)charcount[num[5][i]]-=ar[5];

        ar[7]=charcount['V'];
        for(int i=0;i<num[7].length();i++)charcount[num[7][i]]-=ar[7];

        ar[1]=charcount['O'];
        for(int i=0;i<num[1].length();i++)charcount[num[1][i]]-=ar[1];

        ar[3]=charcount['R'];
        for(int i=0;i<num[3].length();i++)charcount[num[3][i]]-=ar[3];

        ar[8]=charcount['G'];
        for(int i=0;i<num[8].length();i++)charcount[num[8][i]]-=ar[8];

        ar[9]=charcount['I'];
        for(int i=0;i<num[9].length();i++)charcount[num[9][i]]-=ar[9];

        cout<<"Case #"<<j<<": ";
        for(int i=0;i<10;i++){
            for(int k=0;k<ar[i];k++)cout<<i;
        }
        cout<<endl;

    }
}
