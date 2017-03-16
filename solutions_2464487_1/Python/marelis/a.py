import math
import mpmath
mpmath.mp.dps = 100

def solve(r, t):
    d = mpmath.sqrt((2*r-1)*(2*r-1) + 8*t)
    n1 = (-2*r + 1 + d)/4
    print(int(n1))
    print()
    return str(int(n1))

f_in = open("input.txt")
f_out = open("output.txt","+w")
n_cases = int(f_in.readline())
print(str(n_cases) + " test cases!")
for case_nr in range(n_cases):
    r, t = (int(x) for x in f_in.readline().split())
    ans = solve(r, t)
    f_out.write("Case #" + str(case_nr+1) + ": " + ans + "\n")

f_in.close()
f_out.close()
