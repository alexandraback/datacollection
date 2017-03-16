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

def path_x(x):
	if x == 0:
		return ""
	count = abs(x) 
	if x > 0: # EAST
		return "WE" * count
	else:
		return "EW" * count

def path_y(y):
	if y == 0:
		return ""
	count = abs(y)
	if y > 0: # NORTH
		return "SN" * count
	else:
		return "NS" * count

def path_to_target(x,y):
	return path_x(x) + path_y(y)

def execute_path(path):
    x,y = 0,0
    jump = 1
    for ch in path:
        if ch == "N":
            y += jump
        elif ch == "S":
            y -= jump
        elif ch == "E":
            x += jump
        elif ch == "W":
            x -= jump
        else:
            assert False
        jump += 1
    return x,y

def solve(input_filename, output_filename):
    reader = DataReader(input_filename)
    writer = DataWriter(output_filename)

    num_cases = reader.read_int()
    for i in xrange(num_cases):
        x,y = reader.read_ints()
        pathy = path_to_target(x,y)
        #print x,y
        #print pathy
        #print "CORRECT", execute_path(pathy)
        #assert x == execute_path(pathy)[0]
        #assert y == execute_path(pathy)[1]
        writer.write_line(pathy)
        

    writer.flush()

if __name__ == '__main__':
    solve(sys.argv[1], sys.argv[2])    
