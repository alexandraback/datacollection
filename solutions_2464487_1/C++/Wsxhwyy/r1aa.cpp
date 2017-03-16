#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int max=100;                                   
class hpnum{
	friend hpnum operator+(const hpnum& lhs,const hpnum& rhs)
	{ hpnum res=lhs; res+=rhs; return res; }
	friend hpnum operator-(const hpnum& lhs,const hpnum& rhs)
	{ hpnum res=lhs; res-=rhs; return res; }
	friend hpnum operator*(const hpnum&,const hpnum&);
	friend hpnum operator/(const hpnum&,const hpnum&);
	friend bool operator==(const hpnum&,const hpnum&);
	friend bool operator!=(const hpnum& lhs,const hpnum& rhs)
	{ return !(lhs==rhs); }
	friend bool operator<(const hpnum&,const hpnum&);
	friend bool operator<=(const hpnum& lhs,const hpnum& rhs)
	{ return !(lhs>rhs); }
	friend bool operator>(const hpnum&,const hpnum&);
	friend bool operator>=(const hpnum& lhs,const hpnum& rhs)
	{ return !(lhs<rhs); }
	friend ostream& operator<<(ostream&,const hpnum&);
public:
	hpnum(){ fill(Arr,Arr+::max+2,0); Arr[0]=1; } 
	hpnum(const string&);
	hpnum(const char*);
	hpnum(const long long&);
	hpnum& operator+=(const hpnum&);
	hpnum& operator-=(const hpnum&);
	hpnum& operator*=(const hpnum& rhs)
	{ *this=(*this)*rhs; return *this; }
	hpnum& operator/=(const hpnum& rhs)
	{ *this=(*this)/rhs; return *this; }
	hpnum& operator++();                  
	hpnum operator++(int)                
	{ hpnum res=*this; ++*this; return res; }
	hpnum& operator--();                  
	hpnum operator--(int)               
	{ hpnum res=*this; --*this; return res; }
	int size() { return Arr[0]; }
	int Arr[::max+2];
private:
	hpnum(const int*,const int);    
	void mulby10();                       
};


hpnum::hpnum(const string& sc){
	for(int xx=0;xx<(::max+2);xx++)
		Arr[xx]=0;
	Arr[0]=sc.size();
	for(int i=1;i<=Arr[0];++i)                              
		Arr[i]=sc[Arr[0]-i]-'0';
}

hpnum::hpnum(const char* sc){
	for(int xx=0;xx<(::max+2);xx++)
		Arr[xx]=0;
	Arr[0]=strlen(sc);
	for(int i=1;i<=Arr[0];++i)                              
		Arr[i]=sc[Arr[0]-i]-'0';
}

hpnum::hpnum(const long long&s){
	char* sc=new char[25];
	sprintf(sc,"%lld",s);
	for(int xx=0;xx<(::max+2);xx++)
		Arr[xx]=0;
	Arr[0]=strlen(sc);
	for(int i=1;i<=Arr[0];++i)                              
		Arr[i]=sc[Arr[0]-i]-'0';
}

hpnum::hpnum(const int* beg,const int cnt){
	for(int xx=0;xx<(::max+2);xx++)
		Arr[xx]=0;
	for(;Arr[0]<cnt;++beg){
		++Arr[0];
		Arr[Arr[0]]=*beg;
	}
	if(Arr[0]<1) Arr[0]=1;
}

void hpnum::mulby10(){
	if(Arr[0]==1 && Arr[1]==0) return;
	++Arr[0];
	for(int i=Arr[0];i>1;--i)
		Arr[i]=Arr[i-1];
	Arr[1]=0;
}

hpnum& hpnum::operator+=(const hpnum& rhs){
	int i,jin=0,len;
	Arr[0]>rhs.Arr[0]?len=Arr[0]:len=rhs.Arr[0];
	Arr[0]=len;
	for(i=1;i<=len;++i){
		jin+=Arr[i]+rhs.Arr[i];
		Arr[i]=jin%10;
		jin/=10;
	}
	if(jin>0){
		++Arr[0];
		Arr[Arr[0]]=jin;
	}
	return *this;
}

hpnum& hpnum::operator-=(const hpnum& rhs){
	if(*this>=rhs){
		for(int i=1;i<=Arr[0];++i)
			if(Arr[i]<rhs.Arr[i]){
				--Arr[i+1];
				Arr[i]+=(10-rhs.Arr[i]);
			}
			else Arr[i]-=rhs.Arr[i];
			while(Arr[Arr[0]]==0&&Arr[0]>1) --Arr[0];
	}
	return *this;
}

hpnum operator*(const hpnum& lhs,const hpnum& rhs){
	hpnum res;
	res.Arr[0]=lhs.Arr[0]+rhs.Arr[0];
	int i,j,jin;
	for(i=1;i<=lhs.Arr[0];++i){
		jin=0;
		for(j=1;j<=rhs.Arr[0];++j){
			jin+=lhs.Arr[i]*rhs.Arr[j]+res.Arr[i+j-1];
			res.Arr[i+j-1]=jin%10;
			jin/=10;
		}
		if(jin>0) res.Arr[i+rhs.Arr[0]]=jin;
	}
	while(res.Arr[res.Arr[0]]==0 && res.Arr[0]>1) --res.Arr[0];
	return res;
}

hpnum operator/(const hpnum& lhs,const hpnum& rhs){ 
	hpnum res;
	if(rhs.Arr[0]==1 && rhs.Arr[1]==0){
		cerr<<"Divide by zero!"<<endl;
		res.Arr[0]=0;
		return res;
	}
	res.Arr[0]=lhs.Arr[0]-rhs.Arr[0]+1;
	if(res.Arr[0]<1){
		res.Arr[0]=1;
		return res;
	}
	int i=res.Arr[0],j;
	hpnum yu(lhs.Arr+i+1,rhs.Arr[0]-1);                
	for(;i>0;--i){            
		yu.mulby10();
		yu.Arr[1]=lhs.Arr[i];
		j=0;
		while(yu>=rhs){
			yu-=rhs;
			++j;
		}
		res.Arr[i]=j;
	}
	while(res.Arr[res.Arr[0]]==0 && res.Arr[0]>1) --res.Arr[0];
	return res;
}

hpnum& hpnum::operator++(){
	int jin=0,i=2;
	++Arr[1];
	if(Arr[1]==10){
		Arr[1]=0;
		jin=1;
	}
	while(jin>0&&i<=Arr[0]){
		jin=++Arr[i]/10; Arr[i]%=10;
		++i; 
	}
	if(jin>0){
		++Arr[0];
		Arr[Arr[0]]=jin; 
	}
	return *this;
}

hpnum& hpnum::operator--(){
	if(Arr[1]==0 && Arr[0]==1) return *this; 
	--Arr[1]; 
	if(Arr[1]<0){
		Arr[1]=9;
		--Arr[2];
	}     
	for(int i=2;Arr[i]<0;++i){
		Arr[i]=9;
		--Arr[i+1];
	}
	while(Arr[Arr[0]]==0 && Arr[0]>1) --Arr[0];
	return *this;
} 

bool operator==(const hpnum& lhs,const hpnum& rhs){
	if(&lhs!=&rhs)
		for(int i=0;i<=lhs.Arr[0];++i)
			if(lhs.Arr[i]!=rhs.Arr[i]) return false;
	return true;
}

bool operator<(const hpnum& lhs,const hpnum& rhs){
	if(&lhs!=&rhs){
		if(lhs.Arr[0]<rhs.Arr[0]) return true;
		if(lhs.Arr[0]>rhs.Arr[0]) return false;
		int i=lhs.Arr[0];
		while(lhs.Arr[i]==rhs.Arr[i] && i>0) --i;
		if(lhs.Arr[i]<rhs.Arr[i]) return true;
		else return false;
	}
	else return false;
}

bool operator>(const hpnum& lhs,const hpnum& rhs){
	if(&lhs!=&rhs){
		if(lhs.Arr[0]>rhs.Arr[0]) return true;
		if(lhs.Arr[0]<rhs.Arr[0]) return false;
		int i=lhs.Arr[0];
		while(lhs.Arr[i]==rhs.Arr[i] && i>0) --i;
		if(lhs.Arr[i]>rhs.Arr[i]) return true;
		else return false;
	}
	else return false;
}

ostream& operator<<(ostream& os,const hpnum& rhs){
	for(int i=rhs.Arr[0];i>0;--i)
		os<<rhs.Arr[i];
	return os;
}


long long T,rr,tt;

int main()
{
	fin>>T;
	for(int xx=1;xx<=T;xx++){
		cin>>rr>>tt;
		hpnum r=rr,t=tt;
		hpnum left=0LL,right=1000000000000000000LL;
		while(left<right){
			hpnum mid=(left+right)/2;
			hpnum ans=2*mid*mid+(2*r-1)*mid;
			if(ans<=t) left=mid+1;
			else right=mid;
		}
		cout<<"Case #"<<xx<<": "<<left-1<<endl;
	}
}