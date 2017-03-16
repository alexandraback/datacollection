#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;
int t,n,m,a,b;
const int INF=1<<29;
char s[500];
queue<pair<int,int> > kju;
vector<vector<int>  >ve;
vector<string> code;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int CASE=1;CASE<=t;CASE++)
    {
        scanf("%d %d ",&n,&m);
        ve.clear();
        ve.resize(n);
        code.resize(n);
        for(int i=0;i<n;i++)
        {
            scanf(" %s",s);
            code[i]=s;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            ve[a-1].pb(b-1);
            ve[b-1].pb(a-1);
        }
        vector<int> st;
        st.clear();
        for(int i=0;i<n;i++)
            st.pb(i);
        vector<int> moze(n);
        string minio;
        stack<int> stek;
        vector<vector<int> > ke;
        for(int i=0;i<n*5+1;i++)minio+='9';
        do
        {
//            moze.assign(n,INF);
//            while (!kju.empty())kju.pop();kju.push(mp(st[0],0));moze[st[0]]=0;
            ke.clear();ke.resize(n);
            while (!stek.empty())stek.pop();
            stek.push(st[0]);
            for(int i=0;i<ve[st[0]].size();i++)ke[ve[st[0]][i]].pb(st[0]);
            bool da=1;
            for(int i=1;i<n;i++)
            {
                while(!stek.empty())
                {
                        bool ok=0;
                        for(int j=0;j<ke[st[i]].size();j++)if(ke[st[i]][j]==stek.top())ok=1;
                        if(ok)break;else stek.pop();
                }
                if(stek.empty()){da=0;break;}
                stek.push(st[i]);
                for(int j=0;j<ve[st[i]].size();j++)ke[ve[st[i]][j]].pb(st[i]);
            }
//            pair<int,int> tmp;
//            while(!kju.empty())
//            {
//                tmp=kju.front();kju.pop();
//                for(int i=0;i<ve[tmp.xx].size();i++)
//                {
//                    if(moze[ve[tmp.xx][i]]==INF)
//                    {
//                        kju.push(mp(ve[tmp.xx][i],tmp.yy+1));
//                        moze[ve[tmp.xx][i]]=tmp.yy+1;
//                    }
//                }
//            }
//            int da=1;
//            for(int i=0;i<n;i++)da*=(moze[st[i]]<=i);
//            for(int i=0;i<n;i++)
//            {
//                printf("CVOR: (%d,%d) MOZE %d\n",i,st[i],moze[st[i]]);
//            }puts("");
            if(da)
            {
                string cont="";
                for(int i=0;i<n;i++)cont+=code[st[i]];
                minio=min(minio,cont);
            }
        }while(next_permutation(st.begin(),st.end()));
        printf("Case #%d: %s\n",CASE,minio.c_str());
    }
    return 0;
}
