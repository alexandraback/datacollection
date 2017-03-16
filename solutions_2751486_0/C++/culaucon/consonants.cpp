#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

string s;
int n, m;

bool cons(char ch)
{
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
int main()
{
    freopen("consonants.in","r",stdin);
    freopen("consonants.out","w",stdout);
    int nt, tt=1;
    cin>>nt;
    while (nt--)
    {
        cin>>s>>m;
        n=s.size();
        vector<int> st, en;
        for (int i=0;i<n;i++)
            if (!cons(s[i]))
            {
                int j=i+1;
                while (j<n && !cons(s[j])) j++;
                if (j-i>=m)
                {
                    st.push_back(i);
                    en.push_back(j-1);
                }
                i=j-1;
            }
        int ret=0;
        for (int i=0;i<n;i++)
        {
            int lo=0, hi=st.size()-1, r=-1, len=-1;
            while (lo<=hi)
            {
                int mid=(lo+hi)/2;
                if (st[mid]>=i)
                {
                    hi=mid-1;
                    r=mid;
                    len=st[mid]+m-1;
                }
                else if (st[mid]<i && en[mid]>=i && en[mid]-i+1>=m)
                {
                    hi=mid-1;
                    r=mid;
                    len=i+m-1;
                }
                else lo=mid+1;
            }
            if (len==-1) continue;
            ret+=n-len;
        }
        cout<<"Case #"<<tt++<<": "<<ret<<endl;
    }
}
