import math
def solve(N):
    t =  range(1,N[0]+1)
    return " ".join(map(str,t))

def output_res(caseno,output, f):
    s = "Case #{}: {}".format(caseno,output)
    print(s)
    f.write(s + "\n")

f = open("input")
f = open("D-small-attempt2.in")
outfile = open("output","w+")
T = int(f.readline())
for case in range(1, T + 1):
    N = [int(x) for x in f.readline().split()]
    output_res(case, solve(N),outfile)

