#include<iostream>
using namespace std;
int T;
string s;
long long ostatni_cc,koniec,ilosc_cc;
int n;
long long res;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>s;
		cin>>n;
		for(int j=0;j<s.size();j++){
			if((s[j]=='a')||(s[j]=='e')||(s[j]=='i')||(s[j]=='o')||(s[j]=='u'))s[j]='a';
			else s[j]='b';
		}
		ostatni_cc=s.size();
		koniec=s.size();
		ilosc_cc=0;
		for(int j=(s.size()-1);j>=0;j--){
			if(s[j]=='b')ilosc_cc++;
			else ilosc_cc=0;
			if(ilosc_cc>=n){
				ostatni_cc=j+(n-1);
			}
			res+=(koniec-ostatni_cc);
		}
	cout<<"Case #"<<(i+1)<<": "<<res<<"\n";
	res=0;
	}
cout<<endl;
return 0;
}
