#include <fstream>
#include <iostream>

using namespace std;

fstream in("in.txt", fstream::in);
fstream out("out.txt", fstream::out);

/*
void sort(int *a, int len){
	bool repeat = true;
	while(repeat){
		repeat = false;
		for(int i = 0; i < len - 1; i++){
			if(a[i] > a[i + 1]){
				repeat = true;
				int tmp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = tmp;
			}
		}
	}
}
*/

void solve(){
	/* Solve here the case and output the answer without "Case #X: " prefix, but with "endl" in the end */
	int N; in >> N;
	int *a = new int [N];
	int *b = new int [N];
	int *c = new int [N];
	for(int i = 0; i < N; i++){
		in >> a[i] >> b[i];
		c[i] = 0;
	}

	bool toobad = false;
	int nstars = 0, plays = 0, unfinished = N;
	while((unfinished > 0) && !toobad){
		toobad = true;
		for(int i = 0; i < N; i++){
			if((c[i] < 2) && (nstars >= b[i])){
				plays++; unfinished--;
				nstars += c[i] == 1 ? 1 : 2;
				c[i] = 2;
				toobad = false;
			}
		}
		if(toobad){
			int index = -1, maxb = 0;
			for(int i = 0; i < N; i++){
				if((c[i] == 0) && (nstars >= a[i]) && (b[i] > maxb)){
					maxb = b[i]; index = i;
				}
			}
			if(index >= 0){
				plays++; nstars++; c[index] = 1;
				toobad = false;
			}
		}
	}

	if(toobad)
		out << "Too Bad" << endl;
	else
		out << plays << endl;
	
	/*
	sort(a, N);
	sort(b, N);
	
	int nstars = 0, res = 0;
	for(int i = 0; i < N; i++){
		res++;
		if(nstars >= b[i])
			nstars += 2;
		else if(nstars >= a[i]){
			nstars += 1;
			res++;
			if(nstars >= b[i])
				nstars += 1;
			else{
				out << "Too Bad" << endl;
				delete[] a;
				delete[] b;
				return;
			}
		}
		else{
			out << "Too Bad" << endl;
			delete[] a;
			delete[] b;
			return;
		}
	}
	*/

	//out << res << endl;

	delete[] a;
	delete[] b;
	delete[] c;
}

int main(){
	int T; in >> T;
	for(int t = 0; t < T; t++){
		out << "Case #" << t + 1 << ": ";
		solve();
	}
	return 0;
}
