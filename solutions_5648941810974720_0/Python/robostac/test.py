import math

def remove(N, c, v, s):
    V = []
    while c in N:
        V.append(v)
        for x in list(s):
            N.remove(x)
    return V

def solve(N):
    N = list(N)
    V = []
    V += (remove(N,'Z', 0, 'ZERO'))
    V += (remove(N, 'W', 2, 'TWO'))
    V += (remove(N, 'X', 6, 'SIX'))
    V += (remove(N, 'G', 8, 'EIGHT'))
    V += (remove(N, 'H', 3, 'THREE'))
    V += (remove(N, 'R', 4, 'FOUR'))
    V += (remove(N, 'F', 5, 'FIVE'))
    V += (remove(N, 'V', 7, 'SEVEN'))
    V += (remove(N, 'I', 9, 'NINE'))
    V += (remove(N, 'N', 1, 'ONE'))

    V.sort()
    return "".join(map(str,V))


def output_res(caseno,output, f):
    s = "Case #{}: {}".format(caseno,output)
    print(s)
    f.write(s + "\n")


f = open("input.txt")
f = open("A-small-attempt0 (1).in")
outfile = open("output","w+")
T = int(f.readline())
for case in range(1, T + 1):

    output_res(case, solve(f.readline().strip()),outfile)

