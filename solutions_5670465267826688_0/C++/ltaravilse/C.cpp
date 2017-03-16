#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<sstream>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define all(v)v.begin(),v.end()

string st, st2;

struct quaternion{
    char c;
    int sign;
    bool operator==(const quaternion q) const
    {
        return c == q.c && sign == q.sign;
    }
    quaternion operator*(const quaternion q) const
    {
        quaternion res;
        if(c == q.c){
            res.c = '1';
            if(c == '1') {
                res.sign = sign*q.sign;
            }
            else {
                res.sign = -1*sign*q.sign;
            }
            return res;
        }
        if(c == 'i' && q.c == 'j'){
            res.c = 'k';
            res.sign = sign*q.sign;
        }
        if(c == 'j' && q.c == 'i'){
            res.c = 'k';
            res.sign = -1*sign*q.sign;
        }
        if(c == 'i' && q.c == 'k'){
            res.c = 'j';
            res.sign = -1*sign*q.sign;
        }
        if(c == 'k' && q.c == 'i'){
            res.c = 'j';
            res.sign = sign*q.sign;
        }
        if(c == 'j' && q.c == 'k'){
            res.c = 'i';
            res.sign = sign*q.sign;
        }
        if(c == 'k' && q.c == 'j'){
            res.c = 'i';
            res.sign = -1*sign*q.sign;
        }
        if(c == '1'){
            res.c = q.c;
            res.sign = sign*q.sign;
        }
        if(q.c == '1'){
            res.c = c;
            res.sign = sign*q.sign;
        }
        return res;
    }
};

vector<quaternion> vec;
int main()
{
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int casos;
    cin >> casos;
    for(int casito = 1; casito <= casos; casito++)
    {
        int l,x;
        cin >> l >> x >> st;
        if(x > 25)
        {
            x = x-25;
            x = x%4;
            x = x+25;
        }
        st2 = "";
        forn(i,x)
            st2 += st;
        st = st2;
        vec.resize(st.size());
        forn(i,st.size())
        {
            vec[i].sign = 1;
            vec[i].c = st[i];
        }
        for(int i=1;i<st.size();i++){
            vec[i] = vec[i-1]*vec[i];
        }
        quaternion prod = vec[st.size()-1];
        string res = "YES";
        if(prod.c != '1' || prod.sign != -1)
        {
            res = "NO";
        }
        else {
            quaternion ii, kk;
            ii.c = 'i';
            kk.c = 'k';
            ii.sign = 1;
            kk.sign = 1;
            int posi = -1, posj = -1;
            forn(i,vec.size())
            if(vec[i] == ii) {
                posi = i;
                break;
            }
            for(int i = vec.size()-1; i>=0; i--)
            if(vec[i] == kk) {
                posj = i;
                break;
            }
            if(posi == -1 || posj == -1)
                res = "NO";
            else if(posi > posj)
                res = "NO";
        }
        cout << "Case #"<< casito <<": "<< res << endl;
    }
}
