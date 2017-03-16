#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

char input[2001];
int abcd[26];

vector<string> data;
vector<int> ret;


int main(){

    FILE *inf, *outf;
    inf=fopen("A-large.in","r");
    outf=fopen("A-large-result.in","w");
    
    int T,N;
    
    fscanf(inf,"%d",&T);
    for(int i=0;i<T;i++){
        ret.clear();
        memset(abcd,0,sizeof(abcd));
        fscanf(inf,"%s",input);

        for(int j=0;j<strlen(input);j++){
            abcd[input[j]-'A']++;
        }
        for(int j=0;j<abcd[25];j++){
            ret.push_back(0);
        }
        abcd[4]-=abcd[25];
        abcd[14]-=abcd[25];
        abcd[17]-=abcd[25];
        abcd[25]=0;
        for(int j=0;j<abcd[22];j++){
            ret.push_back(2);
        }
        abcd[19]-=abcd[22];
        abcd[14]-=abcd[22];
        abcd[22]=0;
        for(int j=0;j<abcd[20];j++){
            ret.push_back(4);
        }
        abcd[5]-=abcd[20];
        abcd[14]-=abcd[20];
        abcd[17]-=abcd[20];
        abcd[20]=0;
        for(int j=0;j<abcd[23];j++){
            ret.push_back(6);
        }
        abcd[18]-=abcd[23];
        abcd[8]-=abcd[23];
        abcd[23]=0;
        for(int j=0;j<abcd[6];j++){
            ret.push_back(8);
        }
        abcd[4]-=abcd[6];
        abcd[8]-=abcd[6];
        abcd[7]-=abcd[6];
        abcd[19]-=abcd[6];
        abcd[6]=0;
        for(int j=0;j<abcd[7];j++){
            ret.push_back(3);
        }
        abcd[19]-=abcd[7];
        abcd[17]-=abcd[7];
        abcd[4]-=abcd[7];
        abcd[4]-=abcd[7];
        abcd[7]=0;
        for(int j=0;j<abcd[14];j++){
            ret.push_back(1);
        }
        abcd[4]-=abcd[14];
        abcd[13]-=abcd[14];
        abcd[14]=0;
        for(int j=0;j<abcd[5];j++){
            ret.push_back(5);
        }
        abcd[8]-=abcd[5];
        abcd[21]-=abcd[5];
        abcd[4]-=abcd[5];
        abcd[5]=0;
        for(int j=0;j<abcd[21];j++){
            ret.push_back(7);
        }
        abcd[18]-=abcd[21];
        abcd[4]-=abcd[21];
        abcd[4]-=abcd[21];
        abcd[13]-=abcd[21];
        abcd[21]=0;
        for(int j=0;j<abcd[8];j++){
            ret.push_back(9);
        }
        abcd[13]-=abcd[8];
        abcd[13]-=abcd[8];
        abcd[4]-=abcd[8];
        abcd[8]=0;

        sort(ret.begin(),ret.end());

        fprintf(outf,"Case #%d: ",i+1);
        for(int j=0;j<ret.size();j++){
            fprintf(outf,"%d",ret[j]);
        }
        fprintf(outf,"\n");
            
    }
//    getchar();
}