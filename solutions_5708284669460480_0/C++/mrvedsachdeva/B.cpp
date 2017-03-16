#include<bits/stdc++.h>

using namespace std;

#define For(i,n)        for(int i=0;i<n;++i)

int t, k, l, s,cnt,temp,ans,mx;
string keys, target,x;
void rec()
{

    if (x.length() == s)
    {
        temp = 0;
        For(i, s)
        {
            if (x.substr(i, l) == target){
                ++cnt;
                ++temp;
            }
        }
        mx = max(mx, temp);
        return;
    }
    For(i, k)
    {
        x += keys[i];
        rec();
        x = x.substr(0, x.length()-1);
    }
}
int main()
{
    cin >> t;
    For(i, t)
    {
        cin >> k >> l >> s>>keys>>target;
        cnt =0;
        mx = 0;
        ans = pow(k,s);
        rec();
        printf("Case #%d: ", i + 1);
        cout <<fixed<<setprecision(7)<<mx-double(cnt)/ans<<endl;
    }
}

