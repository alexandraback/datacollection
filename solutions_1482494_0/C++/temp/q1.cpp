#include <cstdio>
#include <iostream>
using namespace std;
int main (){
    int cases,A,B,i;
    double p[100002],product,expected,min;
    scanf("%d",&cases);
	
    for (i=1;i<=cases;i++){
	int s[10000][2];
	int com[10000][2];
	for(int j=0;j<10000;j++)
		com[j][0]=com[j][1]=0;
	int t;        
	cin>>t;
	for(int j=0;j<t;j++)
		cin>>s[j][0]>>s[j][1];
	int flag=0;
	int currstar=0;
	int comple=0;
	while(flag==0){
	flag=1;
	int point=currstar;
	for(int j=0;j<t;j++)
	{
		if(s[j][1]<=currstar&&com[j][1]!=1)
		{
			if(com[j][0]!=1) currstar+=2;
			else currstar++;
			com[j][0]=com[j][1]=1;
			flag=0;
			comple+=1;
			break;
		}

	}
	for(int j=0;j<t&&flag==1;j++)
	{	//cout<<s[j][0]<<" "<<currstar<<" "<<com[j][0]<<"\n";
		if(s[j][0]<=currstar&&com[j][0]!=1)
		{
			currstar+=1;
			comple++;
			com[j][0]=1;
			flag=0;
		}
	}
	}
	if(currstar!=t*2) {cout<<"Case #"<<i<<": Too Bad\n";continue;}
        cout<<"Case #"<<i<<": "<<comple<<"\n";
   }
    return 0;
}
