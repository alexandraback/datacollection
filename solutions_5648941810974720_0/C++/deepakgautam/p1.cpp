#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
int has[10000];
int main()
 {
 	freopen("abc.txt","r",stdin);
 	freopen("pqr.txt","w",stdout);
 	int t;
 	cin>>t;
 	int cas=1;
 	while(t--)
 	{
 		memset(has,0,sizeof has);
	 multiset<int> ss;
 	int n;
 	char Z='Z';
 	char E='E';
 	char R='R';
 	char O='O';
 	char A='A';char N='N';char T='T';char W='W';char H='H';
 	char F='F';char U='U';char I='I';
 	char V='V';char S='S';char X='X';
 	char G='G';
 		
 	
 	
 	 
 	 string s; 
 	 cin>>s;
 	// cout<<s<<endl;
 	 int len=s.length();
 	 for(int i=0;i<len;i++)
 	    {
 	  	 has[s[i]]++;
	   }
	   

    int cov=0;
    while(cov!=len)
     {
     	  while(1)
     	    {
     	    	int f=0;//ZERO
     	    	  if(has[Z]>0 && has[E]>0 && has[R]>0 && has[O]>0)
     	    	   {
     	    	   	 has[Z]--;
     	    	   	 has[E]--;
     	    	   	 has[R]--;
     	    	   	 has[O]--;
     	    	   	 ss.insert(0);
     	    	   	 cov+=4;
					}
					else break;
     	   	  
			}
			
			while(1)
     	    {
     	    	int f=0;//Ztwo
     	    	  if(has[T]>0 && has[W]>0 && has[O]>0 )
     	    	   {
     	    	   	 has[T]--;
     	    	   	 has[O]--;
     	    	   	 has[W]--;
     	    	   	 cov+=3;
     	    	   	 ss.insert(2);
					}
					else break;
     	   	  
			}
			
				while(1)
     	    {
     	    	int f=0;//EIGHT
     	    	  if(has[E]>0 && has[I]>0 && has[G]>0  && has[H]>0 && has[T]>0 )
     	    	   {
     	    	   	 has[E]--;
     	    	   	 has[I]--;
     	    	   	 has[G]--;
     	    	   	 has[H]--;
     	    	   	 has[T]--;
     	    	   	 cov+=5;
     	    	   	 ss.insert(8);
					}
					else break;
     	   	  
			}
			
			
			
				while(1)
     	    {
     	    	//cout<<" del 4 "<<endl;
     	    	int f=0;//FOUR
     	    	  if(has[F]>0 && has[O]>0 && has[U]>0  && has[R]>0  )
     	    	   {
     	    	   	 has[F]--;
     	    	   	 has[O]--;
     	    	   	 has[U]--;
     	    	   	 has[R]--;
     	    	   	 cov+=4;
     	    	   	 ss.insert(4);
					}
					else break;
     	   	  
			}
			
			
				while(1)
     	    {
     	    	int f=0;//FIVE
     	    	  if(has[F]>0 && has[I]>0 && has[V]>0  && has[E]>0  )
     	    	   {
     	    	   	 has[F]--;
     	    	   	 has[I]--;
     	    	   	 has[V]--;
     	    	   	 has[E]--;
     	    	   	
     	    	   	 cov+=4;
     	    	   	 ss.insert(5);
					}
					else break;
     	   	  
			}
			
			
			
				while(1)
     	    {
     	    	int f=0;//SIX
     	    	  if(has[S]>0 && has[I]>0 && has[X]>0  )
     	    	   {
     	    	   	 has[S]--;
     	    	   	 has[I]--;
     	    	   	 has[X]--;
     	    	   	cov+=3;
     	    	   	
     	    	   	 
     	    	   	 ss.insert(6);
					}
					else break;
     	   	  
			}
			
			
			
				while(1)
     	    {
     	    	int f=0;//NINE
     	    	  if(has[N]>0 && has[I]>0 && has[E]>0 && has[E]  )
     	    	   {
     	    	   	 has[N]--;
     	    	   	 has[N]--;
     	    	   	 has[E]--;
     	    	   	 	 has[I]--;
     	    	   	
     	    	   	cov+=4;
     	    	   	 
     	    	   	 ss.insert(9);
					}
					else break;
     	   	  
			}
			
				while(1)
     	    {
     	    	int f=0;//THREE
     	    	  if(has[T]>0 && has[H]>0 && has[R]>0  && has[E]>0 && has[E]>0  )
     	    	   {
     	    	   	 has[T]--;
     	    	   	 has[H]--;
     	    	   	 has[R]--;
     	    	   	 	 has[E]--;
     	    	   	 	 has[E]--;
     	    	   	
     	    	   	cov+=5;
     	    	   	 
     	    	   	 ss.insert(3);
					}
					else break;
     	   	  
			}
			
				while(1)
     	    {
     	    	int f=0;//SEVEN
     	    	  if(has[S]>0 && has[E]>0 && has[V]>0  && has[E]>0 && has[N]>0  )
     	    	   {
     	    	   	 has[S]--;
     	    	   	 has[E]--;
     	    	   	 has[V]--;
     	    	   	 	 has[E]--;
     	    	   	 	 has[N]--;
     	    	   	cov+=5;
     	    	   	
     	    	   	 
     	    	   	 ss.insert(7);
					}
					else break;
     	   	  
			}
				while(1)
     	    {
     	    //	cout<<" del "<<1<<endl;
     	    	int f=0;//ONE
     	    	  if(has[O]>0 && has[N]>0 && has[E]>0  )
     	    	   {
     	    	   	 has[O]--;
     	    	   	 has[N]--;
     	    	   	 has[E]--;
     	    	   	 cov+=3;
     	    	   	 ss.insert(1);
					}
					else break;
     	   	  
			}
			
			
	
			
	 }
	 	set<int>:: iterator it;
		cout<<"Case #"<<cas++<<": "; 
		 for(it=ss.begin();it!=ss.end();it++) cout<<*it;
		 
		 cout<<endl;
}
 }
