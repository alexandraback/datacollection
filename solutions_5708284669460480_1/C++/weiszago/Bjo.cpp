#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <unordered_set>

using namespace std;


string key;
string target;
int k, l, s;

int v[100];


typedef vector<int> VI;

void buildTable(string w, VI& t)
{
  t = VI(w.length());
  int i = 2, j = 0;
  t[0] = -1; t[1] = 0;

  while(i < w.length())
  {
    if(w[i-1] == w[j]) { t[i] = j+1; i++; j++; }
    else if(j > 0) j = t[j];
    else { t[i] = 0; i++; }
  }
}



int main()
{
    freopen("B-large.in", "r", stdin);
    cout.precision(12);
    freopen("BBBkilargelarge.txt", "w", stdout);
    int t;
    cin >> t;
    for (int tt=1;tt<=t;tt++) {
        cin >> k>>l>>s;
        cin>> key;
        cin>> target;
        for (int i=0;i<100;i++) v[i]=0;
        for (int i=0;i<key.size();i++) {
            v[key[i]-'A']++;
        }

        //s hosszuba hanyszor target
        VI tab;
        buildTable((target+'.'), tab);
        int elmegy=l-tab[l];
        if (elmegy<=0) elmegy=l;
        long double ma=0;
        int ccc=s;
        //cout << elmegy<<endl;
        if (target.size()==1) {
            elmegy=1;
        }
        if (target.size()==2) {
            if (target[0]==target[1]) elmegy=1;
            else elmegy=2;
        }

        if (target.size()>=2 && target[0]==target[target.size()-1]) elmegy=min(elmegy, (int)target.size()-1);



        while (ccc>=l) {
            ma++;
            ccc-=elmegy;
        }

        for (int i=0;i<target.size();i++) {
            if (v[target[i]-'A']==0) ma=0;
        }


        long double atlag=s-l+1;
        for (int i=0;i<target.size();i++) {
            atlag*=((long double)v[target[i]-'A']/(long double)key.size());
        }


        cout << "Case #" << tt<< ": "<<ma-atlag<<endl;
    }
    return 0;
}
