#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

FILE *input;
FILE *output;

void inputf(void);
void process(int P, int Q);

int main(void)
{
    input=fopen("/Users/khhan1993/Downloads/A-small-attempt2.in","r");
    output=fopen("/Users/khhan1993/Downloads/output.out","w");
    
    int T;
    fscanf(input,"%d", &T);
    
    for(int i=0;i<T;i++)
    {
        fprintf(output,"Case #%d: ",i+1);
        inputf();
    }
    
    return 0;
}

void inputf(void)
{
    int P,Q;
    fscanf(input,"%d/%d", &P, &Q);
    
    process(P,Q);
}

void process(int P, int Q)
{
    int count=0;
    int result=-1;
    
    while(1)
    {
        if(count>40)
        {
            fprintf(output,"impossible\n");
            return;
        }
        
        if(P==Q)
        {
            if(result==-1)
                result=count;
            break;
        }
        
        if(P>=Q)
        {
            if(result==-1)
                result=count;
            
            P-=Q;
        }
        
        P=P<<1;
        count++;
    }
    
    fprintf(output,"%d\n",result);
}