#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
char a[100];
map<char,char> m;
char in1,in2;
int nub;
bool mark;
int main()
{
        FILE *p = fopen("in1.txt","r");
        FILE *p2 = fopen("in2.txt","r");
        FILE *p3 = fopen("in3.txt","r");
        FILE *p4 = fopen("out.txt","w");
        while(fscanf(p,"%c",&in1)!=EOF) {
                fscanf(p2,"%c",&in2);
                m[in1]=in2;
        }
        m['q']='z';
        m['z']='q';
        int n;
        fscanf(p3,"%d",&n);
        fscanf(p3,"%c",&in1);
        nub++;
        while(fscanf(p3,"%c",&in1)!=EOF) {
                if(in1=='\n') {
                        mark=0;
                        nub++;
                        fprintf(p4,"\n");
                }
                else {
                        if(mark) {
                                fprintf(p4,"%c",m[in1]);
                        }
                        else {
                                fprintf(p4,"Case #%d: %c",nub,m[in1]);
                                mark=1;
                        }
                }
        }
        //system("pause");
}
