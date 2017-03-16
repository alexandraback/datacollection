#include<iostream>
#include<stdio.h>
using namespace std;
char key[200];
char set[200];
double count[300];
int main()
{
	int t,k,l,s,i,j;
	cin>>t;
	for(j=1;j<=t;j++)
	{
		cin>>k>>l>>s;
		for(i=0;i<=25;i++) {count[i]=0;}
		for(i=0;i<k;i++) {cin>>key[i];count[key[i]-'A']++;}
		for(i=0;i<=25;i++) count[i]/=k;
		for(i=0;i<l;i++) cin>>set[i];
		double yesprob;
		yesprob=1;
		for(i=0;i<l;i++) yesprob*=count[set[i]-'A'];
		yesprob*=(s+1-l);
		//cout<<yesprob<<endl;
		
		int maxx=0;
		char temp[200];
		for(i=0;i<l;i++) temp[i]=set[i];
		for(i=1;i<l;i++)
		{
			int x;
			bool eq=1;
			for(x=0;i+x<l;x++) if(temp[i+x]!=set[x]) {eq=0;break;}
			if(eq==1) break;
		}
		bool eqeq=1;
		for(i=1;i<l;i++) if(set[i]!=set[i-1]) eqeq=0;
		if(eqeq==1) i=0;
		//cout<<i<<' '<<s<<' '<<l<<endl;
		if(i==0) maxx=s+1-l;
		else maxx=((s-l)/i)+1;
		//cout<<maxx<<' '<<yesprob<<endl;
		printf("Case #%d: %0.8f\n",j,(double)maxx-yesprob);
	}
}
		
