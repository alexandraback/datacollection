#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int a[300],v[100];
int i,j,k,n,m,ca,cas,c;
char s[2010];

int main(){

  freopen("a_l.in","r",stdin);
  freopen("a_l.out","w",stdout);
  scanf("%d",&cas);
  for (ca=1;ca<=cas;ca++){
    memset(a,0,sizeof(a));
    memset(v,0,sizeof(v));
    scanf("%s",s+1);
    n=strlen(s+1);
  //  printf("%d\n",n);
    for (i=1;i<=n;i++) a[s[i]]++;

    c=a['Z'];
    v[0]=c;
    a['Z']-=c;
    a['E']-=c;
    a['R']-=c;
    a['O']-=c;
 //   printf("%d",c);

    c=a['W'];
    v[2]=c;
    a['T']-=c;
    a['W']-=c;
    a['O']-=c;

    c=a['X'];
    v[6]=c;
    a['S']-=c;
    a['I']-=c;
    a['X']-=c;

    c=a['U'];
    v[4]=c;
    a['F']-=c;
    a['O']-=c;
    a['U']-=c;
    a['R']-=c;

    c=a['O'];
    v[1]=c;
    a['O']-=c;
    a['N']-=c;
    a['E']-=c;

    c=a['F'];
    v[5]=c;
    a['F']-=c;
    a['I']-=c;
    a['V']-=c;
    a['E']-=c;

    c=a['V'];
    v[7]=c;
    a['S']-=c;
    a['E']-=(2*c);
    a['V']-=c;
    a['N']-=c;

    c=a['G'];
    v[8]=c;
    a['E']-=c;
    a['I']-=c;
    a['G']-=c;
    a['H']-=c;
    a['T']-=c;

    c=a['I'];
    v[9]=c;

    c=a['H'];
    v[3]=c;
   // printf("%d",c);


    printf("Case #%d: ",ca);
    for (i=0;i<=9;i++)
      for (j=1;j<=v[i];j++) printf("%d",i);
    printf("\n");




  }

  return 0;



}
