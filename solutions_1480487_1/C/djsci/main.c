//
//  main.c
//  judge
//
//  Created by Dingjie Wang on 5/5/12.
//  Copyright 2012 asu. All rights reserved.
//

#include <stdio.h>

int main (int argc, const char * argv[])
{
    float s[200];
    FILE *in;
    FILE *out;
    in=fopen("/Users/dingjiewang/Desktop/coding/judge/A-large.in", "r");
    out=fopen("/Users/dingjiewang/Desktop/coding/judge/out.txt", "w");
    int i, cs;
    float n;
    int j;
    float n1;
    double ans[200];
    float sum;
    float sum1;
    fscanf(in, "%d", &cs);
    for(i=0;i<cs;i++){
        sum=0;
        for(j=0;j<200;j++){
            s[j]=0;
        }
        fscanf(in, "%f", &n);
        for(j=0;j<n;j++){
            fscanf(in, "%f", &s[j]);
        }
        for(j=0;j<n;j++){
            sum=sum+s[j];
        }
        for(j=0;j<n;j++){
            if(s[j]>2*sum/n){
                s[j]=200;
                ans[j]=0;
            }
        }
        sum1=0;
        n1=n;
        for(j=0;j<n;j++){
            if(s[j]!=200){
            sum1=sum1+s[j];
            }
            if(s[j]==200){
                n1--;
            }
        }
        for(j=0;j<n;j++){
            if(s[j]!=200){
            ans[j]=((sum1+sum)/n1-s[j])*100/sum;
            }
        }
        fprintf(out, "Case #%d: ", i+1);
        for(j=0;j<n;j++){
            fprintf(out, "%lf ",ans[j]);
        }
        fprintf(out, "\n");
    }
    fclose(in);
    fclose(out);
}

