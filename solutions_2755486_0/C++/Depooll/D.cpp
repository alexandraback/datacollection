#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string.h>
#pragma comment(linker, "/STACK:10000000") 
#define md 1000000007

using namespace std;

int j,k,ans,test,t,i,n,x,y,w[700000][12],e[700000][12],s[700000][12],di,ni,wi,ei,si,delta_di,delta_pi,delta_si;
int h[4000];

int main()
{
	ifstream f("input.txt");
	ofstream g("output.txt");
	
	f>>t;

	for (test = 1; test<=t;test++)
	{
		g<<"Case #"<<test<<": ";
		for (i=0;i<4000;i++) h[i] = 0;
		for (i=0;i<700000;i++) w[i][0]=0;
		
		f>>n;
		for (i=1;i<=n;i++)
		{
			f>>di>>ni>>wi>>ei>>si>>delta_di>>delta_pi>>delta_si;
			wi*=2;
			ei*=2;
			delta_pi*=2;
			
			wi+=2000;
			ei+=2000;
			for (j=1;j<=ni;j++)
			{
				w[di][0]++;
				w[di][w[di][0]] = wi;
				e[di][w[di][0]] = ei;
				s[di][w[di][0]] = si;
				di+=delta_di;
				wi+=delta_pi;
				ei+=delta_pi;
				si+=delta_si;		
			}
		}
		ans=0;
		for (i=0;i<700000;i++)
		{
		 for (j=1;j<=w[i][0];j++)
		 {
		 	for (k=w[i][j];k<=e[i][j];k++)
		 	{
					 if (h[k]<s[i][j]) 
					 {
						ans++;
						break;		
					 }
			}
	    }
	     for (j=1;j<=w[i][0];j++)
		 	for (k=w[i][j];k<=e[i][j];k++)
		 		if (h[k]<s[i][j]) h[k] = s[i][j];		
		}
		for (i=0;i<700000;i++)
		 for (j=1;j<=w[i][0];j++)
		 	for (k=w[i][j];k<=e[i][j];k++)
		 		if (h[k]<s[i][j]) h[k] = s[i][j];
		
		g<<ans<<endl;
		
	}
}
