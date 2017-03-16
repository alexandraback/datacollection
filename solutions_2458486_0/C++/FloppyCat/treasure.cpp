#include <iostream>
#include <vector>

struct Box {
	int type;
	std::vector<int> keys;
};

typedef std::vector<Box> Boxes;

struct State {
	int bits;
	std::vector<int> keys;
	bool canOpen(const Box &box) const {
		return keys[box.type] != 0;
	}
	bool isOpen(int boxIndex) const {
		return ((bits>>boxIndex)&1) != 0;
	}
	void open(int boxIndex, const Box &box) {
		bits |= 1 << boxIndex;
		keys[box.type]--;
		for  (auto key : box.keys)
			keys[key]++;
	}
	void close(int boxIndex, const Box &box) {
		bits -= 1 << boxIndex;
		keys[box.type]++;
		for  (auto key : box.keys)
			keys[key]--;
	}
};

struct States {
	std::vector<bool> impossible;
	Boxes boxes;
	State current;
	std::vector<int> find() {
		State &state = current;
		if (impossible[state.bits])
			return std::vector<int>();
		int goal = (1<<boxes.size()) - 1;
		for (int nextBox=0; nextBox<static_cast<int>(boxes.size()); nextBox++) {
			if (state.isOpen(nextBox))
				continue;
			if (state.canOpen(boxes[nextBox])) {
				state.open(nextBox, boxes[nextBox]);
				if (state.bits==goal)
					return std::vector<int>(1, nextBox+1);
				std::vector<int> res = find();
				if (!res.empty()) {
					res.push_back(nextBox+1);
					return res;
				}
				impossible[state.bits] = true;
				state.close(nextBox, boxes[nextBox]);
			}
		}
		impossible[state.bits] = true;
		return std::vector<int>();
	}

	States(const std::vector<int> keys, const Boxes &boxes): impossible(1<<boxes.size(), false), boxes(boxes) {
		int maxKey = boxes.front().type;
		for (const Box &box: boxes)
			maxKey = std::max(maxKey, box.type);
		current.keys = std::vector<int>(maxKey+1, 0);
		for (int key : keys)
			if (key<=maxKey)
				current.keys[key]++;
		current.bits = 0;
		for (Box &box: this->boxes) {
			for (size_t i=0; i<box.keys.size(); )
				if (box.keys[i]>maxKey) {
					std::swap(box.keys[i], box.keys.back());
					box.keys.pop_back();
				} else
					i++;
		}
	}
};

int main() {
	try {
		int T;
		std::cin.exceptions(std::ios::failbit|std::ios::badbit);
		std::cin >> T;
		for (int testIndex=1; testIndex<=T; testIndex++) {
			int K, N;
			std::cin >> K >> N;
			std::vector<int> keys(K);
			for (int &key : keys)
				std::cin >> key;
			Boxes boxes(N);
			for (Box &box : boxes) {
				std::cin >> box.type;
				int Ki;
				std::cin >> Ki;
				box.keys.resize(Ki);
				for (int &key : box.keys)
					std::cin >> key;
			}
			States s(keys, boxes);
			std::vector<int> res = s.find();
			std::cout << "Case #" << testIndex << ':';
			if (res.empty())
				std::cout <<  " IMPOSSIBLE";
			else
				for (auto it=res.rbegin(); it!=res.rend(); it++)
					std::cout << ' ' << (*it);
			std::cout << std::endl;
		}
	} catch (const std::exception &ex) {
		std::cerr << "exception: " << ex.what() << std::endl;
	}
	return 0;
}
