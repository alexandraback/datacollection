#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility> 

bool fn (const std::pair<long long, int>& a , const std::pair<long long, int>& b)
{
	return (a.first > b.first) || (b.second > a.second);
}
void solve(int case_num, std::ifstream& input)
{
	std::vector< std::pair<long long, int> > data;
	long long start;
	long long gain;
	long long total;
	int c;
	std::vector< std::pair<long long, int> > used;
	
	input >> start >> gain >> c;
	if(start < gain) {
		gain = start;
	}	
	for(int i =0; i < c;++i) {
		long long v;
		input >> v;
		data.push_back(std::make_pair(v, i));
	}
	std::sort(data.begin(), data.end(), fn);
	total = gain * (c-1) + start;
		
	long long result =0;
	for(unsigned int i =0; i < data.size() && total >0;++i) {
		long long possible = start;
		for(int j =0; j < used.size();++j) {
			int dist = data[i].second - used[j].second;
			if(dist <0) {
				int x = gain * (-dist) - used[j].first;
				if(x <0) {
					possible = std::min(possible , start +x);
				}
			}
			else {
				possible = std::min(possible, gain * dist);
			}
		}
		if(possible > (total - (c - data[i].second) * gain) )
		{
			possible = total - (c - data[i].second) * gain;
			if(possible <0) {
				possible =0;
			}
		}
		total -= possible;
		result += possible * data[i].first;
		used.push_back(std::make_pair(possible, data[i].second));
	}

	std::cout << "Case #" << case_num << ": " << result << "\n";
	
}
int main(int argc, char* argv[]) 
{
	if(argc < 2) {
		std::cerr << "missing input file\n" ;
		return 1;
	}

	std::ifstream in(argv[1]);
	int c ;
	in  >> c;
	for(int i =1; i <=c;++i) {
		solve(i, in);
	}
	return 0;
}
