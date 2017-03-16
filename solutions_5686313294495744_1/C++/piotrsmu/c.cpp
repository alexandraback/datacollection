#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <map>
long long n,t,res,s1il,s2il,ite;
std::string str1,str2;
std::map<std::string,int> s1,s2;
std::vector<int> sa[1001];
int skojarzenie1[1001];
int skojarzenie2[1001];
int opt[1001];
bool skojarz(int i){
	
	if(opt[i]==ite)
		return false;
	opt[i]=ite;
	for(int j=0;j<sa[i].size();j++){
		if(skojarzenie2[sa[i][j]]==-1){
			skojarzenie1[i]=sa[i][j];
			skojarzenie2[sa[i][j]]=i;
			return true;
		}else{
			if(skojarz(skojarzenie2[sa[i][j]])){
				skojarzenie1[i]=sa[i][j];
				skojarzenie2[sa[i][j]]=i;
				return true;
			}
		}
	}
	return false;
			
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin>>t;
	for(int test_nr=1;test_nr<=t;test_nr++){
		s1.clear();
		s2.clear();
		for(int i=0;i<1000;i++){
			skojarzenie1[i]=-1;
			skojarzenie2[i]=-1;
			opt[i]=0;
			sa[i].clear();
		}
		s2il=s1il=0;
		std::cin>>n;
		for(int i=0;i<n;i++){
			std::cin>>str1>>str2;
			if(s1.count(str1)==0){
				s1[str1]=s1il;
				s1il++;
			}
			if(s2.count(str2)==0){
				s2[str2]=s2il;
				s2il++;
			}
			sa[s1[str1]].push_back(s2[str2]);
			//std::cout<<"kra"<<s1[str1]<<" "<<s2[str2]<<std::endl;
		}
		bool cont=true;
		res=s1il+s2il;
		ite=0;
		while(cont){
			ite++;
			cont=false;
			for(int i=0;i<s1il;i++){
				//std::cout<<"deb1"<<std::endl;
				if(skojarzenie1[i]==-1){
					//std::cout<<"y"<<std::endl;
					if(skojarz(i)){
						//std::cout<<"x"<<std::endl;
						cont=true;
						res--;	
					}
				}
			}
		
		}
		std::cout<<"Case #"<<test_nr<<": "<<n-res<<std::endl;
		
	}
}
