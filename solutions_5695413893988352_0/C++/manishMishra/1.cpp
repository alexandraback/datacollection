#include<bits/stdc++.h>
using namespace std;
  
#define MOD 1000000007
#define MAX 1000000007
#define gc getchar()  
#define sc(a) scanf("%d",&a)
#define scs(a) scanf("%s",a+1);
#define pri(a) printf("%d\n",a);
#define rep(a,b,c) for(a=b;a<c;a++) 
#define rrep(a,b,c) for(a=b;a>c;a--)  
#define vit vector<int > :: iterator
#define viit vector<ii > :: iterator
#define mp(a,b)  make_pair(a,b)
#define pb(a,b) a.push_back(b)
#define trv(it,v) for(it=v.begin();it!=v.end();it++)
#define F first
#define S second
#define all(v)	v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout);


int main()
{	
	read("input.in");
	write("output.out");
	int i,j,k,la,n,ta=0,t;
	
	cin>>t;
	string str1,str2;
	int a,b,c,d,e,f;
	while(t--)
	{	ta++;
		cin>>str1>>str2;
				
		
		int mindiff,xx,xy;
		mindiff=1e9;//xx=1e9;xy=1e9;
		
		
		if(str1.size()==1)
		{
		
		
			for(i=0;i<10;i++)
			{
			for(j=0;j<10;j++)
			{
				k=i;
				a=k%10;
				//k=k-c;
				
				d= j%10;
				if(str1[0]=='?'||str1[0]-'0'==a)
				{
							if(str2[0]=='?'||str2[0]-'0'==d)
							{
									//	cout<<"dsfs";
										if(mindiff>abs(j-i))
										{
											mindiff=abs(j-i);
											
											xx=i;xy=j;
										}		
										else if (mindiff==abs(j-i))
										{
											if(xx>i)
											{
												xx=i;
												xy=j;
											}
											else if(xx==i)
											{
												xy=min(xy,j);
											}
										}
									
								
							}
						
					
				}
			}
			}
			
		}
		
		if(str1.size()==2)
		{
			for(i=0;i<100;i++)
			{	
				for(j=0;j<100;j++)
				{
					k=i;
					a=k%10;
				//k=k-c;
				b=(k%100)/10;
				//k=
				
				d= j%10;
				e=(j%100)/10;
				if(str1[1]=='?'||str1[1]-'0'==a)
				{
					if(str1[0]=='?'||str1[0]-'0'==b)
					{
							if(str2[1]=='?'||str2[1]-'0'==d)
							{
								if(str2[0]=='?'||str2[0]-'0'==e)
								{
							//			cout<<"dsfs";
										if(mindiff>abs(j-i))
										{
											mindiff=abs(j-i);
											
											xx=i;xy=j;
										//	cout<<xx<<" "<<xy<<endl;	
										}		
										else if (mindiff==abs(j-i))
										{
											if(xx>i)
											{
												xx=i;
												xy=j;
											}
											else if(xx==i)
											{
												xy=min(xy,j);
											}
										}
									
								}
							}
						
					}
				}
			}
			}
		}
		
		for(i=0;i<1000;i++)
		{
			for(j=0;j<1000;j++)
			{
				k=i;
				a=k%10;
				//k=k-c;
				b=(k%100)/10;
				//k=
				c=(k%1000)/100;
				
				d= j%10;
				e=(j%100)/10;
				f=(j%1000)/100;
				if(str1[2]=='?'||str1[2]-'0'==a)
				{
					if(str1[1]=='?'||str1[1]-'0'==b)
					{
						if(str1[0]=='?'||str1[0]-'0'==c)
						{
							if(str2[2]=='?'||str2[2]-'0'==d)
							{
								if(str2[1]=='?'||str2[1]-'0'==e)
								{
									if(str2[0]=='?'||str2[0]-'0'==f)
									{
										//cout<<"dsfs";
										if(mindiff>abs(j-i))
										{
											mindiff=abs(j-i);
											
											xx=i;xy=j;
										//	cout<<xx<<" "<<xy<<endl;	
										}		
										else if (mindiff==abs(j-i))
										{
											if(xx>i)
											{
												xx=i;
												xy=j;
											}
											else if(xx==i)
											{
												xy=min(xy,j);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		a=xx%10;b=(xx%100)/10;c=(xx%1000)/100;
		d=xy%10;e=(xy%100)/10;f=(xy%1000)/100;
		cout<<"Case #"<<ta<<": ";
		
		if(str1.size()==1)
		cout<<a<<" "<<d<<endl;
		else if(str1.size()==2)
		cout<<b<<a<<" "<<e<<d<<endl;
		else
		cout<<c<<b<<a<<" "<<f<<e<<d<<endl;		
	}

	return 0;
}
