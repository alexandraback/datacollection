#include<bits/stdc++.h>
using namespace std;
#define cin fin
#define cout fout
int ispossible(string s,int c,int d,int e){
	if(s[2]!='?' and s[2]!=('0'+c))
		return 0;
	if(s[1]!='?' and s[1]!=('0'+d))
		return 0;
	if(s[0]!='?' and s[0]!=('0'+e))
		return 0;
	return 1;
}

int ispossible2(string s,int a,int b){
	if(s[1]!='?' and s[1]!=('0'+a))
		return 0;
	if(s[0]!='?' and s[0]!=('0'+b))
		return 0;
	return 1;
}

int main(){
	int t;
	ifstream fin;
	ofstream fout;
	fin.open("B-small-attempt1 (1).in");
	fout.open("2.txt");
	cin>>t;
	int z=1;
	while(t--){
		string s,t;
		cin>>s>>t;
		int n=s.length();
		cout<<"Case #"<<z<<": ";
		z++;
		if(n==1){
			if(s[0]=='?' and t[0]=='?'){
				s[0]='0';
				t[0]='0';
			}
			else if(s[0]=='?' and t[0]!='?'){
				s[0]=t[0];
			}
			else if(s[0]!='?' and t[0]=='?'){
				t[0]=s[0];
			}
			cout<<s<<" "<<t<<endl;
			continue;
		}
		else if(n==2){
			int mindiff=1001,p,q;
			for(int i=0;i<100;i++){
				for(int j=0;j<100;j++){
					int a=i%10,b=i/10;
					int c=j%10,d=j/10;
					if(ispossible2(s,a,b) and ispossible2(t,c,d)){
						if(abs(i-j)<mindiff){
						mindiff=abs(i-j);
						p=i;
						q=j;
					}
					}
				}
			}
			if(p<10)
				cout<<"0";
			cout<<p<<" ";
			if(q<10)
				cout<<"0";
			cout<<q<<endl;
			continue;
		}
		int mindiff=10000;
		int p,q;
		for(int i=0;i<=999;i++){
			for(int j=0;j<999;j++){
				int c,d,e,f,g,h;
				c=i%10;
				d=(i%100)/10;
				e=i/100;
				f=j%10;
				g=(j%100)/10;
				h=j/100;
				if(ispossible(s,c,d,e) and ispossible(t,f,g,h)){
					if(abs(i-j)<mindiff){
						p=i;
						q=j;
						mindiff=abs(i-j);
					}
				}
			}
		}
		if(p<10)
			cout<<"00";
		else if(p<100)
			cout<<"0";
		cout<<p<<" ";
		if(q<10)
			cout<<"00";
		else if(q<100)
			cout<<"0";
		cout<<q<<endl;
	}
	return 0;
}
