#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[1000];
int sumarray[2000005];
main()
{
    FILE *fin = fopen("C.in","r");
    FILE *fout = fopen("B.out","w");
    int t,n,OK=0;
    fscanf(fin,"%d",&t);
    for(int ll=0;ll<t;ll++)
    {
        for(int i=0;i<=2000000;i++) sumarray[i]=0;
        fscanf(fin,"%d",&n);
        for(int i=0;i<n;i++) fscanf(fin,"%d",&a[i]);
        //sort(a,a+n);
    
	
	for (int i = 0; i < (1 << 20); i++) {
        int sum = 0; 
        for (int j = 0; j < 20; j++) {
            if ((i >> j) & 1) sum += a[j];
        }
        if (sumarray[sum] == 0) sumarray[sum] = i;
        else
        {
            OK=1;
            fprintf(fout,"Case #%d:\n",ll+1);
            for(int j=0;j<20;j++) if((i >> j) & 1) fprintf(fout,"%d ",a[j]);
            fprintf(fout,"\n");
            for(int j=0;j<20;j++) if((sumarray[sum] >> j) & 1) fprintf(fout,"%d ",a[j]);
            fprintf(fout,"\n");
            break;
        }
    }
    if(OK==0) fprintf(fout,"Case #%d:\nImpossible\n");
}
	

    
    
    //scanf(" ");
}
