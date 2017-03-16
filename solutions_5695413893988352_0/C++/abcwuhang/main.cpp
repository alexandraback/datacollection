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
long long comb(string x,int from,int to,int fill_in)
{
    long long ret=0,base=1;
    for (int i=to;i>=from;--i)
    {
        if (x[i]!='?') ret+=(x[i]-'0')*base;
        else ret+=fill_in*base;
        base*=10;
    }
    return ret;
}
void sync(string &x,string &y,int idx,int bbb)
{
    for (int j=idx;j<x.length();++j)
        if (j<bbb)
        {
            if (x[j]=='?' && y[j]!='?') x[j]=y[j];
            else if (x[j]!='?' && y[j]=='?') y[j]=x[j];
            else if (x[j]=='?' && y[j]=='?') x[j]=y[j]='0';
        }
        else
        {
            if (x[j]=='?' && y[j]=='?') x[j]=y[j]='0';
        }
}
int main()
{
    //freopen("test.txt","r",stdin);
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int testcase;
    cin>>testcase;
    for (int ii=1;ii<=testcase;++ii)
    {
        string code,jam;
        cin>>code>>jam;
        bool flag=false;
        char code_fill,jam_fill;
        for (int i=0;i<code.length();++i)
            if (!flag && code[i]==jam[i])
            {
                if (code[i]=='?') code[i]=jam[i]='0';
            }
            else if (!flag && code[i]=='?')
            {
                int det=0,id;
                for (int j=i+1;j<code.length();++j)
                    if (code[j]!='?' && jam[j]!='?' && code[j]!=jam[j])
                    {
                        det=code[j]-jam[j];
                        id=j;
                        break;
                    }
                if (!det)
                {
                    code[i]=jam[i];
                }
                else
                {
                    if (det>0)
                    {
                        // code[i] can be filled with jam[i] or max(0,jam[i]-1)
                        string code_cpy=string(code),jam_cpy=string(jam);
                        sync(code_cpy,jam_cpy,i+1,id);
                        code_cpy[i]=jam[i];
                        long long first=comb(code_cpy,i,code_cpy.length()-1,0)-comb(jam_cpy,i,jam_cpy.length()-1,9);
                        if (jam[i]>='1')
                        {
                            code_cpy[i]=jam[i]-1;
                            long long second=comb(code_cpy,i,code_cpy.length()-1,9)-comb(jam_cpy,i,jam_cpy.length()-1,0);
                            if (abs(first)<=abs(second))
                            {
                                flag=true;
                                code_cpy[i]=jam[i];
                                for (int j=i;j<id;++j)
                                {
                                    code[j]=code_cpy[j];
                                    jam[j]=jam_cpy[j];
                                }
                                i=id;
                                code_fill='0';
                                jam_fill='9';
                            }
                            else
                            {
                                flag=true;
                                for (int j=i;j<id;++j)
                                {
                                    code[j]=code_cpy[j];
                                    jam[j]=jam_cpy[j];
                                i=id;
                                }
                                code_fill='9';
                                jam_fill='0';
                            }
                        }
                        else
                        {
                            code[i]=jam[i];
                        }
                    }
                    else
                    {
                        // code[i] can be filled with jam[i] or min(9,jam[i]+1)
                        string code_cpy=string(code),jam_cpy=string(jam);
                        sync(code_cpy,jam_cpy,i+1,id);
                        code_cpy[i]=jam[i];
                        long long first=comb(code_cpy,i,code_cpy.length()-1,9)-comb(jam_cpy,i,jam_cpy.length()-1,0);
                        if (jam[i]<='8')
                        {
                            code_cpy[i]=jam[i]+1;
                            long long second=comb(code_cpy,i,code_cpy.length()-1,0)-comb(jam_cpy,i,jam_cpy.length()-1,9);
                            if (abs(first)<=abs(second))
                            {
                                flag=true;
                                code_cpy[i]=jam[i];
                                for (int j=i;j<id;++j)
                                {
                                    code[j]=code_cpy[j];
                                    jam[j]=jam_cpy[j];
                                }
                                i=id;
                                code_fill='9';
                                jam_fill='0';
                            }
                            else
                            {
                                flag=true;
                                for (int j=i;j<id;++j)
                                {
                                    code[j]=code_cpy[j];
                                    jam[j]=jam_cpy[j];
                                }
                                i=id;
                                code_fill='0';
                                jam_fill='9';
                            }
                        }
                        else
                        {
                            code[i]=jam[i];
                        }
                    }
                }
            }
            else if (!flag && jam[i]=='?')
            {
                int det=0,id;
                for (int j=i+1;j<code.length();++j)
                    if (code[j]!='?' && jam[j]!='?' && code[j]!=jam[j])
                    {
                        det=code[j]-jam[j];
                        id=j;
                        break;
                    }
                if (!det)
                {
                    jam[i]=code[i];
                }
                else
                {
                    if (det<0)
                    {
                        // jam[i] can be filled with code[i] or max(0,code[i]-1)
                        string code_cpy=string(code),jam_cpy=string(jam);
                        sync(code_cpy,jam_cpy,i+1,id);
                        jam_cpy[i]=code[i];
                        long long first=comb(code_cpy,i,code_cpy.length()-1,9)-comb(jam_cpy,i,jam_cpy.length()-1,0);
                        if (code[i]>='1')
                        {
                            jam_cpy[i]=code[i]-1;
                            long long second=comb(code_cpy,i,code_cpy.length()-1,0)-comb(jam_cpy,i,jam_cpy.length()-1,9);
                            if (abs(first)<=abs(second))
                            {
                                flag=true;
                                jam_cpy[i]=code[i];
                                for (int j=i;j<id;++j)
                                {
                                    code[j]=code_cpy[j];
                                    jam[j]=jam_cpy[j];
                                }
                                i=id;
                                code_fill='9';
                                jam_fill='0';
                            }
                            else
                            {
                                flag=true;
                                for (int j=i;j<id;++j)
                                {
                                    code[j]=code_cpy[j];
                                    jam[j]=jam_cpy[j];
                                }
                                i=id;
                                code_fill='0';
                                jam_fill='9';
                            }
                        }
                        else
                        {
                            jam[i]=code[i];
                        }
                    }
                    else
                    {
                        // code[i] can be filled with jam[i] or min(9,jam[i]+1)
                        string code_cpy=string(code),jam_cpy=string(jam);
                        sync(code_cpy,jam_cpy,i+1,id);
                        jam_cpy[i]=code[i];
                        long long first=comb(code_cpy,i,code_cpy.length()-1,0)-comb(jam_cpy,i,jam_cpy.length()-1,9);
                        if (jam[i]<='8')
                        {
                            jam_cpy[i]=code[i]+1;
                            long long second=comb(code_cpy,i,code_cpy.length()-1,9)-comb(jam_cpy,i,jam_cpy.length()-1,0);
                            if (abs(first)<=abs(second))
                            {
                                flag=true;
                                jam_cpy[i]=code[i];
                                for (int j=i;j<id;++j)
                                {
                                    code[j]=code_cpy[j];
                                    jam[j]=jam_cpy[j];
                                }
                                i=id;
                                code_fill='0';
                                jam_fill='9';
                            }
                            else
                            {
                                flag=true;
                                for (int j=i;j<id;++j)
                                {
                                    code[j]=code_cpy[j];
                                    jam[j]=jam_cpy[j];
                                }
                                i=id;
                                code_fill='9';
                                jam_fill='0';
                            }
                        }
                        else
                        {
                            jam[i]=code[i];
                        }
                    }
                }
            }
            else if (!flag)
            {
                flag=true;
                if (code[i]<jam[i])
                {
                    code_fill='9';
                    jam_fill='0';
                }
                else
                {
                    code_fill='0';
                    jam_fill='9';
                }
            }
            else
            {
                if (code[i]=='?') code[i]=code_fill;
                if (jam[i]=='?') jam[i]=jam_fill;
            }
        printf("Case #%d: ",ii);
        cout<<code<<" "<<jam;
        if (ii<testcase) printf("\n");
    }
    return 0;
}
