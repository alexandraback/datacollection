#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;

int main()
{
 
 freopen("inp.txt","r",stdin);
 freopen("out.txt","w",stdout);
 
 int t,id=1;;
 cin>>t;
 while(t--)
 {
 	string str;
 	cin>>str;
 	
 	vector<int>V(30,0);
 	
 	for(int i=0;i<str.length();i++)
 	V[str[i]-'A']++;
 	
 	vector<int>F(30,0);
 	
 	F[0]=V['Z'-'A'];
 	F[4]=V['U'-'A'];
 	F[2]=V['W'-'A'];
 	F[1]=V['O'-'A']-F[0]-F[2]-F[4];
 	F[3]=V['R'-'A']-F[4]-F[0];
 	F[6]=V['X'-'A'];
 	F[5]=V['F'-'A']-F[4];
 	F[7]=V['S'-'A']-F[6];
 	F[8]=V['G'-'A'];
 	F[9]=V['I'-'A']-F[5]-F[6]-F[8];
 	
 	cout<<"Case #"<<id<<": ";
 	
 	id++;
 	
 	
 	for(int i=0;i<=9;i++)
 	{
 		for(int j=0;j<F[i];j++)
 		cout<<i;
	 }

    cout<<endl; 	
 }
 
return 0;
}
