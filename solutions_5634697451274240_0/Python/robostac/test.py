
def test(N, v):
    if len(N) == 0:
        return 0
    if N[0] == v:
        return test(N[1:], v)
    t = 1
    try:
        if (v == '-'):
            return 1 + test(N[N.index(v):],'+')
        else:
            return 1 + test(N[N.index(v):], '-')
    except ValueError:
        return 1

def solve(N):
    N = list(N)
    N.reverse()
    return test(N,'+')

def output_res(caseno,output, f):
    s = "Case #{}: {}".format(caseno,output)
    print(s)
    f.write(s + "\n")








f = open("input")
f = open("B-small-attempt0.in")

outfile = open("output","w+")
T = int(f.readline())
for case in range(1, T + 1):
    N = str(f.readline().strip())
    output_res(case, solve(N),outfile)

