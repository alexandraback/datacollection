#include<cstdio>
#include<ctype.h>


#define MAXLEN 1000005
#define LL long long

int siz;
int size(char *str)
{
    int a=0;
    while(isalpha(str[a]))
    a++;

    return a;
}


int isvowel(char a)
{
    if (a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
    return 1;

    else return 0;
}

int hit_point(char *a,int beg,int len)
{
    int count=0;

    for(int i=beg;i<siz;i++)
    {
        if( !isvowel(a[i]) ) count ++;
        else count = 0;
        if (count==len) //bingo
        {
            //printf("hitpoint at %d\n",i);
            return i;
        }
    }

    //loop complete nothing found
    return    siz;

}

int endpt(char *a,int beg)
{
    for(int i=beg;i<siz;i++)
    {
        if(isvowel(a[i]))
        return i;
    }

    // nothing found
    return siz;
}

/*long long fn(char *str, int len)
{
    siz = size(str);
    int beg=0;
    int a,b,c;
    a=0;
    b=hit_point(str,beg,len);
    printf()
    int sub=0;
    int interval = b-a;
    sub+=((interval+1)*interval)/2;
    printf(" -%d\n",((interval+1)*interval)/2);
    while(b<siz)
    {
     c = endpt(str,b);
     a = c-(len-1);
     b = hit_point(str,b,len);
     interval=b-a;
     sub+=((interval+1)*interval)/2;
     printf(" -%d\n",((interval+1)*interval)/2);
    }
  /*  if(b==-1) b = siz+1;
    interval=b-a;
     sub+=((interval+1)*interval)/2;

     printf(" +%d\n",((siz+1)*siz)/2);
    return ((siz+1)*siz)/2-sub;
}
*/

long long nval(char *str, int len)
{
    siz= size(str);
    int prevstart=-1;
    long long count=0;
    while(prevstart+(len)<siz)
    {
        int start = hit_point(str,prevstart+1,len);

        if(start==siz) break;
        start-=(len-1);//printf("%d\n",start);

        int end = start+len-1;//endpt(str,start);
        //printf("%d\n",end);
         count += (LL)( (start-prevstart)*(siz-end) ) ;
        // printf("+%d",(start-prevstart)*(siz-end));
         prevstart= start;
    }

    return count;

}

int main()
{
    int test;
    scanf("%d",&test);

    for(int i=1;i<=test;i++)
    {
        char str[MAXLEN];
        int len;
        scanf("%s %d",str,&len);

        printf("Case #%d: %lld\n",i,nval(str,len));
    }
}
