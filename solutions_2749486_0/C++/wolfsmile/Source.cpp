#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
string solve(int x, int y);
int main()
{
    int T,Case;
	FILE *in,*out;
	int x, y;
	string nvalue;
	//int num, nvalue;
	in = fopen("B-small-attempt0.in","r");
	out = fopen("out.txt","w");

    fscanf(in,"%d\n",&T);
    Case = 1;
    while(Case<=T)
    {
		//total = 0;
		//target = 0;
		fscanf(in,"%d %d\n",&x,&y);
		nvalue = solve(x, y);
//		nvalue+="news\n";
		fprintf(out,"Case #%d: %s",Case, nvalue.c_str());
		Case++;
    }

    return 0;
}
string solve(int x, int y){
    string result;
    string x1("WE");
    string x2("EW");
    string y1("SN");
    string y2("NS");
    int i;
    if(x>0)
        for(i=0;i<x;++i){
			result+=x1;
		//	result+='E';
		}
    else if(x<0)
        for(i=0;i<(-x);++i){
            result += x2;
	//		result += 'W';

		}
    if(y>0)
        for(i=0;i<y;++i){
            result+=y1;
	//		result+= 'N';
		}
    else if(y<0)
        for(i=0;i<(-y);++i){
            result += y2;
//			result += 'S';
		}
	result+='\n';
    return result;
}

