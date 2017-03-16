from itertools import chain, combinations

def is_possible(denoms, val):
    denoms = denoms[:]
    if val == 0:
        return True
    elif val in denoms:
        return True
    elif not denoms:
        return False
    elif val < 0:
        return False
    else:
        p = denoms.pop()
        return is_possible(denoms, val - p) or \
            is_possible(denoms, val)

        


def solve(C, V, denom):
    needed = set([])
    ss = sorted((denom + list(needed)) * C)
    for num in range(1, V):
        if is_possible(ss, num):
            continue
        else:
            needed.add(num)
            ss = sorted((denom + list(needed)) * C)
            #print ss
    return len(needed)

if __name__ == '__main__':
    cases = input()
    for case in range(cases):
        # C no more than C coins may be used
        # D num  denominations
        # V max value of stuff to be purchased
        C, D, V = map(int,raw_input().split(" "))
        denom = map(int,raw_input().split(" "))
        solution = solve(C, V, denom)
        print "Case #"+str(case+1)+": "+str(solution)