#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int t;
    fin >> t;
    int T=t;
    map<string,char> mp;
    string digs[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int dits[10] = {0,2,6,8,7,3,5,4,1,9};
    mp["ZERO"]='Z';
    mp["ONE"]='O';
    mp["TWO"]='W';
    mp["THREE"]='H';
    mp["FOUR"]='F';
    mp["FIVE"]='V';
    mp["SIX"]='X';
    mp["SEVEN"]='S';
    mp["EIGHT"]='G';
    mp["NINE"]='E';

    while(t--){
        fout<<"Case #"<<T-t<<": ";
        string s;
        int ar[26];
        memset(ar,0,sizeof(ar));
        fin >> s;
        for(int ctr1=0;ctr1<s.size();ctr1++)
            ar[s[ctr1]-'A']++;
        vector<int> rez;
        for(int ctr1=0;ctr1<10;ctr1++){
            int k=ar[mp[digs[dits[ctr1]]]-'A'];
            for(int ctr2=0;ctr2<digs[dits[ctr1]].length();ctr2++)
                ar[digs[dits[ctr1]][ctr2]-'A']-=k;
            for(int ctr2=0;ctr2<k;ctr2++)
                rez.push_back(dits[ctr1]);
        }
        sort(rez.begin(),rez.end());
        for(int ctr1=0;ctr1<rez.size();ctr1++)
            fout<<rez[ctr1];
        fout<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
