#include <stdio.h>
#include <vector>
using namespace std;
vector<int> start;
int con(char w)
{
    if(w=='a' || w=='e' || w=='i' || w=='o' || w=='u') return 0;
    else return 1;
}
int main()
{
    int totalcase,totalk;
    char w[1000005];
    scanf("%d",&totalcase);

    for(int o=0;o<totalcase;o++)
    {
        scanf(" %s %d",w,&totalk);
        int c=0;
        int along=0;
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
        int p=0;
        int count=0;
        /*for(int i=0;i<start.size();i++)
        {
            printf("%d\n",start[i]);
        }*/
        for(int i=0;w[i];i++)
        {
            while(i>start[p] && p<start.size()) p++;
            if(p>=start.size()) break;
            count+=along-(start[p]+totalk-1);
            //printf("plus %d\n",along-(start[p]+totalk-1));
        }
        printf("Case #%d: %d\n",o+1,count);
    }
    return 0;
}
