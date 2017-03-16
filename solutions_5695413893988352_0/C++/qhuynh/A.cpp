#include <bits/stdc++.h>

using namespace std;

char sc1[18], sc2[18];
string s1, s2;
std::vector<pair<string, int> > a,b;

void generate(string s, vector<pair<string, int> > * container){

	int st1,st2,st3, en1,en2, en3;

	st1 = st2 =st3 = 0;
	en1 = en2 = en3 = 9;

	if (s.length() == 3){
		if (s[0] != '?'){
			st1 = en1 = s[0] - 48;
		}

		if (s[1] != '?'){
			st2 = en2 = s[1] - 48;
		}

		if (s[2] != '?'){
			st3 = en3 = s[2] - 48;
		}


		for (int i=st1; i<= en1; i++)
			for (int j =st2; j <=en2; j++)
				for (int k = st3; k <= en3; k++){
					int t = i * 100 + j * 10 + k;
					string s = "";
					s +=  (char) (i + 48);
					s +=  (char) (j + 48);
					s +=  (char) (k + 48);
					container -> push_back(make_pair(s, t));
				}
	} else if (s.length() == 2){
		if (s[0] != '?'){
			st1 = en1 = s[0] - 48;
		}

		if (s[1] != '?'){
			st2 = en2 = s[1] - 48;
		}

		for (int i=st1; i<= en1; i++)
			for (int j =st2; j <=en2; j++)
				{
					int t = i * 10 + j;
					string s = "";
					s +=  (char) (i + 48);
					s +=  (char) (j + 48);
					container -> push_back(make_pair(s, t));
				}
	} else {
		if (s[0] != '?'){
			st1 = en1 = s[0] - 48;
		}
		
		for (int i=st1; i<= en1; i++)
				{
					int t = i;
					string s = "";
					s +=  (char) (i + 48);
					container -> push_back(make_pair(s, t));
				}
	}
}

int main(){
	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("test.out", "w", stdout);

	int test;
	scanf("%d\n", &test);


	for (int t =1; t <= test; t++){

		scanf("%s %s\n", &sc1, &sc2);

		s1 = string(sc1);
		s2 = string (sc2);		
		a.clear(); b.clear();

		generate(s1, &a);
		generate(s2, &b);

		int res = 11111111, resa, resb;

		for (int i =0; i < a.size(); i++)
			for (int j = 0; j < b.size(); j++){
				int tmp = abs(a[i].second - b[j].second);
				if (tmp < res){
					res = tmp;
					resa = i;
					resb = j;
				} else {
					if (res == tmp){
						if (a[resa].second > a[i].second){
							resa = i;
							resb = j;
						} else {
							if (a[resa].second  == a[i].second){
								if (b[resb].second > b[j].second){
									resa = i;
									resb = j;
								}
							}
						}
					}
				}
			}
		printf("Case #%d: %s %s\n", t, a[resa].first.c_str(), b[resb].first.c_str());
		
	}
}