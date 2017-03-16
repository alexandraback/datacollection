#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T,cased=0;
    int N;
//    freopen("a.txt","r",stdin);
//    freopen("b.txt","w",stdout);
    string s1,s2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        map<string,int> mp1,mp2;
        int ans=0;
        for(int i=0;i<N;i++)
        {
            cin>>s1>>s2;
            mp1[s1]++;
            mp2[s2]++;
        }
        vector<int>f,s;
        for(map<string,int>::iterator it=mp1.begin();it!=mp1.end();it++){
            f.push_back(it->second);
        }
        for(map<string,int>::iterator it=mp2.begin();it!=mp2.end();it++){
            s.push_back(it->second);
        }
        sort(f.rbegin(),f.rend());
        sort(s.rbegin(),s.rend());
        for(int i=0;i<min(f.size(),s.size());i++)
            ans+=min(f[i],s[i])-1;
        printf("Case #%d: %d\n",++cased,ans);
    }
    return 0;
}

