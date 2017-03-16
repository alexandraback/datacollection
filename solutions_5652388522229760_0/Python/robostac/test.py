
def digits(v):
    t = 0
    v = str(v)
    for i in range(0,10):
        try:
            c = v.index(str(i))
            t = t | (1 << i)
        except ValueError:
            t = t
    return t


def solve(N):
    N = N[0]
    x = 0
    if N == 0:
        return "INSOMNIA"
    v = 0
    while(x != 1023):
        v += N
        x = x | digits(v)

    return v


def output_res(caseno,output, f):
    s = "Case #{}: {}".format(caseno,output)
    print(s)
    f.write(s + "\n")








f = open("input")
f = open("A-small-attempt0.in")

outfile = open("output","w+")
T = int(f.readline())
for case in range(1, T + 1):
    N = [int(x) for x in f.readline().split()]
    output_res(case, solve(N),outfile)

