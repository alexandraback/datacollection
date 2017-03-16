#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
int i,ntest,j,x,ix,y,iy,xo,yo,t;
char n='N',s='S',e='E',w='W',ct;

scanf("%d",&ntest);

for ( i = 1; i <= ntest; ++i)
{
  scanf(" %d %d",&xo,&yo);

printf("Case #%d: ",i);

x=y=0;
ix=iy=1;
n='N';s='S';e='E';w='W';
if(xo<0){
  xo=-xo;
  e='W';
  w='E';
}
if(yo<0){
  yo=-yo;
  n='S';
  s='N';
}

if(xo<yo){
t=xo;xo=yo;yo=t;
ct=e;e=n;n=ct;
ct=w;w=s;s=ct;
}

while((x+ix) <= xo){
  x+=ix; printf("%c",e);
  ix++; iy++;
  if(iy == yo){
    y+=iy; printf("%c",n);
    ix++; iy++;
  }
}
while(x<xo){
  x-=ix; printf("%c",w);
  ix++;iy++;
  if(iy == yo){
    y+=iy; printf("%c",n);
    ix++; iy++;
  }
  x+=ix; printf("%c",e);
  ix++,iy++;
}
while(x>xo){
  x--;
  printf("%c%c",e,w);
}
while(y<yo){
    y++;
    printf("%c%c",s,n);
  }



printf("\n");
}

  return 0;
}
/*
if(xo>=0)
  for(j=0;j<xo;j++)
    printf("WE");
else {
  xo = -xo;
  for(j=0;j<xo;j++)
    printf("EW");
}

if(yo>=0)
  for(j=0;j<yo;j++)
    printf("SN");
else {
  yo = -yo;
  for(j=0;j<yo;j++)
    printf("NS");
}*/