#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int rpos;
	int cpos;
	int value;
};
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
		out<<"Case #"<<(t+1)<<":"<<endl;
		   int r,c;
		   in>>r>>c;
		    int mines;
		   in>>mines;
		    char a[r][c];
		      for(int i=0;i<r;i++)
		      {
		         for(int j=0;j<c;j++)
		              a[i][j]='.';
		      }
		      if((r*c)-1==mines)
		      {
		      	  for(int i=0;i<r;i++)
		      	  {
		      	     for(int j=0;j<c;j++)
		      	     {
		      	            if(i==(r-1) && j==(c-1))
		      	              out<<"c";
		      	              else
		      	              out<<"*";
		      	     }
		      	       out<<endl;
		          }
		        
		          
		          continue;
		      }
		      if(r>c)
		      {
		      	int flag=0;
		      	
		      	int rpos=0,cpos=0;
		      	  int tempr=r;
		      	  int tempmines=mines;
		      	  int stop;
		      	 	  for(int i=0;i<r;i++)
		      	 	   {   
							 for(int j=0;j<c;j++) //rows
		      	 	           {
		      	 	           	 if(tempmines==0)
		      	 	           	 {
		      	 	           	 	 rpos=i;
		      	 	           	 	 cpos=j;
		      	 	           	 	  flag=0;
		      	 	           	    break;
		      	 	             }
		      	 	           	   a[i][j]='*';
		      	 	           	   tempmines--;
		      	 	           }
		      	 	         if(tempmines==0)
		      	 	           	    break;
		      	 	           	    tempr--;
		      	 	           	    if(tempr==c)
		      	 	           	    {
		      	 	           	    	stop=i;
		      	 	           	     break;
		      	 	           	    }
		                }
		                
		                int ipos=stop,jpos=0;
		                  
		                  ipos++;
		                while(tempmines!=0)
		                {
		                	 for(int i=jpos;i<c;i++)//rows
		                	 {
		                	 	if(tempmines==0)
		                	 	{
		                	 		 rpos=ipos;
		                	 		 cpos=i;
		                	 		 flag=0;
		                	 	 break;
		                	    }
		                	 	a[ipos][i]='*';
								 tempmines--;
		                	 }
		                	 if(tempmines==0)
		                	 break;
		                	  
		                	 for(int i=ipos+1;i<r;i++)//col
		                	 {
		                	 	if(tempmines==0)
								  {
								  	rpos=i;
								  	cpos=jpos;
								  	flag=1;
								  	break;
								  }
		                	       a[i][jpos]='*';
		                	       tempmines--;
							 }
							 if(tempmines==0)
							 break;
						       ipos++;
						       jpos++;
						      
		                	 
		                }
		                if(c>1 && r>1)
		                {
		                if(flag==0)
		                 {
		                 	
		                 	 cpos-=1;
		                 	 if(cpos+1==(c-1))
		                 	   {
		                 	   	for(int i=0;i<c;i++)
		                 	   	    if(a[rpos+1][i]=='.')
		                 	   	    {
		                 	   	    	a[rpos+1][i]='*';
		                 	   	    	 a[rpos][cpos]='.';
		                 	   	    	 break;
		                 	   	    }
		                 	   }
		                 }
		                 if(flag==1)
		                 {
		                 	
		                 	  rpos-=1;
		                 	if(rpos+1==(r-1))
		                 	{
		                 		
		                 		for(int i=0;i<r;i++)
		                 	   	    if(a[i][cpos+1]=='.')
		                 	   	    {
		                 	   	    	a[i][cpos+1]='*';
		                 	   	    	 a[rpos][cpos]='.';
		                 	   	    	 break;
		                 	   	    }
		                 	}
		                 }
		             }
		                
		      }
		      if(c>r)
		      {
		      	 int flag=-1;
		      	int rpos=0,cpos=0;
		      	  int tempc=c;
		      	  int tempmines=mines;
		      	  int stop;
		      	 	  for(int i=0;i<c;i++)
		      	 	   {   
							 for(int j=0;j<r;j++)//col
		      	 	           {
		      	 	           	 if(tempmines==0)
		      	 	           	    {
		      	 	           	    	rpos=j;
		      	 	           	    	cpos=i;
		      	 	           	    	flag=1;
		      	 	           	    	break;
		      	 	           	    }
										
		      	 	           	   a[j][i]='*';
		      	 	           	   tempmines--;
		      	 	           }
		      	 	         if(tempmines==0)
		      	 	           	    break;
		      	 	           	    tempc--;
		      	 	           	    if(tempc==r)
		      	 	           	    {
		      	 	           	    	stop=i;
		      	 	           	     break;
		      	 	           	    }
		                }
		                
		                int ipos=0,jpos=stop;
		                    
		                  jpos++;
		                while(tempmines!=0)
		                {
		                	
		                	  
		                	 for(int i=ipos;i<r;i++)//col
		                	 {
		                	 	if(tempmines==0)
		                	 	{
		                	 		rpos=i;
		                	 		cpos=jpos;
		                	 		flag=1;
		                	 		break;
		                	 	}
		                	       a[i][jpos]='*';
		                	       tempmines--;
							 }
							 if(tempmines==0)
							 break;
							  for(int i=jpos+1;i<c;i++)//rows
		                	 {
		                	 	if(tempmines==0)
								  {
								     rpos=ipos;
									 cpos=i;
									 flag=0;
									 break;	
								  }
		                	 	a[ipos][i]='*';
								 tempmines--;
		                	 }
		                	 if(tempmines==0)
		                	 break;
						       ipos++;
						       jpos++;
						      
			 
		                }
		                 if(r>1 && c>1)
		                 {
		                if(flag==0)
		                 {
		                 	
		                 	 cpos-=1;
		                 	 if(cpos+1==(c-1))
		                 	   {
		                 	   	for(int i=0;i<c;i++)
		                 	   	    if(a[rpos+1][i]=='.')
		                 	   	    {
		                 	   	    	a[rpos+1][i]='*';
		                 	   	    	 a[rpos][cpos]='.';
		                 	   	    	 break;
		                 	   	    }
		                 	   }
		                 }
		                 if(flag==1)
		                 {
		                 	
		                 	  rpos-=1;
		                 	if(rpos+1==(r-1))
		                 	{
		                 		
		                 		for(int i=0;i<r;i++)
		                 	   	    if(a[i][cpos+1]=='.')
		                 	   	    {
		                 	   	    	a[i][cpos+1]='*';
		                 	   	    	 a[rpos][cpos]='.';
		                 	   	    	 break;
		                 	   	    }
		                 	}
		                 }
		               }
		                
		      }
		      if(r==c)
		      {
		      	 int flag=0;
		      	  int rc=0;
		      	 int rpos=0,cpos=0;
		      	 int ipos=0,jpos=0;
		                  int tempmines=mines;
		                while(tempmines!=0)
		                {
		                	 for(int i=jpos;i<c;i++)//row
		                	 {
		                	 	if(tempmines==0)
		                	 	{
		                	 		 rpos=ipos;
		                	 		   cpos=i;
		                	 		   flag=0;
		                	 	 break;
		                	    }
		                	 	a[ipos][i]='*';
								 tempmines--;
		                	 }
		                	 if(tempmines==0)
		                	 break;
		                	  
		                	 for(int i=ipos+1;i<r;i++)//col
		                	 {
		                	 	if(tempmines==0)
		                	 	 {
		                	 	 	rpos=i;
		                	 	 	 cpos=jpos;
		                	 	 	  flag=1;
								  break;
							     }
		                	       a[i][jpos]='*';
		                	       tempmines--;
							 }
							 if(tempmines==0)
							 break;	
						       ipos++;
						       jpos++;
						      
		                	 
		                }
		                 if(r>1 && c>1)
		                 {
		                if(flag==0)
		                 {
		                 	
		                 	 cpos-=1;
		                 	 if(cpos+1==(c-1))
		                 	   {
		                 	   	for(int i=0;i<c;i++)
		                 	   	    if(a[rpos+1][i]=='.')
		                 	   	    {
		                 	   	    	a[rpos+1][i]='*';
		                 	   	    	 a[rpos][cpos]='.';
		                 	   	    	 break;
		                 	   	    }
		                 	   }
		                 }
		                 if(flag==1)
		                 {
		                 	
		                 	  rpos-=1;
		                 	if(rpos+1==(r-1))
		                 	{
		                 		
		                 		for(int i=0;i<r;i++)
		                 	   	    if(a[i][cpos+1]=='.')
		                 	   	    {
		                 	   	    	a[i][cpos+1]='*';
		                 	   	    	 a[rpos][cpos]='.';
		                 	   	    	 break;
		                 	   	    }
		                 	}
		                 }
		              }
		      }
		      for(int i=0;i<r;i++)
		      {
		      	 for(int j=0;j<c;j++)
		      	 {
		      	
		      	 	  if(a[i][j]=='.')
		      	 	  {
		      	 	  	  int count=0;
		      	 	  	  if(i-1>=0)
		      	 	  	  {
		      	 	  	  	   if(a[i-1][j]=='*')
		      	 	  	  	    count++;
		      	 	  	  }
		      	 	  	  if(i+1<r)
		      	 	  	  {
		      	 	  	  	   if(a[i+1][j]=='*')
		      	 	  	  	    count++;
		      	 	  	  }
                           if(j-1>=0)
                           {
                           	  if(a[i][j-1]=='*')
                           	   count++;
                           }
                           if(j+1<c)
                           {
                           	  if(a[i][j+1]=='*')
                           	   count++;
                           }
                           if(i-1>=0 && j-1>=0)
                            {
                            	 if(a[i-1][j-1]=='*')
                            	  count++;
                            }
                             if(i-1>=0 && j+1<c)
                            {
                            	 if(a[i-1][j+1]=='*')
                            	  count++;
                            	
                            }
                            if(i+1<r && j+1<c)
                            {
                            	if(a[i+1][j+1]=='*')
                            	  count++;
                            }
                            if(i+1<r && j-1>=0)
                            {
                            	 if(a[i+1][j-1]=='*')
                            	   count++;
                            }
                            a[i][j]=char(count+48);
		      	 	  }
		      	 }
		      }
		        queue<node> s;
		         node corner;
		         corner.rpos=(r-1);
		         corner.cpos=(c-1);
		         corner.value=int(a[r-1][c-1])-48;
		        
		        s.push(corner);
		        while(!s.empty())
		        {		        	  node f=s.front();
		        	      int i=f.rpos;
		        	      int j=f.cpos;
		    
		        	if(f.value==0)
		        	{
		        	
		             if(i-1>=0)
		      	 	  	  {
		      	 	  	  	      node n;
		      	 	  	  	      n.rpos=i-1;
		      	 	  	  	      n.cpos=j;
		      	 	  	  	      n.value=int(a[i-1][j])-48;
		      	 	  	  	      a[i-1][j]='.';
		      	 	  	  	      s.push(n);
		      	 	  	  }
		      	 	  	  if(i+1<r)
		      	 	  	  {
		      	 	  	  	  node n;
		      	 	  	  	      n.rpos=i+1;
		      	 	  	  	      n.cpos=j;
		      	 	  	  	      n.value=int(a[i+1][j])-48;
		      	 	  	  	      a[i+1][j]='.';
		      	 	  	  	      s.push(n);
		      	 	  	  }
                           if(j-1>=0)
                           {
                           	  node n;
		      	 	  	  	      n.rpos=i;
		      	 	  	  	      n.cpos=j-1;
		      	 	  	  	      n.value=int(a[i][j-1])-48;
		      	 	  	  	        a[i][j-1]='.';
		      	 	  	  	      s.push(n);
                           }
                           if(j+1<c)
                           {
						         node n;
		      	 	  	  	      n.rpos=i;
		      	 	  	  	      n.cpos=j+1;
		      	 	  	  	      n.value=int(a[i][j+1])-48;
		      	 	  	  	       a[i][j+1]='.';
		      	 	  	  	      s.push(n);
                           }
                           if(i-1>=0 && j-1>=0)
                            {
                            	 node n;
		      	 	  	  	      n.rpos=i-1;
		      	 	  	  	      n.cpos=j-1;
		      	 	  	  	      n.value=int(a[i-1][j-1])-48;
		      	 	  	  	      a[i-1][j-1]='.';
		      	 	  	  	      s.push(n);
                            }
                             if(i-1>=0 && j+1<c)
                            {
                            	 node n;
		      	 	  	  	      n.rpos=i-1;
		      	 	  	  	      n.cpos=j+1;
		      	 	  	  	      n.value=int(a[i-1][j+1])-48;
		      	 	  	  	      a[i-1][j+1]='.';
		      	 	  	  	      s.push(n);
                            	
                            }
                            if(i+1<r && j+1<c)
                            {
                            	node n;
		      	 	  	  	      n.rpos=i+1;
		      	 	  	  	      n.cpos=j+1;
		      	 	  	  	      n.value=int(a[i+1][j+1])-48;
		      	 	  	  	      a[i+1][j+1]='.';
		      	 	  	  	      s.push(n);
                            }
                            if(i+1<r && j-1>=0)
                            {
                            	 node n;
		      	 	  	  	      n.rpos=i+1;
		      	 	  	  	      n.cpos=j-1;
		      	 	  	  	      n.value=int(a[i+1][j-1])-48;
		      	 	  	  	      a[i+1][j-1]='.';
		      	 	  	  	      s.push(n);
                            }
		             }
		             s.pop();
		        }
		         a[r-1][c-1]='C';
		         int flag=0;
		         for(int i=0;i<r;i++)
		         {
		           for(int j=0;j<c;j++)
		             if(int(a[i][j])>=48 && a[i][j]<57) 
		             {
		                flag=1;
		              }
		         }
		         
		         if(flag==1)
		         {
		           out<<"Impossible"<<endl;
		             continue;
		         }
		       for(int i=0;i<r;i++)
		       {
		         for(int j=0;j<c;j++)
		            out<<a[i][j];
		          out<<endl;
			   }
			
	}           
}
