#include<stdio.h>
#include<math.h>
int main()
{
    long int signx,signy=0,i,j,lowx,lowy,highx,highy,minx,miny,ux,uy,diffx,diffy;
    long int x,y,t,k=1;

    FILE *fp1,*fp2;
    fp1=fopen("B-small-attempt2.in","r");
    fp2=fopen("B-small-attempt0.out","w");
        fscanf(fp1,"%ld",&t);
    while(t--)
    {
        signx=signy=0;
     fscanf(fp1,"%ld  %ld",&x,&y);
     if(x<0) signx=1;
     if(y<0) signy=1;
     if(x>=0)    ux=x;   else  ux=-x;
     if(y>=0)   uy=y;   else  uy=-y;
    // fscanf(fp,"ux=%d   uy=%d\n",ux,uy);
     fprintf(fp2,"Case #%d: ",k);

        {

            lowy=(long int)((-1+sqrt(1+(8*uy)))/2);
            miny=lowy;
            //lowy=(sqrt(1+(8*uy)));
            //fscanf(fp,"%ld",lowy);

            uy=((miny*(miny+1))/2)+ux;
            //floor((-1+sqrt(1-(8*uy)))/2);
            lowx=(floor((-1+sqrt(1+(8*uy)))/2))-miny;
            minx=lowx;
            if(y>=0)   uy=y;   else  uy=-y;
        }
      // fscanf(fp,"lowx=%ld     and lowy=%ld\n",lowx,lowy);
      //  fscanf(fp,"minx=%ld     and miny=%ld\n",minx,miny);
        if(signy==0)
        {
            for(i=0;i<lowy;i++)
            fprintf(fp2,"N");
        }
        else
        {
            for(i=0;i<lowy;i++)
            fprintf(fp2,"S");
        }

        if(signx==0)
        {
            for(i=0;i<minx;i++)
            fprintf(fp2,"E");
        }
        else
        {
            for(i=0;i<minx;i++)
            fprintf(fp2,"W");
        }

        diffy=uy-((miny*(miny+1))/2);
        diffx=uy+ux-diffy-(((miny+minx)*(miny+minx+1))/2);
        //fprintf(fp2,"diffy=%ld and diffx=%ld\n",diffy,diffx);
        if(signy==0)
        for(i=0;i<diffy;i++)
        fprintf(fp2,"SN");
        if(signy==1)
        for(i=0;i<diffy;i++)
        fprintf(fp2,"NS");

        if(signx==0)
        for(i=0;i<diffx;i++)
        fprintf(fp2,"WE");
        if(signx==1)
        for(i=0;i<diffx;i++)
        fprintf(fp2,"EW");
    fprintf(fp2,"\n");
    k++;
    }
    fclose(fp1);
    fclose(fp2);
    return 0;

}
