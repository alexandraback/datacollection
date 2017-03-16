#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    int t,count,result;
    char str[101],x;
    vector<int> seq;
    bool negStart;
    int res[101];
    res[0]=0;
    res[1]=0;
    res[2]=2;
    for(int i=3;i<=100;i++){
        if(i%2==1) res[i]=res[i-1];
        else{
            res[i]=res[i-2]+2;
        }
    }
    scanf("%d ",&t);
    for(int tc=0;tc<t;tc++){
        scanf("%s ",str);
        int length = strlen(str);
        negStart=(str[0]=='-');
        result=0;
        int i=0;
        if(negStart){
            result++;
            while(i<length && str[i]=='-'){
                i++;
            }
        }
        count=0;
        for(;i<length;i++){
            x=str[i];
            count++;
            while(i+1<length && str[i+1]==x){
                i++;
            }
        }
        result+=res[count];
        printf("Case #%d: %d\n",tc+1,result);
    }
}
