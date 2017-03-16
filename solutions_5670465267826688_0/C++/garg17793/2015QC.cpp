#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mod 1000000007
using namespace std;
string st;
int main()
{
  std:ios_base::sync_with_stdio(false);
  freopen ("C-small-attempt0.in", "r", stdin);
  freopen ("Csmall.in", "w", stdout);
  long long int t,l,x,cs=1,i,n,tmp,cur,prev;
  int a[5][5];
  a[1][1]=1; a[1][2]=2; a[1][3]=3; a[1][4]=4;
  a[2][1]=2; a[2][2]=-1; a[2][3]=4; a[2][4]=-3;
  a[3][1]=3; a[3][2]=-4; a[3][3]=-1; a[3][4]=2;
  a[4][1]=4; a[4][2]=3; a[4][3]=-2; a[4][4]=-1;


  int bar[10004],f,iind,jind,kind,tmpind;
  cin>>t;
  while(t--)
  { st="";
    iind=-1; jind=-1; kind=-1;
  	cin>>l>>x;
  	cin>>st;
  	
	n=l*x;
	if(n<3)	cout<<"Case #"<<cs++<<": "<<"NO"<<"\n";
  	else
  	{ bar[l]=1;
  	  bar[l-1]=(int)(st[l-1]-'i'+2);
  	  for(i=l-2;i>=0;i--)
  	  {
  	  	bar[i]=1;
  	    int right=bar[i+1];
  	  	if(right<0)
  	  	{
  	  		bar[i]*=-1;
  	  		right*=-1;
  	  	} 	
  	  	bar[i]*=a[st[i]-'i'+2][right];
  	  }

  	  prev=1;
	  for(i=0;i<min(n,4*l);i++)
  	  {
  	  	tmpind=i%l;
		cur=1;
		int left=prev;
		if(left<0)
		{	cur=-cur;	left*=(-1);	}
		cur*=(a[left][st[tmpind]-'i'+2]);
		prev=cur;
		if(cur==2)
		{	iind=i; break;}
  	  }
	  //cout<<"iind="<<iind<<"\n";
	  if(iind==-1) 
	  {
	  	cout<<"Case #"<<cs++<<": "<<"NO"<<"\n";
	  	continue;
	  }
	  
	  prev=1;
	  for(i+=1;i<min(n,i+(4*l));i++)
  	  {
  	  	tmpind=i%l;
		cur=1;
		int left=prev;
		if(left<0)
		{	cur=-cur;	left*=(-1);	}
		cur*=(a[left][st[tmpind]-'i'+2]);
		prev=cur;
		if(cur==3)
		{	jind=i; break;}
  	  }
  	  //cout<<"jind="<<jind<<"\n";
  	  if(jind==-1) 
	  {
	  	cout<<"Case #"<<cs++<<": "<<"NO"<<"\n";
	  	continue;
	  }
	  
	  prev=1;
	  for(i+=1;i<min(n,i+(4*l));i++)
  	  {
  	  	tmpind=i%l;
		cur=1;
		int left=prev;
		if(left<0)
		{
			cur=-cur;
			left*=(-1);
		}
		cur*=(a[left][st[tmpind]-'i'+2]);
		prev=cur;
		if(cur==4)
		{	kind=i; break;}
  	  }
	  //cout<<"kind="<<kind<<"\n";
	  if(jind==-1) 
	  {
	  	cout<<"Case #"<<cs++<<": "<<"NO"<<"\n";
	  	continue;
	  }
	  
	  int tt=(i+1)/l; // number of used strings
	  int rem=(i+1)%l; // index remaining string
	  int remx=x-tt;   // number of remaining strings
	  
	  if(rem!=0) remx-=1; // modify number of remaining string
	  
	  prev=1;	// right result
	  if(rem==0)	prev*=bar[l]; // multiply by remaining result
	  else	prev*=bar[rem];
	  
	  int rpow=(remx%4);
	  
	  if(rpow==1)
	  {
	  	cur=1;
	    int left=prev;
	    int right=bar[0];
	    if(left<0 && right>0)
	    {	cur=-cur;	left*=(-1);	}
	    else if(left>0 && right<0)
	    {	cur=-cur;	right*=(-1);	}
	    else if(left<0 && right<0 )
	    {	left*=(-1); right*=(-1); }
	    cur*=(a[left][right]);
	    prev=cur;
	    //cout<<"right1=="<<prev<<"\n";
	  }
	  else if(rpow==2)
	  {
	  	 cur=1;
	  	 int left=prev;
	  	 int right=bar[0];
	  	 if(right==1 || right==-1)	{	}
		 else
		 {
		 	right=-1;
		 	if(left>0)
		 	{	cur-=cur;	right*=(-1);	}
		 	else if(left<0 && right<0 )
	    	{	left*=(-1); right*=(-1);    }
		 	cur*=(a[left][right]);
	    	prev=cur;
		 }
		 //cout<<"right2=="<<prev<<"\n";
	  }
	  else if(rpow==3)
	  {
	  	 cur=1;
	  	 int left=prev;
	  	 int right=bar[0];
	  	 if(right==1)	{	}
		 else if(right==-1)
		 {
		 	right=-1;
		 	if(left>0)
		 	{	cur-=cur;	right*=(-1);	}
		 	else if(left<0 && right<0 )
	   		{	left*=(-1); right*=(-1); }
		 	cur*=(a[left][right]);
	    	prev=cur;
		 }
		 else
		 {
			right*=(-1);
		 	if(left<0 && right>0)
	    	{	cur=-cur;	left*=(-1);		}
	    	else if(left>0 && right<0)
	    	{	cur=-cur;	right*=(-1);	}
	    	else if(left<0 && right<0 )
	   	 	{	left*=(-1); right*=(-1); }
		 	cur*=(a[left][right]);
	    	prev=cur;
		 }
		 //cout<<"right3=="<<prev<<"\n";
	  }
	  if(prev==1)	cout<<"Case #"<<cs++<<": "<<"YES"<<"\n";
	  else	cout<<"Case #"<<cs++<<": "<<"NO"<<"\n";
	  
  	}
  	//cout<<"Case #"<<cs++<<": "<<ans<<"\n";
  }  
  return 0;
}

