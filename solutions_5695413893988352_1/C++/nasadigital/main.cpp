#include <bits/stdc++.h>
#define MOD 1000000007
#define MINF -1000000000000000000

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,string> ss;

char gt(char a,char b,char c){
    if(a!='?')
        return a;
    if(b!='?')
        return b;
    return c;
}

ss rek(string a,string b,int p){
    for(int ctr1=0;ctr1<p;ctr1++){
        if(a[ctr1]!='?' && b[ctr1]!='?'){
            if(a[ctr1]!=b[ctr1])
            return{"",""};
        }
        else{
            a[ctr1]=b[ctr1]=gt(a[ctr1],b[ctr1],'0');
        }
    }
    if(p!=a.size()){
        if(a[p]=='?'){
            if(b[p]=='?')
            {
                a[p]='1';
                b[p]='0';
            }
            else{
                if(b[p]=='9')
                return {"",""};
                a[p]=b[p]+1;
            }
        }
        else{
            if(b[p]=='?')
            {
                if(a[p]=='0')
                    return {"",""};
                    b[p]=a[p]-1;
            }
            if(a[p]<=b[p])
                return {"",""};
        }
    }
    for(int ctr1=p+1;ctr1<a.size();ctr1++){
        if(a[ctr1]=='?')
            a[ctr1]='0';
        if(b[ctr1]=='?')
            b[ctr1]='9';
    }

    return {a,b};
}

ll stol(string a){
    ll rez=0;
    for(int ctr1=0;ctr1<a.size();ctr1++)
    {
        rez*=10;
        rez+=a[ctr1]-'0';
    }
    return rez;
}

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int t;
    fin >> t;
    int T=t;

    while(t--)
    {
        fout<<"Case #"<<T-t<<": ";
        string a,b;
        fin>>a>>b;
        vector<ss> rez1;
        for(int ctr1=0;ctr1<=a.size();ctr1++){
            ss r=rek(a,b,ctr1);
            if(r.first!="")
                rez1.push_back(r);
        }
        swap(a,b);
        for(int ctr1=0;ctr1<=a.size();ctr1++){
            ss r=rek(a,b,ctr1);
            if(r.first!="")
                rez1.push_back({r.second,r.first});
        }
        int r=0;
        for(int ctr1=1;ctr1<rez1.size();ctr1++){
            if(abs(stol(rez1[r].first)-stol(rez1[r].second))>abs(stol(rez1[ctr1].first)-stol(rez1[ctr1].second))){
                r=ctr1;
            }
            else if(abs(stol(rez1[r].first)-stol(rez1[r].second))==abs(stol(rez1[ctr1].first)-stol(rez1[ctr1].second))){
                if(stol(rez1[r].first)>stol(rez1[ctr1].first))
                    r=ctr1;
                else if (stol(rez1[r].first)==stol(rez1[ctr1].first)){
                    if(stol(rez1[r].second)>stol(rez1[ctr1].second))
                        r=ctr1;
                }
            }
        }
        fout<<rez1[r].first<<" "<<rez1[r].second<<"\n";

    }
    fin.close();
    fout.close();
    return 0;
}
