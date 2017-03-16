#include<cstdio>
#include<cstring>
using namespace std;
char name[1000001];
bool isconsonant(char x){
    return !(x=='a'||x=='e'||x=='i'||x=='o'||x=='u');
}
int main(){
    freopen("R1CQA.in","r",stdin);
    freopen("R1CQA.out","w",stdout);
    int numcases;
    scanf("%d",&numcases);
    for(int ccase=0;ccase<numcases;ccase++){
        int conseclen;
        scanf("%s%d",name,&conseclen);
        if(conseclen==0){
            printf("ERROR!\n");
            break;
        }
        int namelen=strlen(name);
        int cstart=0,numcon=0,numss=0;
        int prevok=0;
        for(int i=0;i<namelen;i++){
            bool cisconsonant=isconsonant(name[i]);
            if(numcon<conseclen){
                if(cisconsonant){
                    if(numcon==0) prevok=i;
                    numcon++;
                    if(numcon==conseclen){
                        //printf("~~%d %d\n",cstart,prevok);
                        while(cstart<prevok){
                            numss+=namelen-i;cstart++;
                        }
                        numss+=namelen-i;cstart++;
                        numcon--;
                        prevok++;
                    }
                }
                else{
                    numcon=0;
                }
            }
            //printf("%d\n",numss);
        }
        printf("Case #%d: %d\n",ccase+1,numss);
    }
    return 0;
}
