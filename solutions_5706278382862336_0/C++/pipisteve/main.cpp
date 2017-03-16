//
//  main.cpp
//  CPPLib
//
//  Created by MAC on 2014/5/11.
//  Copyright (c) 2014 Steve__. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <bitset>
#include <algorithm>
#include <numeric>
#include <map>
//#include <queue>


#define LOG(format,...)   printf(format, ##__VA_ARGS__);

FILE *rFptr;
FILE *wFptr;

using namespace std;

long long int c;
long long int p;
double two[40];

long long int GCD(long long int u, long long int v) {
    while ( v != 0) {
        long long int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

void answer()
{
    long long int result=0;
    long long int gcd =GCD(c,p);
    long long int small = p/gcd;
    long long int nc=c/gcd;
    long long int tmp=small;
    while(tmp%2==0)
    {
        tmp/=2;
        result++;
    }
    if(tmp==1)
    {
        for(long long int i=1;i<result;i++)
        {
            if( nc-(long long int)pow(2,result-i) >0)
            {
                result=i;
                break;
            }
        }
        fprintf(wFptr, "%llu",result );
    }
    else
    {
        fprintf(wFptr, "impossible" );
    }
    
}

int main(int argc, const char * argv[])
{
//    rFptr = fopen("./test.in", "r");
    wFptr = fopen("./output.txt", "w");
        rFptr = fopen("./A-small-attempt1.in", "r");
    //    rFptr = fopen("./A-large-practice.in", "r");
    
    if(!rFptr) {
        printf("ReadFile fails.\n");
        return 0;
    }
    
    int num=0;
    // getNumCases
    fscanf( rFptr, "%d%*c", &num );
    printf("N:%d\n", num );
    
//    for(int i=0;i<40;i++)
//    {
//       two[i] = (double)1.0/(double)pow(2,i+1);
//        LOG("%15lf ",two[i])
////        LOG("%lf ",pow(2,i+1))
//    }
//    LOG("\n")
    for(int i=0;i<num;i++)
    {
        fscanf( rFptr, "%llu%*c%llu", &c,&p );
        LOG("%llu %llu\n",c,p)
        fprintf( wFptr, "Case #%d: ", i+1 );
        answer();
        if( i != num -1 )
        {
            fprintf(wFptr, "\n" );
        }
    }
    
    //    LOG( "%llu\n", CNK_num(100, 40) )
    
    fclose(rFptr);
    return 0;
}
