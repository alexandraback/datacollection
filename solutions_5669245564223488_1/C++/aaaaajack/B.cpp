#include<cstdio>
#include<string>
#include<vector>
#include<list>
#include<iostream>
#include<algorithm>
#define Q 1000000007
using namespace std;
struct train{
	string s;
	int num;
	train(){}
	train(const string& _s,int _num):s(_s),num(_num){}
};
int main(){
	int t,c,i,n,j,fcnt,ccnt,k;
	long long ans;
	bool flag,st,ed;
	string s_in;
	char now;
	vector<train> l,temp,deal;
	vector<int> dcnt;
	train merge;
	scanf("%d",&t);
	for(c=1;c<=t;c++){
		scanf("%d",&n);
		l.clear();
		flag=true;
		for(i=0;i<n;i++){
			cin>>s_in;
			s_in.resize(unique(s_in.begin(),s_in.end())-s_in.begin());
			//cout<<s_in<<endl;
			l.push_back(train(s_in,1));
		}
		for(k=0;k<26;k++){
			now='a'+k;
			//printf("%c\n",now);
			//for(i=0;i<l.size();i++) cout<<l[i].s<<endl;
			temp.clear();
			deal.clear();
			dcnt.clear();
			fcnt=0;
			merge=train("",1);
			for(i=0;i<l.size();i++){
				ccnt=0;
				for(j=0;j<l[i].s.size();j++){
					if(l[i].s[j]==now){
						ccnt++;
					}
				}
				if(ccnt==0) temp.push_back(l[i]);
				else if(ccnt==1){
					deal.push_back(l[i]);
					dcnt.push_back(ccnt);
				}
				else{
					flag=false;
					break;
				}
			}
			if(!flag) break;
			if(deal.size()<=1) continue;
			else{
				//printf("%d\n",deal.size());
				st=ed=true;
				for(i=0;i<deal.size();i++){
					if(deal[i].s.size()==1) fcnt++;
					else if(deal[i].s[0]==now&&ed){
						merge.s+=deal[i].s;
						merge.num=1LL*merge.num*deal[i].num%Q;
						ed=false;
					}
					else if(*(--deal[i].s.end())==now&&st){
						merge.s=deal[i].s+merge.s;
						merge.num=1LL*merge.num*deal[i].num%Q;
						st=false;
					}
					else{
						flag=false;
						break;
					}
				}
				if(!flag) break;
				for(i=1;i<=fcnt;i++){
					merge.num=1LL*merge.num*i%Q;
				}
				if(merge.s.size()==0) merge.s.push_back(now);
				merge.s.resize(unique(merge.s.begin(),merge.s.end())-merge.s.begin());
				//cout<<merge.s<<endl;
				temp.push_back(merge);
				l=temp;
			}
		}
		ans=1;			
		for(i=0;i<l.size();i++){
			//cout<<l[i].s<<endl;
			ans*=l[i].num;
			ans%=Q;
			ans*=(i+1);
			ans%=Q;
		}
		if(flag) printf("Case #%d: %lld\n",c,ans);
		else printf("Case #%d: 0\n",c);
	}
	return 0;
}