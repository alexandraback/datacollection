import sys

maxE = -1
def rec(energy,R,values):
    assert energy <= maxE
    #print("rec(%d,%d,%s)" % (energy, R, values))
    N = len(values)
    if N == 1:
        return energy * values[0]

    best = 0
    best_dep = 0
    #for dep_energy in range(min(R,energy), energy+1):
    for dep_energy in range(0, energy+1):
        assert dep_energy <= energy
        new_energy = energy - dep_energy + R
        if new_energy > maxE:
            new_energy = maxE
        x = rec(new_energy, R, values[1:])
        x += dep_energy * values[0]
        if x > best:
            best = x
            best_dep = dep_energy

    #return best_dep, best
    assert best != 0
    return best

def main():
    """
    print rec(5, 3, [2])
    print rec(5, 2, [1000, 1])

    sys.exit(0)
    """
    data = sys.stdin.readlines()
    T = int(data.pop(0).strip())
    for i in range(1,T+1):
        [E, R, N] = map(lambda x:int(x), data.pop(0).split(' '))
        global maxE
        maxE = E
        #print E, R, N
        values = map(lambda x:int(x), data.pop(0).split(' '))

        if E == R:
            best = E * sum(values)
        else:
            best = rec(E, R, values)

        print("Case #%d: %d" % (i, best))

if __name__ == '__main__':
    main()
