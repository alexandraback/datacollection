#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
vector<int> start;
int con(char w)
{
    if(w=='a' || w=='e' || w=='i' || w=='o' || w=='u') return 0;
    else return 1;
}
int main()
{
    long long totalcase,totalk;
    char w[1000005];
    scanf("%d",&totalcase);
    for(int o=0;o<totalcase;o++)
    {
        scanf(" %s %lld",w,&totalk);
        long long c=0;
        long long along=0;
        start.clear();
        for(int i=0;w[i];i++)
        {
            along++;
            if(con(w[i])) c++;
            else c=0;
            if(c>=totalk)
            {
                start.push_back(i-totalk+1);
            }
        }
        long long p=0;
        long long count=0;
        /*for(int i=0;i<start.size();i++)
        {
            printf("%d\n",start[i]);
        }*/
        for(int i=0;w[i];i++)
        {
            while(i>start[p] && p<start.size()) p++;
            if(p>=start.size()) break;
            count+=(long long)along-(long long)((long long)start[p]+(long long)totalk-(long long)1);
            //printf("plus %d\n",along-(start[p]+totalk-1));
        }
        printf("Case #%d: ",o+1);
        cout << count << endl;
    }
    return 0;
}
