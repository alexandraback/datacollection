import itertools


def solve(J, P, S, k):
    outfits = []
    check12 = {(j, p): 0 for j in range(J) for p in range(P)}
    check13 = {(j, s): 0 for j in range(J) for s in range(S)}
    check23 = {(p, s): 0 for p in range(P) for s in range(S)}
    for j, p in itertools.product(range(J), range(P)):
        for s in range(S)[::1 if p%2 else -1]:
            if max(check12[(j, p)], check13[(j, s)], check23[(p, s)]) < k:
                outfits.append([j+1, p+1, s+1])
                check12[(j, p)] += 1
                check13[(j, s)] += 1
                check23[(p, s)] += 1
    return outfits


def main():
    input_filename = 'input.txt'
    output_filename = 'output.txt'
    open(output_filename, 'wb').close()
    with open(input_filename, 'r+b') as f:
        with open(output_filename, 'r+b') as g:
            t = int(f.readline().strip())
            for i in range(1, t+1):
                j, p, s, k = map(long, f.readline().strip().split())
                outfits = solve(j, p, s, k)
                # outfits2 = solve(j, s, p, k)
                # outfits3 = solve(p, j, s, k)
                # outfits4 = solve(p, s, j, k)
                # outfits5 = solve(s, j, p, k)
                # outfits6 = solve(s, p, j, k)
                print "Case #%d: %d" % (i, len(outfits))
                # g.write(' '.join(str(len(x)) for x in [outfits, outfits2, outfits3, outfits4, outfits5, outfits6]))
                # g.write("\n")
                # print [len(x) for x in [outfits, outfits2, outfits3, outfits4, outfits5, outfits6]]
                g.write("Case #%d: %d\n" % (i, len(outfits)))
                for outfit in outfits:
                    print ' '.join(map(str, outfit))
                    g.write(' '.join(map(str, outfit)))
                    g.write("\n")


if __name__ == '__main__':
    main()
