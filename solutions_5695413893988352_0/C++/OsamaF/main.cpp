#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int sc1=-1, sc2=-1;
void rec(int ind, string str1, string str2){

    if(ind == s1.size()){
        int num1, num2;
        stringstream ss;
        ss<<str1;
        ss>>num1;
        ss.clear();
        ss<<str2;
        ss>>num2;
        if(sc1 == -1)
            sc1 = num1, sc2 = num2;
        else if(abs(num1 - num2) < abs(sc1-sc2))
            sc1 = num1, sc2 = num2;
        else if(abs(num1 - num2) == abs(sc1-sc2)){
            if(num1 + num2 < sc1 + sc2)
                sc1 = num1, sc2 = num2;
            else if(num1 < sc1)
                sc1 = num1, sc2 = num2;
            else if (num1 == sc1)
                sc2 = min(sc2, num2);
        }
        return;
    }
    for(int i=0; i<=9; i++){
        for(int j=0; j<=9; j++){
            rec(ind+1, str1 + (s1[ind]=='?'?(char)(i+'0'):s1[ind]), str2 + (s2[ind]=='?'?(char)(j+'0'):s2[ind]));


            if(s2[ind] != '?')
                break;
        }
        if(s1[ind] != '?')
            break;
    }
}
int main()
{
    freopen ("B-small-attempt2.in","r",stdin);
    freopen ("B-small-attempt2.out","w",stdout);

    int t;
    cin>>t;
    for(int f=1; f<=t; f++){
        sc1 = -1, sc2=-1;
        cin>>s1>>s2;
        rec(0, "", "");
        string str1, str2;

        stringstream ss;
        ss<<sc1;
        ss>>str1;
        ss.clear();
        ss<<sc2;
        ss>>str2;
        if(str1.size() < s1.size())
            str1 = string(s1.size() - str1.size(), '0') + str1;
        if(str2.size() < s2.size())
            str2 = string(s2.size() - str2.size(), '0') + str2;
        cout<<"Case #"<<f<<": "<<str1<<" "<<str2<<endl;
    }
    return 0;
}
