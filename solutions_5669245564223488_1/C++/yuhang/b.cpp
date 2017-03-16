#include<iostream>
#include<cstring>
using namespace std;

const long long m=1000000007;

int main(){
	int t;
	cin>>t;
	int perm[101];
	perm[0]=1;
	for(int i=1;i<=100;i++)
		perm[i]=(perm[i-1]*(long long)i) % m;
	for(int i=1;i<=t;i++){
		int n;
		int l[100],r[100];
		int start[26],end[26],midcount[26];
		bool inner[26];
		bool v[26];
		memset(l,255,sizeof l);
		memset(r,255,sizeof r);
		memset(start,255,sizeof start);
		memset(end,255,sizeof end);
		memset(midcount,0,sizeof midcount);
		memset(inner,0,sizeof inner);
		memset(v,0,sizeof v);
		
		bool bad=false;
		cin>>n;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			bool first=true;
			for(int j=1;j<s.length();j++)
				if(s[j]!=s[j-1])
					if(first){
						if(end[s[j-1]-'a']==-1){
							end[s[j-1]-'a']=i;
							l[i]=s[j-1]-'a';
						}
						else
							bad=true;
						first=false;
					}
					else{
						if(inner[s[j-1]-'a'])
							bad=true;
						else
							inner[s[j-1]-'a']=true;
					}
			if(first)
				midcount[s[s.length()-1]-'a']++;
			else if(start[s[s.length()-1]-'a']==-1){
				start[s[s.length()-1]-'a']=i;
				r[i]=s[s.length()-1]-'a';
			}
			else
				bad=true;
		}
		//if(bad)cerr<<"a"<<endl;
		long long total=1;
		int c=0;
		if(!bad)
		for(int i=0;i<26;i++){
			if(inner[i] && (start[i]!=-1 || end[i]!=-1 || midcount[i]!=0)){
				bad=true;
				break;
			}
			if(midcount[i]!=0)
				total=(total*perm[midcount[i]]) % m;
		}
		//if(bad)cerr<<"b"<<endl;
		if(!bad)
		for(int i=0;i<26;i++)
			if(!v[i]){
				v[i]=true;
				for(int j=start[i];j!=-1;j=start[l[j]]){
					if(v[l[j]]){
						bad=true;
						break;
					}
					v[l[j]]=true;
				}
				for(int j=end[i];j!=-1;j=end[r[j]]){
					if(v[r[j]]){
						bad=true;
						break;
					}
					v[r[j]]=true;
				}
				if(bad)
					break;
				if(start[i]!=-1 || end[i]!=-1 || midcount[i]!=0)
					c++;
			}
		if(!bad)
			cout<<"Case #"<<i<<": "<<((total * perm[c]) % m)<<endl;
		else
			cout<<"Case #"<<i<<": "<<0<<endl;
	}
	return 0;
}

