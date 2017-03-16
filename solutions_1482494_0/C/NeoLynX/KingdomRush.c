#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input,*output;
    input=fopen("B-small-attempt2.in","r");
    output=fopen("output.in","w");
    
    int i, j, k, CASES, N, stars, flag, mov, max, maxx, flag2, pos;
    int lvl[10][3], lvls[10][3];
    
    fscanf(input,"%d\n",&CASES);
    
    for(i = 0; i < CASES; i++)
    {
        fscanf(input,"%d\n", &N);
        
        for(j = 0; j < N; j++)
        {
            fscanf(input,"%d %d\n", &lvl[j][0], &lvl[j][1]);
            lvl[j][2] = 0;
        }
        
        for(j = 0; j < N; j++)
        {
            flag2 = 0;
            for(k = 0; k < N; k++)
            {
                  if(flag2 == 0 && lvl[k][2] == 0) 
                  {                 
                      max = lvl[k][1];
                      maxx = lvl[k][0];
                      flag2 = 1;
                      pos = k;
                  }
                  if(flag2 == 1 && lvl[k][1] > max && lvl[k][2] == 0)
                  {
                      max = lvl[k][1];             
                      maxx = lvl[k][0];
                      pos = k;                      
                  }
            }
            lvls[j][0] = maxx;
            lvls[j][1] = max;
            lvls[j][2] = 0;
            lvl[pos][2] = 1;
        }
        
        stars = 0;
        flag = 1;
        mov = 0;
        
        while(stars < N*2 && flag == 1)
        {
            flag = 0;
            
            for(j = 0; j < N; j++)
            {
                if(lvls[j][1] <= stars && lvls[j][2] == 0)
                {
                     stars+=2;
                     lvls[j][2] = 2;
                     flag = 1;
                     mov++;
                     break;                     
                }              
            }
            
            if(flag == 1)
                    continue;
            
            for(j = 0; j < N; j++)
            {
                  if(lvls[j][2] == 1 && lvls[j][1] <= stars)
                  {
                      stars+=1;
                      lvls[j][2] = 2;
                      flag = 1;
                      mov++;
                      break;                      
                  }      
            
            }
            
            if(flag == 1)
                    continue;
            
            for(j = 0; j < N; j++)
            {
                  if(lvls[j][2] == 0 && lvls[j][0] <= stars)
                  {
                      stars+=1;
                      lvls[j][2] = 1;
                      flag = 1;
                      mov++;
                      break;                      
                  }
            }                                
        }
        
        if(flag == 0)
            fprintf(output,"Case #%d: Too Bad\n",i+1);
        else
            fprintf(output,"Case #%d: %d\n",i+1, mov);
    }
    
    fclose(input);
    fclose(output);
    
    return 0;   
}
