
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

struct level
{
	int a;
	int b;
	level(int x,int y):a(x),b(y){}
};

vector<level> vl;

struct revl
{
	int x; 
	int id;
	revl(int p, int q):x(p),id(q){};
	bool operator < (const revl &t) const
	{
		return x<t.x;
	}
};

struct revla
{
        int x;
        int y;
        int id;
        revla(int p, int q, int z):x(p),y(q),id(z){};
        bool operator < (const revla &t) const
        {
                if(x==t.x)
                    return y>t.y;
                else 
                    return x<t.x;
        }
};


vector<revl> bline;
vector<revla> aline;
bool arun[1001];
int main() {
        int T;
        cin>>T;
        int count=1;
        while(T--)
        {

            int N;
            cin>>N;
            vl.clear();
            bline.clear();
            aline.clear();
            for(int i=0;i<N;i++)
            {
            	int a, b;
            	cin>>a>>b;
            	vl.push_back(level(a,b));
            	bline.push_back(revl(b,vl.size()-1));
            	aline.push_back(revla(a,b,vl.size()-1));
            	arun[i]=false;
            }
            
            int bid=0;
            int aid=0;
            int credit=0;
            int tnum=0;
            sort(aline.begin(),aline.end());
            sort(bline.begin(),bline.end());
            bool ip=false;
            
            for(;aid<N||bid<N;)
            {
            	ip=false;
            	if(bid<N)
            	{
            		if(credit>=bline[bid].x)
            		{
            			int realid=bline[bid].id;
            			
            			credit+=(arun[realid]==true)?1:2;
		                arun[realid]=true;
		                bid++;
                                tnum++;
		                ip=true;
            		}
            	}
            	if(ip==true)
            		continue;
            	
            	if(aid<N)
            	{
            		
            		while(credit>=aline[aid].x&&aid<N)
            		{
            		     int realid=aline[aid].id;
            		     
            		     if(arun[realid]==true)
            		     {
            		    	 aid++;
            		    	 continue;
            		     }
            		     
            		     credit+=1;
            			 arun[realid]=true;
            			 aid++;
                                 tnum++;
            			 ip=true;
                                 break; 	
            		 }
            	}
            	
            	if(ip==false)
            	    break;
            }
            
            if(aid==N&&bid==N)
            {
              	cout<<"Case #"<<count++<<": "<<tnum<<endl;
            }
            else
            	cout<<"Case #"<<count++<<": Too Bad"<<endl;
            
         }



        return 0;
}

