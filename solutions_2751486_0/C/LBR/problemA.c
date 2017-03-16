main(){
       int n,i,total[10100],k,j,l,t;
       char s[11000];
       scanf("%d",&t);
       for(l=0;l<t;l++){
          total[l]=0;
          scanf("%s%d",&s,&n);
          for(k=n;k<=strlen(s);k++){
             for(i=0;i<=strlen(s)-k;i++){
                int cont=0;
                for(j=i;j<k+i;j++){
                   if(s[j]!='a'&&s[j]!='e'&&s[j]!='i'&&s[j]!='o'&&s[j]!='u')
                      cont++;
                   else
                      cont=0;
                   if(cont>=n){
                      total[l]+=1;
                      break;
                   }
                }
             }
          }
       }
       for(l=0;l<t;l++)
          printf("Case #%d: %d\n",l+1,total[l]);
       getch();
       }
