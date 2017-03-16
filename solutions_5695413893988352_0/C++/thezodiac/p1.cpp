#include <bits/stdc++.h>
#define fore(i,j,k) for(int i = j;i<k;i++)
#define forr(i,j,k) for(int i = j;i>k;i--)
#define LL long long

using namespace std;

string ps1,ps2;
int ans = INT_MAX;

int get_val(string s){
    int ret = 0;

    fore (i,0,s.length())
        ret = ret * 10 + (s[i] - '0');

    return ret;

}

void rec (string s1,string s2,int ind){

    if(ind >= s1.length() + s2.length()){

        int v1 = get_val(s1),v2 = get_val(s2);
        if(abs(v1-v2) < ans){
            ans = abs(v1-v2);
            ps1 = s1;
            ps2 = s2;
        } else if (abs(v1-v2)==ans){

            if(s1 < ps1){
                ps1 = s1;
                ps2 = s2;
            } else if (s1 == ps1){
                if(s2 < ps2){
                    ps1 = s1;
                    ps2 = s2;
                }
            }

        }
        return;
    }
    //cout << s1 << ' ' << s2 << " " << ind << endl;
    if(ind >= s1.length()){
        int ind1 = ind % s1.length();
        if(s2[ind1] == '?'){
            for(char ch = '0';ch <= '9'; ch++){
                s2[ind1] = ch;
                rec(s1,s2,ind+1);
            }
        } else rec(s1,s2,ind+1);

        return;
    }


    if(s1[ind]=='?'){

         for(char ch = '0';ch <= '9'; ch++){
                s1[ind] = ch;
                rec(s1,s2,ind+1);
            }
    } else rec(s1,s2,ind+1);

}

int main () {

    int t;
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;

    for(int tc = 1;tc<=t;tc++){
        cout << "case #" << tc << ": ";

        string s1,s2;
        cin >> s1 >> s2;
        ans = INT_MAX;
        rec(s1,s2,0);



        cout << ps1 << ' ' << ps2 <<  endl;
    }
}


/// flaw = orders are indeed not in order
