#!/Library/Frameworks/Python.framework/Versions/3.3/bin/python3.3
# Codejam ID 2974486
# Run with parameter
# -p for preprocessing
# -s for small input
# -l for large input
# -m=<int> for multithreading


from GCJ import GCJ
import math

def parse(infile):
    F, i, Z = GCJ.readfloats(infile)
    return F,i,Z
    
def solve(data):
    F, i, Z = data
    t = 2.0
    nt = t + i
    res = 0
    while Z*i > F*nt: 
        res += F/t
        t = nt
        nt += i
    res += Z/t
    return "%.7f" % res



if __name__ == "__main__":
    GCJ('B', solve, parse, None).run()

