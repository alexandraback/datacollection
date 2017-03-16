#include <cstdio>
#include <cstdlib>

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

long long solve(long long N) {
	if(N == 0)
		return -1;

	int rv=1, digit, count = 0;
	long long tempN;
	bool flags[10];
	memset(flags, 0, sizeof(bool)*10);


	tempN = N;

	for(; ;rv++){
		tempN = N * rv;
		//cout<<"tempN: "<<tempN<<endl;
		do{
			digit = tempN%10;
			tempN /= 10;
			if(flags[digit] == false){
				flags[digit] = true;
				count++;
				if(count == 10)
					goto END;
			}
		}while(tempN>0);
	}

	END:

  return rv*N;
}

int main() {

  long long T, N;
  int rv;
  scanf("%lld", &T);
  for (int TC = 1; TC <= T; TC++) {
    scanf("%lld", &N);
    rv = solve(N);
    if(rv == -1)
    	cout<<"Case #"<<TC<<": INSOMNIA"<<endl;
    else
    	cout<<"Case #"<<TC<<": "<<rv<<endl;


  }
}
