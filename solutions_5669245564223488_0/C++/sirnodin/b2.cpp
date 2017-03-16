/*=============================================================================
#     FileName: b2.cpp
#         Desc: 
#       Author: zhangc
#        Email: sirnodin@gmail.com
#     HomePage: 
#      Version: 0.0.1
#     CreateOn: 2014-05-11 17:56:08
#   LastChange: 2014-05-11 19:24:18
#      History:
=============================================================================*/
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;
size_t TEST_CASES;
struct Cars
{
    char head;
    char tail;
    set<char> all_c;
    bool getCars(string str){
        all_c.clear();
        char last_c=' ';
        head=str.front();
        tail=str.back();
        for(size_t i=0;i<str.size();++i){
            if(i>0 && last_c!=str[i] && all_c.count(str[i])>0) return false;
            else 
            {
                all_c.insert(str[i]);
                last_c=str[i];
            }
        }
        return true;
    }
};
int N;
Cars all_cars[110];
int heads_tails[30];
int valid_cars_N;
bool OK;
const long long MODEL=1000000007L;
long long ans=0;
int main()
{
    cin>>TEST_CASES;
    for(size_t CASE=0;CASE<TEST_CASES;++CASE)
    {
        cin>>N;
        string inp;
        OK=true;
        for(int i=0;i<N;++i)
        {
            cin>>inp;
            if(!all_cars[i].getCars(inp)) OK=false;
        }
        if(OK){
            for(int i=0;i<N;++i)
            {
                for(auto & ccc:all_cars[i].all_c)
                {
                    for(int j=0;j<N;++j)
                    {
                        if(i!=j)
                        {
                            if(all_cars[j].all_c.count(ccc)>0)
                            {
                                if(ccc==all_cars[i].head && ccc==all_cars[j].tail) continue;
                                if(ccc==all_cars[j].head && ccc==all_cars[i].tail) continue;
                                ans=0;
                                goto fin;
                            }
                        }
                    }
                }
            }
            ans=1;
            for(int i=0;i<30;++i)
            {
                heads_tails[i]=-1;
            }
            int same_num[30];
            for(int i=0;i<30;++i) same_num[i]=0;
            for(int i=0;i<N;++i)
            {
                if(all_cars[i].head==all_cars[i].tail)
                {
                    same_num[all_cars[i].head-'a']++;
                }
            }
            for(int i=0;i<30;++i)
            {
                if(same_num[i]>=1)
                {
                    for(int j=1;j<=same_num[i];++j)
                    {
                        ans%=MODEL;
                        ans*=j;
                    }
                }
            }
            for(int i=0;i<N;++i)
            {
                char head=all_cars[i].head;
                int head_ind=head-'a';
                int tail_ind=all_cars[i].tail-'a';
                if(heads_tails[head_ind]==-1)
                {
                    heads_tails[head_ind]=tail_ind;
                }
                else
                {
                    if(heads_tails[head_ind]==head_ind)
                    {
                        //if(head==all_cars[i].tail) same_num[i]++;
                        heads_tails[head_ind]=tail_ind;
                    }
                    else
                    {
                        ans=0;
                        goto fin;
                    }
                }
            }
            for(int i=0;i<30;++i)
            {
                if(heads_tails[i]!=-1)
                {
                    int tail_ind=heads_tails[i];
                    if(tail_ind==i) continue;

                    int head_ind=i;
                    set<int> has_set;
                    has_set.insert(head_ind);
                    has_set.insert(tail_ind);
                    while(tail_ind!=-1)
                    {
                        heads_tails[head_ind]=heads_tails[tail_ind];
                        if(tail_ind==heads_tails[tail_ind])
                        {
                            heads_tails[tail_ind]=-1;
                            break;
                        }
                        else if(has_set.count(heads_tails[tail_ind]))
                        {
                            ans=0;
                            goto fin;
                        }
                        else
                        {
                            int temp=heads_tails[tail_ind];
                            heads_tails[tail_ind]=-1;
                            tail_ind=temp;
                            has_set.insert(tail_ind);
                        }
                    }
                }
            }
            int type_n=0;
            for(int i=0;i<30;++i)
            {
                if(heads_tails[i]!=-1) type_n++;
            }
            for(int i=1;i<=type_n;++i)
            {
                ans%=MODEL;
                ans*=i;
            }
            ans%=MODEL;
        }
        else ans=0;
fin:
        printf("Case #%ld: %lld\n",CASE+1,ans);
    }
    return 0;
}
