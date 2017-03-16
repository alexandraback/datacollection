#include<iostream>
#include<fstream>
#include<string>
using namespace std;
long long Gcd(long long A,long long B)
{
	if(A%B == 0ll) return B;
	return Gcd(B,A%B);
}
bool IsPowerOfTwo(long long X) {
	if(( X & (X-1)) == 0ll) return true;
	return false;
}
long long MaxPowerLesser(long long X)
{
	long long res = 1ll;
	while(res*2 <=X) res = res*(2ll);
	return res;
}
int Solve(long long P,long long Q)
{
	long long G = Gcd(P,Q);
	P/=G; Q/=G;
	if(!IsPowerOfTwo(Q)) return -1;
	Q/=2;
	if(P >= Q) return 1;
	long long X = MaxPowerLesser(P);
	return 1 + Solve(X,Q);
}
int main()
{
   ifstream fin("in.txt");
   ofstream fout("out.txt");
   int T; 
   fin>>T;
   for(int t = 1;t<=T;t++)
   {
	   fout<<"Case #"<<t<<": ";
	   long long P = 0,Q = 0;
	   string input; fin>>input;
	   int i = 0; 
	   for(;input[i] != '/';i++)
	   {
		   P = P*10;
		   P+= (long long)(input[i]-'0');
	   }
	   i++;
	   for(;i<input.length();i++)
	   {
		   Q*=10;
		   Q += (long long)(input[i] - '0');
	   }

	   int res = Solve(P,Q);
	   if(res == -1)  fout<<"impossible\n"; 
	   else
		fout<<res<<"\n";
   }
   fout.close();
   fin.close();
}