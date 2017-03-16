#include <iostream>
#include <vector>
#include <stdio.h>
#include <list>

using namespace std;

struct Level{
	int one, two;
	int rate;
};

int main(){
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		int N;
		cin >> N;
		list<Level> level;
		for(int n=0; n<N;n++){
			Level tmp;
			cin >> tmp.one >> tmp.two;
			tmp.rate = 0;
			level.push_back(tmp);
		}
		int star=0;
		int result = 0;
		int most_difficult_two;
		bool target_is_two;
		list<Level>::iterator it, target;
		while(!level.empty()){
			result++;
			target = level.end();
			for(it = level.begin(); it != level.end(); it++){
				/*if(it->rate == 1){
					cout << "  " << it->two << endl;
				}else{
					cout << it->one << " " << it->two << endl;
				}
				*/
				if(it->rate == 0 && it->two <= star){
					target = it;
					break;
				}
				else if((it->one <= star && it->rate==0 || it->two <= star) &&
					(target == level.end()
					|| (target->rate == 0 && it->two <= star || target->rate == 0 && it->rate == 0 && it->two > target->two))){
					target = it;
				}
			}
			if(target != level.end()){
				if(target->two<=star){
					star+=2-target->rate;
					target->rate=2;
				}else{
					star++;
					target->rate++;
				}
				if(target->rate>=2){
					level.erase(target);
				}
			}else{
				printf("Case #%d: Too Bad\n", t);
				goto END;
			}
		}
		printf("Case #%d: %d\n", t, result);
		END:
	}
}