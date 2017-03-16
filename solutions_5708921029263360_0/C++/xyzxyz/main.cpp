#include <bits/stdc++.h>
#include <string>
using namespace std;

int t;
int n;
int j,s,p, k;
map<string, int> mmm;

int ans1[1000000], ans2[1000000], ans3[1000000];
int cnt, say1, say2, say3;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin>>t;
    for(int o = 1; o <= t; ++o)
    {
        cnt = 0;
        cin>>j>>p>>s>>k;
        mmm.clear();
        for(int a = 1; a <= j; ++a)
        for(int b = 1; b <= p; ++b)
        for(int c = 1; c <= s; ++c){
            //int a = 10;
            stringstream ss1;
            ss1 << a;
            string str1 = ss1.str();

            stringstream ss2;
            ss2 << b;
            string str2 = ss2.str();

            stringstream ss3;
            ss3 << c;
            string str3 = ss3.str();



            string s1 = str1 + str2 + "JP";
            string s2 = str1 + str3 + "JS";
            string s3 = str2 + str3 + "PS";
            if(mmm.count(s1) > 0)
                say1 = mmm[s1];
            else
                say1 = 0;
            if(mmm.count(s2) > 0)
                say2 = mmm[s2];
            else
                say2 = 0;
            if(mmm.count(s3) > 0)
                say3 = mmm[s3];
            else
                say3 = 0;
            if(say1 < k && say2 < k && say3 < k){
                ans1[cnt] = a, ans2[cnt] = b, ans3[cnt] = c;
                ++cnt;
                if(mmm.count(s1) > 0)
                    mmm[s1]++;
                else
                    mmm[s1] = 1;
                if(mmm.count(s2) > 0)
                    mmm[s2]++;
                else
                    mmm[s2] = 1;
                if(mmm.count(s3) > 0)
                    mmm[s3]++;
                else
                    mmm[s3] = 1;
            }
        }

        cout<<"Case #"<<o<<": "<<cnt<<endl;
        for(int i = 0; i < cnt; ++i){
            cout<<ans1[i]<<" "<<ans2[i]<<" "<<ans3[i]<<endl;
        }

    }

    return 0;
}
