#file_in = "A-test.in"
##file_in = "A-small-attempt0.in"
##file_out = "A-small-attempt0.out"
file_in = "A-large.in"
file_out = "A-large.out"

def solve(N):
    digits = set()
    for k in range(1,101):
        p = k*N
        digits.update([int(x) for x in str(p)])
        if len(digits) == 10:
            return p
    return "INSOMNIA"

with open(file_in, "r") as fin, open(file_out, "w") as fout:
    T = int(fin.readline().strip())
    for case in range(1, T + 1):
        print("Case #{0}".format(case))
        N = int(fin.readline().strip())
        fout.write("Case #{0}: {1}\n".format(case, solve(N)))

