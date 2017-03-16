#include <cstdio>

void read(int& a){ scanf("%d",&a); }

char data[110];

void work(){
    scanf("%s",data);
    int i;
    int gcnt=0;
    char last=-1;
    for(i=0;data[i];++i){
        if(last != data[i]){
            ++gcnt;
            last = data[i];
        }
    }
    printf("%d\n",gcnt-1 + (data[i-1]=='-'));
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    read(t);
    for(int tc=1;tc<=t;++tc){
        printf("Case #%d: ",tc); work();
    }
    return 0;
}
