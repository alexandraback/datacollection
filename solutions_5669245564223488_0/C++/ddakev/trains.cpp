#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<fstream>
using namespace std;
long long t,used[26],n,lts[26],ansa[26];
queue<int> q;
string s[101];
vector<long long> z[101];
long long fact(int n)
{
    int ans=1;
    for(int j=2; j<=n; j++)
    {
        ans=(ans*j)%1000000007;
    }
    return ans;
}
bool dfs(int s, int f, int p)
{
    int m=z[s].size();
    for(int i=0; i<=m-1; i++)
    {
        if(z[s][i]==p) continue;
        if(z[s][i]==f) return true;
        return dfs(z[s][i],f,s);
    }
    return false;
}
long long bfs(int l)
{
    long long ans=1;
    q.push(l);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        used[x]=1;
        int same=0;
        int start=0;
        int fin=0;
        int f=0;
        int g=0;
        for(int i=1; i<=n; i++)
        {
            int e=0;
            for(int j=0; j<=s[i].size()-1; j++)
            {
                if(s[i][j]-'a'!=x) {e=1; break;}
            }
            if(e==0) {g=1; same++; continue;}
            int p1=0;
            int p2=s[i].size()-1;
            if(s[i][0]-'a'==x&&s[i][s[i].size()-1]-'a'==x) return 0;
            if(s[i][0]-'a'==x)
            {
                if(f!=0) return 0;
                if(start!=0) return 0;
                start=i;
                g=1;
            }
            else if(s[i][s[i].size()-1]-'a'==x)
            {
                if(f!=0) return 0;
                if(fin!=0) return 0;
                fin=i;
                g=1;
            }
            if(s[i][0]-'a'==x)
                for(int j=1; j<=s[i].size()-1; j++)
                    if(s[i][j]-'a'!=x)
                        p1=j;
            if(s[i][s[i].size()-1]-'a'==x)
                for(int j=s[i].size()-2; j>=0; j--)
                    if(s[i][j]-'a'!=x)
                        p2=j;
            for(int j=p1; j<=p2; j++)
                if(s[i][j]-'a'==x)
                {
                    if(g==1) return 0;
                    else if(f==0) {f=i; break;}
                    else return 0;
                }
        }
        ans=(ans*fact(same))%1000000007;
        //cout<<x<<" "<<f<<" "<<fin<<" "<<start<<" "<<same<<" "<<ans<<endl;
        if(f!=0)
        {
            for(int j=0; j<=s[f].size()-1; j++)
                if(used[s[f][j]-'a']==0)
                    q.push(s[f][j]-'a');
        }
        else
        {
            if(fin!=0&&start!=0)
            {
                if(dfs(start,fin,0)==true) return 0;
                else z[fin].push_back(start);
            }
            if(start!=0&&used[s[start][s[start].size()-1]-'a']==0)
                q.push(s[start][s[start].size()-1]-'a');
            if(fin!=0&&used[s[fin][0]-'a']==0)
                q.push(s[fin][0]-'a');
        }
    }
    return ans;
}
int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("B-small-attempt6.in");
	cout.open("output.txt");
	cin>>t;
	for(int o=1; o<=t; o++)
	{
		cout<<"Case #"<<o<<": ";
		cin>>n;
		int br=0;
		for(int i=0; i<=25; i++)
        {
            lts[i]=0;
            used[i]=0;
            ansa[i]=0;
        }
		for(int i=1; i<=n; i++)
        {
            cin>>s[i];
            for(int j=0; j<=s[i].size()-1; j++)
            {
                lts[s[i][j]-'a']=1;
            }
        }
		for(int i=0; i<=25; i++)
        {
            if(used[i]==0&&lts[i]==1)
            {
                ansa[br]=bfs(i);
                br++;
                if(ansa[br-1]==0) break;
            }
        }
        long long ans=1;
        for(int i=0; i<=br-1; i++)
        {
            ans=(ans*ansa[i])%1000000007;
        }
        for(int i=1; i<=br; i++)
        {
            ans=(ans*i)%1000000007;
        }
        cout<<ans<<endl;
        for(int i=1; i<=n; i++)
            z[i].clear();
	}
	cin.close();
	cout.close();
	return 0;
}
