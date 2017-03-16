import sys
import itertools

class DataReader:
    def __init__(self, input_filename):
        self.data = [x.strip() for x in open(input_filename)]
        self.curr_line = 0
        
    def read_line(self):
        data = self.data[self.curr_line]
        self.curr_line += 1
        return data

    def read_int(self):
        return int(self.read_line())
    
    def read_ints(self):
        line = self.read_line()
        return [int(x) for x in line.split()]

    def read_floats(self):
        line = self.read_line()
        return [float(x) for x in line.split()]

class DataWriter:
    def __init__(self, output_filename):
        self.lines = []
        self.output_filename = output_filename
        self.num_case = 1

    def write_data(self, data):
        self.lines.append("%s\n" % data)
        
    def write_line(self, data):
        self.lines.append("Case #%i: %s\n" % (self.num_case, data))
        self.num_case += 1

    def write_int(self, num):
        self.write_line(str(num))

    def write_float(self, num):
        self.write_line(str(num))
        
    def write_ints(self, ints):
        self.write_line(" ".join([str(x) for x in ints]))

    def write_floats(self, floats):
        self.write_line(" ".join([str(x) for x in ints]))

    def flush(self):
        open(self.output_filename, "w").writelines(self.lines)

        
def dbg(*args):
    import inspect
    namespace = inspect.currentframe().f_back.f_locals
    to_output = []
    for arg in args:
        to_output.append(arg)
        to_output.append(namespace[arg])
    print ("%s=%s   " * len(args)) % tuple(to_output)

import string
consonats =  set(string.lowercase[:26]) - set("aeuoi")
assert len(consonats) == 21


INF = 999999999999999999999999

def cons_vows(s, n):
	intervals = []
	count = 0
	start = INF
	for idx, ch in enumerate(s):
            if ch in consonats:
                if start == INF:
                    start = idx
                count += 1
            else:
                if count >= n:
                    intervals.append((start, idx))
                start = INF
                count = 0

        if count >= n:
            intervals.append((start, len(s)))

	return intervals

	
X=  set([])

def count_interval(s, n, start, end, low_bound):
	count = (start - low_bound) * (len(s) - end + 1)
	for x in xrange(start - low_bound, start):
            for y in xrange(len(s) - end + 1, len(s)):
                X.add((x,y))
	#print "X", count
	for x in xrange(start, end-n+1):
		count += (len(s) - (x+n-1))
		for y in xrange(x+n-1, len(s)):
                    X.add((x,y))
	return count
		

def num_of_string(s, n):
        global X
        X = set([])
	intervals = cons_vows(s, n)

	count = 0
	low_bound = 0
	for start, end in intervals:
		this_count =  count_interval(s, n, start, end, low_bound)
		dbg("start","end","this_count","low_bound")
		print s[start:end]
		count += this_count
		low_bound = end - n + 1		
	return count


Y = set([])

def naive_sol(s, n):
    global Y
    Y = set([])
    count = 0
    for i in xrange(0, len(s)):
        for j in xrange(i+1, len(s)+1):
            if len(cons_vows(s[i:j], n)) > 0:
                Y.add((i,j))
                count += 1

    return count


def solve(input_filename, output_filename):
    reader = DataReader(input_filename)
    writer = DataWriter(output_filename)

    num_cases = reader.read_int()
    for i in xrange(num_cases):
        s, n = reader.read_line().split()
        n = int(n)
        dbg("s", "n")
        num_strings =  num_of_string(s,n)
        num_strings_naive = naive_sol(s,n)
        #if num_strings != num_strings_naive:
        #    print X.symmetric_difference(Y)
        #dbg("num_strings","num_strings_naive")
        #assert num_strings_naive == num_strings
        writer.write_int(num_strings_naive)
    writer.flush()

if __name__ == '__main__':
    solve(sys.argv[1], sys.argv[2])    
