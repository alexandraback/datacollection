# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<math.h>
# define PI 3.14159265358979323846
# define N 105

FILE *input,*output;
int compare1(const void *a,const void *b )
{
	return *(int*)a - *(int*)b;
}
typedef struct abc
{
	int x,y;
	char c;
	int parent;
	int flag;
}node;



node b[500000];
int visited [2000][2000];

void print(int start)
{
	if(start ==0) return;
	print(b[start].parent);
	fprintf(output,"%c",b[start].c);

}
int main()
{
	int T,t;
	
    int x,y,start,end;
   
    
	input  = fopen("B-small-attempt2.in","r");
	output = fopen("output.txt","w");
	fscanf(input,"%d",&T);
	
	
	
	for(t=1;t<=T;t++)
	{
		
		
		
		fprintf(output,"Case #%d: ",t);
		fscanf(input,"%d%d",&x,&y);
		
		
		memset(visited, 0, sizeof(visited[0][0]) * 2000 * 2000);
		
		b[0].x = 0;
		b[0].y = 0;
		b[0].flag = 1;
		b[0].parent =0;
		visited[N][N] = 1;
		
		b[1].x = 0;
		b[1].y =0;
		b[1].parent =  -1;
		
		start = 0;
		end = 1;
		int step = 1;
		while(!(b[start].x == x && b[start].y == y))
		{
			
			if(b[start].parent == -1)
			{
				
				step++;
				end++;
				b[end].x = 0;
				b[end].y =0;
				b[end].parent =  -1;
				
				
			}
			else
			{			
			if(!visited[N+b[start].x+step][N+b[start].y])
			{
				end++;
				b[end].x = b[start].x+step;
				b[end].y = b[start].y;
				b[end].parent = start;
				b[end].c = 'E';
				visited[N+b[start].x+step][N+b[start].y] = 1;
				
			}
			
			if(!visited[N+b[start].x-step][N+b[start].y])
			{
				end++;
				b[end].x = b[start].x-step;
				b[end].y = b[start].y;
				b[end].parent = start;
				b[end].c = 'W';
				visited[N+b[start].x-step][N+b[start].y] = 1;
			}
			
			if(!visited[N+b[start].x][N+b[start].y+step])
			{
				end++;
				b[end].x = b[start].x;
				b[end].y = b[start].y+step;
				b[end].parent = start;
				b[end].c = 'N';
				visited[N+b[start].x][N+b[start].y+step] =1;
			}
			
			if(!visited[N+b[start].x][N+b[start].y-step])
			{
				end++;
				b[end].x = b[start].x;
				b[end].y = b[start].y-step;
				b[end].parent = start;
				b[end].c = 'S';
				visited[N+b[start].x][N+b[start].y-step]=1;
				
			}
			
			}
			
			
			
			
			
			start++;
			
	
			
		}
		/*printf("%d %d\n",b[start].x,b[start].y);
		
		printf("%d %d",start,end);
		getchar();
		
			for(int i=0;i<=end;i++)
			{
				printf("%d %d %d %d\n",i,b[i].x,b[i].y,b[i].parent);
				if(b[i].x==0 && b[i].y==0)
					getchar();
			}	
		
		
	*/	
		print(start);
	
	
		
		
			
		fprintf(output,"\n");
	
	}
return 0;	
}



