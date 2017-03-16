def gen_list(S):
    if S == "":
        return [""]
    nL = []
    L = gen_list(S[1:])
    nL = nL + [s + S[0] for s in L]
    nL = nL + [S[0] + s for s in L]
    return nL

def f(S):
    return sorted(gen_list(S[::-1]))[-1]

def g(S):
    r = ""
    for c in S:
        if len(r) > 0 and c >= r[0]:
            r = c + r
        else:
            r = r + c
    return r

def main():
    T = int(raw_input())
    for t in range(1, T + 1):
        word = raw_input().strip()
        print "Case #{0}: {1}".format(t, g(word))

if __name__ == "__main__":
    main()