#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int arr[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
        int l,x;
        cin>>l>>x;
        string s,s1;
        cin>>s1;
        for(int f=0;f<x;f++)
            s+=s1;
        int val=1;
        map<char,int>m;
        m['i']=2,m['j']=3,m['k']=4;
        int i=0;
        for(int f=0;f<s.size();f++)
        {
            if(val<0)
            {
                val=-arr[-val][m[s[f]]];
            }
            else
                val=arr[val][m[s[f]]];
            if(val==2&&i==0)
                val=1,i++;
            if(val==3&&i==1)
                val=1,i++;
            if(val==4&&i==2)
                val=1,i++;
        }
        cout<<"Case #"<<tc<<": ";
        if(val==1&&i==3)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
