#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;
int size,t,l,x;
vector<int> data;
int memo[110001][9][3];
int table[5][5];
int solve(int nowpos,int sum, int find)
{
  int &ret=memo[nowpos-1][sum+4][find-2];
  if(ret!=-1) return ret;
  else{
    ret=0;
    int newsum,modpos,tmp;
    modpos=(nowpos-1)%l;
    tmp=1;
    if(sum<0) tmp=-1;
    newsum=tmp*table[abs(sum)][data[modpos]];
    if(nowpos==size){
      if(find==4&&newsum==4){
        ret=1;
        return ret;
      }
      else{
        ret=0;
        return ret;
      }
    }
    else{
      if(newsum==find&&find<4){
        ret=max(ret,solve(nowpos+1,1,find+1));
        ret=max(ret,solve(nowpos+1,newsum,find));
      }else{
        ret=solve(nowpos+1,newsum,find);
      }
    }
  }
  return ret;
}
int main()
{
  FILE *ifp,*ofp;
  long long longx;
  int dmax,ret,retmin;
  char yes[]="YES";
  char no[]="NO";
  char *result;
  table[1][1]=1;
  table[1][2]=2;
  table[1][3]=3;
  table[1][4]=4;
  table[2][1]=2;
  table[2][2]=-1;
  table[2][3]=4;
  table[2][4]=-3;
  table[3][1]=3;
  table[3][2]=-4;
  table[3][3]=-1;
  table[3][4]=2;
  table[4][1]=4;
  table[4][2]=3;
  table[4][3]=-2;
  table[4][4]=-1;
  data.reserve(100001);
  ofp=fopen("C-small-result.in","w");
  if((ifp=fopen("C-small-attempt1.in","r"))!=NULL){
    fscanf(ifp,"%d",&t);
    for(int i=0;i<t;i++){
      data.clear();
      memset(memo,-1,sizeof(memo));
      fscanf(ifp,"%d",&l);
      fscanf(ifp,"%lld",&longx);
      if(longx>11){
        x=8+longx%4;
      }
      else{
        x=(int)longx;
      }
      char c;
      fscanf(ifp,"%c",&c);
      for(int j=0;j<l;j++){
        fscanf(ifp,"%c",&c);
        data.push_back((int)(c-(int)'g'));
      }
      size=l*x;
      int iresult = solve(1,1,2);//nowpos,beforesum,find
      if(iresult==1)result=yes;
      else result=no;
      fprintf(ofp,"Case #%d: %s\n",i+1,result);
      printf("Case #%d: %s\n",i+1,result);
    
    }
  }
  fclose(ifp);
  fclose(ofp);
}
