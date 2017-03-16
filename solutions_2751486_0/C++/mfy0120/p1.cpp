#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main()
{
		int n;
		string ss;
		int aimd;
		ifstream ist("input1.in");
		ofstream ost("output1.out");

		ist >> n;
		for (int i = 1;i<=n;i++)
		{
				ist >> ss;
				ist >> aimd;
				int lenn = ss.length();
				int ans = 0;
				int pred = -1;
				int nowadd = 0;
				for (int i2 = 0;i2<=lenn-1;i2++)
				{
					if ((ss[i2] != 'a')&&(ss[i2] != 'e')&&(ss[i2] != 'i')&&(ss[i2] != 'o')&&(ss[i2] != 'u')) nowadd++;
					else nowadd = 0;
					if (nowadd == aimd){
						ans += (lenn-i2);
						ans += (i2 - aimd - pred)*(lenn-i2);
						pred = i2 - aimd + 1;
						nowadd -=1;
					}
					
				}
				//if (nowadd + 1 - aimd >=0) ans += nowadd + 1 - aimd;
				ost<< "Case #"<<i<<": "<<ans<<endl;
		}
		ist.close();
		ost.close();
}