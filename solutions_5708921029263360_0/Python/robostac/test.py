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
    print(outfits)
    jp = []
    js = []
    ps = []
    removed = []
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
            removed.append(x)
            continue
        if  js[x[0] - 1][x[2] - 1]  >= N[3]:
            outfits.remove(x)
            removed.append(x)
            continue
        if  ps[x[1] - 1][x[2] - 1] >= N[3]:
            outfits.remove(x)
            removed.append(x)
            continue
        jp[x[0] - 1][x[1] - 1] += 1
        js[x[0] - 1][x[2] - 1] += 1
        ps[x[1] - 1][x[2] - 1] += 1
    if (len(outfits) != N[0] * N[1] * min(N[2],N[3])):

        print(outfits)
        print(removed)
    return outfits



def solve(N):
    # outfits = []
    # jp = []
    # js = []
    # ps = []
    # for j in range(0, N[0]):
    #     x = [0] * N[1]
    #     jp.append(x)
    #     x = [0] * N[2]
    #     js.append(x)
    # for p in range(0, N[1]):
    #     x = [0] * N[2]
    #     ps.append((x))
    #
    # for j in range(0, N[0]):
    #     for p in range(0, N[1]):
    #         for s in range(0, N[2]):
    #           #  print(j,p,s)
    #             if jp[j][p] >= N[3]:
    #                 continue
    #             if (js[j][s] >= N[3]):
    #                 continue
    #             if (ps[p][s] >= N[3]):
    #                 continue
    #             o = [j + 1, p + 1, s + 1]
    #             jp[j][p] += 1
    #             js[j][s] += 1
    #             ps[p][s] += 1
    #             outfits.append(o)
    #         if jp[j][p] >= N[3]:
    #             continue
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
#f = open("input.txt")
#f = open("D-small-attempt2.in")
outfile = open("output","w+")
T = int(f.readline())
for case in range(1, T + 1):
    N = [int(x) for x in f.readline().split()]
    output_res(case, solve(N),outfile)

