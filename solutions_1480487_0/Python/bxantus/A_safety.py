
def solve(scores):
    S = sum(scores)
    avg = float(2 * S) / len(scores) # avg = (s1 + s2 + .. sn + sum (somebody gets 100%, or bonuses distrubuted)) / N
    sp = 0 # superflous scores, already distributed to items > avg
    splist = [x - avg for x in scores if x > avg]
    sp = sum(splist)
    avg = avg - float(sp) / (len(scores) - len(splist))

    return [max(float(avg - x) * 100 / S, 0) for x in scores]

def main():
    tc = 'A-small-attempt1'
    f = open("%s.in" % (tc))
    outf = open("%s.out" % (tc), "w")

    T = int(f.readline())

    for i in xrange(1, T + 1):
        scores = [int(x) for x in f.readline().split()][1:]
        result = solve(scores)
        print i, scores
        print result
        outf.write("Case #%d:" % (i))
        for res in result:
            outf.write(" %f" % (res))
        outf.write("\n")

    f.close()
    outf.close()


if __name__ == '__main__':
    main()
