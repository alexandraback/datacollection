#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	
	int nn;
	cin>>nn;
	
	for(int kk=0; kk<nn; kk++){
		cout << "Case #" << kk+1 << ":" << endl;
		
		int H,W,M,N;
		cin>>H>>W>>M;
		
		N = W*H-M;
		
		char **table = new char*[H];
		table[0] = new char[W*H];
		for(int i=1; i<H; i++)
			table[i] = &table[0][i*W];
			
		for(int i=0; i<H; i++)
		for(int j=0; j<W; j++)
			table[i][j] = '*';
		
		if( W == 1 || H == 1 || N == 1){
			
			int sp = 0;
			for(int i=0; i<H && sp<N; i++){
				for(int j=0; j<W && sp<N; j++){
					table[i][j] = '.';
					sp++;
				}
			}
			table[0][0] = 'c';
			for(int i=0; i<H; i++){
				for(int j=0; j<W; j++){
					cout << table[i][j];
				}
				cout << endl;
			}
			
			
		}
		else{
			
			int sl = N;
			bool found = false;
			vector<int> seq;
			
			int h=min(H, N/2);
			if(N-2*h == 1) h--;
			while(h>=2){
				
				if( sl == 1 ) break;
				
				if( sl - h == 1 ) h--;
				else if( sl <= h ){
					seq.push_back(sl);
					sl = 0;
					found = true;
					break;
				}
				else{
					
					sl -= h;
					seq.push_back(h);
					
				}
				
			}
			
			if( !found || seq.size()>W) cout << "Impossible" << endl;
			else{
				
				for(int i=0; i<seq.size(); i++){
					int xx = seq[i];
					for(int j=0; j<xx; j++)
						table[j][i] = '.';
				}
				table[0][0] = 'c';
				
				for(int i=0; i<H; i++){
					for(int j=0; j<W; j++){
						cout << table[i][j];
					}
					cout << endl;
				}
				
			}
			
			
		}
		
		
		delete table[0];
		delete table;
	}
	
}
