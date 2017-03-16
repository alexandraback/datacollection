#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int N=32,J=500;

long long jz(string s,int j){
	long long ret=0;
	int l=s.length();
	for(int i=0;i<l;i++)
		if(s[l-i-1]=='1')
		ret+=pow(j,i);
	return ret;
}

string verify(string s){
	/*for(int j=2;j<=10;j++)
	{
		cout<<"under "<<j<<":\t"<<jz(s,j)<<endl;
	}

	for(int j=2;j<=10;j++)
		if(jz(s,j)%(j+1)!=0)return "!";*/
	string ans=" 3 4 5 6 7 8 9 10 11";
	return ans;
}

string merger(string s1,string s2){
	string s="1";
	for(int i=0;i<s1.length();i++){
		s+=s1[i];
		s+=s2[i];
	}
	s+="1";
	return s;
}

void generate_all(){
	vector<string> part;
	part.clear();
	string zeros;
	int M=N/2-1;
	zeros="";
	for(int i=0;i<M;i++)zeros+="0";



	for(int i=0;i<M-1;i++)
	for(int j=i+1;j<M;j++){
		string s=zeros;
		s[i]=s[j]='1';
		part.push_back(s);
	}
	int C=part.size();

	int total=0;
	for(int i=0;i<C;i++)
		for(int j=0;j<C;j++){
			string ans=merger(part[i],part[j]);
			cout<<ans<<verify(ans)<<endl;	
			total++;
			if(total==J)return;
		}
}

/*void checkall(){
	string s;
	//odd:p1=1 even:pN=1
	for(int i=2;i<=N/2;i++)
		for(int j=1;j<N/2;j++){
			s="";
			for(int k=1;k<=N/2;k++){
				char c1='0',c2='0';
				if(k==1 || k==i)c1='1';
				if(k==N/2 || k==j)c2='1';
				s+=c1;
				s+=c2;
			}

			cout<<s<<verify(s)<<endl;			
		}
	s="";for(int i=0;i<N;i++)s+='1';

	cout<<s<<verify(s)<<endl;
}*/

int main(){
	cout<<"Case #1:"<<endl;
	generate_all();
	return 0;
}