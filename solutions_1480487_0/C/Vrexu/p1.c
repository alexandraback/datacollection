#include <stdio.h>
#include <stdlib.h>

#define FILE_IN "data.in"
#define FILE_OUT "data.out"

#define DEBUG 0

int main(int argc, char **argv)
{
        FILE *file_in, *file_out;
        unsigned char t;
        unsigned char n;
        unsigned char i;
        unsigned char j;
        unsigned char count;
        unsigned char mark[200];
        unsigned char eliminated[200];
        unsigned char is_eliminated;
        float sum, avg, ans, sum2;

        if(!(file_in = fopen(FILE_IN, "r")))
                return -1;

        if(!(file_out = fopen(FILE_OUT, "w")))
                return -1;

        fscanf(file_in, "%hhu", &t);
        for(i = 1; i <= t; i++)
        {
                sum = 0;
                fprintf(file_out, "Case #%hhu:", i);

                fscanf(file_in, "%hhu", &n);
                for(j = 0; j < n; j++)
                {
                        fscanf(file_in, "%hhu", mark + j);
                        sum += mark[j];
                }
                sum2 = sum;
                avg = (sum + sum2) / n;

                for(j = 0; j < n; j++)
                {
                        eliminated[j] = 0;
                }

                // fprintf(file_out, " x%hhu", n);
                is_eliminated = 1;
                while(is_eliminated)
                {
                        is_eliminated = 0;
                        count = 0;
                        for(j = 0; j < n; j++)
                                if(!eliminated[j])
                                {
                                        ans = (avg - mark[j]) * 100 / sum;
                                        if(ans < 0)
                                        {
                                                eliminated[j] = 1;
                                                is_eliminated = 1;
                                                sum2 -= mark[j];
                                        }
                                        else
                                                count++;
                                }
                        avg = (sum + sum2) / count;
                }
                // fprintf(file_out, " y%hhu", count);

                for(j = 0; j < n; j++)
                {
                        if(eliminated[j])
                                ans = 0;
                        else
                                ans = (avg - mark[j]) * 100 / sum;

                        fprintf(file_out, " %f", ans);
                }

                fprintf(file_out, "\n");
        }


        fclose(file_in);
        fclose(file_out);

        return 0;
}

