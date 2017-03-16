#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

vector<string> candi;

int cmp(string x,string y){
	if(x.length()<y.length())return -1;
	if(x.length()>y.length())return 1;
	if(x<y)return -1;
	if(x>y)return 1;
	return 0;
}

void doit(vector<int> tmp){
	int d=tmp.size();
	string s(2*d-1,'0');
	for(int i=0;i<d;i++)for(int j=0;j<d;j++){
		s[i+j]+=tmp[i]*tmp[j];
		if(s[i+j]>'9')return;
	}
	candi.push_back(s);
}

main(){
	for(int d=1;d<=50;d++){
		if(d==1){
			doit(vector<int>(1,1));
			doit(vector<int>(1,2));
			doit(vector<int>(1,3));
		}else{
			//2...2
			vector<int> s(d);
			s[0]=s[d-1]=2;doit(s);
			if(d%2==1){s[(d-1)/2]=1;doit(s);}
			
			
			vector<int> tmp(d);
			int n=d/2;
			if(d%2==0){
				for(int b=1;b<(1<<n);b+=2){
					if(__builtin_popcount(b)>=5)continue;
					for(int i=0;i<n;i++)tmp[d-1-i]=tmp[i]=((b>>i)&1);
					doit(tmp);
				}
			}else{
				for(int c=0;c<=2;c++){
					tmp[n]=c;
					for(int b=1;b<(1<<n);b+=2){
						if(__builtin_popcount(b)>=5)continue;
						for(int i=0;i<n;i++)tmp[d-1-i]=tmp[i]=((b>>i)&1);
						doit(tmp);
					}
				}
			}
		}
	}
	//for(int i=0;i<candi.size();i++)printf("%s\n",candi[i].c_str());
	int testcase;
	scanf("%d ",&testcase);
	for(int casenum=1;casenum<=testcase;casenum++){
		string A,B;
		cin >> A >> B;
		int cnt=0;
		for(int i=0;i<candi.size();i++)if(cmp(A,candi[i])<=0 && cmp(candi[i],B)<=0){cnt++;}//printf("%s\n",candi[i].c_str());}
		printf("Case #%d: %d\n",casenum,cnt);
		if(casenum%100==0)fprintf(stderr,"#%d done\n",casenum);
	}
}