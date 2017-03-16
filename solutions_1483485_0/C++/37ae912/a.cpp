
#include <cstring>
#include <cstdio>


int a[26]={24,13,5,8,2,22,11,1,10,20,14,12,23,18,4,21,25,15,3,17,9,6,19,7,0,16};

char buf[110];
char buf2[110];

int index[26];

void init()
{
    for(int i=0;i<26;++i)
        index[ a[i] ]=i;
}



int main()
{
    init();
    int cs;
    int i=0;
    scanf("%d",&cs);
    gets(buf);
    while(i++<cs){
        gets(buf);
        printf("Case #%d: ",i);
        int len = strlen(buf);
        for(int i=0;i<len;++i){
            if(buf[i]>='a' && buf[i]<='z')
                putchar( 'a'+index[ buf[i]-'a' ] );
            else
                putchar(buf[i]);
        }
        putchar('\n');
    }

    /*
    int i,k;
    memset(a,-1,sizeof(a));
    while(scanf("%d %d",&i,&k)==2){
        a[i]=k;
    }

    for(int i=0;i<26;++i){
        if(a[i]==-1){
            
            for(int j=0;j<26;++j){
                bool in=false;
                for(int x=0;x<26;++x){
                    if(j==a[x])in=true;
                }
                if(in==false)
                    a[i]=j;
            }
        }
    }

    for(int i=0;i<26;++i)
        printf("%d,",a[i]);

    /*
    gets(buf);
    gets(buf2);
    
    memset(a,-1,sizeof(a));

    printf("buf=%sEND\n,buf2=%sEND\n",buf,buf2);
    int len = strlen(buf);

    for(int i=0;i<len;++i){
        if(buf2[i]!=' ')
        a[ buf2[i]-'a' ] = buf[i]-'a';
    }

    for(int i=0;i<26;++i)
        if(a[i]>=0)
        printf("%d %d\n",i,a[i]);

    */


    return 0;
}
