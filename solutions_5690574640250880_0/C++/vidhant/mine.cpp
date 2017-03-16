#include <stdio.h>

FILE *fout=fopen("ans.txt","w");

long long int count=0;
int row,col;
int click[2];
bool printed;

bool backtrack;
int tester(int **arr,int r,int c);

void combinationUtil(int arrays[], int data[], int start, int end, int index, int r);
 

void printCombination(int arrays[], int n, int r)
{

    int data[r];
 
    
    combinationUtil(arrays, data, 0, n-1, 0, r);
}
 

void combinationUtil(int arrays[], int data[], int start, int end, int index, int r)
{
    
    if (index == r)
    {
        int **matrix,i,j;
		
		matrix=new int*[10];
		
		for(i=0;i<6;i++)
		{
			matrix[i]=new int[10];
			
			for(j=0;j<10;j++)
				matrix[i][j]=55;
		}
		int x;
		
		/*
		for (int j=0; j<r; j++)
            printf("%d ", data[j]);
        printf("\n");
		*/
		
		
		for (int j=0; j<r; j++)
		{
			x=data[j]-1;
			matrix[x/col][x%col]=-1;
		}
            //printf("%d ", data[j]);
        //printf("\n");
		
		/*printf("arraysangement--->\n");
		
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
				printf("%3d",matrix[i][j]);
			
			printf("\n");
		}
		*/
		
		if(tester(matrix,row,col))
		{
			printf("Solution exists if mines= %d!!\n",r);
			fprintf(fout,"%d %d %d 1\n",row,col,r);
			
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
				{
					if(matrix[i][j]==-1)
						fprintf(fout,"*");
					else if(i==click[0]&&j==click[1])
						fprintf(fout,"c");
					else
						fprintf(fout,".");
				}
			
				fprintf(fout,"\n");
			}
			
			backtrack=false;
			printed=true;
		}
		
		
		
		count++;
        return;
    }
 
   
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arrays[i];
        combinationUtil(arrays, data, i+1, end, index+1, r);
		if(backtrack==false)
			break;
    }
}
 

int main()
{
    int n,i,j,x;
	
	//scanf("%d %d",&row,&col);
	
	for(row=1;row<=5;row++)
	{
		for(col=1;col<=5;col++)
		{
			
		
	
	
			n=row*col;

			int *arrays=new int[n];

			for(i=0;i<n;i++)
				arrays[i]=i+1;


			for(i=0;i<=(n);i++)
			{
				count=0;
				backtrack=true;
				printed=false;
				int r = i;
				printf("Ways of placing %d mines\n",r);
				printCombination(arrays, n, r);
	
				if(printed==false)
				{
					fprintf(fout,"%d %d %d 0\n",row,col,r);
		
					for(x=0;x<row;x++)
					{
						for(j=0;j<col;j++)
						{
							//if(matrix[i][j]==-1)
							fprintf(fout,"*");
				
					
						}
		
						fprintf(fout,"\n");
					}
				}
	
				//printf("For placing %d mines, ways are %lld\n",r,count);
			}
		}
	}

	return 0;
}




/*
int r,c;
int arr[10][10];
*/
void check(int,int,int **,int,int);

int tester(int **arr,int r,int c)
{
	int ans[10][10]={0};
	int orig[10][10];
	int i,x,y,j;
	bool finally=false;
	
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			orig[i][j]=arr[i][j];
		}
		
	//click one by one and check
	
	for(i=0;i<r*c;i++)
	{
		//printf("Clicked at: %d, %d\n",i/c,i%c);
		
		for(x=0;x<r;x++)
			for(y=0;y<c;y++)
				arr[x][y]=orig[x][y];
		
		if(arr[i/c][i%c]==-1)
			continue;
		
		check(i/c,i%c,arr,r,c);
		
		bool res=true;
		
		for(x=0;x<r;x++)
			for(y=0;y<c;y++)
				if(arr[x][y]==55)
					res=false;
		
		ans[i/c][i%c]=res;

		if(res)
		{
			//printf("Solution exists for %d, %d\n",i/c,i%c);
			finally=true;
			click[0]=i/c;
			click[1]=i%c;
			break;
		}
		//printf("Click at %d, %d results in %d\n",i/c,i%c,ans[i/c][i%c]);
	}
	
	if(finally)
		return true;
	else
		return false;
	
	
	
	
}

void calc_mine(int i,int j,int** arr,int r,int c)
{
	int count=0;
	
	if(i-1>=0&&j-1>=0)		
		if(arr[i-1][j-1]==-1)
			count++;
	
	if(i-1>=0&&j>=0)
		if(arr[i-1][j]==-1)
			count++;
	
	if(i-1>=0&&j+1<c)
		if(arr[i-1][j+1]==-1)
			count++;
	
	if(j-1>=0)
		if(arr[i][j-1]==-1)
			count++;
	
	if(j+1<c)
		if(arr[i][j+1]==-1)
			count++;
	
	if(i+1<r&&j-1>=0)
		if(arr[i+1][j-1]==-1)
			count++;
	
	if(i+1<r)
		if(arr[i+1][j]==-1)
			count++;
	
	if(i+1<r&&j+1<c)
		if(arr[i+1][j+1]==-1)
			count++;
	
	arr[i][j]=count;
	
	
	
	
}

void check(int i,int j,int ** arr,int r,int c)
{
	calc_mine(i,j,arr,r,c);
	
	bool done[10][10]={0};
	
	//done[i][j]=true;
	
	while(1)
	{
		bool zero=false;
		
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(arr[i][j]==0&&done[i][j]==false)		//try to find a zero
				{
					zero=true;
					//printf("found a zero at %d, %d in for loop\n",i,j);
					break;
				}
			}
			if(zero==true)
				break;
		}
		
		if(zero==false)
			return;
		
		//zero found, reveal all neighbours of this one
		
		//printf("found a zero at %d, %d\n",i,j);
		
		int x;
		//scanf("%d",&x);
		
		if(i-1>=0&&j-1>=0)		
			calc_mine(i-1,j-1,arr,r,c);
	
		if(i-1>=0&&j>=0)
			calc_mine(i-1,j,arr,r,c);
	
		if(i-1>=0&&j+1<c)
			calc_mine(i-1,j+1,arr,r,c);
	
		if(j-1>=0)
			calc_mine(i,j-1,arr,r,c);
	
		if(j+1<c)
			calc_mine(i,j+1,arr,r,c);
	
		if(i+1<r&&j-1>=0)
			calc_mine(i+1,j-1,arr,r,c);
	
		if(i+1<r)
			calc_mine(i+1,j,arr,r,c);
	
		if(i+1<r&&j+1<c)
			calc_mine(i+1,j+1,arr,r,c);
		
		done[i][j]=true;
		
		int y;
		
		/*
		
		for(x=0;x<r;x++)
		{
			for(y=0;y<c;y++)
				printf("%3d",arr[x][y]);
			
			printf("\n");
		}
		*/
		
	}
	
	return;	
}
