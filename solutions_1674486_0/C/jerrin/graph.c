#include<stdio.h>
#include<stdlib.h>

int N;
int main_count=0;

struct linked_list  {
int vertex;
struct linked_list *adjacent[1000];
int count;
};

typedef struct linked_list node;
node *array[1000];

void dfs_visit(node *ptr, int vert)  {
	int i;

	if(ptr->vertex == vert)
		main_count++;
	
	for(i=0;i<(ptr->count);i++) 
				dfs_visit(ptr->adjacent[i], vert);	
}

int dfs()  {
	int i, j;
	
	int vertex1;
	for(i=0;i<N;i++)  {
		
		for(vertex1=1; vertex1<=N;vertex1++)  {
			main_count=0;
			
			if(vertex1!=array[i]->vertex) 
				dfs_visit(array[i], vertex1);
			
			if(main_count>=2)
				return 1;
		}
	}
	return 0;
}

node *search(int ch)  {
	node *temp;
	int i;
	for(i=0;i<N;i++)
		if(array[i]->vertex==ch)
			return(array[i]);

	return NULL;	
}

int main()  {

	int i,j, M, t, v, p;
	node *temp;

	int T;
	
	scanf("%d", &T);
	for(p=0;p<T;p++)  {
		
		printf("Case #%d: ", p+1);
		scanf("%d",&N);
		
		for(i=0;i<N;i++)	{
		
			array[i]=(node *)malloc(sizeof(node));
			array[i]->vertex=i+1;
			array[i]->count=0;
		}
		
		for(i=0;i<N;i++)	{
			
			scanf("%d", &M);
			array[i]->count=M;
			
			for(t=0;t<M;t++)  {
			
				scanf("%d",&v);
				temp=search(v);
				array[i]->adjacent[t]=temp;
			}
		}

		if(dfs())
			printf("Yes\n");
		else
			printf("No\n");
	}
	

return(0);
}
