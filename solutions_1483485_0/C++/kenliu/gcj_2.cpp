#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define PI 3.141592653589793
#define DEBUG 0
#define INF 1000000007 

using namespace std;

int n;
int main(){
    char c;
    int i,j;
    string mp = "yhesocvxduiglbkrztnwjpfmaq";
    string s,res;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        while((c=getchar())!='\n'){
            s+=c;
        }
        //printf("t: %s\n", s.c_str());
        for(j=0;j<s.size();j++){
            char d = mp[s[j]];
            if(d!= ' ')
                res+=char(mp[s[j]-'a']);
            else res+= d;
        }
        printf("Case #%d: ",i+1);
        for(j=0;j<res.size();j++)
            if(res[j]<'a')printf(" ");
            else printf("%c",res[j]);
        printf("\n");
        res.clear();
        s.clear();
    }
    
    return 0;
}
