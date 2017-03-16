import math

def get_max(X):
    return ("".join(['9' if x == '?' else x for x in X]))
def get_min(X):
    return ("".join(['0' if x == '?' else x for x in X]))

def awkward(C,J, N, offset, clessj):
    lw = J
    orig = N[1]
    if clessj:
        lw = C
        J = list(get_max(J))
        orig = N[0]
    else:
        C = list(get_max(C))
    orig = list(orig)
    for i in range(offset+1, len(lw)):
        if lw[i] == '?':
            lw[i] = '0'


    while (orig[offset - 1]  == '?') and (offset >= 1):
        lw[offset - 1] = str(int(lw[offset - 1]) + 1)
        if (lw[offset-1] != '10'):
            if clessj:
                return lw, J
            else:
                return C, lw
        else:
            lw[offset-1] = '0'
            offset -= 1

    raise NameError("test")

def solve(N):
    last_change_c = -1
    last_change_j = -1
    C = list(N[0])
    J = list(N[1])
    for i in range(0,len(C)):
        c = C[i]
        j = J[i]
        if (c == '?'):
            last_change_c = i
            if (j == '?'):
                last_change_j = i
                C[i] = '0'
                J[i] = '0'
            else:
                C[i] = j
        elif (j == '?'):
            last_change_j = i
            J[i] = c
        else:

            if j > c:
                jj = get_min(J)
                cc = get_max(C)
                if (int(j) - int(c)) > 5:
                    try:
                        print(cc, jj)
                        xcc, xjj = awkward(C,J,N,i, True)

                        xcc = "".join(xcc)
                        xjj = "".join(xjj)
                        print(xcc, xjj)
                        if (int(jj) - int(cc)) > (int(xcc) - int(xjj)):
                            cc = xcc
                            jj = xjj
                    except:
                        cc = cc
            else:
                jj = get_max(J)
                cc = get_min(C)
                if (int(c) - int(j)) >= 5:
                    try:
                        xcc, xjj = awkward(C,J,N,i, False)
                        xcc = "".join(xcc)
                        xjj = "".join(xjj)
                        if (int(cc) - int(jj)) > (int(xjj) - int(xcc)):
                            cc = xcc
                            jj = xjj
                    except:
                        cc = cc
            print(N)
            return str(cc) + " " + str(jj)
    return "".join(C) + " " +"".join(J)


def output_res(caseno,output, f):
    s = "Case #{}: {}".format(caseno,output)
    print(s)
    f.write(s + "\n")


f = open("input.txt")
f = open("B-small-attempt3.in")
outfile = open("output","w+")
T = int(f.readline())
for case in range(1, T + 1):
    N = [x for x in f.readline().split()]
    output_res(case, solve(N),outfile)

