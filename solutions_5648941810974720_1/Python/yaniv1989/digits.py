import sys


def f(S):
    r = []
    for t in xrange(3):
        if t == 0:
            first = "ZWUXG"
            nums = [0, 2, 4, 6, 8]
            words = ["ZERO", "TWO", "FOUR", "SIX", "EIGHT"]
        elif t == 1:
            first = "OTFS"
            nums = [1, 3, 5, 7]
            words = ["ONE", "THREE", "FIVE", "SEVEN"]
        else:
            first = "N"
            nums = [9]
            words = ["NINE"]
        for i, c in enumerate(first):
            while c in S:
                for j in xrange(len(words[i])):
                    for k in xrange(len(S)):
                        if S[k] == words[i][j]:
                            S = S[:k] + S[k+1:]
                            break

                r += [nums[i]]
    return sorted(r)


if __name__ == "__main__":
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    else:
        fname = "in.txt"
    
    inp = open(fname, "rb").read()
    inp = inp.splitlines()[1:]

    outp = open(r"out.txt", "wb")
    for i in xrange(len(inp)):
        r = "".join(map(str, f(inp[i])))
        outp.write("Case #%d: " % (i+1) + r + "\r\n")        
        
    outp.close()


