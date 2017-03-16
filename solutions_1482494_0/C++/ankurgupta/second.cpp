#include<iostream>
using namespace std;

struct level
{
   int f,s;    
}l[1100];

bool comp(struct level i,struct level j)
{
     if(i.s==j.s) return i.f<j.f;
     return i.s<j.s;
}
int main()
{
    int t,m=1;
    cin>>t;
    while(t--)
    {
        int n,strt=0,level=0;
        cin>>n;
        for(int i=0;i<n;i++) 
          cin>>l[i].f>>l[i].s;
        sort(l,l+n,comp);
        //for(int i=0;i<n;i++) cout<<l[i].f<<" "<<l[i].s<<"\n";
        for(int i=0;i<n;)
        {
           if(strt>=l[i].s)       
           {
              int c=0;                    
              if(l[i].f==-1)
                c=1;
              else c=2;  
              strt+=c;
              l[i].s=-1;                    
              level++;
              i++;              
           }
           else
           {
              int min=5000,pos=-1; 
              for(int j=0;j<n;j++)  
              {
                 if(l[j].f<min && l[j].s!=-1 && l[j].f!=-1)
                 {
                   pos=j;
                   min=l[j].f;            
                 } 
                 if(l[j].f==min && l[j].s!=-1 && l[j].f!=-1 && l[j].s>l[pos].s)
                   pos=j;
              }
              if(pos==-1 || l[pos].f>strt) break;
              else
              {
                  strt++;
                  l[pos].f=-1;
                  level++;
              }
              //cout<<pos<<" "<<l[pos].s<<" ";
           }
           //cout<<strt<<" "<<level<<"\n";
        }
        int flag=1;
        for(int i=0;i<n;i++) if(l[i].s!=-1) flag=0;
        if(!flag)
          printf("Case #%d: Too Bad\n",m++);
        else
          printf("Case #%d: %d\n",m++,level);
        //cout<<level<<"\n";
    }
}
