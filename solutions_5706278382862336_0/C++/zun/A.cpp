#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int GetHCF(int firstNum, int secondNum) {
     while (firstNum != 0 && secondNum != 0)
     {
         if (firstNum > secondNum)
         {
            firstNum %= secondNum;
         }
         else
         {
            secondNum %= firstNum;
         }
     }

     if (firstNum == 0)
     {
         return secondNum;
     }
     else
     {
         return firstNum;
     }
}

int main() {
  ifstream fin("A.in");
	ofstream fout("A.out");
	int t;
	fin>>t;
	for( int tt=0; tt<t; tt++) {
				long long int p=0,q=0;
				string A;
				fin>>A;
				int i;
				for(i=0; i<A.size(); i++) {
				  if(A[i]=='/') {
					  i++;
						break;
					}
					else {
						p*=10;
						p += (A[i]-48);
					}
				}
				for(;i<A.size(); i++) {
					q*=10;
					q+=A[i]-48;
				}
				int hcf = GetHCF(p,q);
				p /= hcf;
				q /= hcf;
				int count = 0;
				
				while(p<q) {
					p*=2;
					count++;
				}
				bool flag =true;
				while(q>1) {
				  if(q%2==1) {
					  fout<<"Case #"<<tt+1<<": impossible"<<endl;
						flag = false;
						break;
					}
					q/=2;
				}
				if(flag)
				fout<<"Case #"<<tt+1<<": "<<count<<endl;
	}
}