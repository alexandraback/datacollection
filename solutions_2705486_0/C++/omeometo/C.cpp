#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define INF 1010101010

main(){
	vector<string> words;
	
	FILE *fp=fopen("dictionary.txt","r");
	
	for(int cnt=0;;cnt++){
		char buf[300];
		if(fgets(buf,300,fp)==NULL)break;
		while(buf[strlen(buf)-1]<32)buf[strlen(buf)-1]=0;
		words.push_back(string(buf));
	}
	fclose(fp);
	

	int testcase;
	scanf("%d ",&testcase);
	for(int casenum=1;casenum<=testcase;casenum++){
		printf("Case #%d: ",casenum);
		char buf[6000];
		gets(buf);
		int l=strlen(buf);
		
		vector<pair<int,pair<pair<int,int>,int> > > edg[6000];
		for(int t=0;t<l;t++){
			for(int i=0;i<words.size();i++){
				string s=words[i];
				int ls=s.length();
				if(ls>l-t)continue;
				int mindiff=INF;
				int maxdiff=-INF;
				int prevdiff=-INF;
				int cntdiff=0;
				bool ok=true;
				for(int j=0;j<ls;j++){
					if(s[j]!=buf[t+j]){
						if(j-prevdiff<5){ok=false;break;}
						prevdiff=j;
						mindiff=min(mindiff,j);
						maxdiff=max(maxdiff,j);
						cntdiff++;
					}
				}
				if(ok)edg[t].push_back(make_pair(ls,make_pair(make_pair(mindiff,maxdiff),cntdiff)));
			}
		}
		
		int dp[6000][5];
		for(int t=0;t<=l;t++)for(int d=0;d<=4;d++)dp[t][d]=INF;
		dp[0][4]=0;
		for(int t=0;t<l;t++){
			if(t%100==0)fprintf(stderr,"dp %d...\n",t);
			for(int d=0;d<=4;d++){
				for(int p=0;p<edg[t].size();p++){
					int ls=edg[t][p].first;
					int c=edg[t][p].second.second;
					int mindiff=edg[t][p].second.first.first;
					int maxdiff=edg[t][p].second.first.second;
					if(mindiff-(-1-d)<5)continue;
					int nt=t+ls;
					int nd=min(4,min(d+ls,ls-1-maxdiff));
					dp[nt][nd]=min(dp[nt][nd],dp[t][d]+c);
				}
			}
		}
		
		int ans=INF;
		for(int d=0;d<=4;d++)ans=min(ans,dp[l][d]);
		printf("%d\n",ans);
		/*
		for(int t=0;t<=l;t++){
			for(int d=0;d<=4;d++)printf("%d ",dp[t][d]);
			puts("");
		}
		*/
	}
}