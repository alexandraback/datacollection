#include<bits/stdc++.h>
using namespace std;

int t, k, l, s,cnt,temp,ans,mx;
string keys1, target1,x1;
void rec()
{

    if (x1.length() == s)
    {
        temp = 0;
        for(int i=0;i<s;i++)
        {
            if (x1.substr(i, l) == target1){
                ++cnt;
                ++temp;
            }
        }
        mx = max(mx, temp);
        return;
    }
    for(int i=0;i<k;i++)
    {
        x1 += keys1[i];
        rec();
        x1 = x1.substr(0, x1.length()-1);
    }
}
int main()
{
    freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> k >> l >> s>>keys1>>target1;
        cnt =0;
        mx = 0;
        ans = pow(k,s);
        rec();
        printf("Case #%d: ", i + 1);
        cout <<fixed<<setprecision(7)<<mx-double(cnt)/ans<<endl;
    }
    return 0;
}
