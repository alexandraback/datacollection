#include <stdio.h>
#include <vector>

int main()
{
    FILE * pFile = fopen("C-small-attempt2.in", "r");
	FILE * pFile2 = fopen("C-small-attempt2.out", "w");
	int T;
	fscanf(pFile, "%d", &T);
	for(int t = 0; t < T; t++)
	{
		int R, C, M;
		fscanf(pFile, "%d %d %d", &R, &C, &M);

		//Build snake shape
		int r2 = R, c2 = C, m2 = M;
		while(true){
			if(r2 > c2)
			{
				if(r2 > 2 && m2 >= c2)
				{
					r2--;
					m2 -= c2;
				}
				else if(c2 > 2 && m2 >= r2)
				{
					c2--;
					m2 -= r2;
				}
				else
					break;
			}
			else
			{
				if(c2 > 2 && m2 >= r2)
				{
					c2--;
					m2 -= r2;
				}
				else if(r2 > 2 && m2 >= c2)
				{
					r2--;
					m2 -= c2;
				}
				else
					break;
			}
		}
		if(m2 == 0)
		{
			fprintf(pFile2,"Case #%d:\n", t+1);
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
				{
					if(i < r2 && j < c2)
					{
						if(i == 0 && j == 0)
							fprintf(pFile2,"c");
						else
							fprintf(pFile2,".");
					}
					else
						fprintf(pFile2,"*");
				}
				fprintf(pFile2,"\n");
			}
		}
		else if(r2 == 1)
		{
			fprintf(pFile2,"Case #%d:\n", t+1);
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
				{
					if(i == 0)
					{
						if(j == 0)
							fprintf(pFile2,"c");
						else if(j < c2-m2)
							fprintf(pFile2,".");
						else
							fprintf(pFile2,"*");
					}
					else
						fprintf(pFile2,"*");
				}
				fprintf(pFile2,"\n");
			}
		}
		else if(c2 == 1)
		{
			fprintf(pFile2,"Case #%d:\n", t+1);
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
				{
					if(j == 0)
					{
						if(i == 0)
							fprintf(pFile2,"c");
						else if(i < r2-m2)
							fprintf(pFile2,".");
						else
							fprintf(pFile2,"*");
					}
					else
						fprintf(pFile2,"*");
				}
				fprintf(pFile2,"\n");
			}
		}
		else{
			//r2 >= 2, c2 >= 2, m2 >= 1

			bool *map = new bool[r2*c2];//true for mine
			bool *iszero = new bool[r2*c2];
			for(int i = 0; i < r2*c2; i++){
				map[i] = false;
				iszero[i] = true;
			}
			map[r2*c2-1] = true;
			m2--;
			int k = 1;
			while(m2 > 0){
				if(r2 > c2)
				{
					//col first		
					if(m2 > 0){
						//(r2-1-k, c2-1)
						map[c2*(r2-1-k)+c2-1] = true;
						m2--;
					}
					if(m2 > 0){
						//(r2-1, c2-1-k)
						map[c2*(r2-1)+(c2-1-k)] = true;
						m2--;
					}		
				}
				else{
					if(m2 > 0){
						//(r2-1, c2-1-k)
						map[c2*(r2-1)+(c2-1-k)] = true;
						m2--;
					}						
					if(m2 > 0){
						//(r2-1-k, c2-1)
						map[c2*(r2-1-k)+c2-1] = true;
						m2--;
					}	
				}
				k++;
			}
			if(r2 < R)
			{
				for(int x = 0; x < c2; x++)
					iszero[c2*(r2-1)+x] = false;
			}
			for(int x = 0; x < c2; x++)
				if(map[c2*(r2-1)+x])
				{
					iszero[c2*(r2-2)+x] = false;
					if(x > 0)
					{
						iszero[c2*(r2-2)+x-1] = false;
						iszero[c2*(r2-1)+x-1] = false;
					}
				}
			if(c2 < C)
			{
				for(int y = 0; y < r2; y++)
					iszero[c2*y+(c2-1)] = false;
			}
			for(int y = 0; y < r2; y++)
				if(map[c2*y+c2-1])
				{
					iszero[c2*y+c2-2] = false;
					if(y > 0)
					{
						iszero[c2*(y-1)+c2-2] = false;
						iszero[c2*(y-1)+c2-1] = false;
					}
				}
			int count_unreachable = 0;
			for(int y = 0; y < r2; y++)
				for(int x = 0; x < c2; x++)
					if(!map[c2*y+x] && !iszero[c2*y+x])
					{
						bool flag = false;
						if(y > 0 && iszero[c2*(y-1)+x])
							flag = true;
						else if(x > 0 && iszero[c2*y+x-1])
							flag = true;
						else if(x>0 && y>0 && iszero[c2*(y-1)+(x-1)])
							flag = true;
						if(!flag)
							count_unreachable++;
					}
			if((iszero[0] && count_unreachable > 0) || (!iszero[0] && count_unreachable > 1))
				fprintf(pFile2,"Case #%d:\nImpossible\n", t+1);
			else{
				fprintf(pFile2,"Case #%d:\n", t+1);
				for(int i = 0; i < R; i++)
				{
					for(int j = 0; j < C; j++)
					{
						if(i < r2 && j < c2)
						{
							if(i == 0 && j == 0)
								fprintf(pFile2,"c");
							else
							{
								if(map[c2*i+j])
									fprintf(pFile2,"*");
								else
									fprintf(pFile2,".");
							}
						}
						else
							fprintf(pFile2,"*");
					}
					fprintf(pFile2,"\n");
				}
			}
			delete []map;
			delete []iszero;
		}
	}
	fclose(pFile);
	fclose(pFile2);
	return 0;
}