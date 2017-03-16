#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>  
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <math.h>
using namespace std;


string format;
int lines_per_case=0;
int no_cases=0;

vector<vector<vector<string>>> in_s;
vector<vector<vector<int>>> in_i;
vector<vector<vector<long long>>> in_l;
vector<vector<vector<double>>> in_d;
vector<vector<vector<char>>> in_c;

ofstream out;

/***********************************************************************
POSSIBLY USEFUL STUFF
/***********************************************************************/

template <class T>
bool from_string(T& t, const std::string& s, std::ios_base& (*f)(std::ios_base&)) {
  std::istringstream iss(s);
  return !(iss >> f >> t).fail();
}

template <typename T>
string tostr(const T& t) { 
	ostringstream os; os<<t; 
	return os.str();
} 


void debug_string() {
	for (unsigned int t=0;t<in_s.size();t++) {
		cout << "Case #" << t+1 << " strings:\n";
		for (unsigned int l=0;l<in_s[t].size();l++) {
			for (unsigned int r=0;r<in_s[t][l].size();r++) {
				cout << in_s[t][l][r] << "; ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

void debug_double() {
	for (unsigned int t=0;t<in_d.size();t++) {
		cout << "Case #" << t+1 << " doubles:\n";
		for (unsigned int l=0;l<in_d[t].size();l++) {
			for (unsigned int r=0;r<in_d[t][l].size();r++) {
				cout << in_d[t][l][r] << "; ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

void debug_int() {
	for (unsigned int t=0;t<in_i.size();t++) {
		cout << "Case #" << t+1 << " integers:\n";
		for (unsigned int l=0;l<in_i[t].size();l++) {
			for (unsigned int r=0;r<in_i[t][l].size();r++) {
				cout << in_i[t][l][r] << "; ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

void debug_char() {
	for (unsigned int t=0;t<in_i.size();t++) {
		cout << "Case #" << t+1 << " chars:\n";
		for (unsigned int l=0;l<in_c[t].size();l++) {
			for (unsigned int r=0;r<in_c[t][l].size();r++) {
				cout << in_c[t][l][r];
			}
			cout << "\n";
		}
		cout << "\n";
	}
}


string tobase(long long number, int base) {
	string ans;
	while (number>0) {
		int digit=number%base;
		if (digit<10) ans.insert(ans.begin(),digit+48); 
		else ans.insert(ans.begin(),digit+55);
		number/=base;
	}
	return ans;
}

long long frombase(string number, int base) {
	vector<char> data(number.begin(), number.end());
	long long ans=0;
	long long val=1;
	for (int i=data.size()-1;i>=0;i--) {
		int digit=0;
		if ((data[i]>=48) && (data[i]<=57)) digit=data[i]-48;
		if ((data[i]>=65) && (data[i]<=96)) digit=data[i]-55;
		if (data[i]>=97) digit=data[i]-87;
		ans+=digit*val;
		val*=base;
	}
	return ans;
}

long long fac(int i) {
	long long ans=1;
	for (int j=2;j<=i;j++) {
		ans*=j;
	}
	return ans;
}

long long pow(int i, int j) {
	if (j==1) return i;
	if (j==0) return 1;
	long long ans=i;
	for (int k=1;k<j;k++) {
		ans*=i;
	}
	return ans;
}

long long choose(int a, int b) {
	return fac(a)/(fac(b)*(fac(a-b)));
}

void fill(vector<vector<char>>& m, unsigned int x, unsigned int y, char filler) {
	if (m[x][y]==filler) return;
	char c=m[x][y];
	m[x][y]=filler;
	if (x<m[0].size()-1) if (c==m[x+1][y]) fill(m,x+1,y, filler);
	if (y<m.size()-1) if (c==m[x][y+1]) fill(m,x,y+1, filler);
	if (x>0) if (c==m[x-1][y]) fill(m,x-1,y, filler);
	if (y>0) if (c==m[x][y-1]) fill(m,x,y-1, filler);
}

int gcd(int a, int b) {
    int c;
    while (a!=0) {c=a; a=b%a; b=c;}
    return b;
}

int gcd(vector<int> a) {
    int ans;
    if(a.size()<2) return 0;
    ans = gcd(a[0], a[1]);
    for(unsigned int i=2;i<a.size();i++) {
        ans = gcd(ans, a[i]);
    }
    return ans;
}


/***********************************************************************
CODE GOES HERE
/***********************************************************************/
void solve(int i) {
	long long a=in_l[i][0][0];
	long long b=in_l[i][0][1];
	if (a<b) swap(a,b);
	long long k=in_l[i][0][2];
	long long c=0;
	for (long long bb=0;bb<b;bb++) {
		if ((a&bb)<k) c+=a;
	}
	for (long long aa=0;aa<a;aa++) {
		if ((aa&b)<k) c+=b;
	}
	cout << c << "\n";
	out << c << "\n";
}

/***********************************************************************
GCJ TEMPLATE
/***********************************************************************/
void load(string filename) {
	ifstream in (filename);
	string line,cell;
	vector<vector<string>> m;
	if (in.is_open())
	{
	    while ( getline (in ,line) )
	    {
			stringstream lineStream(line);
			vector<string> tmp;
			while( getline( lineStream, cell, ' ' ) ) {
				tmp.push_back(cell);
			}
			m.push_back(tmp);
		}
		in.close();
	}
	from_string<int>(no_cases, m[0][0], std::dec);
	unsigned int linenumber=1;
	for (int n=0;n<no_cases;n++) {
		unsigned int tmplines=lines_per_case;
		if (tmplines==0) {
			from_string<unsigned int>(tmplines, m[linenumber][0], std::dec);
			linenumber++;
			//tmplines--;
		}
		vector<vector<string>> tmp_s;
		vector<vector<int>> tmp_i;
		vector<vector<long long>> tmp_l;
		vector<vector<double>> tmp_d;
		vector<vector<char>> tmp_c;

		for (unsigned int l=linenumber;l<(linenumber+tmplines);l++) {
			vector<string> tmp_s2;
			vector<int> tmp_i2;
			vector<double> tmp_d2;
			vector<long long> tmp_l2;
			vector<vector<char>> tmp_c2;
			int fcpos=min(l-linenumber, format.length()-1);
			//int fcpos=l-linenumber;
			if (format.substr(fcpos,1).find('-')!=std::string::npos) {
				//ignore this line
			} else if (format.substr(fcpos,1).find('i')!=std::string::npos) {
				//integers
				for (unsigned int c=0;c<m[l].size();c++) {
					int itmp;
					from_string<int>(itmp, m[l][c], std::dec);
					tmp_i2.push_back(itmp);
				}
				tmp_i.push_back(tmp_i2);
			} else if (format.substr(fcpos,1).find('l')!=std::string::npos) {
				//long long integers
				for (unsigned int c=0;c<m[l].size();c++) {
					long long ltmp;
					from_string<long long>(ltmp, m[l][c], std::dec);
					tmp_l2.push_back(ltmp);
				}
				tmp_l.push_back(tmp_l2);
			} else if (format.substr(fcpos,1).find('d')!=std::string::npos) {
				//doubles
				for (unsigned int c=0;c<m[l].size();c++) {
					double dtmp;
					from_string<double>(dtmp, m[l][c], std::dec);
					tmp_d2.push_back(dtmp);
				}
				tmp_d.push_back(tmp_d2);
			} else if (format.substr(fcpos,1).find('c')!=std::string::npos) {
				//chars
				string stmp="";
				for (unsigned int c=0;c<m[l].size();c++) {
					stmp.append(m[l][c]);
					stmp.append(" ");
				}
				vector<char> ctmp(stmp.begin(), stmp.end()-1);
				tmp_c.push_back(ctmp);
			} else {
				//something else, save as strings
				for (unsigned int c=0;c<m[l].size();c++) {
					tmp_s2.push_back(m[l][c]);
				}
				tmp_s.push_back(tmp_s2);
 	 		}
		}
		in_s.push_back(tmp_s);
		in_d.push_back(tmp_d);
		in_i.push_back(tmp_i);
		in_l.push_back(tmp_l);
		in_c.push_back(tmp_c);
		linenumber+=tmplines;
	}
}

int main(int argc, char* argv[])
{
	if (argc!=2) return 0;

	//init io stuff
	string infilename=argv[1];
	string basefilename=infilename.substr(infilename.find_last_of("\\")+1,infilename.find(".in")-infilename.find_last_of("\\")-1);
	string outfilename="c:\\gcj\\";
	outfilename.append(basefilename).append(".out");
	out.open(outfilename.c_str());
	out.precision(7);

	//read input file
	cout << "Reading file...";
	lines_per_case=1;
	format ="l";
	load(infilename);
	cout << " done!\n\n";

	//solve
	for (int t=0;t<no_cases;t++) {
		cout << "Case #" << t+1 << ": \n";
		 out << "Case #" << t+1 << ": ";
		 solve(t);
	}

	out.close();

	//copy source
	string cpptarget="c:\\gcj\\";
	cpptarget.append(basefilename).append(".cpp");
	CopyFileA("d:\\codejam\\codejam\\codejam\\codejam.cpp", cpptarget.c_str(), false);
	cout << "\n\n";
	system("pause");
	return 1;
}