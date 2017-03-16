/*
 * =====================================================================================
 *
 *       Filename:  2.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/08/2016 01:04:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gaurav (disisbig), giganticgemmic@gmail.com
 *   Organization:  PEC University of Technology,Chandigarh
 *
 * =====================================================================================
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
ifstream fin;
ofstream fout;
fin.open("input");
fout.open("output");

int T;
fin>>T;
for(int t=1;t<=T;t++)
{
		long long b,m;
		fin>>b>>m;
		long long arr[b+1];
		arr[b]=0;
		int j=0;
		bool ans[b+1][b+1];
		for (int  i = 1;  i < b+1;  i++) {
					for (int j = 1; j < b+1; j++) {
						ans[i][j]=0;
					}
		}
		for (int  i = b-1;  i>0;  i--) {
				arr[i]=pow(2,j++);
		}
		if(m>arr[1])
		{
				fout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
		}
		else
		{
				long long temp =m;
				int k=0;
				while(temp>0)
				{
						if((temp&1)==1)
						{
								int index=b-k-1;
								if(index!=1)
								ans[1][index]=1;

								for (int  i = index;  i <b;  i++) {
											for (int  j = i+1;  j <=b;  j++) {
												ans[i][j]=1;
											}
								}
						}
						temp=temp>>1;
						k++;
				}
				fout<<"Case #"<<t<<": "<<"POSSIBLE"<<endl;
				for (int  i = 1;  i <=b;  i++) {
							for (int  j = 1;  j <=b;  j++) {
								fout<<ans[i][j];
							}
							fout<<endl;
				}
		}

}

return 0;
}

