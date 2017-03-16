#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <memory>
#include <assert.h>


#define NOT_USED(formal_param)  {(formal_param) = (formal_param);}


template<class T, class E>
inline bool contains(const T & Container, const E & Element)
{
	return find(Container.begin(), Container.end(), Element) != Container.end();
}


template<class T>
inline std::string to_string(const T & value)
{
	std::ostringstream oss;
	std::string res;
	oss.setf(std::ios::fixed); 
	oss.precision(15); 
	oss << value;
	res = oss.str();
	return res;
}


template<class T>
inline T from_string(const std::string & s)
{
	std::istringstream iss(s);
	T res;
	iss >> res;
	return res;
}


template<typename T>
inline bool from_string(const std::string & s, T & dest)
{
    std::istringstream iss(s);
    return iss >> dest != 0;
}



#ifdef _DEBUG

	inline void assert_false_plus(const std::string & message)
	{message;
 		assert(false);
	}

	inline void assert_false()				{ assert_false_plus(""); }

	#define assert_plus(expr, message)		{ if (!(expr)) assert_false_plus(message); }
	#define assert_(expr)					{ assert_plus(expr, ""); }

#else

	#define assert_false_plus(message)
	#define assert_false()
	#define assert_plus(expr, message)
	#define assert_(expr)

#endif






using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

typedef long long chunk_length;
typedef long long sent_size;
typedef int type;



int nb_boxes, nb_toys;


void step(
	vector<pair<stack<chunk_length>, type>> & Boxes,
	int b,
	vector<pair<stack<chunk_length>, type>> & Toys,
	int t,
	sent_size cur_sent,
	sent_size & max_sent
)
{
	if ((b == nb_boxes) || (t == nb_toys))
	{
		if (cur_sent > max_sent) max_sent = cur_sent;
		return;
	}

	auto & chunkBox = Boxes[b];
	auto & chunkToy = Toys[t];
	if (chunkBox.second == chunkToy.second)
	{
		auto n = min(chunkBox.first.top(), chunkToy.first.top());
		cur_sent += n;
		chunkBox.first.push(chunkBox.first.top() - n);
		chunkToy.first.push(chunkToy.first.top() - n);
		step(Boxes,	b+1, Toys, t, cur_sent, max_sent);
		step(Boxes,	b, Toys, t+1, cur_sent, max_sent);
		chunkBox.first.pop();
		chunkToy.first.pop();
	}
	else
	{
		step(Boxes,	b+1, Toys, t, cur_sent, max_sent);
		step(Boxes,	b, Toys, t+1, cur_sent, max_sent);
	}
}



string solveTest(int t)
{
	NOT_USED(t)

	fin >> nb_boxes >> nb_toys;
	vector<pair<stack<chunk_length>, type>> Boxes(nb_boxes);
	vector<pair<stack<chunk_length>, type>> Toys(nb_toys);

	for (int i = 0 ; i < nb_boxes ; ++i)
	{
		Boxes[i].first.push(0);
		fin >> Boxes[i].first.top() >> Boxes[i].second;
	}

	for (int i = 0 ; i < nb_toys ; ++i)
	{
		Toys[i].first.push(0);
		fin >> Toys[i].first.top() >> Toys[i].second;
	}

	sent_size max_sent;
	step(Boxes,	0, Toys, 0, 0, max_sent);

	return to_string(max_sent);
}



int main()
{
	assert_plus(fin, "could not open input file");
	assert_plus(fout, "could not create output file");
	fout.setf(ios::fixed);
	fout.precision(15);

	int T;
	fin >> T;
	{ string s; getline(fin, s); }
	for (int t = 1 ; t <= T ; ++t)
	{
		cout << "Case #" << t << "..." << endl;
		fout << "Case #" << t << ": " << solveTest(t) << endl;
	}

	return 0;
}

