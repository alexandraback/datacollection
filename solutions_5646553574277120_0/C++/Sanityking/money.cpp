#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

int t, c, d, v, l[35], left;
bool pos[35], used[35];
FILE *inp, *out;

int main(){
	inp = fopen("a.in", "r");
	out = fopen("b.out", "w");
	ifstream fin("a.in");
	fin >> t;
	//scanf("%d", &t);
	for(int ti = 1; ti <= t; ++ti){
		int ans = 0;
		cout << "test" << endl;
		fin >> c >> d >> v;
		//cout << c << " " << d << " " << v << endl;
		//scanf("%d%d%d", &c, &d, &v);
		memset(pos, false, sizeof pos);
		memset(used, false, sizeof used);
		for(int a = 0; a < d; ++a){
			fin >> l[a];
			//cout << l[a] << endl;
			//scanf("%d", &l[a]);
			used[l[a]] = true;
		}
		
		sort(l, l+d);
		pos[0] = true;
		int conut = 0;
		//cout << "teest" << endl;
		for(int a = 0; a < d; ++a){
			for(int b = v; b >= l[a]; --b){
				if(!pos[b]){
					if(pos[b-l[a]]){
						pos[b] = true;
						++conut;
					}
				}
			}
		}
		
		while(conut < v){
			cout << conut << endl;
			for(int b = v; b > 0; --b){
				if(!pos[b]){
					//cout << conut << " " << b << endl;
					for(int a = 1; a <= v; ++a){
						if(used[a]) continue;
						if(b-a < 0) break;
						if(pos[b-a]){
							used[a] = true;
							++ans;
							//cout << a << endl;
							for(int ci = v; ci >= a; --ci){
								if(!pos[ci]){
									if(pos[ci-a]){
										pos[ci] = true;
										++conut;
									}
								}
							}
							break;
						}
					}
				}
			}
		}
		//cout << "yay" << endl;
		//cout << ans << endl;
		fprintf(out, "Case #%d: %d\n", ti, ans);
	}
	
	fclose(inp);
	fclose(out);
	return 0;
}
