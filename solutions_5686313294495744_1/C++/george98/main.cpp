#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string,int> vaz1,vaz2;
vector<int> v[1010];
int cup1[1010],cup2[1010];
char vaz[1010];

int cupleaza(int nod)
{
    if(vaz[nod]) return 0;
    vaz[nod]=1;
    for(vector<int>::iterator it=v[nod].begin();it!=v[nod].end();it++)
        if(!cup2[*it] || cupleaza(cup2[*it]))
        {
            cup1[nod]=*it;
            cup2[*it]=nod;
            return 1;
        }
    return 0;
}

int main()
{
    ifstream cin("file.in");
    ofstream cout("file.out");
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        int n,nr1=0,nr2=0,sol=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            if(!vaz1[s1]) vaz1[s1]=++nr1;
            if(!vaz2[s2]) vaz2[s2]=++nr2;
            v[vaz1[s1]].push_back(vaz2[s2]);
        }
        int ok=1;
        while(ok)
        {
            ok=0;
            for(int i=1;i<=nr1;i++) vaz[i]=0;
            for(int i=1;i<=nr1;i++)
                if(!cup1[i]) ok|=cupleaza(i);
        }
        for(int i=1;i<=nr1;i++)
            if(cup1[i]) sol++;
        cout<<"Case #"<<t<<": "<<n-(nr1+nr2-sol)<<"\n";
        for(int i=1;i<=nr1;i++)
        {
            cup1[i]=0;
            v[i].clear();
        }
        for(int i=1;i<=nr2;i++) cup2[i]=0;
        vaz1.clear();
        vaz2.clear();
    }
    return 0;
}
