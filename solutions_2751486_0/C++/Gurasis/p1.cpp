#include<iostream>
#include<string.h>
using namespace std;




int main()
	{int m,t,r,n,l;
	char a[100000];
	cin>>t;
	for(m=0;m<t;m++)
		{cin>>a;
		cin>>n;
		int tp=-1;
		
	int len=strlen(a);
	int i=0;
	int cal=0,te=0;
	for(i=0;i<len;i++)
		{if(a[i]!='a'&&a[i]!='e'&&a[i]!='u'&&a[i]!='i'&&a[i]!='o')
			{int j=i;
			te=0;
			while(te<n)
				{if(j>len-1) break;
				else if(a[j]!='a'&&a[j]!='e'&&a[j]!='u'&&a[j]!='i'&&a[j]!='o'&&a[j]!='\0')
						{j++;te++;
						}
				else {break;}								
				}
			if(te==n)
				{int b=i-tp-1;
				j=j-1;
				int af=len-1-j;
			
			cal=cal+(b+af+ af*b) +1;
				
				tp=i;				
				}
			

			}
		
		}
	
		cout<<"Case #"<<m+1<<": "<<cal<<endl;		

		}

		
	}


