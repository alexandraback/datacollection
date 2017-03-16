#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	char arr[200],str[150],temp,ans[100][150];
	
	int t,i=1,j,k;
	
	arr['y']='a';
	arr['n']='b';
	arr['f']='c';
	arr['i']='d';
	arr['c']='e';
	arr['w']='f';
	arr['l']='g';
	arr['b']='h';
	arr['k']='i';
	arr['u']='j';
	arr['o']='k';
	arr['m']='l';
	arr['x']='m';
	arr['s']='n';
	arr['e']='o';
	arr['v']='p';
	arr['z']='q';
	arr['p']='r';
	arr['d']='s';
	arr['r']='t';
	arr['j']='u';
	arr['g']='v';
	arr['t']='w';
	arr['h']='x';
	arr['a']='y';
	arr['q']='z';
	arr[' ']=' ';
	
	scanf("%d",&t);	
	
	scanf("%c",&temp);
	
	while(i<=t)
	{
		k=-1;
		
		do
		{
			k++;	
				
			scanf("%c",&str[k]);
		
		}while(str[k]!='\n');
		
		str[k]='\0';
		
		cout << "Case #";
		cout<<i;
		cout<<": ";
		
		for(j=0;str[j]!='\0';j++)
		{
			//ans[i][j]=arr[str[j]];
			cout<<arr[str[j]];
		}
		
		cout<<endl;
		
		i++;
	}
	
	/*i=1;
	
	while(i<=t)
	{
		cout << "Case #";
		cout<<i;
		cout<<": ";
		if(i<t)
		cout<<ans[i]<<endl;
		else
		cout<<ans[i];
		i++;
	}	
*/
	return 0;
}
