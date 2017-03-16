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

INF = 9999999999999999999999

def num_ops_to_absorb(a, n, motes, op_num = 0):
    if op_num == n:
        return INF
    
    i = 0
    while i < len(motes):
        if a > motes[i]:
            a += motes[i]
            i += 1
        else:
            num_with_added = num_ops_to_absorb(a, n, [a-1] + motes[i:], op_num + 1)
            return min(1 + num_with_added, len(motes[i:]))
            
    return 0
            

def solve(input_filename, output_filename):
    reader = DataReader(input_filename)
    writer = DataWriter(output_filename)

    num_cases = reader.read_int()
    for i in xrange(num_cases):
        a,n = reader.read_ints()
        motes = list(reader.read_ints())
        motes = sorted(motes)

        num_ops =  num_ops_to_absorb(a,n, motes)
        print num_ops
        writer.write_int(num_ops)
        

    writer.flush()

if __name__ == '__main__':
    solve(sys.argv[1], sys.argv[2])    
