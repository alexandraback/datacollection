def solution(R,C,W):
    search = C // W
    sink = W-1 if C % W == 0 else W
    
    return R * search + sink

def print_all():
    n = 1
    for C in range(1,11):
        for W in range(1,C+1):
            print("Case #{}: {}".format(n, solution(1,C,W)))
            n += 1

def parse(inputfilename):
    it = iter(open(inputfilename))
    T = int(next(it))
    for i in range(T):
        line = next(it)
        R,C,W = map(int, line.split())
        print("Case #{}: {}".format(i+1, solution(R,C,W)))
  
# print_all()
import sys
if len(sys.argv) > 1:
    parse(sys.argv[1])
else:
    parse("A-small.in")