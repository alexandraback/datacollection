#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define len(x) ((int)(x.size()))
#define inf 1061109567


int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int tst;

    cin>>tst;

    for(int tt=1;tt<=tst;tt++){
        cout<<"Case #"<<tt<<": ";
        string s;
        cin>>s;
        map<char,int> m;
        for(int i=0;i<len(s);i++)m[s[i]]++;
        string ans="";
        for(int i=0;i<len(s);i++){
            if(s[i]=='Z'){
                ans+="0";
                m['Z']--;
                m['E']--;
                m['R']--;
                m['O']--;
            }
            if(s[i]=='W'){
                ans+="2";
                m['T']--;
                m['W']--;
                m['O']--;
            }
            if(s[i]=='U'){
                ans+="4";
                m['F']--;
                m['O']--;
                m['U']--;
                m['R']--;
            }            
            if(s[i]=='X'){
                ans+="6";
                m['S']--;
                m['I']--;
                m['X']--;
            }
        }
        s=ans;
        map<char,int> m1=m;

        for(auto a:m1){
            for(int j=0;j<a.second;j++){
                if(a.first=='O'){
                    s+="1";
                    m['O']--;
                    m['N']--;
                    m['E']--;
                }
            }
        }

        map<char,int> m2=m;

        for(auto a:m2){
            for(int j=0;j<a.second;j++){
                if(a.first=='R'){
                    s+="3";
                    m['T']--;
                    m['H']--;
                    m['R']--;
                    m['E']--;
                    m['E']--;
                }
            }
        }


        map<char,int> m3=m;

        for(auto a:m3){
            for(int j=0;j<a.second;j++){
                if(a.first=='S'){
                    s+="7";
                    m['S']--;
                    m['E']--;
                    m['V']--;
                    m['E']--;
                    m['N']--;
                }
            }
        }

        map<char,int> m4=m;

        for(auto a:m4){
            for(int j=0;j<a.second;j++){
                if(a.first=='T'){
                    s+="8";
                    m['E']--;
                    m['I']--;
                    m['G']--;
                    m['H']--;
                    m['T']--;
                }
            }
        }


        map<char,int> m5=m;

        for(auto a:m5){
            for(int j=0;j<a.second;j++){
                if(a.first=='V'){
                    s+="5";
                    m['F']--;
                    m['I']--;
                    m['V']--;
                    m['E']--;
                }
            }
        }


        map<char,int> m6=m;

        for(auto a:m6){
            for(int j=0;j<a.second;j++){
                if(a.first=='E'){
                    s+="9";
                    m['N']--;
                    m['I']--;
                    m['N']--;
                    m['E']--;
                }
            }
        }
        sort(s.begin(),s.end());
        cout<<s<<endl;


    }

}

