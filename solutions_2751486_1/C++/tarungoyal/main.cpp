/* 
 * File:   main.cpp
 * Author: tarungoyal
 *
 * Created on May 12, 2013, 2:40 PM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

typedef unsigned long long ulint;
/*
 * 
 */


bool isCons(char a)
{
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return 0;
    return 1;
}
int main(int argc, char** argv) {
    
    FILE *fin = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","w");
    int t;
    fscanf(fin,"%d",&t);
    for(int I=1;I<=t;I++)
    {
        ulint len;
        char *s = new char[1000010];
        fscanf(fin,"%s",s);
        len = (ulint) strlen(s);
        int n;
        fscanf(fin,"%d",&n);
        ulint lenx = len+(ulint)1 -(ulint)n;
        ulint total = (lenx*(lenx+(ulint)1))/2; 
        int prev = 0;
        for(int i=0;i<len;i++)
        {
            int j = 0;
            for(;isCons(s[i+j])&&(i+j)<len;j++)
            {
                
            }
            if(j>=n)
            {
                cout<<"i : "<<i<<" j:"<<j<<" n: "<<n<<" prev:"<<prev<<" ";
                ulint x = (ulint) (i-prev);
                total -= (x*(x+1))/2;
                prev = i+j-n+1;
                int common = 2*n-2-j;
//                if(common< 0 ) common = 0;
//                else {total+=(common*(common+1))/2;}
                i = prev;
                cout<<I<<" "<<x<<" "<<common<<" "<<prev<<endl;
            }
            else i=i+j;
        }
        ulint sub = (ulint) (len-prev-n+1);
        total-=(sub*(sub+1))/2;
        fprintf(fout,"Case #%d: %llu\n",I,total);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
