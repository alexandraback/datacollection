#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

char s[1000001];
int c[1000001];
class Record
{
public:
    int start,end;
};
vector<Record> v;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A_output_large.txt","w",stdout);
    int T,N;
    scanf("%d",&T);
    Record rec;
    for (int cases=1;cases<=T;cases++)
    {
        scanf("%s",s);
        scanf("%d",&N);
        int L=strlen(s);
        c[0]=0;
        v.clear();
        int start=-1;
        int end=-1;
        for (int i=1;i<=L;i++)
        {
                if (s[i-1]=='a' || s[i-1]=='e'
                   || s[i-1]=='i' || s[i-1]=='o' || s[i-1]=='u')
                {
                    c[i]=0;
                    if (start>=0 && c[i-1]>=N)
                    {
                        rec.start=start;
                        rec.end=end;
                        v.push_back(rec);
                    }
                    start=end=-1;
                }else{
                    c[i]=c[i-1]+1;
                    if (start<0) start=i;
                    end=i;
                }
        }
        if (start>=0 && c[L]>=N)
        {
            rec.start=start;
            rec.end=L;
            v.push_back(rec);
        }
        /*for (int j=0;j<v.size();j++)
        {
            printf("start=%d end=%d\n",v[j].start,v[j].end);
        }*/
        __int64 result=0;
        for (int i=1;i<=L;i++)
        {
            int index=-1;
            for (int j=0;j<v.size();j++)
            {
                if (v[j].end<i || v[j].end-i+1<N) continue;
                index=j;
                break;
            }
            if (index>=0)
            {
                int pos=max(i,v[index].start)+N-1;
                //printf("i=%d pos=%d\n",i,pos);
                if (pos>0) result+=(__int64)(L-pos+1);
            }
        }
        printf("Case #%d: %I64d\n",cases,result);
    }
    return 0;
}
