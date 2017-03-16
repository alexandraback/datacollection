/*
name:Rollchuchy
type:
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int INF=1e9;
const int maxn=1000+7;
map<char,int> GG;
int n,m,t,ans;
string s;
int GGG[10];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for (int GGGG = 1; GGGG<=t; GGGG += 1)
	{
		printf("Case #%d: ",GGGG);
		GG.clear();
		cin>>s;
		for (int i = 0; i < s.length(); i += 1)
		{
			GG[s[i]]++;
		}
		GGG[0]=GG['Z'];
		GG['Z']-=GGG[0];
		GG['E']-=GGG[0];
		GG['R']-=GGG[0];
		GG['O']-=GGG[0];
		GGG[6]=GG['X'];
		GG['X']-=GGG[6];
		GG['S']-=GGG[6];
		GG['I']-=GGG[6];
		GGG[7]=GG['S'];
		GG['S']-=GGG[7];
		GG['E']-=GGG[7]*2;
		GG['V']-=GGG[7];
		GG['N']-=GGG[7];
		GGG[2]=GG['W'];
		GG['T']-=GGG[2];
		GG['W']-=GGG[2];
		GG['O']-=GGG[2];
		GGG[4]=GG['U'];
		GG['F']-=GGG[4];
		GG['O']-=GGG[4];
		GG['U']-=GGG[4];
		GG['R']-=GGG[4];
		GGG[1]=GG['O'];
		GG['O']-=GGG[1];
		GG['N']-=GGG[1];
		GG['E']-=GGG[1];
		GGG[9]=GG['N']/2;
		GG['N']-=GGG[9]*2;
		GG['I']-=GGG[9];
		GG['E']-=GGG[9];
		GGG[5]=GG['V'];
		GG['F']-=GGG[5];
		GG['I']-=GGG[5];
		GG['V']-=GGG[5];
		GG['E']-=GGG[5];
		GGG[8]=GG['G'];
		GG['E']-=GGG[8];
		GG['I']-=GGG[8];
		GG['G']-=GGG[8];
		GG['H']-=GGG[8];
		GG['T']-=GGG[8];
		GGG[3]=GG['T'];
		for (int i = 0; i < 10; i += 1)
		{
			if(GGG[i]!=0){
				while (GGG[i]--)
				{
					cout<<i;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}

