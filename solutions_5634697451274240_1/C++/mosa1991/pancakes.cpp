#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int solv(string m)
{
   int count = 0;

   for(int i=1;i<m.size();i++)
   {
	if(m[i] != m[i-1])
	   count++;
   } 

  if(m[m.size()-1] == '-')
	count++;
  return count;

}
int main() {
	int n;
	string m;
	cin >> n;
	for(int i=0;i<n;i++)
	{
	    cin >> m;
	    int ans = solv(m);
	    cout << "Case #" << i+1 <<": " << ans << endl;
	}
	return 0;
}
