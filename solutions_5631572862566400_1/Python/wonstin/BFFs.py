import string
import itertools
from collections import defaultdict

def solve(N):
    bffs = map(lambda s : int(s) - 1, raw_input().strip().split())

    print "bffs:"
    for i in range(len(bffs)):
        print i, "->", bffs[i]

    sinks = [kid for kid in range(len(bffs)) if bffs[bffs[kid]] == kid]
    print sinks
    nonsinks = [kid for kid in range(len(bffs)) if kid not in sinks]
    print nonsinks

    tail_lengths = defaultdict(int)
    longest_cycle = 0

    for loner in nonsinks:
        print "finding path for", loner
        seen = [loner]
        tail_length = 1
        loner = bffs[loner]
        while loner not in sinks and loner not in seen:
            tail_length += 1
            seen.append(loner)
            loner = bffs[loner]

        if loner in seen:
            longest_cycle = max(longest_cycle, tail_length - seen.index(loner))
            print "found cycle starting at", loner, "with length", tail_length-seen.index(loner)
        else:
            tail_lengths[loner] = max(tail_length, tail_lengths[loner])
            print "ends at", loner, "with tail length", tail_length

    print "max cycle:", longest_cycle
    print "tails:", tail_lengths
    return max(longest_cycle, len(sinks) + sum(tail_lengths.values()))

def main():

    outfile = open('a.out','w')
    T = int(string.strip(raw_input()))    

    for k in xrange(1,T+1):
        print k
        N = map(int,string.strip(raw_input()).split())[0]

        answer = solve(N) # add appropriate arguments
        outfile.write('Case #%d: %s\n' % (k,answer))

if __name__ == '__main__':
    main()