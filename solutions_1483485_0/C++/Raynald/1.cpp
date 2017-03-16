#include<iostream>

using namespace std;

int T;
int a[27];
char str[110];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d\n",&T);
    a[1]=25;//a
    a[2]=8;//b
    a[3]=5;//c
    a[4]=19;//d
    a[5]=15;//e
    a[6]=3;//f
    a[7]=22;//g
    a[8]=24;//h
    a[9]=4;//i
    a[10]=21;//j
    a[11]=9;//k
    a[12]=7;//l
    a[13]=12;//m
    a[14]=2;//n
    a[15]=11;//o
    a[16]=18;//p
    a[17]=26;//q
    a[18]=20;//r
    a[19]=14;//s
    a[20]=23;//t
    a[21]=10;//u
    a[22]=16;//v
    a[23]=6;//w
    a[24]=13;//x
    a[25]=1;//y
    a[26]=17;//z
    for(int i=1;i<=T;i++)
    {
        gets(str);
        for(int j=0;j<strlen(str);j++)
        if(str[j]!=' ') str[j]=a[str[j]-'a'+1]-1+'a';
        printf("Case #%d: %s\n",i,str);
    }
    return 0;
}
