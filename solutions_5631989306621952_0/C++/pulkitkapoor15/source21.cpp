#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	int t,testCases,i,para,num2,num1;
	cin>>t;
	for(testCases=1;testCases<=t;testCases++)
	{
		char antl[5000];
		scanf("%s",&antl);
		char para;
		para=antl[0];
		char anss[5000];
		num1=2000;
		num2=2001;
		anss[num1--]=para;
		
		for(i=1;antl[i]!='\0';i++)
	    {
	    	if(antl[i]>=para)
	    	{
	    		para=antl[i];
	    			anss[num1--]=para;
			}
		    else
		    {
		    	anss[num2++]=antl[i];
			}
		}
        cout<<"Case #"<<testCases<<": ";
		for(i=num1+1;i<num2;i++)
		{
			cout<<anss[i];
		}
		cout<<endl;
	}
}