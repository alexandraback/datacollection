#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int box_lock[200];
int total_keys[200];
map<int, int> box_keys[200];
set<int> locker_to_box[200];
map<int, int> keys;
vector<int> sol_order;
int in_k;
int in_n;
bool solve();
void add_locker_to_box(int used_key, int n_box)
{
	locker_to_box[used_key].insert(n_box);
}
void remove_locker_to_box(int used_key, int n_box)
{
	locker_to_box[used_key].erase(n_box);
}
void add_key(int key, int num=1)
{
	map<int, int>::iterator ittt_keys = keys.find(key);
	if(ittt_keys == keys.end())
	{
		keys[key] = num;
	}
	else
	{
		ittt_keys->second+=num;
	}
}
void remove_key(int key, int num=1)
{
	map<int, int>::iterator ittt_keys = keys.find(key);
	if(ittt_keys->second <= num)
	{
		keys.erase(ittt_keys);
	}
	else
	{
		ittt_keys->second-=num;
	}
}
int main(int argc, char **argv)
{
	
	char *filename_in = "input.txt";
	if(argc > 1)
	{
		filename_in = argv[1];
	}
	string filename_out(filename_in);
	filename_out.append("_output.txt");
	FILE *fi = fopen(filename_in, "rt");
	if(fi == NULL)
	{
		return -1;
	}
	FILE *fo = fopen(filename_out.c_str(), "wt");
	int in_t;
	fscanf(fi, "%d", &in_t);
	for(int it_t = 1; it_t <= in_t; it_t++)
	{
		for(int i = 0; i < 200; i++)
		{
			total_keys[i] = 0;
			box_keys[i].clear();
			locker_to_box[i].clear();
		}
		keys.clear();
		sol_order.clear();

		fscanf(fi, "%d %d", &in_k, &in_n);
		for(int k = 0; k < in_k; k++)
		{
			int in_kn;
			fscanf(fi, "%d", &in_kn);
			add_key(in_kn);
			total_keys[in_kn]++;
		}
		for(int it_n = 0; it_n < in_n; it_n++)
		{
			int inbox_ki;
			fscanf(fi, "%d", &box_lock[it_n]);
			fscanf(fi, "%d", &inbox_ki);
			for(int it_ki = 0; it_ki < inbox_ki; it_ki++)
			{
				int inbox_key;
				fscanf(fi, "%d", &inbox_key);
				map<int, int>::iterator it_k = box_keys[it_n].find(inbox_key);
				if(it_k == box_keys[it_n].end())
				{
					box_keys[it_n][inbox_key] = 1;
				}
				else
				{
					it_k->second++;
				}
				total_keys[inbox_key]++;
			}
			locker_to_box[box_lock[it_n]].insert(it_n);
		}
		bool isImpossible = false;
		for(int i = 0; i < 200; i++)
		{
			if(locker_to_box[i].size() > total_keys[i])
			{
				isImpossible = true;
			}
		}
		if(isImpossible || !solve())
		{
			fprintf(fo, "Case #%d: IMPOSSIBLE", it_t);
			fprintf(fo, "\n");
		}
		else
		{
			fprintf(fo, "Case #%d: ", it_t);
			for(int sol = 0; sol < sol_order.size(); sol++)
			{
				if(sol != 0){fprintf(fo, " ");}
				fprintf(fo, "%d", sol_order[sol] + 1);
			}
			fprintf(fo, "\n");
		}
	}
	fclose(fi);
	fclose(fo);
}
bool solve()
{
	vector<int> next_boxes;
	vector<int> next_boxes_temp;
	int total_size = 0;
	if(sol_order.size() == in_n)
	{
		return true;
	}
	for(map<int, int>::iterator it_keys = keys.begin(); it_keys != keys.end(); it_keys++)
	{
		total_size += locker_to_box[it_keys->first].size();
	}
	if(total_size == 0)
	{
		printf("Trial Failed: ");
		for(int sol = 0; sol < sol_order.size(); sol++)
		{
			if(sol != 0){printf(" ");}
			printf("%d", sol_order[sol] + 1);
		}
		printf("\n");
		return false;
	}
	next_boxes.resize(total_size);
	std::vector<int>::iterator it_npv;
	int cur_size = 0;
	for(map<int, int>::iterator it_keys = keys.begin(); it_keys != keys.end(); it_keys++)
	{
		next_boxes_temp = next_boxes;
		it_npv=std::set_union (locker_to_box[it_keys->first].begin(), locker_to_box[it_keys->first].end(), next_boxes_temp.begin(), next_boxes_temp.begin()+cur_size, next_boxes.begin());
		cur_size = it_npv-next_boxes.begin();
	}
	next_boxes.resize(cur_size);
	//find reachable set
	vector<int> new_keys;
	map<int, int> key_temp = keys;
	for(int n_boxit = 0; n_boxit < next_boxes.size(); n_boxit++)
	{
		for(map<int,int>::iterator it_boxkeys = box_keys[next_boxes[n_boxit]].begin(); it_boxkeys != box_keys[next_boxes[n_boxit]].end(); it_boxkeys++)
		{
			if(key_temp.find(it_boxkeys->first) == key_temp.end())
			{
				new_keys.push_back(it_boxkeys->first);
				key_temp[it_boxkeys->first] = it_boxkeys->second;
			}
		}
	}
	while(new_keys.size() > 0)
	{
		int new_key_check = new_keys[new_keys.size() - 1];
		new_keys.pop_back();
		for(set<int>::iterator itlocker = locker_to_box[new_key_check].begin(); itlocker != locker_to_box[new_key_check].end(); itlocker++)
		{
			for(map<int,int>::iterator itnek = box_keys[(*itlocker)].begin(); itnek != box_keys[(*itlocker)].end(); itnek++)
			{
				if(key_temp.find(itnek->first) == key_temp.end())
				{
					new_keys.push_back(itnek->first);
					key_temp[itnek->first] = itnek->second;
				}
			}
		}
	}
	for(int i = 0; i < 200; i++)
	{
		if(locker_to_box[i].size() > 0 && key_temp.find(i) == key_temp.end())
		{
			/*
			printf("EARLY TERMINATION: ");
			for(int sol = 0; sol < sol_order.size(); sol++)
			{
				if(sol != 0){printf(" ");}
				printf("%d", sol_order[sol] + 1);
			}
			printf("\n");
			*/
			return false;
		}
	}
	for(int n_boxit = 0; n_boxit < next_boxes.size(); n_boxit++)
	{
		//choose
		int n_box = next_boxes[n_boxit];
		int used_key = box_lock[n_box];
		//remove locker_to_box
		remove_locker_to_box(used_key, n_box);
		//remove keys used
		remove_key(used_key);
		//add box_keys
		for(map<int,int>::iterator it_boxkeys = box_keys[n_box].begin(); it_boxkeys != box_keys[n_box].end(); it_boxkeys++)
		{
			add_key(it_boxkeys->first, it_boxkeys->second);
		}
		//add sol_order
		sol_order.push_back(n_box);
		//recursive to next
		if(solve())
		{
			return true;
		}
		//rollback
		//remove sol_order
		sol_order.pop_back();
		//remove box_keys
		for(map<int,int>::iterator it_boxkeys = box_keys[n_box].begin(); it_boxkeys != box_keys[n_box].end(); it_boxkeys++)
		{
			remove_key(it_boxkeys->first, it_boxkeys->second);
		}
		//add keys used
		add_key(used_key);
		//add locker_to_box
		add_locker_to_box(used_key, n_box);
	}
	printf("Trial Failed: ");
	for(int sol = 0; sol < sol_order.size(); sol++)
	{
		if(sol != 0){printf(" ");}
		printf("%d", sol_order[sol] + 1);
	}
	printf("\n");
	return false;
}