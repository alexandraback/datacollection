from math import sqrt

def solve(f):
    ern = f.readline().split()
    e = long(ern[0])
    r = long(ern[1])
    n = long(ern[2])

    v = map(int, f.readline().split())

    output = 0

    energy = e
    i = 0
    while i < n:
        j = i+1
        while j < n:
            if v[j] > v[i]:
                break
            j += 1
        if j >= n:
            output += energy*v[i]
            energy = 0
        else:
            available = max(energy + (j-i)*r - e, 0)
            available = min(available, e)
            output += available*v[i]
            energy -= available
        energy = min(energy + r, e)
        i += 1

    return output



if __name__ == "__main__":
    solve()