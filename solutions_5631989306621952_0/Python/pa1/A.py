def gen_list(S):
    if S == "":
        return [""]
    nL = []
    L = gen_list(S[1:])
    nL = nL + [s + S[0] for s in L]
    nL = nL + [S[0] + s for s in L]
    return nL

def main():
    T = int(raw_input())
    for t in range(1, T + 1):
        word = raw_input().strip()[::-1]
        print "Case #{0}: {1}".format(t, sorted(gen_list(word))[-1])

if __name__ == "__main__":
    main()