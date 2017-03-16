#include <cstdio>
int numDigits,numCases,lowBound,upBound,lastDigit,nonUniqueNum;
int tempChange,ans;
int pow10[10];
int nonUniques[15];
bool isUnique;


int main(){
    freopen("C-large.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&numCases);
    pow10[0]=1;
    for(int i=1;i<9;i++){
        pow10[i]=pow10[i-1]*10;
    }
    for(int i=1;i<=numCases;i++){
        scanf("%d %d",&lowBound,&upBound);
        for(int p=0;;p++){
            if(pow10[p]>upBound){
                numDigits=p;
                break;
            }
        }
        ans=0;
        for(int p=lowBound;p<upBound;p++){
            tempChange=p;
            nonUniqueNum=0;
            isUnique=true;
            for(int t=1;t<numDigits;t++){
                lastDigit=tempChange%10;
                tempChange-=lastDigit;
                tempChange/=10;
                tempChange+=lastDigit*pow10[numDigits-1];
                if(lastDigit==0){
                    continue;
                }
                if(tempChange>p && tempChange<=upBound){
                    for(int q=0;q<nonUniqueNum;q++){
                        if(tempChange==nonUniques[q]){
                            isUnique=false;
                            break;
                        }
                    }
                    if(isUnique){
                        nonUniques[nonUniqueNum]=tempChange;
                        nonUniqueNum++;
                        ans++;
                    }
                    //printf("%d %d\n",p,tempChange);
                }
            }
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}

