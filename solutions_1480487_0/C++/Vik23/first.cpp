#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define Max 20
struct node
{
 int indx;
 int judge;
 float audience;
};
bool cmp_judge(const node &a,const node &b)
{
 return a.judge<b.judge;
}
bool cmp_indx(const node &a,const node &b)
{
 return a.indx<b.indx;
}
vector<node> list;
int main()
{
 int test_cases,no,sum,tmpsc,bailout,level;
 scanf("%d",&test_cases);
 node temp;
 for(int t=1;t<=test_cases;t++)
 {
  list.clear();
  scanf("%d",&no);
  sum=0;
  for(int i=0;i<no;i++)
  {
   scanf("%d",&tmpsc);
   temp.indx=i;
   temp.judge=tmpsc;
   list.push_back(temp);
   sum+=tmpsc;
  }
  bailout=sum;
  sort(list.begin(),list.end(),cmp_judge);

  
  level=list[0].judge;


  int indx=1;
  while(indx<no && bailout>0 && (list[indx].judge-level)*indx< bailout)
  {
	  bailout-=(list[indx].judge-level)*indx;
	  level=list[indx].judge;
	  indx++;
  }
  //printf("%d %d",bailout,indx);
   for(int i=0;i<indx;i++)
   {
	   list[i].audience=level+(bailout/(float)indx)*1.0;
   }
   for(int i=indx;i<no;i++)
   {
	   list[i].audience=list[i].judge;
   }
   sort(list.begin(),list.end(),cmp_indx);
   printf("Case #%d:",t);
   for(int i=0;i<no;i++)
   {
	   printf(" %f",(list[i].audience-list[i].judge)/sum*100.0);
   }
   printf("\n");
 }
 return 0;
}
