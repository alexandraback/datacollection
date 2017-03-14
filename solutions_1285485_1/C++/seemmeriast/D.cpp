#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int T;
char s[40][40];
vector<pair<int,int> > V;
int divide(int x,int y)
{
     if(y==0)
     return 0;
     return x/y;
     }
bool divisible(int x,int y)
{
     return x*y>=0;
     }
int abs(int x)
{
     if(x>=0)
     return x;
     return -x;
     }
int sign(int x)
{
     if(x<0)
     return -1;
     if(x==0)
     return 0;
     return 1;
     }
bool eat(pair<int,int>x, pair<int,int>y)
{
     int x1=x.first;
     int x2=x.second;
     int y1=y.first;
     int y2=y.second;

     /*if(x1==0&&y1==0)
     return abs(x2)>abs(y2)&&sign(x2)==sign(y2);
     if(x1==0||y1==0)
     return false;

     if(x2==0&&y2==0)
     return abs(x1)>abs(y1)&&sign(x1)==sign(y1);
     if(x2==0||y2==0)
     return false;

     if(divisible(x1,y1)&&divisible(x2,y2))
     {
          return x1/y1==x2/y2;
          }
     return false;*/

     return x1*y2==x2*y1 && x1*y1>=0 && abs(x1)>=abs(y1) && x2*y2>=0 && abs(x2)>=abs(y2);
     }
void clearvector()
{
     while(!V.empty())
     V.pop_back();
     }
void calculate(int x1,int x2,int y1,int y2,int d)
{
     int dx,dy;
     for(int x=-50;x<=50;x++)
     {
          if(x>=0)
          dx=(x1+x2)*(x/2)+x2*(x%2);
          else
          dx=-(x1+x2)*((-x)/2)-x1*((-x)%2);

          for(int y=-50;y<=50;y++)
          {
               if(y>=0)
               dy=(y1+y2)*(y/2)+y1*(y%2);
               else
               dy=-(y1+y2)*((-y)/2)-y2*((-y)%2);

               if(dx*dx+dy*dy<=d*d&&!(x==0&&y==0))
               {
                    V.push_back(pair<int,int>(dx,dy));
                    //cout<<x<<" "<<y<<" "<<dx<<" "<<dy<<endl;
                    }
               }
          }
     }
int main()
{
     freopen("D-large.in","r",stdin);
     freopen("D-large.out","w",stdout);

     cin>>T;
     for(int t=1;t<=T;t++)
     {
          int h,w,d;
          cin>>h>>w>>d;

          for(int i=0;i<h;i++)
          cin>>s[i];

          int x1,x2,y1,y2;
          for(int i=0;i<h;i++)
          {
               for(int j=0;j<w;j++)
               {
                    if(s[i][j]=='X')
                    {
                         y1=2*i-1;
                         y2=2*h-4-y1;
                         x1=2*j-1;
                         x2=2*w-4-x1;
                         }
                    }
               }

          //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;

          clearvector();
          calculate(x1,x2,y1,y2,d);

          //cout<<V.size()<<endl;;

          //for(int i=0;i<V.size();i++)
          //cout<<V[i].first<<" "<<V[i].second<<endl;

          int ans=0;
          for(int i=0;i<V.size();i++)
          {
               int good=1;
               for(int j=0;j<V.size();j++)
               {
                    if(j!=i&&eat(V[i],V[j]))
                    {
                         good=0;
                         //cout<<V[i].first<<" "<<V[i].second<<" eats "<<V[j].first<<" "<<V[j].second<<endl;
                         break;
                         }
                    }
               if(good)
               {
                    //cout<<V[i].first<<" "<<V[i].second<<"good"<<endl;
                    ans++;
                    }
               }

          cout<<"Case #"<<t<<": "<<ans<<endl;
          }
     }
