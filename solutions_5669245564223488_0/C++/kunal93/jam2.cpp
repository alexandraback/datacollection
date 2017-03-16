#include<iostream>
using namespace std;
#include<string.h>
char s[102][1000];
long long MOD=1000000007;
long long count=0;
#include<stdio.h>
int a[10]={0};
int n;
int ctr[26]={0};
char temp2[12*1000+1];
void recur(char last,int c,int m)
 {// cout<<m;
 //char temp[12*1000+1];
//cout<<m<<endl;
 	int i;
 	if(c==n)
 	  {  
 	  	count=(count+1)%MOD;
 	  
 	  	return;
 	  }
 	 
 	int l;
 	 
 	 
 	  for(i=0;i<n;i++)
 	   {int flag=1;
		if(a[i])
 	     continue;
 	    // cout<<"safe"<<endl;
 	   l=strlen(s[i]);
 	  for(int j=0;j<l;j++)
 	  	     {if(j==0)
 	  	       		{
 	  	       			if(s[i][j]!=last && ctr[s[i][j]-97]!=0)
 	  	  	   			 flag=0;
 	  	       		}
 	  	       else
 	  	  	  		{
 	  	  	  	 	 if(s[i][j]!=s[i][j-1] && ctr[s[i][j]-97]!=0)
 	  	  	   			 flag=0;
 	  	  			}
				ctr[s[i][j]-97]++;
				//cout<<"safe"<<endl;
 	  	     }
 	  	     
 	  	    a[i]=1;
 	    if(flag)
 	   	       recur(s[i][l-1],c+1,i);
 	   	    for(int j=0;j<l;j++)
 	  	     {
 	  	  	  
 	  	  	  ctr[s[i][j]-97]--;
 	  	     }
		   a[i]=0;
	 }
 }

int main()
 {
 	freopen("in2.cpp","r",stdin);
 freopen("out.txt","w",stdout);
char ans[102*1000+1];
 	int t;
 	cin>>t;
 	for(int l=1;l<=t;l++)
 	  {//ans[0]='\0';
 	 
 	  	cin>>n;
 	  	for(int i=0;i<n;i++)
 	  	   {
 	  	   	cin>>s[i];
 	  	   }  
	    count=0;
	    memset(a,0,sizeof(a));
	     memset(ctr,0,sizeof(ctr));
 	  	for(int i=0;i<n;i++)
 	  	  {a[i]=1;
 	  	  //cout<<1<<endl;
 	  	  strcpy(temp2,s[i]);
 	  	  int l=strlen(s[i]);
 	  	  int flag=1;
 	  	  ctr[s[i][0]-97]++;
 	      for(int j=1;j<l;j++)
 	  	     {
 	  	  	  if(s[i][j]!=s[i][j-1] && ctr[s[i][j]-97]!=0)
 	  	  	    {//cout<<i<<" "<<j;
 	  	  	    flag=0;
 	  	  	    }
 	  	  	  ctr[s[i][j]-97]++;
 	  	     }
 	  	     if(flag)
 	   	       recur(s[i][l-1],1,i);
 	   	    for(int j=0;j<l;j++)
 	  	     {
 	  	  	  
 	  	  	  ctr[s[i][j]-97]--;
 	  	     }
		   a[i]=0;
		 //  cout<<endl;
 	  	  }
 	  	 cout<<"Case #"<<l<<": "<<count<<endl;
 	  }
 }
