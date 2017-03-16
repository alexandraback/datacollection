#include<stdio.h>
#include<string.h>
#include<conio.h>

int t[10000],r[100000];

void reverse(char *str)
{
       for(int i=0;str[i]!='\0';i++)
       {
              if(str[i]=='N')
                     str[i]='S';
              else if(str[i]=='S')
                     str[i]='N';
              else if(str[i]=='E')
                     str[i]='W';
              else if(str[i]=='W')
                     str[i]='E';
       }
}

void getsubsethalfsum(int a[],int n)
{
       int k=0;
       t[0]=1;
       for(int i=0;i<n;i++)     
       {     
             k+=a[i];
       }
       for(int i=1;i<k;i++)     
       {     
             t[i]=0;
             r[i]=0;
       }
       for(int i=0;i<n;i++)
       {
            for(int j=k-a[i];j>=0;j--)
            {
                 if(t[j])
                 {
                      t[j+a[i]]=1;        
                      r[j+a[i]]=i;
                 }     
            }        
       }     
}

void subset(int arr[],int s,int k,char str[])
{
       if(s<=0||s>k) return;     
       else if(t[s])
       {
            subset(arr,s-arr[r[s]],k,str);
            str[arr[r[s]]-1]='N'; 
            //printf("h %d\n",arr[r[s]]);    
       }
}

void getX(char *str,int xv)
{
     int tb;
     int arr[500];
     int i=0,val=1,sum=0;
     if(xv<0)   tb=-xv;   
     else tb=xv;
     while(sum%2!=0||val<=tb)
     {
             if(val!=tb)               
             {       
                   arr[i++]=val;  
                  // printf("arr %d\n",arr[i-1]);
                   sum+=val;
             }      
             val++;
     }
     val--;
     str[tb-1]='N';
     //printf("sum= %d",t-1);
     getsubsethalfsum(arr,i);
     subset(arr,sum/2,sum,str);
     for(int j=0;j<val;j++)
     {
             //printf("%c",str[j]);
             if(str[j]=='a')
                      str[j]='S';
     }
     str[val]='\0';
     if(xv<0)   reverse(str);
}

void translate(char *str)
{
     for(int i=0;str[i]!='\0';i++)     
     {
           if(str[i]=='N')
                  str[i]='E';
           else str[i]='W';               
     }
}

int main()
{
       char x[500],y[500];
       int ts,xv,yv;
       scanf("%d",&ts);
     //  printf("%d\n",ts);
       for(int cnt=1;cnt<=ts;cnt++)    
       {
                for(int j=0;j<500;j++){ x[j]='a';  y[j]='a'; }
                
                scanf("%d %d",&xv,&yv);                 
                getX(x,xv); 
                getX(y,yv);
                translate(y);
                //if((strlen(x)+strlen(y))>500)
                //printf("here %d %d %d\n",cnt,xv,yv);
               printf("Case #%d: %s%s\n",cnt,x,y);
       }
      // getch();
}
