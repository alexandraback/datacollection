from itertools import permutations
from collections import Counter

def solve(N, Cars):
    """ solve the problem """

    count = 0
    p = permutations(Cars)

    for cars in p:
        letters = ''.join(cars)
        used = set()
        last = None
        ok = True
        for ch in letters:
            if last is None:
                last = ch
                used.add(ch)
            else:
                if ch == last: continue
                else:
                    if ch in used: 
                        ok = False
                        break
                    else:
                        used.add(ch)
                        last = ch
        if ok: count += 1



    return count


def parse():
    """ parse input """

    N = int( input() )
    Cars = [i for i in input().split(' ')]

    return N, Cars


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
