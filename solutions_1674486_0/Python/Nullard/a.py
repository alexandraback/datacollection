import os.path, glob
PROBLEM = os.path.basename(__file__)[0].upper()
DL_DIR = os.path.join(os.environ['USERPROFILE'], 'Downloads', PROBLEM)
if os.path.exists(DL_DIR + '-large.in'):
    INP_PATH = DL_DIR + '-large.in'
    OUT_PATH = DL_DIR + '-large.ot'
else:
    inputs = glob.glob(DL_DIR + '-small-attempt[0-9].in')
    maxnum = -1
    for inp_fn in inputs:
        if int(inp_fn[-4]) > maxnum: maxnum = int(inp_fn[-4])
    if maxnum > -1:
        INP_PATH = DL_DIR + '-small-attempt' + str(maxnum) + '.in'
        OUT_PATH = DL_DIR + '-small-attempt' + str(maxnum) + '.ot'
    else:
        INP_PATH = os.path.join('..', 'data', PROBLEM + '.in')
        OUT_PATH = os.path.join('..', 'data', PROBLEM + '.ot')

in_file = open(INP_PATH)
out_file = open(OUT_PATH, 'w')

def pp(s):
    out_file.write(s + '\n')
    print s

nodes = dict()

class cls(object):
    def __init__(self, num, parents):
        self.parents = parents
        self.num = num
        
    def check(self, st):
        if not st: st = set()
        for parent in self.parents:
            if parent in st:
                return True
            st.add(parent)
            if parent.check(st): return True
        return False

NUM_CASES = int(in_file.readline().strip())
for case in range(1, NUM_CASES + 1):
    inherited_from = set()
    soln = ''
    data_size = int(in_file.readline().strip())
    for i in range(1, data_size + 1):
        data = map(int, in_file.readline().strip().split())
        data = data[1:]
        parents = []
        if len(data): inherited_from.add(i)
        for ele in data:
            if ele not in nodes:
                nodes[ele] = cls(ele, [])
            parents.append(nodes[ele])
        if i not in nodes:
            nodes[i] = cls(i, [])
        nodes[i].parents = parents
    found = False
    for i in inherited_from:
        if nodes[i].check(None):
            found = True
            break
    if found: soln = 'Yes'
    else: soln = 'No'
    
    pp('Case #' + str(case) + ': ' + str(soln))
out_file.close()
in_file.close()
