#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <bitset>


using namespace std;
struct wall_part{
	wall_part(int s, int e, int str){
		this->start = s;
		this->end = e;
		this->strength = str;
	}
	int start;
	int end;
	int strength;
	bool operator<(const wall_part &p)const{
		return start < p.start;
	}
};
struct tribe{
	tribe(){}
	tribe(int d, int n, int w, int e, int s, int dd, int dp, int ds){
		this->first_attack = d;
		this->attack_amount = n;
		this->first_attack_west = w;
		this->first_attack_east = e;
		this->first_attack_strength = s;
		this->attack_time_interval = dd;
		this->travel_distance = dp;
		this->strength_change = ds;
	}
	int first_attack;
	int attack_amount;
	int first_attack_west;
	int first_attack_east;
	int first_attack_strength;
	int attack_time_interval;
	int travel_distance;
	int strength_change;
};
struct attack{
	attack(int i, int d, int w, int e, int s, int n){
		this->tribe_index = i;
		this->day = d;
		this->west = w;
		this->east = e;
		this->strength = s;
		this->attack_number = n;
	}
	int tribe_index;
	int day;
	int west, east;
	int strength;
	int attack_number;
	bool operator<(const attack &a) const{
		return day > a.day;
	}
};
set<wall_part> wall;
tribe tribes_data[1000];
void upgrade_wall(wall_part w){
	set<wall_part>::iterator start_it = wall.lower_bound(w);
	if(start_it == wall.end()){
		wall.insert(w);
		return;
	}
	if(start_it == wall.begin()){
		if(start_it->start > w.start){
			wall.insert(wall_part(w.start, start_it->start-1, w.strength));
		}
	}
	if(wall.rbegin()->end < w.end){
		wall.insert(wall_part(wall.rbegin()->end+1, w.end, w.strength));
	}
	//set<wall_part> to_remove;
	list<wall_part> to_insert;
	list<wall_part> to_remove;
	for(set<wall_part>::iterator start_it = wall.lower_bound(w); start_it != wall.end(); ++start_it){
		if(start_it->start > w.start)
			break;	
		if(start_it->end <= w.end){
			//start_it->strength = max(start_it->strength, w.strength);
			if(start_it->strength < w.strength){
				to_remove.push_back(*start_it);
				to_insert.push_back(wall_part(start_it->start, start_it->end, w.strength));
			}
		}else{
			to_insert.push_back(wall_part(w.end+1, start_it->end, start_it->strength));
			//start_it->end = w.end;
			//start_it->strength = w.strength;
			to_remove.push_back(*start_it);
			to_insert.push_back(wall_part(start_it->start, w.end, w.strength));
		}
	}
	for(list<wall_part>::iterator it = to_remove.begin(); it != to_remove.end(); ++it){
		wall.erase(*it);
	}
	for(list<wall_part>::iterator it = to_insert.begin(); it != to_insert.end(); ++it){
		wall.insert(*it);
	}
	wall_part curr(0,0,-1);
	//to_remove.clear();
	to_insert.clear();
	for(set<wall_part>::iterator it = wall.begin(); it != wall.end(); ++it){
		if(curr.strength == it->strength){
			curr.end = it->end;
		}else{
			if(curr.strength != -1)
				to_insert.push_back(curr);
			
			curr = wall_part(it->start, it->end, it->strength);
		}
	}
	if(curr.strength != -1)
		to_insert.push_back(curr);
	wall.clear();
	for(list<wall_part>::iterator it = to_insert.begin(); it != to_insert.end(); ++it){
		wall.insert(*it);
	}
	/*	to_remove.clear();
	//list<wall_part> to_remove;
	set<wall_part>::iterator prev = wall.end();
	int curr_start;
	for(set<wall_part>::iterator it = wall.begin(); it != wall.end(); ++it){
	if(prev != wall.end()){
	if(prev->strength == it->strength){
	prev->start= it->end;
	to_remove.push_back(*it);
	}else{
	prev = it;
	}
	}else{
	prev = it;
	}
	}*/
}
int main(){
	int T;
	scanf("%d", &T);
	for(int curr_case = 1; curr_case <= T; ++curr_case){
		wall.clear();
		//wall.push_back(wall_part(0,100,0));		
		int N;
		scanf("%d", &N);
		priority_queue<attack> pq;
		for(int i = 0; i < N; ++i){
			int d, n, w, e, s, dd, dp, ds;
			scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
			tribes_data[i]=tribe(d, n, w, e, s, dd, dp, ds);
			pq.push(attack(i, d, w, e, s, 1));
		}
		int amount = 0;
		while(!pq.empty()){
			list<wall_part> parts_list;
			int day = pq.top().day;
			while(!pq.empty() && pq.top().day == day){
				attack a = pq.top();
				pq.pop();
				wall_part w(a.west, a.east, a.strength);
				set<wall_part>::iterator start_it = wall.lower_bound(w);
				bool attacked = false;
				if((start_it == wall.begin() && w.start < start_it->start) || start_it == wall.end()){
					attacked = true;
				}else{
					int last = start_it->end;
					while(start_it != wall.end()){
						if(start_it->start > last+1){
							attacked = true;
							break;
						}
						last = start_it->end;
						if(start_it->strength < a.strength){
							attacked = true;
							break;
						}
						if(start_it->end >= a.east)
							break;
						++start_it;
					}
					if(last < a.east)
						attacked = true;
				}
				if(attacked){
					parts_list.push_back(w);
					++amount;
					//printf("Attack at day %d of tribe %d\n", a.day, a.tribe_index+1);
				}
				tribe t = tribes_data[a.tribe_index];
				if(a.attack_number < t.attack_amount){
					pq.push(attack(a.tribe_index, a.day+t.attack_time_interval, a.west+t.travel_distance, a.east+t.travel_distance, a.strength+t.strength_change, a.attack_number+1));
				}
			}
			for(list<wall_part>::iterator it = parts_list.begin(); it != parts_list.end(); ++it){
				upgrade_wall(*it);
			}
		}
		printf("Case #%d: %d\n", curr_case, amount);
	}
	return 0;
}
