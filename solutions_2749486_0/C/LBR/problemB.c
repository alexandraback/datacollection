main(){
       int n,i,xf,yf,x,y,a,k;
       char s[60][3010];
       scanf("%d",&n);
       for(k=0;k<n;k++){
       scanf("%d%d",&xf,&yf);
       x=0;
       y=0;
       a=1;
       i=0;
       if(xf!=0)
       while(x!=abs(xf)){
          if(a%2){
             x+=a;
             s[k][i]='E';
          }
          else{
             x-=a;
             s[k][i]='W';
          }
          i++;
          a++;
       }
       if(yf!=0)       
       if (a>abs(yf)){
          y-=a;
          a++;
          s[k][i]='S';
          i++;
       }
       if(yf!=0)
       while(y!=abs(yf)){
          if(a%2){
             y+=a;
             s[k][i]='N';
          }
          else{
             y-=a;
             s[k][i]='S';
          }
          a++;
          i++;
       }
       int j=0;
       for(j=0;j<strlen(s[k]);j++){
          if(xf<0&&s[k][j]=='E')
             s[k][j] = 'W';
          else if(xf<0&&s[k][j]=='W')
             s[k][j] = 'E';
          else if(yf<0&&s[k][j]=='N')
             s[k][j] = 'S';
          else if(yf<0&&s[k][j]=='S')
             s[k][j] = 'N';
          }
       i--;
       }

       for(k=0;k<n;k++){
          printf("Case #%d: %s\n",k+1,s[k]);
       }
       getch();
       }
  


/*main(){
       int n,i,xf,yf,x,y,a,k;
       char s[60][3010];
       scanf("%d",&n);
       for(k=0;k<n;k++){
       scanf("%d%d",&xf,&yf);
       x=0;
       y=0;
       a=1;
       i=0;
       if(xf!=0)
       while(x!=abs(xf)){
          if(a%2){
             x+=a;
             if(xf>0)
                s[k][i]='E';
             else
                s[k][i]='W';
          }
          else{
             x-=a;
             if(xf<0)
                s[k][i]='E';
             else
                s[k][i]='W';
          }
          i++;
          a++;
       }
       if(yf!=0)       
       if (a>abs(yf)&&yf>0){
          y-=a;
          a++;
          s[k][i]='S';
          i++;
       }
       if(yf!=0)       
       if (a>abs(yf)&&yf<0){
          y+=a;
          a++;
          s[k][i]='N';
          i++;
       }
       if(yf!=0)
       while(y!=abs(yf)){
          if(a%2){
             y+=a;
             if(yf>0)
                s[k][i]='N';
             else
                s[k][i]='S';

          }
          else{
             y-=a;
             if(yf<0)
                s[k][i]='N';
             else
                s[k][i]='S';
          }
          a++;
          i++;
       }
       i--;
       //s[k][i]='\0';
       }
       for(k=0;k<n;k++)
       printf("Case #%d: %s\n",k+1,s[k]);
       getch();
       }
       */
