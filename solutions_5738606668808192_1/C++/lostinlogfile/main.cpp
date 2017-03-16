#include <iostream>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <vector>

using namespace std;
const int N=32;
__int128_t interpretate(const std::bitset<N>& value,__int128_t pow)
{
    __int128_t ret=0;
    __int128_t cp=1;
    //cout<<value<<" as "<<(unsigned long long)pow<<" base is ";
    for(long i=0;i<N;i++,cp=cp*pow)
        if(value.test(i))
        ret+=cp;
   //cout<<(unsigned long long)ret<<endl;
    return ret;
}
int get_devisor(__int128_t for_w)
{
    for(int i=2;i<1000;i++)
        if(for_w%i==0)
            return i;
    return 0;
}
int main()
{
    //cout<<sizeof(__int128_t)<<endl;
    freopen("out.txt","w+",stdout);
    int e_count=0;
    unsigned int try_it=0;
    std::bitset<N> bit;
    cout<<"Case #1:\n";
    while(e_count<500)
    {
tourist_is_dick:
        try_it++;
        unsigned int val=(try_it<<1)+1;
        val=val|(1<<(N-1));
        bit=std::bitset<N>(val);
        vector<int> answer;
        answer.clear();

        for(int p=2;p<=10;p++)
        {
            int v=get_devisor(interpretate(bit,p));
            if(v==0)
                goto tourist_is_dick;
            answer.push_back(v);
        }
        cout<<bit;
        for(int p=2;p<=10;p++)
        {
            cout<<" "<<answer[p-2];
        }
        cout<<endl;
        e_count++;

    }
    return 0;
}
