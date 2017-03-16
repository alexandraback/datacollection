/*
TASK: C
TASKNAME: Recycled Numbers
LANG: C++
NOTE: Google Code jam 2012
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <map>
#include <string>
using namespace std;
priority_queue <int> Q[2000005],tmp;
map <int,bool> passed;
char buffer[100];

int len(int num){ return (int)( log10((double)(num)))+1; }
void swap(char &a,char &b){ char tmp = a; a = b; b = tmp;}


void gen(){
    int now,ind,length;
    for(int i=1;i<=2000000;i++){
        now = i;
        length = len(i);sprintf(buffer,"%d",i);
        passed.clear();
        for(int j=1;j<=length-1;j++){
            do{
                for(int k=0;k<length-1;k++)    swap(buffer[k],buffer[k+1]);
                j++;
            }while(buffer[0] == '0');
            j--;
            if(j > length-1)   break;
            now = atoi(buffer);
            if(passed[now]==false && now!=i){
                Q[i].push(now);
                passed[now] = true;
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    gen();
    int n,a,b;
    long long int count = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        count = 0;
        for(int j=a;j<=b;j++){
            tmp = Q[j];
            while(tmp.size() >= 1 && tmp.top() > b)  tmp.pop();
            while(tmp.size() >= 1 && tmp.top() >= a && tmp.top() <= b){
                count++;
                tmp.pop();
            }
        }
        printf("Case #%d: %lld\n",i,count/2);
    }
    return 0;
}
