#include<cstdio>
const int N=1000010;
int DP[N];
bool isV(char t)
{
    return (t=='a'||t=='e'||t=='i'||t=='o'||t=='u');
}
char tmp[N];
int main()
{
    int k,T,index=0;
    scanf("%d",&T);
    while(T>0)
    {
        index++;
        scanf("%s %d",tmp,&k);
        int i=1;
        DP[0]=0;
        int con=0;
        while(tmp[i-1]!='\0')
        {
            if(isV(tmp[i-1]))
            {
                DP[i]=DP[i-1];
                con=0;
            }
            else
            {

                con++;
                if(con>=k)
                {

                    DP[i]=i-k+1;
                }
                else DP[i]=DP[i-1];
            }
            i++;
        }
        int sum=0;
        for(int j=0;j<i;j++)
        {
           sum+=DP[j];


        }

        printf("Case #%d: %d\n",index,sum);
        T--;
    }
}
