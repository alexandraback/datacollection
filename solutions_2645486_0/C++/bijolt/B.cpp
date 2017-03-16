#include <iostream>
#include <fstream>


using namespace std;


int maxgain(int v[], int E, int pos, int ETotal, int R, int N)
{
	if (pos == N) return 0;
	
	int maxim=0 ,mygain;
	for (int i=0; i <= E ;i++){
		int efinal = E-i+R;
		if(ETotal <= efinal) efinal = ETotal;
		
		mygain = v[pos]*i + maxgain(v,efinal,pos+1,ETotal,R,N);
		
		if(mygain > maxim) maxim = mygain;
	}
	return maxim;
}

int main()
{

ifstream fi;
ofstream fo;
fi.open("input.in");
fo.open("output.in");

int T;
fi >> T;
for (int i=1; i<=T; i++)
{
int E,R,n;
fi>>E>>R>>n;
int * v  = new int [n];

for(int j=0; j<n;j++)
fi >> v[j];

int gain = maxgain(v,E,0,E,R,n);
fo << "Case #" << i << ": " << gain<<endl;
}


fi.close();
fo.close();
}
