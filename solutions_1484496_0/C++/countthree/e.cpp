#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma pack(1)
using namespace std;

__int64 data[500];
__int64 sum[500];
char output[500];
bool found;
int n;

int sol(__int64 sum, int len){
    int p = 0; 
    __int64 temp = 0;
    while(p >= 0)
	{
        if('N' == output[p]){
            output[p] = 'Y';
            temp += data[p];
            if(temp == sum){
                return 1;
            }
            else if(temp > sum){
                output[p] = 'N';
                temp -= data[p];
            }
            p++;
        }
        if(p >= len)
		{
            while('Y' == output[p-1]){
                p--;
                output[p] = 'N';
                temp -= data[p];
                if(p < 1){
                    return 0;
                }
            }
            while('N' == output[p-1]){
                p--;
                if(p < 1){
                    return 0;
                }
            }
            output[p-1] = 'N';
            temp -= data[p-1];
        }
    }
    return 0;
}

int main()
{
	FILE *in = fopen("C:\\Users\\acer\\Desktop\\C-small-attempt1.in", "r");
	FILE *out = fopen("C:\\Users\\acer\\Desktop\\A-small-attempt0.out", "w");
	//in = stdin;
	//out = stdout;
	int T;
	fscanf(in, "%d", &T);
	for (int k = 1; k <= T; k++)
	{
		fscanf(in, "%d", &n);
		bool f = false;
		for (int i = 0; i < n; i++)
		{
			fscanf(in, "%lld", &data[i]);
		}

		//sort(data, data+n);
		
		for(int i = 0; i < n;i++)
		{
			if (i == 0)
				sum[i] = data[i];
			else
				sum[i] = sum[i-1] + data[i];
			output[i] = 'N';
		}
		
		for (int i = 1; i < n; i++)
		{
			if (sum[i] % 2 == 0)
			{
				if (sol(sum[i]/2, 1+i))
				{
					fprintf(out, "Case #%d: \n", k);
					__int64 sum1 = 0;
					__int64 sum2 = 0;					
					for (int j = 0; j <= i; j++)
					{
						
						if (output[j] == 'N')
						{
							fprintf(out, "%I64d ", data[j]);
							sum1+=data[j];
						}
					}
					cout << sum1 <<endl;
			
					fprintf(out, "\n");

					for (int j = 0; j <= i; j++)
					{
						if (output[j] == 'Y')
						{
							fprintf(out, "%I64d ", data[j]);
							sum2+=data[j];
						}						
					}
					cout << sum2 <<endl;
					fprintf(out, "\n");
					f = true;
					break;
				}
			}
		}
		if (!f)
			fprintf(out, "Case #%d: \nImpossible\n", k);
	}
}






