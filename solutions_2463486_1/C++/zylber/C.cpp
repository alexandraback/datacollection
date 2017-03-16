#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> doupals;

void calc(string num, int maxpos, int actpos, int sum)
{
    if(actpos==maxpos)
    {
        string fin=num;
        for(int i=0; i<maxpos; i++)
            fin+=num[maxpos-i-1];

        doupals.push_back(fin);

        for(int i=0; i*i+sum<10; i++)
        {
            string fin2=num;
            fin2+=i+'0';
            for(int i=0; i<maxpos; i++)
                fin2+=num[maxpos-i-1];

            doupals.push_back(fin2);
        }

    }
    else
    {
        for(int n=0; n<=3; n++)
            if(sum+2*n*n<10 && (n!=0 || actpos!=0) )
            {
                string res=num;
                res+='0'+n;
                calc(res, maxpos, actpos+1, sum+2*n*n);
            }
    }
    return;
}

bool cmp(string a, string b)
{
    if(a.size()<b.size())
        return true;
    if(a.size()>b.size())
        return false;
    return (a<=b);
}

string sq(string s)
{
    string res=""; int ss=s.size();

    for(int sum=0; sum<2*ss-1; sum++)
    {
        int k=0;
        for(int j=max(0,sum-ss+1); j<min(sum+1,ss); j++)
            k+=(s[j]-'0')*(s[sum-j]-'0');
        res+=k+'0';
    }
    return res;
}

int calc(string A)
{
    int top=doupals.size(), bot=0, mid=(top+bot)/2;
    while(top-bot>1)
    {
        if(cmp(sq(doupals[mid]),A))
            bot=mid;
        else
            top=mid;
        mid=(top+bot)/2;
    }
    return bot;
}

string dec(string s)
{
    int i=s.size()-1;
    while(s[i]=='0')
    {
        s[i]='9';
        i--;
    }
    s[i]--;
    return s;

}

int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);

    for(int i=0; i<25; i++)
        calc("",i,0,0);

    sort(doupals.begin(), doupals.end(), cmp);

    int tc;
    cin >> tc;
    for(int nt=1; nt<=tc; nt++)
    {
        string A, B;
        cin >> A >> B;
        cout << "Case #" << nt << ": ";
        cout << calc(B)-calc(dec(A)) << endl;
    }
}
