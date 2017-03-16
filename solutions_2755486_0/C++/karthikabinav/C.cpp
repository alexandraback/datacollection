#include <iostream>
#include <map>
using namespace std;

struct tribe
{
    int di;
    int ni;
    int wi;
    int ei;
    int si;
    int deldi;
    int delpi;
    int delsi;


}info[100];

int main()
{
  int t;
  cin>>t;
  
  int count = 1;
  while(t--)
  {
      int N;
      cin>>N;

      int i,j,l;
      double k;
      map<float,int> height;
      bool hits[676065];
      for(i=0;i<=676060;i++)
      	hits[i] = false;
      for(k=0;k<5000;k+=0.5)
        height[i] = 0;

      for(i=0;i<N;i++)
      {
          cin>>info[i].di>>info[i].ni>>info[i].wi>>info[i].ei>>info[i].si>>info[i].deldi>>info[i].delpi>>info[i].delsi;
          info[i].wi+=1000;
          info[i].ei+=1000;
		  
		  
		  for(j=0;j<info[i].ni;j++)
		  	hits[info[i].di + j*info[i].deldi] = true;
      }
      
      int num = 0;
      for(i=0;i<=676060;i++)
      {
			if(!hits[i])
				continue;
          for(j=0;j<N;j++)
          {
              for(l=0;l<info[j].ni;l++)
              {
                 if(info[j].di+(l)*info[j].deldi == i)
                   break; 
              }
              if(l==info[j].ni)
                continue;
              int le = info[j].wi + l*info[j].delpi;
              int re = info[j].ei + l*info[j].delpi;
              int str = info[j].si + l*info[j].delsi;
              for(k = le;k<=re;k+=0.5)
              {
                  if(height[k]<str)
                  {
                      num++;
                      break;
                  }
              
              }
          }
//          if(i<=20)
 //           cout<<i<<" "<<num<<endl;
          //Update height
         for(j=0;j<N;j++)
          {
              for(l=0;l<info[j].ni;l++)
              {
                 if(info[j].di+(l)*info[j].deldi == i)
                   break; 
              }
              if(l == info[j].ni)
              	continue;
              int le = info[j].wi + l*info[j].delpi;
              int re = info[j].ei + l*info[j].delpi;
              int str = info[j].si + l*info[j].delsi;
              for(k = le;k<=re;k+=0.5)
              {
                  height[k] = max(height[k],str); 
              }
          }
      
      }
      cout<<"Case #"<<count<<": "<<num<<endl;
      count++;
      

  
  
  }

}
