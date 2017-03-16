#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define ran 1111111

int T,k,len;
char s[ran];
int f[ran];
vector<int>seg,cato;

long long ans;

bool vowel(char ch){
	if(ch=='a')return true;
	if(ch=='e')return true;
	if(ch=='i')return true;
	if(ch=='o')return true;
	if(ch=='u')return true;
	return false;
}

long long calc0(int len){
	return 1LL*len*(len+1)/2;
}
long long calc1(int len){
	long long rem=len-(k-1);
	return rem*(k-1)+1LL*k*(k-1)/2;
	//k-1 k-1 k-2... 4 3 2 1
}
long long calc01(int len0,int len1){
	long long choice_1=k-1;
	long long res=choice_1*len0;
	return res;
}
long long calc10(int len1,int len0){
	return 1LL*(k-1)*len0;
}
long long calc101(int len1,int len0,int len2){
	return 1LL*(k-1)*(k-1);
}

int main(){
	scanf("%d",&T);
	for(int _=1;_<=T;_++){
		scanf("%s%d",s,&k);
		
		len=strlen(s);
		for(int i=0;i<len;i++)
			f[i]=!vowel(s[i]);
		f[len]=-1;
		
		seg.clear();cato.clear();
		int cnt=1,last=f[0];
		for(int i=1;i<=len;i++){
			if(f[i]==last)cnt++;
			else {
				seg.push_back(cnt);
				cato.push_back(last);
				cnt=1;
			}
			last=f[i];
		}
		for(int i=0;i<seg.size();i++)
			if(seg[i]<k)cato[i]=0;
		int sz=0;
		for(int i=1;i<seg.size();i++)
			if(cato[i]==cato[sz]){
				seg[sz]+=seg[i];
			}else{
				sz++;
				seg[sz]=seg[i];
				cato[sz]=cato[i];
			}
		seg.resize(sz+1);
		cato.resize(sz+1);
		
		ans=len;
		ans*=len+1;
		ans/=2;
		for(int i=0;i<seg.size();i++)
			if(cato[i]==0)
				ans-=calc0(seg[i]);
			else if(cato[i]==1)
				ans-=calc1(seg[i]);
		for(int i=0;i<(int)seg.size()-1;i++)
			if(cato[i]==0)
				ans-=calc01(seg[i],seg[i+1]);
			else ans-=calc10(seg[i],seg[i+1]);
		for(int i=0;i<(int)seg.size()-2;i++)
			if(cato[i]==1)
				ans-=calc101(seg[i],seg[i+1],seg[i+2]);
		printf("Case #%d: %I64d\n",_,ans);
	}

	return 0;
}