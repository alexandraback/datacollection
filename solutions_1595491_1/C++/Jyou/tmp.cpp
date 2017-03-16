#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   for (int i=0;i<t;++i)
   {
	   int n,s,p;
	   cin >> n;
	   cin >> s;
	   cin >> p;
	   int ans=0;
	   for (int j=0;j<n;++j)
	   {
		   int tri=0;
		   cin >> tri;
		   if (tri>=p)
		   {
		   if (tri>=3*p-2) ++ans;
		   else if (tri>=3*p-4)  
		   {
				if (s>0)
				{
					++ans;
					--s;
				}
		   }
		   }
	   }
	   cout << "Case #" << i+1 << ": " << ans << endl;
   }
   return 0;
}
