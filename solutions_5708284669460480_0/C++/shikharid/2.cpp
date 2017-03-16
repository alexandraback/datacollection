#include<bits/stdc++.h>
using namespace std;
vector<string> all;
int create(string st,int li, string t,int s){
        if(t.length()==s) { all.push_back(t); return 0;}
        string x ;
        for(int i = 0;i<li;i++){
            x = t + st[i];
            create(st,li,x,s);
        }
        return 0;

}

//countSubstring taken from Rosetta code
// returns count of non-overlapping occurrences of 'sub' in 'str'

int coun( string s, string t){
    int flag,ct =0;
    for(int i = 0;i < (s.length()-t.length()+1);i++){
        int flag=1;
        for(int j = i;j<(i+t.length());++j){
            if(s[j]!=t[j-i]){
                flag = 0;
                break;
            }

        }
        if(flag == 1) ct++;
    }
    return ct;

}
int main(){
    int t, k, l, s;
    string tar, st;
    ifstream cin("E.in");
    ofstream cout("4000.txt");
    cin >> t;
    for(int tt=1;tt<=t;tt++){
          cin >> k >> l >> s;
          cin >>  st >> tar;
          all.clear();
          string x="";

          create(st,k,x,s);
          int ma = 0, ct = 0;
          for(int i = 0;i < all.size(); ++i){
            int c = coun(all[i], tar);
            if(c > ma) ma = c;
            ct += c;
          }
          double exp = (ct / (all.size()*1.0));
          double lef = ma - exp;
          cout.precision(10);
          cout<<"Case #"<<tt<<": "<<lef<<endl;
        printf("%d\n",tt);


    }
    return 0;
}
