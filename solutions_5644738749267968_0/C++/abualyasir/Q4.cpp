#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
 using namespace std;
 int max(vector<double> s)
 {
 	double m=s[0];
 	int pos=0;
 	  for(int i=0;i<s.size();i++)
 	    if(s[i]>m)
 	    {
		  m=s[i];
 	       pos=i;
		 }
		  return pos;
 	     
 }
 
 int min(vector<double> s)
 {
 	double m=s[0];
 	int pos=0;
 	  for(int i=0;i<s.size();i++)
 	    if(s[i]<m)
 	    {
		  m=s[i];
 	       pos=i;
		 }
		  return pos;
 	     
 }
 void print(vector<double> s)
 {
 	for(int i=0;i<s.size();i++)
 	 cout<<s[i]<<" ";
 	 cout<<endl;
 }
 int war(vector<double> girl,vector<double> boy)
 {
 	     int count=0;
 	     while(girl.size()!=0)
 	     {
 	     	  int maxgirl=max(girl);
 	     	   int maxboy=max(boy);
 	     	   int minboy=min(boy);
 	     	      if(girl[maxgirl]>boy[maxboy])
 	     	      {
 	     	      	girl.erase(girl.begin()+maxgirl);
 	     	      	 boy.erase(boy.begin()+minboy);
 	     	      	 count++;
 	     	      }
 	     	      else{
 	     	      	    int nextmax=-1;
 	     	      	     for(int i=0;i<boy.size();i++)
 	     	      	                if(boy[i]>girl[maxgirl])
										{
											  nextmax=i;
											  break;
										} 
 	     	      	 girl.erase(girl.begin()+maxgirl);
 	     	      	    boy.erase(boy.begin()+nextmax);
 	     	      }
 	     }
 	     return count;
 }
 int dwar(vector<double> girl,vector<double> boy)
 {
 	int count=0;
 	while(girl.size()!=0)
 	{
 		sort(boy.begin(),boy.end());
 		 sort(girl.begin(),girl.end());
      int maxgirl=max(girl);
      int mingirl=min(girl);
         int maxboy=max(boy);
         int minboy=min(boy);
          if(girl[maxgirl]>boy[maxboy])
          {
          	     int nextmin;
          	     for(int i=0;i<girl.size();i++)
          	        if(girl[i]>boy[minboy])
          	            {
          	            	nextmin=i;
          	            	break;
          	            }
          	     girl.erase(girl.begin()+nextmin);
          	      boy.erase(boy.begin()+minboy);
            count++;
		  }
          else{
          	     int nextmax;
          	 for(int i=0;i<boy.size();i++)
          	   if(boy[i]>girl[maxgirl])
          	   {
          	   	    nextmax=i;
          	   	    break;
          	   }
          	   boy.erase(boy.begin()+nextmax);
          	    girl.erase(girl.begin()+mingirl);
          }
    }
    return count;
 }
 int main()
 {
      ifstream in;
	  in.open("how.txt");
	  ofstream out;
	  out.open("output.txt");
	   int tc;
	   in>>tc;
	   for(int t=0;t<tc;t++)
	   {
	   	  int blocks;
	   	  in>>blocks;
	   	   vector<double> girl;
	   	    vector<double> boy;
	   	    double mass;
	   	    for(int i=0;i<blocks;i++)
	   	     {
	   	     	in>>mass;
	   	     	girl.push_back(mass);
	   	     }
	   	     for(int i=0;i<blocks;i++)
	   	     {
	   	     	in>>mass;
	   	     	boy.push_back(mass);
	   	     }
	   	     sort(boy.begin(),boy.end());
	   	      sort(girl.begin(),girl.end());
	   	        out<<"Case #"<<(t+1)<<": ";
	   	      out<<dwar(girl,boy)<<" ";
	   	      out<<war(girl,boy)<<endl;
	   }	
 }
