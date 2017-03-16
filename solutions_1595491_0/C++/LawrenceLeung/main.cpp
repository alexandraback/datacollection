#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
 	int nCase;
 	scanf("%d", &nCase);
 	for (int cId = 1; cId <= nCase; cId++)
 	{
	 	int N, S, p;
	 	scanf("%d%d%d", &N, &S, &p);
	 	int nDummySurprise = 0;
	 	int nMustSurprise = 0;
	 	int nTest = 0;
	 	int test[100];
	 	for (int i = 0; i < N; i++)
	 	{
	         int t;
 		 	 scanf("%d", &t);
 		 	 
 		 	 if (t >= p)	// no -ve score, so total must >= p
 		 	 {
  	   		    if (t < 3*p - 4)
  	   		    {
			   	   nDummySurprise++;
			    }
			    else if (t >= 3*p - 4 && t <= 3*p -3)
 		 	 	{
		  	       nMustSurprise++;
				}
				else
				{
					test[nTest++] = t;
				}
			 }
 			 else if (t >= 2)
 			 {
			  	  nDummySurprise++; 	  
			 }
	  	}
	 	int ans;	  	
	  	if (p == 0)
	  	{
 	       // assumption: valid input which is possible to have S surprise given the input
     	   ans = N;
	    }
	    else
	    {
		 	if (nMustSurprise > S)	// no enough surpise for the must-set
		 	{
 		 	   ans = nTest + S;
		    }
		    else // remain some surprise to resolve
		    {
			   ans = nTest + nMustSurprise;
			   /*
               S = S - nMustSurprise - nDummySurprise;
			   if (S <= 0)	// all surprise resolved
			   {
				   ans = nTest + nMustSurprise;
			   }
			   else	// need to resolve remaining surprise in the test set
			   {
				    int nResolved = 0;
					for (int i = 0; i < nTest; i++)
					{
						int k = test[i] / 3;
						if (test[i] >= 29 || test[i] <= 1) {
							continue;
						}
						else
						{
							nResolved++;
						}
					}
			   }
			   */
			}
		}
		printf ("Case #%d: %d\n", cId, ans);
	}
 	
    //system("PAUSE");
    return EXIT_SUCCESS;
}
