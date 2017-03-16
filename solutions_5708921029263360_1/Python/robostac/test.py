import math

def brute(N):
    outfits = []
    for j in range(0, N[0]):
        for p in range(0, N[1]):
            start = (j + p) % N[2]
            for s in range(start, N[2]):
                o = [j + 1, p + 1, s + 1]
                outfits.append(o)
            for s in range(0, start):
                o = [j + 1, p + 1, s + 1]
                outfits.append(o)
    jp = []
    js = []
    ps = []
    for j in range(0, N[0]):
        x = [0] * N[1]
        jp.append(x)
        x = [0] * N[2]
        js.append(x)
    for p in range(0, N[1]):
        x = [0] * N[2]
        ps.append((x))
    for x in outfits.copy():

        if jp[x[0]-1][x[1]-1]  >= N[3]:
            outfits.remove(x)
            continue
        if  js[x[0] - 1][x[2] - 1]  >= N[3]:
            outfits.remove(x)
            continue
        if  ps[x[1] - 1][x[2] - 1] >= N[3]:
            outfits.remove(x)
            continue
        jp[x[0] - 1][x[1] - 1] += 1
        js[x[0] - 1][x[2] - 1] += 1
        ps[x[1] - 1][x[2] - 1] += 1
    return outfits



def solve(N):

    outfits =brute(N)
    answer = str(len(outfits))
    for x in outfits:
        answer += "\n" + " ".join(map(str,x))
    return answer


def output_res(caseno,output, f):
    s = "Case #{}: {}".format(caseno,output)
    print(s)
    f.write(s + "\n")


f = open("C-small-attempt6.in")
f = open("C-large (1).in")
#f = open("D-small-attempt2.in")
outfile = open("output","w+")
T = int(f.readline())
for case in range(1, T + 1):
    N = [int(x) for x in f.readline().split()]
    output_res(case, solve(N),outfile)

