#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define lenn 26
struct vvv{
   char s[111];    
}s[4444444],sta,stb;
int tot,tmp[111],a[111],b[111],t;

bool cmp(const vvv &a,const vvv &b){
     if (strlen(a.s)==strlen(b.s))
        return strcmp(a.s,b.s)<0;
      return strlen(a.s)<strlen(b.s);    
}

bool cmpe(const vvv &a,const vvv &b){
     if (strlen(a.s)==strlen(b.s))
        return strcmp(a.s,b.s)<=0; 
     return strlen(a.s)<strlen(b.s); 
}

int find(const vvv &a,const vvv &b){
  int  i=0,j=tot-1,mid,a1,a2;
  while (i<j){
      mid=(i+j)/2;
      if (cmp(s[mid+1],a))
         i=mid+1;
      else 
         j=mid;  
  }    
  a1=i;
  i=0,j=tot-1;
  while (i<j){
        mid=(i+j)/2;      
        if (cmpe(s[mid+1],b))
         i=mid+1;
        else 
         j=mid;  
  }
  a2=i;
  return a2-a1;
}



bool p(int cc[],int l){
  int i,j;
  j=l;
  for (i=0;i<j;i++)
      if (cc[i]!=cc[j-1-i]) return false;    
  return true;   
}

void cal(int len){
  int i,j;
  memset(b,0,sizeof(b));
  for (i=0;i<len;i++)
      for (j=0;j<len;j++)
          b[i+j]+=a[i]*a[j];
  for (i=0;i<len*2;i++)    
     if (b[i]>=10){
         b[i+1]+=b[i]/10;
         b[i]%=10;         
     }
  j=len*2;
  while (b[j]==0)
        j--;
  if (p(b,j+1)){
      for (i=0;i<j+1;i++)
          s[tot].s[i]=b[i]+'0';
      s[tot].s[j+1]=0;
      tot++;
  }
  else{
  //     cout<<"error"<<endl;
  //    for (i=0;i<len;i++)
  //        cout<<a[i];
  //        cout<<endl;     
  }
}


void test(int one,int two){
     int i,j,k;
     k=0;
     i=0;
     while (!tmp[i])
           i++;
     for (j=i;j<lenn;j++)
         a[k++]=tmp[j];
    //   if (two&&(one>1||one==1&&a[k-1]!=1))
   //      return;
     if (two&&(a[0]!=2&&a[k-1]!=2))
        return; 
         
     if ((one<5)&&!(a[0]==2&&one)){    
         for (i=0;i<k;i++)
             a[k*2-1-i]=a[i];
         cal(k*2);
     }
     if (one<5||a[k-1]==1){
         for (i=0;i<k-1;i++)
             a[k*2-2-i]=a[i];
         cal(k*2-1);
     }
}

void gen(int id,int one,int two){
     int i;
     if (one>5||two>1) return;
     if (id==lenn){
       if (one||two)
       test(one,two);
     }
     else{
        tmp[id]=0;
        gen(id+1,one,two);
        tmp[id]=1;
        gen(id+1,one+1,two);
        tmp[id]=2;
        gen(id+1,one,two+1);  
     }
}


int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    tot=2;
    s[0].s[0]='9';
    s[0].s[1]=0;
    s[1].s[0]='0';
    s[1].s[1]=0;
    gen(0,0,0);
    //cout<<tot<<endl;  
    sort(s,s+tot,cmp);
   // for (int i=0;i<10;i++)
   //    cout<<s[i].s<<endl; 
   // cin>>tot;
    scanf("%d",&t);
    for (int r=1;r<=t;r++){
        scanf("%s%s",sta.s,stb.s);
        printf("Case #%d: %d\n",r,find(sta,stb));    
    }
    return 0;   
}
