/*
TASK: B
TASKNAME: Dancing With the Googlers
LANG: C++
NOTE: Google Code jam 2012
*/
#include <cstdio>
int n,s,p,t[105],count,counts;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int T;  scanf("%d",&T);
    for(int _i=1;_i<=T;_i++){
        scanf("%d %d %d",&n,&s,&p);
        count = 0;counts = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&t[i]);
            if(t[i]%3!= 0 && t[i]/3 + 1 >= p)  {count++; continue;}
            else if(t[i]%3 == 0 && t[i]/3 >= p){count++; continue;}
            if(counts < s){
                if((t[i]-2)%3 == 0){
                    if( ((t[i]-2)/3 >= 0) && ((t[i]-2)/3+2 >= p) && ((t[i]-2)/3+2 <= 10)){count++; counts++;}
                }else if((t[i]-3)%3 == 0){
                    if( ((t[i]-3)/3 >= 0) && ((t[i]-3)/3+2 >= p) && ((t[i]-3)/3+2 <= 10)){count++; counts++;}
                }else if((t[i]-4)%3 == 0){
                    if( ((t[i]-4)/3 >= 0) && ((t[i]-4)/3+2 >= p) && ((t[i]-4)/3+2 <= 10)){count++; counts++;}
                }
            }
        }
        printf("Case #%d: %d\n",_i,count);
    }
    return 0;
}
