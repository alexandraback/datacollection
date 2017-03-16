#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>

#define pb push_back
#define mk make_pair
#define mod 1000000007

using namespace std;

int t,n,p,s,x;
int a[15][15],b[15][15],c[15][15];

int main() {

    freopen("C-small-attempt3.in","r",stdin);
    freopen("datas.out","w",stdout);
    cin>>t;
    for(int j=1; j<=t; j++)
    {
        for(int i=1; i<=3; i++)
        {
            for(int k=1; k<=3; k++)
            {
                a[i][k]=0;
                b[i][k]=0;
                c[i][k]=0;
            }
        }
        cin>>n>>p>>s>>x;

        bool ok=true;
        vector<string> li;
        li.pb("0");
        li.pb("1");
        string st;

        while(ok)
        {
            ok=false;
            for(int i=1; i<=n; i++)
            {
                for(int k=1; k<=p; k++)
                {
                    for(int l=1; l<=s; l++)
                    {
                        if(a[i][k]<x && b[i][l]<x && c[k][l]<x)
                            {
                                st="";
                                if(i==10)
                                    st+="10";
                                else
                                    st+=char(i+'0');
                                st+=' ';
                                if(k==10)
                                    st+="10";
                                else
                                    st+=char(k+'0');
                                st+=' ';
                                if(l==10)
                                    st+="10";
                                else
                                    st+=char(l+'0');
                                //cout<<st<<' ';
                                for(int o=0; o<li.size()-1; o++)
                                {
                                    if(st!=li[o] && st!=li[o+1])
                                    {
                                        a[i][k]++;
                                        b[i][l]++;
                                        c[k][l]++;
                                        li.insert(li.begin()+o+1,st);
                                        ok=true;
                                        break;
                                    }
                                }
                            }
                    }
                }
            }
        }
        cout<<"Case #"<<j<<": "<<li.size()-2<<'\n';
        for(int i=1;i<li.size()-1; i++)
            cout<<li[i]<<'\n';

    }
}
