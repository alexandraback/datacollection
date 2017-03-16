#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int query(int w, int len){
	if (w > len)
		return 5000;
	if (w == len)
		return w;
	if (w == 1)
		return len;
	int min = len;
	for (int i = 0; i<w; i++){
		int start = i - w + 1;
		int end = i + w;
		start = start >= 0 ? start : 0;
		end = end <= len ? end : len;
		int hit = query(w-1,end-start);
		start = w;
		end = w + 1 <= len ? w + 1 : len;
		int ql = query(w, start);
		int qr = query(w, len - end);
		int miss = 5000;
		if (start >= w){
			int missL = ql;// +(len - end) / w;
			if (len - end >= w){
				int t = start / w + qr;
				missL = missL > t ? missL : t;
			}
			miss = missL;
		}
		if (len - end >= w){
			int missR = qr;
			if (start >= w){
				int t = (len - end) / w + ql;
				missR = missR > t ? missR : t;
			}
			if (miss > missR)
				miss = missR;
		}
		int max = hit > miss ? hit : miss;
		min = min < max ? min : max;
	}
	return min + 1;
}

int main(){
	int n;
	ifstream inf("A-small-attempt4.in");
	ofstream outf("A-small-attempt4.out");
	inf >> n;
	for (int i = 1; i <= n; i++){
		int R, C, W,tot = 0;
		inf >> R >> C >> W;
		if (W == 1)
			tot = R*C;
		else{
			tot = (R - 1) * (C / W);
			tot += query(W, C);
		}
		outf << "Case #" << i << ": " << tot << "\n";
	}


	return 0;
}