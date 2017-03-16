#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("A-small-attempt2.in","r",stdin); freopen("00_output.txt","w",stdout);
    string digits[10]= {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int t;
    cin>>t;
    cin.ignore();
    for(int tc=1;tc<=t;tc++){
        string s;
        getline(cin,s);
        int letters[26];
        memset(letters,0,sizeof(letters));
        for(int i=0;i<s.length();i++){
            letters[s[i]-'A']++;
        }
        int numbers[10];
        memset(numbers,0,sizeof(numbers));
        int marker[s.length()];
        memset(marker,0,sizeof(marker));
        if (letters[25]>0){
            int zeroCount=letters[25];
            numbers[0]+=zeroCount;
            letters['Z'-'A']-=zeroCount;
            letters['E'-'A']-=zeroCount;
            letters['R'-'A']-=zeroCount;
            letters['O'-'A']-=zeroCount;
        }
         if (letters[22]>0){
            int zeroCount=letters[22];
            numbers[2]+=zeroCount;
            letters['T'-'A']-=zeroCount;
            letters['W'-'A']-=zeroCount;
            letters['O'-'A']-=zeroCount;
        }
         if (letters[20]>0){
            int zeroCount=letters[20];
            numbers[4]+=zeroCount;
            letters['F'-'A']-=zeroCount;
            letters['O'-'A']-=zeroCount;
            letters['U'-'A']-=zeroCount;
            letters['R'-'A']-=zeroCount;
        }
         if (letters[23]>0){
            int zeroCount=letters[23];
            numbers[6]+=zeroCount;
            letters['S'-'A']-=zeroCount;
            letters['I'-'A']-=zeroCount;
            letters['X'-'A']-=zeroCount;
        }
         if (letters[6]>0){
            int zeroCount=letters[6];
            numbers[8]+=zeroCount;
            letters['E'-'A']-=zeroCount;
            letters['I'-'A']-=zeroCount;
            letters['G'-'A']-=zeroCount;
            letters['H'-'A']-=zeroCount;
            letters['T'-'A']-=zeroCount;
        }
         if (letters[7]>0){
            int zeroCount=letters[7];
            numbers[3]+=zeroCount;
            letters['T'-'A']-=zeroCount;
            letters['H'-'A']-=zeroCount;
            letters['R'-'A']-=zeroCount;
            letters['E'-'A']-=zeroCount;
            letters['E'-'A']-=zeroCount;
        }
         if (letters[5]>0){
            int zeroCount=letters[5];
            numbers[5]+=zeroCount;
            letters['F'-'A']-=zeroCount;
            letters['I'-'A']-=zeroCount;
            letters['V'-'A']-=zeroCount;
            letters['E'-'A']-=zeroCount;
        }
         if (letters[18]>0){
            int zeroCount=letters[18];
            numbers[7]+=zeroCount;
            letters['S'-'A']-=zeroCount;
            letters['E'-'A']-=zeroCount;
            letters['V'-'A']-=zeroCount;
            letters['E'-'A']-=zeroCount;
            letters['N'-'A']-=zeroCount;
        }
         if (letters[6]>0){
            int zeroCount=letters[6];
            numbers[8]+=zeroCount;
            letters['E'-'A']-=zeroCount;
            letters['I'-'A']-=zeroCount;
            letters['G'-'A']-=zeroCount;
            letters['H'-'A']-=zeroCount;
            letters['T'-'A']-=zeroCount;
        }
         if (letters[8]>0){
            int zeroCount=letters[8];
            numbers[9]+=zeroCount;
            letters['N'-'A']-=zeroCount;
            letters['I'-'A']-=zeroCount;
            letters['N'-'A']-=zeroCount;
            letters['E'-'A']-=zeroCount;
        }
        if (letters[4]>0)
            numbers[1]+=letters[4];


        cout<<"Case #"<<tc<<": ";

        for(int i=0;i<10;i++){
            for(int j=1;j<=numbers[i];j++)
                cout<<i;
        }

        cout<<endl;


    }
}
