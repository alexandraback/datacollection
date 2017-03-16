#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1005;

struct node
{
    int x,c;
    node(int a,int b):x(a),c(b){}
};

vector<node> v;
char s[maxn];

int l;
int main()
{
    int t,cs=0;scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d%s",&l,s);
        for(int i=0;i<=l;i++)
            if(s[i]!='0')
                v.push_back(node(i,s[i]-'0'));
        int r = 0,sum=0;
        for(int i=0;i<v.size();i++)
        {
            if(sum<v[i].x)
            {
                r = max(r,v[i].x-sum);
            }
            sum += v[i].c;
        }
        printf("Case #%d: %d\n",++cs,r);
    }
}
