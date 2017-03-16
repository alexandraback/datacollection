#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	FILE* in;
	FILE* out;
	in = fopen("b.in","r");
	out = fopen("output.txt","w+");
	//in = stdin;
	//out=stdout;
	int cases =0;
	fscanf(in,"%d",&cases);
	for(int c =0;c<cases;c++)
	{
		int numNode = 0;
		fscanf(in,"%d",&numNode);
		bool** arr = new bool*[numNode];
		for(int i=0;i<numNode;i++)
		{
			arr[i]= new bool[numNode];
			for(int j=0;j<numNode;j++)
			{
				arr[i][j]=false;
			}
		}
		for(int i=0;i<numNode;i++)
		{
			int con =0;
			fscanf(in,"%d",&con);
			for(int j=0;j<con;j++)
			{
				int val =0;
				fscanf(in,"%d",&val);
				val--;
				if(val >=0){
					arr[i][val]=true;
					//printf("i%d val%d\n",i,val);
				}
			}
		}
		bool found = false;
		for(int i =0;i<numNode && found == false;i++)
		{
			bool* visited = new bool[numNode];
			for(int ii =0;ii<numNode;ii++)
			{
				visited[ii]=false;
			}
			
			stack<int> s;
			s.push(i);
			//printf("new push %d\n",i);
			visited[i]=true;
			while(s.empty()== false && found == false)
			{
				int n = s.top();
				s.pop();
				
				for(int k =0;k<numNode;k++)
				{
					if(arr[n][k]==true && visited[k]==true)
					{
						found = true;
					}
					if(arr[n][k]==true && visited[k]==false)
					{
						s.push(k);
						//printf("push %d\n",k);
						visited[k]=true;
					}
				}
				
			}
		}
		if(found == true)
			fprintf(out,"Case #%d: Yes\n",c+1);
		else
			fprintf(out,"Case #%d: No\n",c+1);
	}
}
