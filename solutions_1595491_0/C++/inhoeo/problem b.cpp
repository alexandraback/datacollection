#include <stdio.h>
#define MAX 100
#define TRIPLET 3
typedef struct {
	int n;
	int s;
	int p;
	int result;
	int arr[MAX];
}a;
a googler[MAX];
int t;

void f_in(FILE *in)
{
	int i=0, j=0;
	in=fopen("B-small-attempt0.in", "r");
	fscanf(in, "%d", &t);
	for(i=0; i<t; i++)
	{
		fscanf(in, "%d %d %d", &googler[i].n, &googler[i].s, &googler[i].p);
		for(j=0; j<googler[i].n; j++)
		{
			fscanf(in, "%d", &googler[i].arr[j]);
		}
	}
}
void sort(int index)
{
	int i=0, j=0, temp=0, high=0;
	high=((googler[index].p-1)*TRIPLET+1);
	for(i=0; i<googler[index].n; i++)
	{
		if(googler[index].arr[i]>=high)
		{
			googler[index].result++;
			googler[index].arr[i]=0;
		}
	}
	for(i=0; i<googler[index].n-1; i++)
	{
		for(j=i+1; j<googler[index].n; j++)
		{
			if(googler[index].arr[i]<googler[index].arr[j])
			{
				temp=googler[index].arr[i];
				googler[index].arr[i]=googler[index].arr[j];
				googler[index].arr[j]=temp;
			}
		}
	}
	googler[index].n-=googler[index].result;
}
void analysis(int index)
{
	int i=0, j=0, going=0, total=0;
	if(googler[index].s>=googler[index].n)
	{
		going=googler[index].n;
	}
	else
	{
		going=googler[index].s;
	}
	for(i=0; i<going; i++)
	{
		if(googler[index].arr[i]==0)
		{
			if(googler[index].p==0)
			{
				googler[index].result++;
			}
		}
		else if(googler[index].arr[i]%TRIPLET==0 || googler[index].arr[i]%TRIPLET==1)
		{
			total=(googler[index].arr[i]/TRIPLET)+1;
			if(total>=googler[index].p)
			{
				googler[index].result++;
			}
		}
		else if(googler[index].arr[i]%TRIPLET==2)
		{
			total=(googler[index].arr[i]/TRIPLET)+2;
			if(total>=googler[index].p)
			{
				googler[index].result++;
			}
		}
	}
}
void f_out(FILE *out)
{
	int i=0;
	out=fopen("output.out", "w");
	for(i=0; i<t; i++)
	{
		fprintf(out, "Case #%d: %d\n", i+1, googler[i].result); 
	}

}
int main(void)
{
	int i=0;
	FILE *in=0, *out=0;
	f_in(in);
	for(i=0; i<t; i++)
	{
		sort(i);
		analysis(i);
	}
	f_out(out);
	return 0;
}