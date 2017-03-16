/*#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef pair<int,int> PP;
map<int,int,greater<int> > m;
bool all_positive()
{
    for (map<int,int,greater<int> >::iterator it=m.begin();it!=m.end();++it)
        if (it->second<0) return false;
    return true;
}
double sum()
{
    double ret=0;
    for (map<int,int,greater<int> >::iterator it=m.begin();it!=m.end();++it)
        ret+=pow(1.46557123187677d,it->first)*it->second;
    return ret;
}
void add(int pos,int val)
{
    if (!val) return ;
    map<int,int,greater<int> >::iterator it=m.find(pos);
    if (it==m.end())
    {
        m.insert(make_pair(pos,val));
        return ;
    }
    if (it->second+val==0)
    {
        m.erase(it);
        return ;
    }
    it->second+=val;
}
void dump()
{
    printf("===\n");
    for (map<int,int,greater<int> >::iterator it=m.begin();it!=m.end();++it)
        printf("%d, %d\n",it->first,it->second);
    printf("===\n");
}
int main()
{
    int n=10;
    m.clear();
    vector<int> ans;
    ans.clear();
    m.insert(make_pair(log(n)/log(1.46557123187677d),-1));
    m.insert(make_pair(0,n));
    ans.push_back(2);
    while (m.size()>1 || m.size()==1 && m.begin()->second!=1)
    {
        map<int,int,greater<int> >::iterator ii=m.begin();
        PP head=make_pair(ii->first,ii->second);
        if (head.first+3<=ans[ans.size()-1] && head.second==1 &&
            sum()-pow(1.46557123187677d,head.first)*head.second>0 && !all_positive())
        {
            ans.push_back(head.first);
            m.erase(m.begin());
        }
        else
        {
            if (all_positive())
            {
                m.erase(m.begin());
                add(head.first+1,head.second);
                add(head.first-2,-head.second);
            }
            else
            {
                m.erase(m.begin());
                add(head.first-1,head.second);
                add(head.first-3,head.second);
            }
        }
        dump();
    }
    ans.push_back(m.begin()->first);
    for (int i=0;i<ans.size();++i)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int a[300];
int main()
{
    //freopen("test.txt","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int testcase;
    cin>>testcase;
    for (int ii=1;ii<=testcase;++ii)
    {
        string inp;
        cin>>inp;
        memset(a,0,sizeof(a));
        for (int i=0;i<inp.length();++i)
            a[inp[i]]++;
        int b[10];
        b[0]=a['Z'];
        b[2]=a['W'];
        b[4]=a['U'];
        b[6]=a['X'];
        b[8]=a['G'];
        a['Z']-=b[0];a['E']-=b[0];a['R']-=b[0];a['O']-=b[0];
        a['T']-=b[2];a['W']-=b[2];a['O']-=b[2];
        a['F']-=b[4];a['O']-=b[4];a['U']-=b[4];a['R']-=b[4];
        a['S']-=b[6];a['I']-=b[6];a['X']-=b[6];
        a['E']-=b[8];a['I']-=b[8];a['G']-=b[8];a['H']-=b[8];a['T']-=b[8];
        b[3]=a['R'];
        b[5]=a['F'];
        b[7]=a['S'];
        a['T']-=b[3];a['H']-=b[3];a['R']-=b[3];a['E']-=b[3];a['E']-=b[3];
        a['F']-=b[5];a['I']-=b[5];a['V']-=b[5];a['E']-=b[5];
        a['S']-=b[7];a['E']-=b[7];a['V']-=b[7];a['E']-=b[7];a['N']-=b[7];
        b[1]=a['O'];
        b[9]=a['I'];
        printf("Case #%d: ",ii);
        for (int i=0;i<=9;++i)
            for (int j=1;j<=b[i];++j)
                printf("%d",i);
        if (ii<testcase) printf("\n");
    }
    return 0;
}
