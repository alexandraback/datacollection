from __future__ import print_function
import argparse

def tiles(k, c, s):
    #k * c tiles
    check = [0] * k
    j = 0;
    t = []
    while 0 in check:
        exp = c -1
        current_tile = 0
        for _ in range(c):
            if 0 not in check:
                break
            index = check.index(0)
            check[index] = 1
            current_tile += index * (k ** exp)
            exp -= 1
        current_tile += 1
        t.append(current_tile)
    if len(t) > s:
        return "IMPOSSIBLE"
    return ' '.join([str(x) for x in t])

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('infile')
    args = parser.parse_args()
    with open(args.infile, 'rU') as infile:
        infile.readline()
        j = 1
        for line in infile:
            k, c, s = [int(x) for x in line.split()]
            answer = tiles(k, c, s)
            print("Case #%s: %s" % (j, answer))
            j += 1

if __name__=="__main__":
    main()
