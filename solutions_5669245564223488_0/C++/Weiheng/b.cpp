#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<string> train;
int mark[30];
int curr[30];
int visited[200];
int num=0;
int n;
string test;

int isValid(string st, string en)
{
    int mark[30]={0};
    int i;
    char pre=st[st.size()-1];
    for(i=0; i<st.size(); i++)
        mark[st[i]-'a']=1;
    for(i=0; i<en.size(); i++)
    {
        if( en[i]!=pre && mark[en[i]-'a']==1)
            return 0;
        pre = en[i];
        mark[en[i]-'a']=1;
    }
    return 1;
}

int isTrain(int st)
{
    if(st>=train.size())
    {
        num+=1;
        return 1;
    }
    int i,j;
    for(i=0; i<train.size(); i++)
    {
        if(visited[i]==1)continue;
        if( isValid(test, train[i]) != 1)
            continue;
        test+=train[i];
        visited[i]=1;
        isTrain(st+1);
        test=test.substr(0,test.size()-train[i].size());
        visited[i]=0;
    }
}

int main()
{
    int t,c;
    cin>>t;
    c=1;
    int i,j;
    char mid[1000];
    while(c<=t)
    {
        train.clear();
        cin>>n;
        for(i=0; i<30; i++)
            mark[i]=curr[i]=0;
        for(i=0;i<n;i++)
        {
            scanf("%s", mid);
            train.push_back(string(mid));
            for(j=0;mid[j]!=0;j++)
                mark[mid[j]-'a']+=1;
            visited[i]=0;
        }
        num=0;
        test="";
        isTrain(0);
        cout<<"Case #"<<c<<": "<<num<<endl;
        c++;
    }
    return 0;
}

