#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

string i1="ejp mysljylc kd kxveddknmc re jsicpdrysi";
string i2="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
string i3="de kr kd eoya kw aej tysr re ujdr lkgc jv";
string i4="yqee";

string o1="our language is impossible to understand";
string o2="there are twenty six factorial possibilities";
string o3="so it is okay if you want to just give up";
string o4="azoo";

int cm[26]={-1};

void premap(string &i1, string &o1)
{
	for(size_t i=0;i<i1.size();i++)
	        {
		        if(i1[i]==' ')
		        	continue;
		        
	        	int k=i1[i]-'a';
	        	int v=o1[i]-'a';
	        	if(cm[k]==-1)		
	        	    cm[k]=v;
	        }
}

int main() {
 
        memset(cm,-1,sizeof(cm));
        
        premap(i1,o1);
        premap(i2,o2);
        premap(i3,o3);
        premap(i4,o4);
        
        cm[25]=16;
        int N;
        cin>>N;
        string nn;
        getline(cin,nn);
        int count=1;
        while(N--)
        {
                string str;
                getline(cin,str);
                
                char ostr[200];
                size_t i=0;
                for(i=0;i<str.size();i++)
                {
                	if(str[i]==' ')
                	{
                        	ostr[i]=' ';
                        }
                	else
                	{
                		int k=str[i]-'a';
                		char c=cm[k]+'a';
                		ostr[i]=c;
                	}
                }
                ostr[i]='\0';


                cout<<"Case #"<<count++<<": "<<string(ostr)<<endl;
         }



        return 0;
}
