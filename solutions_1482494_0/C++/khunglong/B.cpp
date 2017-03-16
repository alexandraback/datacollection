#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

#define file_in "B-small-attempt0.in"
#define file_out "B.out"

int test, n;          /* # of test case */
int a[1001];
int b[1001];
int c[1001];
FILE *fi;
FILE *fo;

bool finishgame()
{
	int j;
	for (j=0; j<n; j++)
	{
		if (c[j]<2) return false;
	}
	return true;
}

int main() {
    int i, j, ma, pos, star, play;
    bool flag;
    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");

    fscanf(fi, "%d", &test);
    //scanf("%d", &test);
    for (i=1; i<=test; i++)
    {
        fscanf(fi, "%d", &n);
        ma = -1;
        pos = -1;
		for (j=0; j<n; j++)
        {
            fscanf(fi, "%d %d", &a[j], &b[j]);
            c[j] = 0;
            if (b[j]==0)
            {
				pos=j;
				ma = 5000;
            }
            else if ((a[j]==0)&&(b[j]>ma))
            	{
					pos = j;
					ma = b[j];
            	}
        }
		
		if (pos<0)
		{
            fprintf(fo, "Case #%d: Too Bad\n", i);
            continue;   //next test
		}
		
		if (b[pos]==0) c[pos] = 2;  else c[pos]=1;
		star = c[pos];
		play = 1;
		//cout<<test<<" "<<pos<<" "<<star;
		//getch();
		
		while (!finishgame())
		{
			//neu co game nao finish dc 2 sao thi finish
			flag = false;
            for (j=0; j<n; j++)
			{
				if ((b[j]<=star)&&(c[j]<2))
				{
					star += (2-c[j]);
					c[j] = 2;
					play++;
					flag = true;
					break;
					//continue while
				}
			}
			
			if (flag) continue;
			
			//an 1 sao
			ma = -1;
			pos = -1;
			for (j=0; j<n; j++)
			{
				if ((a[j]<=star)&&(c[j]==0))
				{
					if (b[j]>ma)
					{
						ma = b[j];
						pos = j;
					}
				}
			}
			
			if (pos<0)
			{
                fprintf(fo, "Case #%d: Too Bad\n", i);
            	break;
			}
			else
			{
				play++;
				star++;
				c[pos]=1;
			}
		}
		
		if (finishgame()) fprintf(fo, "Case #%d: %d\n", i, play);
          
    }
    fclose(fi);
    fclose(fo);
}


