#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int flag = 0;
string calc(string p, int ch[], string num){
    string ret = "";
    int i;
    if(p == "")
        return "";
    int n = ch[p[0]];
    for(i=0;i<n;i++)
        ret += num;
    for(i=0;i<p.size();i++){
        ch[p[i]] -= n;
    }
    return ret;
}
int main()
{
    int i, j, tn, n;
    int ch[1000];
    string in;
    freopen("gcas.in", "r", stdin);
    freopen("gcas.out", "w", stdout);
    scanf("%d",&tn);
    for(int tt = 1;tt<=tn;tt++){
        cin>>in;
        string ret = "";
        memset(ch, 0, sizeof(ch));
        for(i=0;i<in.size();i++){
            ch[in[i]]++;
        }
        //string p;
        ret += calc("ZERO", ch, "0");
        ret += calc("WTO", ch, "2");
        ret += calc("XIS", ch, "6");
        ret += calc("UFOR", ch, "4");
        ret += calc("FIVE", ch, "5");
        ret += calc("VSEEN", ch, "7");
        ret += calc("ONE", ch, "1");
        ret += calc("GIEHT", ch, "8");
        ret += calc("THREE", ch, "3");
        ret += calc("INEN", ch, "9");
        sort(ret.begin(), ret.end());

        cout<<"Case #"<<tt<<": "<<ret<<endl;
    }
    return 0;
}
