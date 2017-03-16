#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;


set<int> b[1001];
int a[1001];
int result;
bool used[1001];
vector<int> v;

void go(int i)
{
    if (v.size()>result && v.size()!=1 && (a[v[v.size()-1]]==v[0] || a[v[v.size()-1]]==v[v.size()-2])) result=v.size();
    if (i<0 || used[i])
    {
        if (v.size()>result) {if (v.size()!=1 && (a[v[v.size()-1]]==v[0] || a[v[v.size()-1]]==v[v.size()-2])) result=v.size();}
        return;
    }
    v.push_back(i);
    used[i]=true;
    if (v.size()>result) {if (v.size()!=1 && (a[v[v.size()-1]]==v[0] || a[v[v.size()-1]]==v[v.size()-2])) result=v.size();}

    if (v.size()==1)
    {
        go(a[i]);
    }
    else
    {
        int last=v[v.size()-2];
        if (a[i]!=last)
        {
            go(a[i]);
        }
        else
        {
            if (v.size()>result && v.size()!=1 && (a[v[v.size()-1]]==v[0] || a[v[v.size()-1]]==v[v.size()-2])) result=v.size();
            set<int>::iterator it;
            for (it=b[i].begin(); it!=b[i].end(); ++it)
            {
                go(*it);
            }
        }
    }
    v.pop_back();
    used[i]=false;
}

int main()
{
    freopen("C-small-attempt5.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    long long T,t,tt;
    long long i,j,k;


    int n;
    int temp;
    cin>>T;
    for(tt=1;tt<=T;tt++)
    {
        for (i=0;i<1001;i++) b[i].clear();
        memset(a,-1,sizeof(a));
        cin>>n;
        for (i=0;i<n;i++)
        {
            cin>>temp;
            temp--;
            a[i]=temp;
            b[temp].insert(i);
        }

        result=1;
        v.clear();
        for (i=0;i<n;i++)
        {
            memset(used,0,sizeof(used));
            go(i);
        }


        cout<<"Case #"<<tt<<": "<<result<<endl;
    }

    return 0;
}


