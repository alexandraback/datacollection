/*    SHUBHAM SINHA    */



#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <math.h>

#define ll long long int
#define maxN 100000
#define maxVal 100000000
#define minVal -100000000
#define mod 1000000007LL

#define gcd(a,b) __gcd(a,b)

using namespace std;

string a;

int c[30];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef LOCAL_SYS
        freopen("A-large.in","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t,i,j,n0,n1,n2,n3,n4,n5,n6,n7,n8,n9;
    cin>>t;
    for(i=1;i<=t;i++)
    {
    	cin>>a;
    	fill(c,c+26,0);
    	for(j=0;j<(int)a.length();j++)
    		c[a[j]-'A']++;
    	n0=c[25];
    	c['E'-'A']-=c['Z'-'A'];
    	c['R'-'A']-=c['Z'-'A'];
    	c['O'-'A']-=c['Z'-'A'];
    	c['Z'-'A']=0;
    	n2=c['W'-'A'];
    	c['T'-'A']-=c['W'-'A'];
    	c['O'-'A']-=c['W'-'A'];
    	c['W'-'A']=0;
    	n8=c['G'-'A'];
    	c['E'-'A']-=c['G'-'A'];
    	c['I'-'A']-=c['G'-'A'];
    	c['H'-'A']-=c['G'-'A'];
    	c['T'-'A']-=c['G'-'A'];
    	c['G'-'A']=0;
    	n3=c['T'-'A'];
    	c['H'-'A']-=c['T'-'A'];
    	c['R'-'A']-=c['T'-'A'];
    	c['E'-'A']-=c['T'-'A'];
    	c['E'-'A']-=c['T'-'A'];
    	c['T'-'A']=0;
    	n4=c['U'-'A'];
    	c['F'-'A']-=c['U'-'A'];
    	c['O'-'A']-=c['U'-'A'];
    	c['R'-'A']-=c['U'-'A'];
    	c['U'-'A']=0;
    	n6=c['X'-'A'];
    	c['S'-'A']-=c['X'-'A'];
    	c['I'-'A']-=c['X'-'A'];
    	c['X'-'A']=0;
    	n7=c['S'-'A'];
    	c['E'-'A']-=c['S'-'A'];
    	c['V'-'A']-=c['S'-'A'];
    	c['E'-'A']-=c['S'-'A'];
    	c['N'-'A']-=c['S'-'A'];
    	c['S'-'A']=0;
    	n5=c['V'-'A'];
    	c['F'-'A']-=c['V'-'A'];
    	c['I'-'A']-=c['V'-'A'];
    	c['E'-'A']-=c['V'-'A'];
    	c['V'-'A']=0;
    	n1=c['O'-'A'];
    	c['N'-'A']-=c['O'-'A'];
    	c['E'-'A']-=c['O'-'A'];
    	c['O'-'A']=0;
    	n9=c['I'-'A'];
    	c['N'-'A']-=c['I'-'A'];
    	c['N'-'A']-=c['I'-'A'];
    	c['E'-'A']-=c['I'-'A'];
    	c['I'-'A']=0;
    	cout<<"Case #"<<i<<": ";
    	for(j=0;j<n0;j++)
    		cout<<0;
    	for(j=0;j<n1;j++)
    		cout<<1;
    	for(j=0;j<n2;j++)
    		cout<<2;
    	for(j=0;j<n3;j++)
    		cout<<3;
    	for(j=0;j<n4;j++)
    		cout<<4;
    	for(j=0;j<n5;j++)
    		cout<<5;
    	for(j=0;j<n6;j++)
    		cout<<6;
    	for(j=0;j<n7;j++)
    		cout<<7;
    	for(j=0;j<n8;j++)
    		cout<<8;
    	for(j=0;j<n9;j++)
    		cout<<9;
    	cout<<"\n";
    }
    return 0;
}