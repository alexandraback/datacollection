#include <iostream>
using namespace std;
#include<algorithm>
#include<stdio.h>
#include<fstream>
#include<math.h>
using namespace std;

long long int hcf(long long int a, long long int b)
{
	if(a%b==0)
	return b;
	else
	return (hcf(b,a%b));
}
 
int main() {
	long long int ne= pow(2,40);
	ifstream myReadFile;
 	myReadFile.open("text.txt");
	long long int t,m=0;
	myReadFile>>t;
	ofstream myfile;
    myfile.open ("example.txt");
	while(t--)
	{
		long long int p,q;
		char ch;
		m++;
	    myReadFile>>p>>ch>>q;
	    long long int y=hcf(p,q);
	    p=p/y;
	    q=q/y;
	    if((q&-q)!=q)
	    myfile<<"Case #"<<m<<": impossible\n";
	    else
	    {
	    	
	    	long long int ans=0;
	    	while(q!=ne)
	    	{
	    		q*=2;
	    		p*=2;
	    	}
	    	while(p!=0)
	    	{
	    		p/=2;
	    		ans++;
	    	}
	    	myfile<<"Case #"<<m<<": "<<41-ans<<"\n";
	    }
	    
	}
		myfile.close();
		myReadFile.close();
	return 0;
}
