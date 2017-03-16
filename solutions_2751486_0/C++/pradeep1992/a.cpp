#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define ppp cout<<"hai ";

using namespace std;
	string s;
	
bool check(int t,int e,int b){
bool res=false;int count=0;char c;
for(int i=b;i<=e;i++){
	c=s[i];//cout<<c;
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
	count=0;}
	else {count++;}
	if(count ==t){res=true;			//	cout <<"\t<= here";
	break;}
}
//cout<<b<<"\t"<<e<<endl;
return res;}



int main()
{
    freopen("a1.in", "r", stdin);
    freopen("a1.out", "w", stdout);
int no,x,y,count=0;
	cin >>no;
	for(int i=0;i<no;i++){count=0;
	int t;
	s=" ";
	cin >>s>>t;
for(int j=0;j<=s.size()-t;j++){
	for(int k=j+t-1;k<=s.size()-1;k++){
	if(check(t,k,j))
	count++;	}
	}
cout<<"Case #"<<i+1<<": "<<count<<endl;	
}	
	

    
    return 0;
}
