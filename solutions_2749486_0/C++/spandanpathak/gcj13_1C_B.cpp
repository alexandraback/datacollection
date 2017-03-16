#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

FILE *f1,*f2;

int main()
{
	int x,y,p,q;
	int i,j,l,n,t;		
		
	
	f1=fopen("B-small-attempt2.in","r+");
	f2=fopen("out.txt","w");
		
	fscanf(f1,"%d",&t);
	
	for(int tt=1;tt<=t;tt++)
	{
		fscanf(f1,"%d",&x);
		fscanf(f1,"%d",&y);
		
		
		p=q=0;
		
		vector<char> v;
		
		i=1;
		
		while(1)
		{
			if(p<x && p+i<=x)
			{
				if(1)
				{
/*					p-=i;
					v.push_back('W');
				}
				else
				{
*/					p+=i;
					v.push_back('E');
					i++;
				}	
				
			}
			else if(p>x && p-i>=x)
			{
				if(1)
				{
/*					p+=i;
					v.push_back('E');
				}
				else
				{
*/					p-=i;
					v.push_back('W');
					i++;
				}	
				
			}			
			else if(q<y && q+i<=y)
			{
				if(1)
				{
/*					q-=i;
					v.push_back('S');
				}
				else
				{
*/					q+=i;
					v.push_back('N');
					i++;
				}	

			}
			else if(q>y && q-i>=y)
			{
				if(1)
				{
/*					q+=i;
					v.push_back('N');
				}
				else
				{
*/					q-=i;
					v.push_back('S');
					i++;
				}	
				
			}
			else if(p<x)
			{
				p-=i;
				v.push_back('W');
				i++;
			}
			else if(p>x)
			{
				p+=i;
				v.push_back('E');				
				i++;
			}
			else if(q<y)
			{
				q-=i;
				v.push_back('S');
				i++;
			}
			else if(q>y)
			{
				q+=i;
				v.push_back('N');
				i++;
			}
			
			if( p==x && q==y ) break;			
			
//			cout<<p<<" "<<q<<endl;
		}
				
		fprintf(f2,"Case #%d: ",tt);
		
		if(v.size()>500) 
			cout<<"hi";
		
//		cout<<tt<<endl;
		for(i=0;i<v.size();i++)
			fprintf(f2,"%c",v[i]);
			
		fprintf(f2,"\n");
	}
	
	return 0;
}