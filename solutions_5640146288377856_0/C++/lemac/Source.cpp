#include<fstream>
#include<vector>
using namespace std;

int main(){
	ifstream in("A-small-attempt0.in");
	ofstream out("ans.txt");
	int T;
	in >> T;
	for (int t = 1; t <= T; t++){
		int r, c, w;
		in >> r >> c >> w;
		int ans = 0;
		if (w == 1){
			ans = r*c;
		}
		else {
			int k = c / w;
			ans += (r-1)*k;
			if (c%w == 0){
				ans += k + w - 1;
			}
			else {
				ans += k + w;
			}
		}
		out << "Case #" << t<<": " << ans << endl;
	}
	in.close();
	out.close();
}