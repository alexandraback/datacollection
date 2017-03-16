#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>

#include<set>
#include<string>
using namespace std;

#define MAX_N 100
string boxes[MAX_N];
int n;

bool cmpLess(const string &a, const string &b)
{
    if(a[0]!=b[0])
    {
        return a[0]<b[0];
    }
    else
    {
        if(a[a.length()-1]!=b[b.length()-1])
            return a[a.length()-1]<b[b.length()-1];
    }
    return false;
}

bool theSame(const string &a, const string &b)
{
    if(a[0]==a[a.length()-1]&&a[a.length()-1]==b[0]
       &&b[0]==b[b.length()-1])
        return true;

    else
        return false;

}

bool notInter(const string &a, const string &b)
{
    for(int i=0; a[i]; i++)
    {
        for(int j=0;b[j]; j++)
        {
            if(a[i]==b[j])
                return false;
        }
    }
    return true;
}

bool valid()
{
    bool table[26];
    for(int i=0;i<26;i++)
    {
        table[i] = false;
    }

    char nowc = 0;

    for(int i=0; i<n; i++)
    {
        const string &s = boxes[i];
        for(int j=0;s[j];j++)
        {
            char c = s[j];
            if(nowc==c)
            {
            }
            else
            {
                nowc = c;
                if(table[c-'a'])
                {
                    return false;
                }
                table[c-'a'] = true;
            }
        }
    }
    return true;
}

long long int MOD = 1000000007LL;

long long int calc()
{
    if(!valid())
    {
        return 0LL;
    }
    int acc = 1;
    long long int sum = 1;
    int sets = 1;
    for(int i=0; i<n-1; i++)
    {
        if(theSame(boxes[i],boxes[i+1]))
        {
            acc++;
        }
        else
        {
            sum = (sum*acc)%MOD;
            acc = 1;
            if(notInter(boxes[i],boxes[i+1]))
            {
                sets++;
            }
        }

        //set++??

    }
    sum = (sum*acc)%MOD;

    for(int i=1; i<=sets; i++)
        sum = (sum*i)%MOD;

    return sum;
}


int main()
{
    int T;
    cin >> T;

    for(int runT=0; runT<T; runT++)
    {
        cin >> n;

        string str;

        for(int i=0; i<n; i++)
        {
            cin >> boxes[i];
        }

        std::sort(boxes, boxes+n, cmpLess);

        long long int ans = calc();

        cout << "Case #" <<  runT+1 << ": " << ans << endl;
    }

    return 0;
}
