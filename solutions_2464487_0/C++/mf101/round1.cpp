#include<iostream>

using namespace std;

long long MAX_LONG = (long long)2e18 + 1;
long long r = 0;


long long val(long long n)
{
	 long long tmp = 2LL * n * r ;
	 long long ans = 0;

	 if(n > MAX_LONG / r) return MAX_LONG;
	 ans += tmp;
	 
	 tmp = (( 2LL * (n-1) + 3LL ) * (n-1) ) + 1LL;
	 if(n > 1 && ( 2LL * (n-1) + 3LL ) > MAX_LONG / (n-1)) return MAX_LONG;

	 ans += tmp;

	 if(ans < 0) return MAX_LONG;
	 return ans;
}

long long binary_search(long long key, long long imin, long long imax)
{
  // continue searching while [imin,imax] is not empty
  while (imax >= imin)
    {
      /* calculate the midpoint for roughly equal partition */
      long long imid = (imin + imax) / 2;
 
      // determine which subarray to search
      if (val(imid) > key && val(imid-1) <= key)
        return imid-1;
      else if (val(imid) <= key)
        imin = imid + 1;
      else
        imax = imid - 1;
    }
  // key not found
  return -1;
}


int main()
{


	int cases;
	long long t;

	scanf("%d",&cases);
	for(int test = 1; test <= cases; test++)
	{
		scanf("%lld %lld",&r, &t);

		printf("Case #%d: %lld\n",test,binary_search(t, 1, t) );
	}

	return 0;

}